# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.
"""
Load and parse compiler settings from JSON.
"""

import json
import os
import pprint

from gs.buildtools import basic


compiler_settings = None
validWarningLevels = {'strict', 'relaxed'}


def keyValueMatch(set, key, value):
    if value and (key in set) and (set[key] == value):
        return True
    return False


def hasKey(set, key):
    if (key in set) and set[key]:
        return True
    return False


def byteify(input):
    if isinstance(input, dict):
        return {byteify(key): byteify(value) for key, value in input.items()}
    elif isinstance(input, list):
        return [byteify(element) for element in input]
    # elif isinstance(input, unicode):
    #     return input.encode('utf-8')
    else:
        return input


# extend key, e.g. key += key_suffix
def extend_values(set, suffix):
    suffix = '_' + suffix
    for key in set:
        if key.endswith(suffix):
            base_key = key.replace(suffix, "")
            # print "found key: " + key + ", base_key: " + base_key
            if not hasKey(set, base_key):
                raise KeyError('Missing base key [%s] for [%s]' % (base_key, key))
            set[base_key] += set[key]


def load(file="compiler_settings.json"):
    global compiler_settings
    if not compiler_settings:
        absfile = os.path.join(os.path.dirname(__file__), file)
        # print "Loading compiler settings: " + absfile
        settings = None
        with open(absfile) as ifile:
            settings = json.load(ifile)
            settings = byteify(settings)  # some of Waf python doesn't like unicode for compiler options
        compiler_settings = settings
        if os.path.exists(os.path.join(basic.get_project_root(), 'compiler_settings.json')):
            with open(os.path.join(basic.get_project_root(), 'compiler_settings.json')) as fp:
                local_settings = json.load(fp)
                local_settings = byteify(local_settings)
            compiler_settings = _dict_override(compiler_settings, local_settings)
    return compiler_settings


def get(part=None, arch=None, mcu=None, warninglevel="relaxed", build='release', docker_image=None):

    if warninglevel not in validWarningLevels:
        raise KeyError('Invalid warninglevel=[%s], valid levels=[%s]' %
                       (str(warninglevel), ', '.join(sorted(validWarningLevels, key=str.lower))))

    settings = load()
    sets = dict()
    match = None

    for set in settings['compiler_settings']:

        if 'name' not in set:
            raise KeyError('Missing key=[name] in: ' + pprint.pformat(set))

        name = set['name']
        if name in sets:
            raise KeyError('Duplicate set: ' + pprint.pformat(set))

        sets[name] = set
        if keyValueMatch(set, 'gs_part', part):
            match = name
        elif keyValueMatch(set, 'gs_mcu', mcu):
            match = name
        elif (not match) and keyValueMatch(set, 'gs_arch', arch):
            match = name
        elif (not match) and keyValueMatch(set, 'docker-container', docker_image):
            match = name

    if match is None:
        raise LookupError("Failed to find compiler settings for: part=[%s], arch[%s], mcu[%s], image[%s]" %
                          (str(part), str(arch), str(mcu), str(docker_image)))

    set = sets[match]

    extend_values(set, build.upper())
    extend_values(set, warninglevel)

    for key in ['CFLAGS', 'CXXFLAGS']:
        if hasKey(set, key):
            wkey = 'warnings'
            if hasKey(set, wkey):
                set[key] += set[wkey]

    return set


def _dict_override(base, override):
    """
    Return base compiler settings dict but with fields overridden from override dict if present
    Only selected fields are extracted
    """
    if 'default_part' in override:
        base['default_part'] = override['default_part']
    if 'label_mapping' in override:
        base['label_mapping'] = override['label_mapping']
    return base


def _include_part(set, keywords, excludes, label_mapping):
    yes = False
    no = False

    if 'gs_part' in set:
        for kw in keywords:
            if kw in label_mapping:
                if set['gs_part'] in label_mapping[kw]:
                    yes = True
        for ex in excludes:
            if ex in label_mapping:
                if set['gs_part'] in label_mapping[ex]:
                    no = True

    for key, value in set.items():
        if not isinstance(value, list):
            value = value.split(' ')

        for label in excludes:
            if label in value:
                no = True
                break

        if len(keywords) == 0:
            yes = True
            continue

        for label in keywords:
            if label in value:
                yes = True

    return ((not no) and (yes))


def get_parts(keywords=[], excludes=[]):
    """
    Return parts matching the specified keywords
    """
    if len(keywords) == 0:
        keywords = ['main_archs']
    settings = load()
    parts = []
    for set in settings['compiler_settings']:
        if 'gs_part' not in set:
            continue

        part = set['gs_part']
        if _include_part(set, keywords, excludes, settings['label_mapping']):
            if part not in parts:  # keep order
                parts.append(part)
        else:
            if part in parts:
                parts.remove(part)

    # Ensure that the default part is last if present
    if get_default_part() in parts:
        parts.remove(get_default_part())
        parts.append(get_default_part())
    return list(parts)


def get_container_settings_from_part(part):
    settings = load()

    for s in settings['compiler_settings']:
        if s['gs_part'] == part:
            if 'docker-container' in s.keys() and 'docker-args' in s.keys():
                return (s['docker-container'], s['docker-args'])
            else:
                return (None, None)
    return (None, None)


def get_default_part():
    """
    Return the configured default part from compiler settings json
    """
    data = load()
    return data['default_part']
