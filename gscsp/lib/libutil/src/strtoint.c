/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. [rescinded 22 July 1999]
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*

@deftypefn Supplemental {long int} strtol (const char *@var{string}, @
  char **@var{endptr}, int @var{base})
@deftypefnx Supplemental {unsigned long int} strtoul (const char *@var{string}, @
  char **@var{endptr}, int @var{base})

The @code{strtol} function converts the string in @var{string} to a
long integer value according to the given @var{base}, which must be
between 2 and 36 inclusive, or be the special value 0.  If @var{base}
is 0, @code{strtol} will look for the prefixes @code{0} and @code{0x}
to indicate bases 8 and 16, respectively, else default to base 10.
When the base is 16 (either explicitly or implicitly), a prefix of
@code{0x} is allowed.  The handling of @var{endptr} is as that of
@code{strtod} above.  The @code{strtoul} function is the same, except
that the converted value is unsigned.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include <ctype.h>
#include <gs/util/error.h>
#include <gs/util/string.h>

/*
 * Convert a string to a long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
int32_t gs_string_strto32int(const char *nptr, char **endptr, uint8_t base, gs_error_t * err)
{
    register const char *s = nptr;
    register uint32_t acc;
    register int c;
    register uint32_t cutoff;
    register int neg = 0, any, cutlim;

    /*
     * Skip white space and pick up leading +/- sign if any.
     * If base is 0, allow 0x for hex and 0 for octal, else
     * assume decimal; if base is already 16, allow 0x.
     */
    do
    {
        c = *s++;
    } while (isspace(c));
    if (c == '-')
    {
        neg = 1;
        c = *s++;
    } else if (c == '+')
    {
        c = *s++;
    }
    if ((base == 0 || base == 16) &&
            c == '0' && (*s == 'x' || *s == 'X'))
    {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
    {
        base = c == '0' ? 8 : 10;
    }

    /*
     * Compute the cutoff value between legal numbers and illegal
     * numbers.  That is the largest legal value, divided by the
     * base.  An input number that is greater than this value, if
     * followed by a legal input character, is too big.  One that
     * is equal to this value may be valid or not; the limit
     * between valid and invalid numbers is then based on the last
     * digit.  For instance, if the range for longs is
     * [-2147483648..2147483647] and the input base is 10,
     * cutoff will be set to 214748364 and cutlim to either
     * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
     * a value > 214748364, or equal but the next digit is > 7 (or 8),
     * the number is too big, and we will return a range error.
     *
     * Set any if any `digits' consumed; make it negative to indicate
     * overflow.
     */
    cutoff = neg ? -(uint32_t)INT32_MIN : INT32_MAX;
    cutlim = cutoff % (uint32_t)base;
    cutoff /= (uint32_t)base;
    for (acc = 0, any = 0;; c = *s++)
    {
        if (isdigit(c))
        {
            c -= '0';
        }
        else if (isalpha(c))
        {
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        }
        else
        {
            break;
        }
        if (c >= base)
        {
            break;
        }
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
        {
            any = -1;
        }
        else
        {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0)
    {
        acc = neg ? INT32_MIN : INT32_MAX;
        *err = GS_ERROR_OVERFLOW;
    } else if (neg)
    {
        acc = -acc;
    }
    if (endptr != 0)
    {
        *endptr = (char *) (any ? s - 1 : nptr);
    }
    return (acc);
}


/*
 * Convert a string to an unsigned long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
uint32_t gs_string_strto32uint(const char *nptr, char **endptr, uint8_t base, gs_error_t * err)
{
    register const char *s = nptr;
    register uint32_t acc;
    register int32_t c;
    register uint32_t cutoff;
    register int32_t neg = 0, any, cutlim;

    /*
     * See strtol for comments as to the logic used.
     */
    do
    {
        c = *s++;
    } while (isspace(c));
    if (c == '-')
    {
        neg = 1;
        c = *s++;
    } else if (c == '+')
    {
        c = *s++;
    }
    if ((base == 0 || base == 16) &&
            c == '0' && (*s == 'x' || *s == 'X'))
    {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
    {
        base = c == '0' ? 8 : 10;
    }
    cutoff = (uint32_t)UINT32_MAX / (uint32_t)base;
    cutlim = (uint32_t)UINT32_MAX % (uint32_t)base;
    for (acc = 0, any = 0;; c = *s++)
    {
        if (isdigit(c))
        {
            c -= '0';
        }
        else if (isalpha(c))
        {
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        }
        else
        {
            break;
        }
        if (c >= base)
        {
            break;
        }
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
        {
            any = -1;
        }
        else
        {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0)
    {
        acc = UINT32_MAX;
        *err = GS_ERROR_OVERFLOW;
    } else if (neg)
    {
        acc = -acc;
    }
    if (endptr != 0)
    {
        *endptr = (char *) (any ? s - 1 : nptr);
    }
    return (acc);
}


int64_t gs_string_strto64int(const char *nptr, char **endptr, uint8_t base, gs_error_t * err)
{
    register const char *s = nptr;
    register uint64_t acc;
    register int32_t c;
    register uint64_t cutoff;
    register int32_t neg = 0, any, cutlim;

    /*
     * Skip white space and pick up leading +/- sign if any.
     * If base is 0, allow 0x for hex and 0 for octal, else
     * assume decimal; if base is already 16, allow 0x.
     */
    do {
        c = *s++;
    } while (isspace(c));
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
            c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;

    /*
     * Compute the cutoff value between legal numbers and illegal
     * numbers.  That is the largest legal value, divided by the
     * base.  An input number that is greater than this value, if
     * followed by a legal input character, is too big.  One that
     * is equal to this value may be valid or not; the limit
     * between valid and invalid numbers is then based on the last
     * digit.  For instance, if the range for longs is
     * [-2147483648..2147483647] and the input base is 10,
     * cutoff will be set to 214748364 and cutlim to either
     * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
     * a value > 214748364, or equal but the next digit is > 7 (or 8),
     * the number is too big, and we will return a range error.
     *
     * Set any if any `digits' consumed; make it negative to indicate
     * overflow.
     */
    cutoff = neg ? -(uint64_t)INT64_MIN : INT64_MAX;
    cutlim = cutoff % (uint64_t)base;
    cutoff /= (uint64_t)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? INT64_MIN : INT64_MAX;
        *err = GS_ERROR_OVERFLOW;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *) (any ? s - 1 : nptr);
    return (acc);
}


/*
 * Convert a string to an unsigned long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */

uint64_t gs_string_strto64uint(const char *nptr, char **endptr, uint8_t base, gs_error_t * err)
{
    register const char *s = nptr;
    register uint64_t acc;
    register int32_t c;
    register uint64_t cutoff;
    register int32_t neg = 0, any, cutlim;

    /*
     * See strtol for comments as to the logic used.
     */
    do {
        c = *s++;
    } while (isspace(c));
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
            c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (uint64_t)UINT64_MAX / (uint64_t)base;
    cutlim = (uint64_t)UINT64_MAX % (uint64_t)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = UINT64_MAX;
        *err = GS_ERROR_OVERFLOW;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *) (any ? s - 1 : nptr);
    return (acc);
}
