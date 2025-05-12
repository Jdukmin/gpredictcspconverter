# Copyright (c) 2013-2017 GomSpace A/S. All rights reserved.

import os
import sys

_buildtools_root = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), ".."))
sys.path.append(_buildtools_root)

if 'GS_BUILDTOOLS' not in os.environ:
    os.environ['GS_BUILDTOOLS'] = _buildtools_root
