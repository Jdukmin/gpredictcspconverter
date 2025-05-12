#!/usr/bin/python
# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.

import sys
import os


def find_buildtools(project_root):
    if os.path.isfile(os.path.join(project_root, "gsbuildtools_bootstrap.py")):
        return project_root

    if os.path.isdir(os.path.join(project_root, "tools/buildtools")):
        return os.path.join(project_root, "tools/buildtools")

    return os.path.dirname(os.path.realpath(__file__))


if __name__ == "__main__":
    project_root = os.getcwd()
    buildtools_root = find_buildtools(project_root)
    os.environ['GS_BUILDTOOLS'] = buildtools_root
    sys.path.insert(0, buildtools_root)

    import gs.buildtools.cmdline

    try:
        gs.buildtools.cmdline.syscmd(['', 'bootstrap'] + sys.argv[1:])
    except:  # noqa
        print("Update your buildtools version to support 'bootstrap' option")
        gs.buildtools.cmdline.syscmd(['', 'setup'])
