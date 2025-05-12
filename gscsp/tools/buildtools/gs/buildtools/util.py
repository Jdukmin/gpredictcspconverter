# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.

import os
import subprocess
import re
import sys
import pprint
import errno
import shutil
import glob
import json

from gs.buildtools import basic

# Extended buildtools only
try:
    from gs.buildtools import docker_functions
except ImportError as e:
    docker_functions = None
try:
    from gs.buildtools import foreach
except ImportError:
    foreach = None


git_present_cache = [False, False]  # [is tested, is present]


def check_output(cmd, **kws):
    result = subprocess.check_output(cmd, **kws)
    if sys.version_info.major < 3:
        return result
    return result.decode('utf-8')


def sizeof(type):
    return basic.sizeof(type)


def mkdirs(path, mode=777):
    return basic.mkdirs(path, mode)


def file_callee():
    return basic.file_callee()


def dir_callee():
    return basic.dir_callee()


def byteify(input):
    return basic.byteify(input)


def get_iso8601(seconds=None):
    return basic.get_iso8601(seconds)


def git_present():
    if git_present_cache[0]:
        return git_present_cache[1]
    git_present_cache[0] = True  # Is tested
    try:
        output = check_output(['git', 'remote', '-v'], stderr=subprocess.STDOUT)
        if 'github.com' in output.lower() and 'gomspace' in output.lower():
            git_present_cache[1] = True
            return True
    except Exception as e:
        print(e)
        pass
    git_present_cache[1] = False
    return False


def list_append_unique(list, elm):
    if elm not in list:
        list += [elm]


def get_relative_git_path():
    proj_path = get_project_root()
    path = os.getcwd()
    if path == proj_path:
        return os.path.basename(path)
    path = re.sub(r'^' + proj_path + '/', '', path)
    return path


