# Snapshot snapshot-2026-09-26-b00ba89

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `claude/custom-cuda-core-infra-6msg93` at `b00ba89118ef40d62476232a8f65d6eaf4f3b99f`; this branch is rebuilt from source by
`tools/make-release.sh`, and nothing here flows back.

Beyond the source tree at that commit:

- **`build/generated/`:** TableGen's output, including `CCV.json`,
  which `tools/ccv-as.py` assembles from. A build product on the
  development branch.
- **`release/bin/ccv-sim`:** the built functional simulator
  (`ccv-sim.txt` records its system-library dependencies). A pinned
  snapshot commit is how another repository runs it.
- **`release/bench/`:** `tools/bench.py` and both sweeps -- the
  numbers `docs/benchmarks.md` is checked against.
- **`release/asm/`:** every CUDA kernel under `test/`, compiled.
- **`release/verify.log`:** the gate.

| | |
|---|---|
| Source | `claude/custom-cuda-core-infra-6msg93` @ `b00ba89118ef40d62476232a8f65d6eaf4f3b99f` |
| Built | 2026-09-26 (UTC) |
| Gate | `tools/verify.sh`: VERIFY: PASS |
| clang | Ubuntu clang version 18.1.3 (1ubuntu1) |
| LLVM | 18.1.3 |
| Platform | x86_64, ldd (Ubuntu GLIBC 2.39-0ubuntu8.7) 2.39 |

## Manifest of release/

```
8e92658b48ed6eec5b0bc697d75fef8a23775e44132963f9f2ab984073107e3d  release/asm/bench-dot.s
4d46205c4b39b00af7d18b08ab09b6b9ac67b6eb64d5df4c92f3405dc7625c7a  release/asm/bench-reduce.s
36e655edcd412253b85614a2f7374faf371b49509cd1de49b4afe4915068f3d5  release/asm/bench-saxpy.s
07e8c88ffd575a3a159682cef503c08eeefe3243af8f10897dab3e25415a4488  release/asm/bench-transpose.s
b4afdc71cfb622375b6759d2ad8a22c0c84d8864417344e63f0790dfb7c13c8e  release/asm/bench-vadd.s
a415822bd284132c043f8985d643efd1595bd77945105875c7d1fddcc2bae514  release/asm/bench-vadd16.s
91a4699ec0c21c5fc89c9bde855e0b6051ae7b8276e8dab787f1293c6ee4199d  release/asm/bench-vadd16_loop.s
add6cfaf2b41fdd02e5f2becc79d229ee30e5e8a1a6c6a8a18110edc7ef71846  release/asm/bench-vadd_loop.s
8aee33c8656e8617aa5db1d870bfc634990ef14e2cfec7cc3be99a7d675151ba  release/asm/cuda-divconst.s
963680c1593fa880a49622a465ded2e4a2824c219de14cf6c85b930fe9d1dadf  release/asm/cuda-dp4.s
0ce772ac6db2afd0005043ec9c928c9856de6996650a3476a914b4cf67357c6b  release/asm/cuda-fused.s
3116ad343d8ce0c275face4da960970c58cfd50eb66e8be5cd7a30b1219c8d42  release/asm/cuda-gemv.s
1d05353fa428a3e598e67d913abb129d5ef75d00c9bda8b448f9ad5acd637338  release/asm/cuda-gemv8.s
39950f3947045f5cc22b9fd15ed5f0ab698d4fbc8eadd36fcbd387635dd93dda  release/asm/cuda-igemm.s
151fdd1405818ffb238dee8f1f3978bd768b67e4fde3b1a75ed5bc83521d2ff3  release/asm/cuda-reduce.s
67f1ef05aa89dcbdc01c73b795b65eeded0df43fba39af8f5085c337731806cb  release/asm/cuda-sgemm.s
cc7a6984b354fff2133876f327b3fd2c8cfb5a3a7d51bd1f171ccb80426a4f22  release/asm/cuda-vadd-aligned.s
3a1b81cf8a4eb4ef231d51ff187f1138dd239e1302245531cbc7923c73dbe227  release/asm/cuda-vadd.s
b8982bcbc886d44af54ca7d8407b2393083f08a2b34e372cbc0e1a8d377f4b74  release/bench/bench.json
67c04af509362b1e74050abd592cdc23e8c2a0adcead73d30554c51870e0e390  release/bench/bench.txt
a9d92b3061f26d91a6eb6b6a04443e6bd2ad7c3281f6f566810b9dda8030dfde  release/bench/sweep-decode.txt
eb6d722fd0f11e7d58e0200733f7f4398035974d0bf74329c01ca4dcefdf1c1a  release/bench/sweep-tiles.txt
cc1a9cc1c44c239dc74d6639b33b22dafb5dabcf60436083b54083ddc41f3212  release/bin/ccv-sim
01ec11d5a49cdbb7dac51a193531bd1c804ad4a93dce9282ba14f498212158e1  release/bin/ccv-sim.txt
15781e5a289eb7aaa1da352e8b6f09eca7777994abe4eb4590d82a62ad8431d6  release/verify.log
```
