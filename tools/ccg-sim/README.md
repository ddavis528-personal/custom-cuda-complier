# ccg-sim — functional simulator

Executes one warp of the ISA in
[`../../docs/isa-v1.5-operation-map-and-encoding.md`](../../docs/isa-v1.5-operation-map-and-encoding.md).

## What it models, and what it does not

**Decoding is not re-implemented.** The simulator drives the disassembler that
`gen-disassembler` produces, so this code is *semantics only*. That split is
deliberate (roadmap F-6): the encoder and decoder check each other through
`ccg-roundtrip`, and the simulator checks what instructions compute.

**Per-thread PCs are real, not approximated.** Each lane carries its own PC.
The main loop picks the lowest PC among active lanes and issues for every lane
sitting there; nothing forces convergence, and there is no mask stack or bracket
instruction. Lanes that diverge regroup if and when their PCs coincide — which
is observable: under divergence the mask narrows for the guarded body and comes
back to `ffffffff` at `exit`.

Lowest-PC-first is a scheduling policy, not semantics. Any order gives the same
results; this one is just deterministic.

**Register and predicate shapes follow the ISA.** A GPR is 32 lanes, one element
per lane (§1). A predicate is 32 bits, one per lane, at every `chwidth`
(invariant 5). Predicates live in their own namespace.

**Not modelled:** timing, occupancy, the coalescer, rename, or anything else
microarchitectural. This answers "does it compute the right answer," which is
what Step 1 could not.

**Lane gating is counted, not simulated.** `-counters` reports lane-activations
separately from lane-instructions, which is the number O-33 exists to move. It
is an accounting of what the predicate masks say, not a claim about what the RTL
will do — see O-33 for the hardware property it assumes.

## Coverage

Formats A/A′, B/B′, C/C′/C″, D/D′, E, F, G, I, J and K, as listed in
`Interp.cpp`: integer and FP ALU with their predicated twins, the full compare
family across all four encodings, global and shared memory in both addressing
modes, barriers, `shfl.idx`, `srd`, conversions and the SFU points O-31 added.
An instruction without semantics stops the run and names itself rather than
silently doing nothing.

**Not implemented:** atomics (Format M), `chwidth` and the narrow-width paths,
`packi`/`unpacki`, `dp4`/`dp8`, and `call`/`ret`. None is reachable from any
kernel that compiles today.

## Running

```
python3 tools/ccg-as.py build/generated/CCG.json test/elementwise.s kernel.bin
build/ccg-sim kernel.bin -poke 0x20000=32 -peek 0x50000 -trace
```

`-poke addr=value` seeds memory before the run and `-peek addr` reads it after;
both take hex or decimal. `-trace` prints the issue mask and disassembly of each
group, which is the quickest way to see divergence.

`-counters` reports issue groups, lane-instructions, lane-activations, per-thread
work, SIMT efficiency, dynamic bits per instruction, and a breakdown by class
with spill traffic separated. It is named `-counters` rather than `-stats`
because LLVM's own `-stats` option is already in the namespace.

`tools/run-tests.sh` drives the whole thing and checks results; `tools/bench.py`
and `tools/sweep-tiles.sh` use the counters.
