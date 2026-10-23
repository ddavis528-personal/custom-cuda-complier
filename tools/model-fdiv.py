#!/usr/bin/env python3
"""The fp32 divide's algorithm check, now tools/model-ieee-sfu (F-181).

The ISA text (O-36, IS's) cites this file as the check of the software
divide's ALGORITHM against exact arithmetic. That check moved to C++, because
IS-12 made the SFU approximate and the claim worth making is now exhaustive:
the IEEE divide, 1.0f/x and sqrtf correctly rounded at every input over a seed
that may be off by several ulps, which is billions of cases. This runs it, so
the citation still names something that does what it says.

    tools/model-fdiv.py [--samples N]   ->   build/model-ieee-sfu --divs N
"""
import argparse
import os
import subprocess
import sys

ap = argparse.ArgumentParser()
ap.add_argument("--samples", type=int, default=500000)
a = ap.parse_args()
root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.exit(subprocess.run([os.path.join(root, "build/model-ieee-sfu"),
                         "--divs", str(a.samples)]).returncode)
