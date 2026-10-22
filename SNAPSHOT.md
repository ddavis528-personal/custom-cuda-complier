# Snapshot snapshot-2026-10-22-07ab44a

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `ccr-ea1c4e17-tem30u` at `07ab44ad7bb1b5496a5b8dd4249c0d82c44fe007`; this branch is rebuilt from source by
`tools/make-release.sh`, and nothing here flows back.

Beyond the source tree at that commit:

- **`build/generated/`:** TableGen's output, including `CCV.json`,
  which `tools/ccv-as.py` assembles from. A build product on the
  development branch.
- **`release/bin/ccv-sim`:** the built functional simulator
  (`ccv-sim.txt` records its system-library dependencies). A pinned
  snapshot commit is how another repository runs it.
- **`release/bench/`:** `tools/bench.py` and both sweeps -- the
  numbers `docs/benchmarks.md` is checked against -- and the
  CoreMark-derived workload's run shapes and callee-saved sweep (AR-20),
  and frame sizes, frame traffic and indexed stores (AR-23, PF-43).
- **`release/asm/`:** every CUDA kernel under `test/`, compiled.
- **`release/kernels/`:** kernels for a consumer without `ccv-llc`
  (TI-30): ccv-as source, the image, the launch as `-poke` lines, and
  the opcodes issued, each launch checked against a reference.
- **`release/verify.log`:** the gate.

| | |
|---|---|
| Source | `ccr-ea1c4e17-tem30u` @ `07ab44ad7bb1b5496a5b8dd4249c0d82c44fe007` |
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
f708848401d6d126bc33b212d7043cba6841e6ef0f98057512885a1b83a064bd  release/asm/cuda-bytes.s
1f26d7ee153520931e5eb272ef77d1c8d75cf8fa6a33ef5ef9c790edf555d872  release/asm/cuda-byval.s
fc212b8437e14e2fc663362485f24eb590bc353e6e76776f16b0ad5b6e0ec614  release/asm/cuda-calls.s
3c19ff201a515a8e7504e94d6370f3ae3427848d217ff2e575014799970837ff  release/asm/cuda-divconst.s
c0a3175bcf36b3b9a65b50d78fade10df23ff64e851bb2866a6a899f9900f362  release/asm/cuda-dp4.s
8f8ea379638fe9c0c5477ca4edc59bee0e2140e845c6b581983f8d6f149f024b  release/asm/cuda-fused.s
55a629138c527087f29f2e5eebe801112a11e3d1d389266965df78e25d58e888  release/asm/cuda-gemv.s
62862fe008b730958a0f6a5ab763ca7f73958293cf08b5271777459a97051188  release/asm/cuda-gemv8.s
664d5e1b49848b8b3d24b46ac785ebb7b9fdd4559b4a3fdec18087e78a68ba05  release/asm/cuda-globals.s
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
a6f8714acb354be54969225401d5993cf1c43eb7f7ceb045cac04d953646d18a  release/bench/sweep-coremark.txt
b7e7adbfd99c4b2c1c2e5ea653273976d3f98fd179972597a4329938df50af80  release/bench/sweep-decode.txt
eaca28d853e3cd40291e3fd86cedb7d688ede4f2ac0852e9dd38db985fb1ba10  release/bench/sweep-frames.txt
eb6d722fd0f11e7d58e0200733f7f4398035974d0bf74329c01ca4dcefdf1c1a  release/bench/sweep-tiles.txt
95f4156250879803ac60a6ce3706a884ee06f62ea6bbb2d1fd6e169e6ae06922  release/bin/ccv-sim
f406394f9d9fe14ec4f261c087c4c799040eb62a14eeba74bf0aed7e0563259e  release/bin/ccv-sim.txt
795ddec2ad120317dd9da5e48a141b5c6a3e9abadfbf13bc37114b0cab6c5506  release/kernels/coremark-derived/kernel.bin
b76252fafa0996072f7e51707f307b8587b12b9ac0f2db25d53e0df63a7af497  release/kernels/coremark-derived/kernel.s
0c651ef270ced41afc6a40d386f9019d6971dd7dfd108849003ed8fadefb7a2c  release/kernels/coremark-derived/launch.txt
5bc14da2c8b27a16726aa965817fd4936c5b5d3804c69a4be06ca5897235ffd9  release/kernels/coremark-derived/ops.txt
0ddda9feb5145350dcfd3d94a9eb5028bfbd1d0ad41f12851bfce048c0c7ffc9  release/kernels/layernorm/kernel.bin
d881d8dc76c9b594ec1f203de485ce16f3f6b281d657610e97483bc8400feea5  release/kernels/layernorm/kernel.s
e5769fbef4614ef8aed74537de07a82c9018d4215845ec73a517026f606d6d54  release/kernels/layernorm/launch.txt
8be4de0c8320086709d5cfe8b2ad0cf39abdecbfe215d30603382efb3399b411  release/kernels/layernorm/ops.txt
0c3d9b696419898f9de2c02eebea217370cbda1378cd8a8d39ad12f7cad7b10c  release/kernels/rope/kernel.bin
726182c9a3c852ce8b46d9b35640a800a70f2ce60ae711b48c1660a753857b39  release/kernels/rope/kernel.s
12795ff2ace11fc143ad508c1a541846387f492fba37433e1502316ec19c65b3  release/kernels/rope/launch.txt
2497007156e55cf968c095bf5800cb0adce150dfe85961df79762b5643bb78aa  release/kernels/rope/ops.txt
c0e6c272321e1d99ffa66b2c3c0f20236910293bd00810da6cd783b17075b9ab  release/verify.log
```
