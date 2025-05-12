/* Copyright (c) 2013-2017 GomSpace A/S. All rights reserved. */

#define GS_GOSH_REMOTE_INTERNAL_USE 1

#include <gs/gosh/internal/remote.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <pthread.h>
#include <gs/csp/csp.h>
#include <gs/util/string.h>
#include <gs/util/log.h>

struct thread_args {
    FILE *stdin;
    FILE *stdout;
    csp_conn_t *conn;
    unsigned int timeout;
};

static void * remote_shell_client_reader(void *params)
{
    struct thread_args *args = (struct thread_args *) params;

    while (1) {
        csp_packet_t * packet = csp_read(args->conn, args->timeout);
        if (!packet) {
            log_error("%s: connection timed out", __FUNCTION__);
            break;
        }

        struct gosh_sys_shell_rep *rep = (struct gosh_sys_shell_rep *) packet->data;

        if (rep->err != 0) {
            log_debug("%s: non-error returned", __FUNCTION__);
            csp_buffer_free(packet);
            break;
        }

        rep->output[sizeof(rep->output) - 1] = '\0';
        const size_t len = strlen(rep->output);
        if (fwrite(rep->output, 1, len, args->stdout) != len) {
            log_warning("%s: write failed", __FUNCTION__);
            csp_buffer_free(packet);
            break;
        }

        csp_buffer_free(packet);
    }

    /* Send DONE */
    log_debug("%s: sending DONE", __FUNCTION__);
    struct gosh_sys_shell_req req = {
        .type = GOSH_TYPE_SYS_SHELL_REQ,
        .flags = GOSH_FLAG_DONE,
    };
    if (csp_transaction_persistent(args->conn, args->timeout, &req, shell_request_size(1), NULL, 0) == 0) {
        log_warning("%s: could not send DONE packet", __FUNCTION__);
    }

    log_debug("%s: client reader exit", __FUNCTION__);

    pthread_exit(NULL);
}

static int readinput(int fd, char *line, int max)
{
    int r;

    r = read(fd, line, max);
    if (r < 1)
        return 0;

    line[r] = '\0';

    return r + 1;
}

static void * remote_shell_client_writer(void *params)
{
    struct thread_args * args = (struct thread_args *) params;

    int r = 1;
    while (r > 0) {
        struct gosh_sys_shell_req req;
        r = readinput(fileno(args->stdin), req.input, sizeof(req.input));
        if (r <= 0) {
            req.flags = GOSH_FLAG_DONE;
        }

        req.type = GOSH_TYPE_SYS_SHELL_REQ;
        if (csp_transaction_persistent(args->conn, args->timeout, &req, shell_request_size(r), NULL, 0) == 0)
            break;
    }

    log_debug("%s: client writer exit", __FUNCTION__);

    pthread_exit(NULL);
}

gs_error_t gs_gosh_remote_shell_stdio(uint8_t node, unsigned int timeout, bool raw, const char *command, FILE *stdin, FILE *stdout)
{
    //struct termios orig_termios[3];
    //tcgetattr(STDIN_FILENO,  &orig_termios[0]);
    //tcgetattr(STDOUT_FILENO, &orig_termios[1]);
    //tcgetattr(STDERR_FILENO, &orig_termios[2]);

    log_info("%s: connecting to %u:%u, timeout: %u mS", __FUNCTION__, node, GS_CSP_PORT_REMOTE_SHELL, timeout);

    csp_conn_t *conn = csp_connect(CSP_PRIO_NORM, node, GS_CSP_PORT_REMOTE_SHELL, timeout, CSP_O_RDP);
    if (!conn) {
        log_error("%s: failed to connect", __FUNCTION__);
        return GS_ERROR_IO;
    }

    struct gosh_sys_shell_req req = {
        .type = GOSH_TYPE_SYS_SHELL_REQ,
        .flags = raw ? GOSH_FLAG_CHAR : 0,
    };
    GS_STRNCPY(req.input, command);

    if (csp_transaction_persistent(conn, timeout, &req, shell_request_size(strlen(req.input) + 1), NULL, 0) == 0)
        goto out;

    struct thread_args args = {
        .stdin = stdin,
        .stdout = stdout,
        .conn = conn,
        .timeout = timeout,
    };

    /* Spawn reader/writer threads and wait for them to exit */
    pthread_t treader = 0;
    pthread_create(&treader, NULL, remote_shell_client_reader, &args);

    pthread_t twriter = 0;
    if (stdin) {
        pthread_create(&twriter, NULL, remote_shell_client_writer, &args);
    } else {
        log_debug("%s: No stdin specified - client writer wont be started", __FUNCTION__);
    }

    pthread_join(treader, NULL);

    if (twriter) {
        pthread_cancel(twriter);
        pthread_join(twriter, NULL);
    }

out:
    csp_close(conn);

    //tcsetattr(STDIN_FILENO,  TCSAFLUSH, &orig_termios[0]);
    //tcsetattr(STDOUT_FILENO, TCSAFLUSH, &orig_termios[1]);
    //tcsetattr(STDERR_FILENO, TCSAFLUSH, &orig_termios[2]);

    return GS_OK;
}

gs_error_t gs_gosh_remote_shell(uint8_t node, unsigned int timeout, bool raw, const char *command)
{
    return gs_gosh_remote_shell_stdio(node, timeout, raw, command, stdin, stdout);
}
