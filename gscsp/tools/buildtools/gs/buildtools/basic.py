# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.

"""
Basic (simple) utilities.

NOTE: Try not to import other buildtools modules.
"""

import os
import sys
import inspect
import time
import subprocess

# Check if we should use colors
USE_COLOR = sys.platform.startswith('linux')
if not USE_COLOR:
    pass
if ('NOCOLOR' in os.environ) or 'NO_COLOR' in os.environ:
    # Colors disabled through
    USE_COLOR = False
elif 'INSIDE_EMACS' in os.environ:
    # Compiling from Emacs uses internal coloring, but not ANSI colors, disable it explicit
    USE_COLOR = False
elif not (hasattr(sys.stdout, 'isatty') and os.isatty(1)) or not (hasattr(sys.stderr, 'isatty') and os.isatty(2)):
    # Enable ANSI colors if a tty and not redirected (individual for STDOUT, STDERR)
    USE_COLOR = False
else:
    # If '--color no' has been passed to waf, do not use colors
    try:
        if '--color' in sys.argv:
            if sys.argv[sys.argv.index('--color') + 1] == 'no':
                USE_COLOR = False
    except Exception:
        pass

if not USE_COLOR:
    os.environ['NOCOLOR'] = '1'
    os.environ['NO_COLOR'] = '1'


_datatypes = {"uint8": ["UINT8", 1, "uint8_t"],
              "uint16": ["UINT16", 2, "uint16_t"],
              "uint32": ["UINT32", 4, "uint32_t"],
              "uint64": ["UINT64", 8, "uint64_t"],
              "int8": ["INT8", 1, "int8_t"],
              "int16": ["INT16", 2, "int16_t"],
              "int32": ["INT32", 4, "int32_t"],
              "int64": ["INT64", 8, "int64_t"],
              "x8": ["X8", 1, "uint8_t"],
              "x16": ["X16", 2, "uint16_t"],
              "x32": ["X32", 4, "uint32_t"],
              "x64": ["X64", 8, "uint64_t"],
              "double": ["DOUBLE", 8, "double"],
              "float": ["FLOAT", 4, "float"],
              "string": ["STRING", -1, "char"],
              "data": ["DATA", -1, "uint8_t"],
              "bool": ["BOOL", 1, "bool"]}


def sizeof(type):
    return _datatypes[type][1]


def use_color():
    return USE_COLOR


def mkdirs(path, mode=777):
    try:
        os.makedirs(path)
    except OSError as e:
        # be happy if someone already created the path
        if e.errno != os.errno.EEXIST:
            raise


def file_callee():
    for frame in inspect.stack():
        file = inspect.getfile(frame[0])
        if "buildtools" not in file:
            caller = inspect.getframeinfo(frame[0])
            return caller.filename, caller.lineno
    return ".", 0


def dir_callee():
    for frame in inspect.stack():
        file = inspect.getfile(frame[0])
        if "buildtools" not in file:
            return os.path.dirname(file)
    return "."


def byteify(input):
    if isinstance(input, dict):
        return {byteify(key): byteify(value)
                for key, value in input.items()}
    elif isinstance(input, list):
        return [byteify(element) for element in input]
    elif isinstance(input, unicode):
        return input.encode('utf-8')
    else:
        return input


def get_iso8601(seconds=None):
    """
    Returns ISO8601 timestamps.
    """
    if seconds is None:
        seconds = time.time()
    return (time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime(seconds)),
            time.strftime("%Y-%m-%d", time.gmtime(seconds)),
            time.strftime("%H:%M:%SZ", time.gmtime(seconds)))


def buildtools_root():
    return os.environ['GS_BUILDTOOLS']


def is_project_root(dir):
    """
    Returns True if directory is project root.
    NOTE: This only works, if gsbuildtools_bootstrap.py has been run from project root.
    """
    if dir:
        path = os.path.join(dir, '.waf_gs_project_root')
        if os.path.isfile(path):
            return True
    return False


def get_project_root():
    """
    Returns project root directory
    NOTE: This only works, if gsbuildtools_bootstrap.py has been run from project root.
    """
    path = os.getcwd()
    while path:
        if is_project_root(path):
            return path
        (path, tail) = os.path.split(path)
        if not path or not tail:
            break

    raise Exception("get_project_root() failed, could not find root above [%s] "
                    "- please run gsbuildtools_bootstrap.py from root" % (dir))


def is_component_root(dir):
    """
    Returns True if directory is component root.
    NOTE: This only works with GIT and sub-modules.
    """
    if dir:
        path = os.path.join(dir, '.git')
        if os.path.isdir(path) or os.path.isfile(path):
            return True
        return False
    return True


def create_dir_for_filename(filename):
    mkdirs(os.path.dirname(filename))


def flush():
    sys.stdout.flush()
    sys.stderr.flush()


def execute(cmd, dir=None, ignore_exit_code=False, interactive=False, env=None, output=None):
    if not dir:
        dir = '.'
    dir = os.path.abspath(dir)

    if env:
        copy = os.environ.copy()
        copy.update(env)
        env = copy

    cmd_str = ' '.join(cmd)
    docker_str = ''
    if "GS_IN_DOCKER" in os.environ:
        docker_str = '(docker:%s)' % os.environ.get('GS_DOCKER_IMAGE_NAME', '?')
    print('CMD%s: [%s], dir: [%s]' % (docker_str, cmd_str, dir))

    flush()
    if interactive:
        exit_code = os.system(cmd_str)
    else:
        exit_code = subprocess.Popen(cmd, cwd=dir, stdout=output, stderr=output, env=env).wait()
    flush()
    if exit_code:
        error_str = "CMD FAILED: [%s], dir: [%s], exit code: %s" % (cmd_str, dir, str(exit_code))
        if ignore_exit_code:
            print(error_str)
        else:
            raise Exception(error_str)


def print_gcc_diagnostic(message, file=None, line=None, column=None, line_content=None,
                         category=None, type=None):
    """
    Print GCC formated diagnostic message, e.g. warning

    Default values for fileref and lineref, will allow content to be parsable by IDEs, e.g. Emacs.
    """

    file = ((str(file) + ':') if file else '.:')
    line = ((str(line) + ':') if line else '0:')
    column = ((str(column) + ':') if column else '')
    line_content = ((': "%s"' % str(line_content).strip()) if line_content else '')
    category = (str(category) if category else 'gsbuildtools')
    type = (str(type) if type else 'warning')

    # Color codes (as gcc)
    if use_color():
        color_file = '[01m[K'
        color_warn = '[01;35m[K'
        color_reset = '[m[K'
    else:
        color_file = ''
        color_warn = ''
        color_reset = ''

    print('%s%s%s%s%s %s%s%s: %s: %s%s\n' %
          (color_file, file, line, column, color_reset,
           color_warn, type, color_reset,
           category, message, line_content))


def print_gcc_warning(message, file=None, line=None, column=None, line_content=None,
                      category=None):
    print_gcc_diagnostic(message, file=file, line=line, column=column, line_content=line_content,
                         category=category, type='warning')
