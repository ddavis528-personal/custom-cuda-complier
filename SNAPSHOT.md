# Snapshot snapshot-2026-10-22-de0b311

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `ccr-ea1c4e17-tem30u` at `de0b311f21c42f1f46152725573a524502c30611`; this branch is rebuilt from source by
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
| Source | `ccr-ea1c4e17-tem30u` @ `de0b311f21c42f1f46152725573a524502c30611` |
| Built | 2026-10-22 (UTC) |
| Gate | `tools/verify.sh`: VERIFY: PASS |
| clang | Ubuntu clang version 18.1.3 (1ubuntu1) |
| LLVM | 18.1.3 |
| Platform | x86_64, ldd (Ubuntu GLIBC 2.39-0ubuntu8.9) 2.39 |

## Manifest of release/

```
e9f5d9c97491d89ebd839b31a183bb3faf65ef774f6e800b1582ff826200b336  release/asm/bench-dot.s
0445f71471cdad0ad4cc8aa38acee4fd4961a4235fb25e9735c1d06314958a5f  release/asm/bench-reduce.s
3d07bb0eae19b6cc326464e99486409c86e2743bab529ae2be3f939f120ac20c  release/asm/bench-saxpy.s
2f1c21a785dad00d38d8877b0e99a61dd81bc0538d37250bd18f05a8cd11b934  release/asm/bench-transpose.s
507b9a5ef42b84011aefc6d03cc2079b70f9dded4f33914747f59f11dba7e431  release/asm/bench-vadd.s
d1825cc689f6094e35e3a24b144576c67d44e6995960739a3f95e7d9ef2162f5  release/asm/bench-vadd16.s
dd05714aa352e4b46c5fa8aaaa531d4c219c2a44ca1fc1a83f131bb72d4df5b5  release/asm/bench-vadd16_loop.s
1ab4360d07e9db8b92b340ce99306c8bfe7392e51ac96c61a3e69e445c895d02  release/asm/bench-vadd_loop.s
ce633b5713036d7524e482dc2f7870435037bfaa79302180f904d5cff0fe285c  release/asm/cuda-argorder.s
1f26d7ee153520931e5eb272ef77d1c8d75cf8fa6a33ef5ef9c790edf555d872  release/asm/cuda-byval.s
13eed4bbd665fd38fdefe516631b78f3c9b160a22391519686da606c99627ac0  release/asm/cuda-calls.s
3c19ff201a515a8e7504e94d6370f3ae3427848d217ff2e575014799970837ff  release/asm/cuda-divconst.s
c0a3175bcf36b3b9a65b50d78fade10df23ff64e851bb2866a6a899f9900f362  release/asm/cuda-dp4.s
8f8ea379638fe9c0c5477ca4edc59bee0e2140e845c6b581983f8d6f149f024b  release/asm/cuda-fused.s
55a629138c527087f29f2e5eebe801112a11e3d1d389266965df78e25d58e888  release/asm/cuda-gemv.s
62862fe008b730958a0f6a5ab763ca7f73958293cf08b5271777459a97051188  release/asm/cuda-gemv8.s
6fd267f4e682661abf41191aca3b5a6a77ffac60c6f7cf04849c4335299a46a4  release/asm/cuda-igemm.s
eb9ae9a68a0a6a8cc8b828c971c5aed37812587061b76234760c743493a0d0e7  release/asm/cuda-ptrlist.s
a1a46d39eb75272a8d61e2ced4f9e44cf16e210700da850182c1a93b8e357329  release/asm/cuda-ptrmem.s
05488e7011400262be37232f57f34c5cb4448c87685fd5de62315ccd3977dc57  release/asm/cuda-reduce.s
e4703fb1c0b5a880ab1554c695dc2dc0f81743a655255af45ad7aa0f2e054526  release/asm/cuda-sfu.s
e80c3c2e56a19b58612c5c6fff71e62538e69251ad30dfb39cb6bb716369c08b  release/asm/cuda-sgemm.s
1b38a19d06d2db75cb19303a3cb990abecade207eb7b83d60346f4919adab75a  release/asm/cuda-spinwait.s
56f8bc23746061159d146f248d605bdd2f430be318ba29477aa4c946533bc993  release/asm/cuda-vadd-aligned.s
f540a502bf7063cfb75450053c5163bc8986871d7cb0aa9bc2b8ee8cb9637a3c  release/asm/cuda-vadd.s
8e736d528d4ba7f3827683aa1ca76d6f159005c3d90af10a296040f7a88dadac  release/bench/bench.json
74f722d1b50b6e23f8379727243b480a810e07219cd3b8676c475bcce69a1883  release/bench/bench.txt
b7e7adbfd99c4b2c1c2e5ea653273976d3f98fd179972597a4329938df50af80  release/bench/sweep-decode.txt
eb6d722fd0f11e7d58e0200733f7f4398035974d0bf74329c01ca4dcefdf1c1a  release/bench/sweep-tiles.txt
1ed0295b9d596984b24097508b4356d01d12f36d76cb195b249ed1566423c1db  release/bin/ccv-sim
7dfee47898dfde8170f09b2f90d89048e14d3d83c071b66d8cf09a0e0e0843ab  release/bin/ccv-sim.txt
4fd579172fe8c23aad4c42f84e80daf4c48c6e78464e778d61fe84ec21bd79d5  release/verify.log
```
