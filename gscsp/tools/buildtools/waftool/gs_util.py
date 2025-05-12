#!/usr/bin/env python
# encoding: utf-8
# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.
"""
GOMSpace Waf tool extension for: utilities
"""
import os
import sys
from waflib import Logs
import gs_setup_buildtools
import gs.buildtools.util

PYTHON_MODULE_TEMPLATE = '''
import %s as current_module
version = getattr(current_module, '__version__', None)
if version is not None:
    print(str(version))
else:
    print('unknown version')
'''


def add_task_param_gen(ctx, name, prefix, input=[], define_prefix=None, header_path=None,
                       gen_struct=False, generate_addr=True):
    pass


def ant_glob(*args, **kwargs):
    """
    Return list of files using Waf's path.ant_glob(), but raises an exception if no files are found
    """
    files = args[0].path.ant_glob(None, **kwargs)
    if len(files) == 0:
        raise Exception('No files found using: %s' % (str(kwargs['incl'])))
    return files


def check_python_module(conf, module_name, var, condition=''):
    """
    Check if the selected python interpreter can import the given python module::

        def configure(conf):
            conf.check_python_module('numpy', 'PYTHON-NUMPY')
            conf.check_python_module('myhdl', 'PYTHON-MYHDL')
            conf.check_python_module('re', 'PYTHON-RE', condition="ver > num(2, 0, 4) and ver <= num(3, 0, 0)")

    :param module_name: module
    :type module_name: string
    :param var: environment variable name to save version string under
    :type var: string
    """
    msg = "Checking for python module %r" % module_name
    if condition:
        msg = '%s (%s)' % (msg, condition)
    conf.start_msg(msg)
    try:
        ret = conf.cmd_and_log(conf.env.PYTHON + ['-c', PYTHON_MODULE_TEMPLATE % module_name])
    except waflib.Errors.WafError:
        conf.end_msg(False)
        conf.fatal('Could not find the python module %r' % module_name)

    ret = ret.strip()
    if condition:
        conf.end_msg(ret)
        if ret == 'unknown version':
            conf.fatal('Could not check the %s version' % module_name)

        from distutils.version import LooseVersion

        def num(*k):
            if isinstance(k[0], int):
                return LooseVersion('.'.join([str(x) for x in k]))
            else:
                return LooseVersion(k[0])
        d = {'num': num, 'ver': LooseVersion(ret)}
        ev = eval(condition, {}, d)
        if not ev:
            conf.fatal('The %s version does not satisfy the requirements' % module_name)
        else:
            conf.env[var] = ret
    else:
        if ret == 'unknown version':
            conf.end_msg(True)
        else:
            conf.end_msg(ret)
        conf.env[var] = ret


def print_to_console(text, fgcolor=None, newline=True):
    print_string = ""
    if fgcolor == "red" or fgcolor == "error":
        print_string += "\033[31m"
    elif fgcolor == "yellow" or fgcolor == "warning":
        print_string += "\033[33m"
    elif fgcolor == "green" or fgcolor == "ok":
        print_string += "\033[32m"
    elif fgcolor == "blue" or fgcolor == "info":
        print_string += "\033[34m"
    elif fgcolor == "magenta" or fgcolor == "info2":
        print_string += "\033[35m"
    elif fgcolor == "cyan" or fgcolor == "info3":
        print_string += "\033[36m"

    print_string += text
    print_string += "\x1b[0m"
    if newline:
        print(print_string)
    else:
        sys.stdout.write(print_string)
