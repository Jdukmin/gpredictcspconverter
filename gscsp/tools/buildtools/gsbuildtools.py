#!/usr/bin/env python
# Copyright (c) 2013-2018 GomSpace A/S. All rights reserved.

import sys
import os

_buildtools_root = os.path.abspath(os.path.dirname(os.path.realpath(__file__)))
os.environ['GS_BUILDTOOLS'] = _buildtools_root
sys.path.append(_buildtools_root)

if __name__ == '__main__':
    from gs.buildtools import cmdline
    cmdline.syscmd(sys.argv)