def get_git_info(tag=None, forcedTag=None, extendedInfo=False, gitTagPattern=None, allowLightweight=True):
    """
    Return GiT information as a dictionary
    """
    # get version information
    def _get_version():
        # Always use 'forcedTag' if specified
        if forcedTag:
            return forcedTag

        # Try the VERSION file
        try:
            with open('VERSION', 'r') as f:
                return f.read().replace('\n', '').strip()
        except IOError:
            pass

        # Try GiT
        if git_present():
            cmd = ['git', 'describe', '--long', '--always', '--dirty=+']
            # Wait for --exclude support in GiT 2.12+ -> Ubuntu 18.04
            # if allowLightweight:
            #    cmd += ['--tags', '--exclude', '*-latest']
            if gitTagPattern is not None:
                cmd += ["--match", gitTagPattern]
            gittag = check_output(cmd).strip()
            return gittag

        # Default to 'tag'
        return tag

    tag = _get_version()
    if not tag:
        raise Exception("No version tag found: no 'forcedTag' (API), "
                        "no VERSION file, GiT is not present, no 'tag' (API)")

    variant = None
    revision = None
    elms = tag.split('/')
    if len(elms) == 1:
        revision = elms[0]
    if len(elms) >= 2:
        variant = elms[0]
        revision = elms[1]

    if variant and re.search(r'[^a-zA-Z0-9-]', variant):
        raise Exception("Invalid variant [%s] in tag [%s]" % (variant, tag))

    revision = re.sub(r'^v', '', revision)  # remove legacy leading 'v'

    info = {}
    info['revision'] = revision
    info['variant'] = variant

    version = None
    version_only = None
    dirty = False
    shortcommit = None

    # version tag in revision: <version>-<commits_after>-g<shortcommit>[dirty]
    m = re.search(r'^([0-9]+(?:\.[0-9]+)+)-([0-9]+)-g([a-f0-9]+)(\+)?$', revision)
    if m and m.lastindex >= 3:
        version_only = m.group(1)
        shortcommit = m.group(3)
        if m.lastindex >= 4:
            dirty = True
        if int(m.group(2)) or dirty:
            version = revision  # none-tagged release, use revision
        else:
            version = version_only  # only use version number

    else:
        m = re.search(r'^([a-f0-9]+)(\+)?$', revision)
        if m and m.lastindex >= 1:
            # no version tag - just short commit - so use that as version
            shortcommit = m.group(1)
            version = shortcommit
            if m.lastindex >= 2:
                dirty = True
        else:
            m = re.search(r'^([0-9]+(?:\.[0-9]+)+)?$', revision)
            if m and m.lastindex >= 1:
                version = version_only = revision
            else:
                raise Exception("Invalid tag [%s]" % (tag))

    info['version'] = version
    info['version_only'] = version_only
    info['dirty'] = dirty
    info['shortcommit'] = shortcommit
    if info['version_only']:
        if len(info['version_only'].split('.')) == 3:
            info['major'], info['minor'], info['fix'] = info['version_only'].split('.')

    # if tag provided (usually written in wscript), we should validate against GiT
    # - but tag will soon be removed, so we skip

    if extendedInfo:

        commit = None
        tags = []
        branches = []

        cmd = ['git', 'rev-parse', 'HEAD']
        commit = check_output(cmd).strip()
        if not re.match(r'^[a-f0-9]+$', commit):
            raise Exception("Invalid commit [%s]" % (commit))
        if not commit.startswith(shortcommit):
            raise Exception("Mismatch in commit SHAs [%s] [%s]" % (commit, shortcommit))

        info['commit'] = commit
        info['path'] = get_relative_git_path()

        cmd = ['git', 'branch', '-a', '--contains', commit]
        out = check_output(cmd).strip()
        pattern = re.compile(r'^\s*\*?\s*([^()/\n]+)$', re.MULTILINE)
        for m in re.finditer(pattern, out):
            list_append_unique(branches, m.group(1).strip())
        pattern = re.compile(r'^.+/([^/\n].+)$', re.MULTILINE)
        for m in re.finditer(pattern, out):
            list_append_unique(branches, m.group(1).strip())

        cmd = ['git', 'tag', '--contains', commit]
        out = check_output(cmd).strip()
        pattern = re.compile(r'^(.+)', re.IGNORECASE | re.MULTILINE)
        for m in re.finditer(pattern, out):
            list_append_unique(tags, m.group(1))

        info['tags'] = tags
        info['branches'] = branches

        cmd = 'git remote -v'.split()
        output = check_output(cmd)
        repo_name_pat = re.compile(r'/([a-zA-Z0-9_\-]+)')
        url_pat = re.compile(r'((git@|https)[a-zA-Z0-9\-_./:]+)')

        for l in output.split('\n'):
            m = repo_name_pat.findall(l)
            if len(m) > 0:
                info['repo_name'] = m[-1]
            m = url_pat.search(l)
            if m:
                info['url'] = m.group(0)

        # Tags on current branch
        cmd = ['git', 'tag', '--merged', 'HEAD']
        info['branch_tags'] = check_output(cmd).strip().split('\n')

    return info


class build_info:
    def __init__(self, info={}):
        self.__info = info

    def __str__(self):
        str = pprint.pformat(self.__info) + "\n"
        str += "doc revision     : " + self.doc_revision() + "\n"
        str += "filename revision: " + self.filename_revision() + "\n"
        str += "model(<model>)   : " + self.model("<model>")
        return str

    def value(self, key):
        if (key in self.__info):
            return self.__info[key]
        return None

    def info(self):
        return self.__info

    def variant(self):
        return self.value('variant')

    def revision(self):
        return self.value('revision')

    def doc_revision(self):
        ret = ''
        variant = self.variant()
        if variant:
            ret += variant + '-'
        ret += self.__info['version']
        return ret

    def filename_revision(self):
        return self.doc_revision()

    def model(self, model):
        variant = self.variant()
        if variant:
            model += '-' + variant
        return model


