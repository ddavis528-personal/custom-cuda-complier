#!/usr/bin/env python3
"""Instruction count and bit total for a .s, using the §2 length rule applied
to the mnemonics. Shares its sizing with check-spec-vs-codegen.py so the
benchmark and the spec check cannot disagree about what an instruction costs."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import importlib.util
spec = importlib.util.spec_from_file_location(
    "cs", os.path.join(os.path.dirname(os.path.abspath(__file__)),
                       "check-spec-vs-codegen.py"))
cs = importlib.util.module_from_spec(spec); spec.loader.exec_module(cs)
r = cs.parse_asm(sys.argv[1])
print(r["instructions"], r["bits"])
