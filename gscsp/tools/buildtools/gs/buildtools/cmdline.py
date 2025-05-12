#!/usr/bin/python
# Copyright (c) 2013-2018 GomSpace A/S. All rights reserved.

import sys
import os
import datetime
import stat
import re
import argparse
import shutil

from gs.buildtools import util


def cmd_where(args):
    print("GOMspace buildtools: %s" % util.buildtools_root())


def link_waf(dir, docker=False):
    if not docker:
        target = os.path.join(util.buildtools_root(), 'waftool/waf')
    else:
        target = os.path.join(util.buildtools_root(), 'tools/dock_waf')

    linkname = os.path.join(dir, 'waf')
    if os.path.isfile(linkname) and not os.path.islink(linkname):
        return
    try:
        os.remove(linkname)
    except OSError:
        pass
    os.symlink(target, linkname)


def create_gsbuildtools(dir):
    bootstrap = os.path.join(dir, "gsbuildtools_bootstrap.py")
    helper = os.path.join(dir, "gsbuildtools.py")
    if os.path.exists(bootstrap) and os.path.exists(helper):
        return

    try:
        os.remove(helper)
    except OSError:
        pass
    with open(helper, 'w') as f:
        f.write("#!/usr/bin/env python\n")
        f.write("# Copyright (c) 2013-{0} GomSpace A/S. All rights reserved.\n".format(datetime.datetime.now().year))
        f.write("import sys\n")
        f.write("import os\n")
        f.write("_buildtools_root = '" + util.buildtools_root() + "'\n")
        f.write("os.environ['GS_BUILDTOOLS'] = _buildtools_root\n")
        f.write("sys.path.append(_buildtools_root)\n")
        f.write("\n")
        f.write("if __name__ == '__main__':\n")
        f.write("    from gs.buildtools import cmdline\n")
        f.write("    cmdline.syscmd(sys.argv)\n")
    os.chmod(helper, stat.S_IRUSR | stat.S_IXUSR | stat.S_IRGRP | stat.S_IXGRP)


def wscript_uses_buildtools(wscript):
    with open(wscript, 'r') as fd:
        content = fd.read()
        if re.search('gs_gcc|gs_test|gs_util|gs.buildtools|gs_doc|gs_hdl', content):
            # print "file is using buildtools" + wscript
            return True
    return False


def check_if_force_docker(enabled):
    ret_val = enabled
    if 'gsbuildall.py' in os.listdir('.'):
        with open('gsbuildall.py') as fp:
            data = fp.read()
            if 'FORCE_DOCKER_ON' in data:
                ret_val = True
            if 'FORCE_DOCKER_OFF' in data:
                ret_val = False
    if ret_val != enabled:
        print('Docker setting forced to [%d] by gsbuildall.py' % int(ret_val))
    return ret_val


def configure_project(bootstrap=False, docker=False):
    docker = check_if_force_docker(docker)
    try:
        import docker_functions
    except ImportError:
        docker = False
    if docker:
        print("Setting up project to use buildtools with docker: " + util.buildtools_root())
    else:
        print("Setting up project to use buildtools (no docker): " + util.buildtools_root())
    prf = '.waf_gs_project_root'
    if bootstrap:
        open(prf, 'w').close()
    for root, dirs, files in os.walk('.'):
        if bootstrap and (root != '.') and (prf in files):
            os.remove(os.path.join(root, prf))
        if 'gsbuildall.py' in files:
            create_gsbuildtools(root)
            link_waf(root, docker=docker)
        elif ('wscript' in files) and wscript_uses_buildtools(os.path.join(root, 'wscript')):
            link_waf(root, docker=docker)
        if bootstrap:
            for d in dirs:
                if re.search(r'^\.waf-\d+\.\d+.*', d):
                    shutil.rmtree(os.path.join(root, d))


def cmd_setup(args):
    configure_project(bootstrap=False, docker=(not args.no_docker))


def cmd_bootstrap(args):
    configure_project(bootstrap=True, docker=(not args.no_docker))


def get_main_parser():
    # create the top-level parser
    main_parser = argparse.ArgumentParser(description="GOMspace buildtools commandline")
    subparser = main_parser.add_subparsers(title='Commands')

    # Basic buildtools commands
    parser = subparser.add_parser('where', help='show where buildtools is located')
    parser.set_defaults(func=cmd_where)

    parser = subparser.add_parser('setup', help='create links to Waf/scripts (recursively from current directory)')
    parser.add_argument('-d', '--docker', action='store_true', default=False,
                        help='Use docker (default) - deprecated/ignored')
    parser.add_argument('-n', '--no-docker', action='store_true', default=False,
                        help='Do NOT use docker')
    parser.set_defaults(func=cmd_setup)

    parser = subparser.add_parser('bootstrap', help='run "setup" and mark current directory as project root')
    parser.add_argument('-d', '--docker', action='store_true', default=False,
                        help='Use docker (default) - deprecated/ignored')
    parser.add_argument('-n', '--no-docker', action='store_true', default=False,
                        help='Do NOT use docker')
    parser.set_defaults(func=cmd_bootstrap)

    # Extended buildtools commands
    try:
        import gs.buildtools.check
        gs.buildtools.check.add_cmdline(subparser)

    except ImportError:
        pass

    try:
        import gs.buildtools.foreach
        gs.buildtools.foreach.add_cmdline(subparser)
    except ImportError:
        pass

    try:
        import gs.buildtools.status
        gs.buildtools.status.add_cmdline(subparser)
        import gs.buildtools.verify_build
        gs.buildtools.verify_build.add_cmdline(subparser)

    except ImportError as e:
        pass

    try:
        import gs.buildtools.git
        gs.buildtools.git.add_cmdline(subparser)
        gs.buildtools.git.add_clone_cmdline(subparser)

    except ImportError:
        pass

    try:
        import gs.buildtools.gcov
        gs.buildtools.gcov.add_cmdline(subparser)
    except ImportError:
        pass

    try:
        import gs.buildtools.dependencies
        gs.buildtools.dependencies.add_cmdline(subparser)
    except ImportError:
        pass

    return main_parser


def syscmd(argv):
    args = get_main_parser().parse_args(argv[1:])
    args.func(args)