def get_build_info(appName=None, tag=None, seconds=None, forcedTag=None, writeToArtifacts=False, gitTagPattern=None):
    """
    Return build information, e.g. timestamps, revision, etc.
    """
    info = get_git_info(tag, forcedTag, gitTagPattern=gitTagPattern)
    if info['version'] is None:
        raise Exception("No tag found in github repository - it is needed in get_build_info (e.g., in doc)")
    (info['timestamp'], info['date'], info['time']) = get_iso8601(seconds)
    info['time_csp'] = re.sub(r'Z$', '', info['time'])
    if appName:
        info['appname'] = appName
    if writeToArtifacts:
        filename = os.path.join(artifact_dir_name(), "build_info.json")
        create_dir_for_filename(filename)
        with open(filename, 'w') as f:
            json.dump(info, f, indent=4, separators=(',', ': '))
    return build_info(info)


def flush():
    basic.flush()


def execute_in_docker(cmd, dir=None, ignore_exit_code=False, interactive=False, env=None, output=None,
                      docker_image=None, docker_args=None, no_docker_in_docker=False, part=None, pull=False):
    # Use docker if possible
    if docker_functions:
        docker_functions.run(dir, cmd, docker_image=docker_image, docker_args=docker_args,
                             interactive=interactive, pull=pull, no_docker_in_docker=no_docker_in_docker,
                             part=part, env=env, output=output)
    else:
        basic.execute(dir, cmd, ignore_exit_code=ignore_exit_code, interactive=interactive, env=env, output=output)


def bash_command(command, dir=None, docker_image=None, part=None):
    execute_in_docker(['/bin/bash', '-c', ' '.join(command)], dir=dir, docker_image=docker_image, part=part)


def waf_command_exec(cmd, options, dir, force_docker_img=None):
    cmd = ['python', 'waf'] + cmd + options
    if docker_functions and force_docker_img:
        cmd = cmd + ["--container", force_docker_img]
    basic.execute(cmd, dir=dir)


def waf_command(options=[],
                cmd=['distclean', 'configure', 'clean', 'build'],
                dir='.',
                recurse=False,
                force_docker_img=None):
    """
    Run a ``waf`` command

    :param options: a list of command line options passed to ``waf``
    :param cmd: a list of subcommands to run with ``waf``, useful when wanting to build ``doc`` or ``gs_dist``
    :param dir: the working directory for the ``waf`` command.
    :param recurse: If True run the ``waf`` command in all subfolder with a wscript
    :param force_docker_img: If set the waf command will be executed using the specified docker image
    """
    if recurse:
        for tgt_dir in recurse_for_wscript(dir):
            waf_command_exec(cmd, options, dir=tgt_dir, force_docker_img=force_docker_img)
    else:
        waf_command_exec(cmd, options, dir=dir, force_docker_img=force_docker_img)


def build_command(options=[], dir='.'):
    """
    Build with default options
    """
    waf_command(options=options, dir=dir)


def doc_command(dir='.'):
    """
    Build the documentation of the project
    """
    waf_command(cmd=['configure', 'doc'], dir=dir)


def test_command(options=[], dir='tst', recurse=True):
    """
    Run all unit tests in the tst folder
    """
    waf_command(options=options, dir=dir, recurse=recurse)


def dist_command(cmd=[]):
    """
    Package the contents of the repository for distribution
    """
    waf_command(cmd=['gs_dist'] + cmd)


def recurse_for_wscript(folder):
    """
    Will recurse down looking for wscripts
    if a wscript is found the recursing will stop

    :param folder: start folder
    """
    lst = []
    dir_lst = os.listdir(folder)
    if 'wscript' in dir_lst:
        lst.append(folder)
    else:
        for e in dir_lst:
            p = os.path.join(folder, e)
            if os.path.isdir(p):
                lst += recurse_for_wscript(p)
    return lst


def buildtools_root():
    return basic.buildtools_root()


def buildtools_cmd():
    script = 'gsbuildtools.py'
    cmd = os.path.abspath(os.path.join('.', script))
    if not os.path.exists(cmd):
        cmd = os.path.join(buildtools_root(), script)
    return cmd


def is_project_root(dir):
    return basic.is_project_root(dir)


def get_project_root():
    return basic.get_project_root()


def is_component_root(dir):
    return basic.is_component_root(dir)


