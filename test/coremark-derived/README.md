# A CoreMark-derived device workload (AR-20)

`upstream/` is four sources and the header of EEMBC's CoreMark, unmodified, from
https://github.com/eembc/coremark at 1f483d5b8316753a742cbf5590caf5bd0a4e4777,
under the Apache License 2.0 in `upstream/LICENSE.md`.

The harness is not CoreMark's: `kernel.cu` runs one CoreMark context per lane,
each on its own 2000-byte block with the 2K performance-run seeds (0, 0, 0x66),
and stores the four CRCs. There is no timing and no `core_main.c`. Results from
it are a CoreMark-derived workload's, never CoreMark scores: the licence's
acceptable-use agreement keeps the trademark for unmodified runs.

- `core_portme.h`: the port layer (types, no stdio, no time, malloc'd memory).
- `kernel.cu`: the device harness, mirroring `core_main.c`'s `iterate`.
- `host.c`: the same harness for the host, which gives the final CRC for a
  given iteration count; the other three are CoreMark's published values.

`tools/check-coremark-derived.sh` builds and runs it in the gate.