def buildtools_command(options=['-h']):
    cmd = [buildtools_cmd()] + options
    flush()
    subprocess.check_call(cmd)
    flush()


def artifact_dir_name(subdir=None):
    dir = 'artifacts'
    if subdir:
        dir = os.path.join(dir, subdir)
    return dir


def clear_artifacts():
    dir = artifact_dir_name()
    if os.path.exists(dir):
        entries = os.listdir(dir)
        for e in entries:
            if e in ['version.txt']:  # buildtools generaeted files
                continue
            path = os.path.join(dir, e)
            if os.path.isdir(path):
                shutil.rmtree(path)
            else:
                os.remove(path)


def create_dir_for_filename(filename):
    return basic.create_dir_for_filename(filename)


def copy_to_artifact(files, subdir=None):
    dir = os.path.join(artifact_dir_name(subdir))
    for i in files:
        for file in glob.glob(r'' + i):
            if os.path.isdir(file):
                print('Copying directory: ' + file + ' -> ' + dir + ' ...')
                shutil.copytree(file, dir)
            else:
                mkdirs(dir)
                print('Copying file: ' + file + ' -> ' + dir + ' ...')
                shutil.copy(file, dir)


def client_gsbuildall(dir='client'):
    basic.execute(['python', 'gsbuildall.py'], dir=dir)


def lib_gsbuildall():
    if foreach:
        if '--gs-lib-gsbuildall' in sys.argv:
            sys.argv.remove('--gs-lib-gsbuildall')
            foreach.run_command_for_each(['python', 'gsbuildall.py'], only_with_gsbuildall=True)


def manifest_command(exclude=[], subdir=None):
    cmd = ['gitinfo', '-r', '--manifest']
    if subdir:
        cmd += ['--manifest-subdir=' + subdir]
    if len(exclude):
        cmd += ['--exclude'] + exclude
    buildtools_command(cmd)


def status_command(skip_verify=[], verbose=False):
    import gs.buildtools.status
    gs.buildtools.status.status_command(skip_verify=skip_verify, verbose=verbose)


def cppcheck_command(options=['--enable=all',
                              '--inconclusive',
                              '--std=posix',
                              '--std=c99',
                              '--inline-suppr'],
                     sources=['.'],
                     suppression_files=[],
                     output_file='build/cppcheck-results.xml',
                     excludes=[],
                     basic_excludes=['./artifacts', './clients', './lib', './.jenkinstmp']):
    import gs.buildtools.check
    gs.buildtools.check.cppcheck_command(options=options, sources=sources, suppression_files=suppression_files,
                                         output_file=output_file, excludes=excludes, basic_excludes=basic_excludes)


def stylecheck_command(sources=['src/**/*.[c,h]*', 'include/**/*.h*', 'tst/**/*.[h,c]*'],
                       python_sources=[],
                       profile='gomspace_basic', output_file=None,
                       excludes=[],
                       basic_excludes=['artifacts/**/*', '.jenkinstmp/**/*', 'lib/**/*', 'clients/**/*',
                                       '**/.waf*/**/*', '**/build/**/*', '**/tools/buildtools/**/*']):
    import gs.buildtools.check
    gs.buildtools.check.stylecheck_command(sources=sources, python_sources=python_sources, profile=profile,
                                           output_file=output_file, excludes=excludes, basic_excludes=basic_excludes)


def get_existing_modules(search=True, search_folder=None):
    try:
        import gs.buildtools.dependencies
        return gs.buildtools.dependencies.get_existing_modules(search_folder=search_folder)
    except ImportError:
        return []


def py3_string(s):
    if sys.version_info.major < 3 or (isinstance(s, str)):
        return s
    else:
        return s.encode('utf-8')


class file_open:
    def __init__(self, fn, mode='r'):
        self._fn = fn
        self._mode = mode

    def __enter__(self):
        if sys.version_info.major < 3:
            self._fp = open(self._fn, self._mode)
        else:
            self._fp = open(self._fn, self._mode, encoding='utf-8')
        return self._fp

    def __exit__(self, t, v, tb):
        self._fp.close()
