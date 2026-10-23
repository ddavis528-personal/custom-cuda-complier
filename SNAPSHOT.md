# Snapshot snapshot-2026-10-23-27ef4f1

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `ccr-ea1c4e17-tem30u` at `27ef4f17cf8f4e1573a2f581e8dda1d812a8e7b6`; this branch is rebuilt from source by
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
| Source | `ccr-ea1c4e17-tem30u` @ `27ef4f17cf8f4e1573a2f581e8dda1d812a8e7b6` |
| Built | 2026-10-23 (UTC) |
| Gate | `tools/verify.sh`: VERIFY: PASS |
| clang | Ubuntu clang version 18.1.3 (1ubuntu1) |
| LLVM | 18.1.3 |
| Platform | x86_64, ldd (Ubuntu GLIBC 2.39-0ubuntu8.9) 2.39 |
| Kernels not compiled at default parameters | test/cuda/fp8.cu |

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
0116de90126825a9c05ce79635fa600b35ff9f1b8305111cc0f46b853b1fc865  release/asm/cuda-bytes.s
1f26d7ee153520931e5eb272ef77d1c8d75cf8fa6a33ef5ef9c790edf555d872  release/asm/cuda-byval.s
fb1470aecc3c18b93e4f32b5508e4930a04215cc61531838235ae02c7d82d98c  release/asm/cuda-calls.s
3c19ff201a515a8e7504e94d6370f3ae3427848d217ff2e575014799970837ff  release/asm/cuda-divconst.s
c0a3175bcf36b3b9a65b50d78fade10df23ff64e851bb2866a6a899f9900f362  release/asm/cuda-dp4.s
8f8ea379638fe9c0c5477ca4edc59bee0e2140e845c6b581983f8d6f149f024b  release/asm/cuda-fused.s
49d03ba4e1e00261e518ddd313dd9c55554310711e1ee29b8489c348f01573a5  release/asm/cuda-gemv.s
f83fec49eda3e36dc904352d6a9c5e98a2892ceba9b36b29ee7bd4f2d0b66ba4  release/asm/cuda-gemv8.s
664d5e1b49848b8b3d24b46ac785ebb7b9fdd4559b4a3fdec18087e78a68ba05  release/asm/cuda-globals.s
acc8f86619bfe1d781c8805a1cf593a004b15c6f1fac2bc15186b9e59f4ea245  release/asm/cuda-igemm.s
9a42334191b0097a9a2ef4bff22137e9f02ea896d99744bf7b91939ec4dbd745  release/asm/cuda-ptrlist.s
a1a46d39eb75272a8d61e2ced4f9e44cf16e210700da850182c1a93b8e357329  release/asm/cuda-ptrmem.s
05488e7011400262be37232f57f34c5cb4448c87685fd5de62315ccd3977dc57  release/asm/cuda-reduce.s
e4703fb1c0b5a880ab1554c695dc2dc0f81743a655255af45ad7aa0f2e054526  release/asm/cuda-sfu.s
d6a4721a8234c8349cffcdfd1f1a675bc32901a12635816fa733fe222bb64a05  release/asm/cuda-sgemm.s
1b38a19d06d2db75cb19303a3cb990abecade207eb7b83d60346f4919adab75a  release/asm/cuda-spinwait.s
56f8bc23746061159d146f248d605bdd2f430be318ba29477aa4c946533bc993  release/asm/cuda-vadd-aligned.s
f540a502bf7063cfb75450053c5163bc8986871d7cb0aa9bc2b8ee8cb9637a3c  release/asm/cuda-vadd.s
8e736d528d4ba7f3827683aa1ca76d6f159005c3d90af10a296040f7a88dadac  release/bench/bench.json
74f722d1b50b6e23f8379727243b480a810e07219cd3b8676c475bcce69a1883  release/bench/bench.txt
a6f8714acb354be54969225401d5993cf1c43eb7f7ceb045cac04d953646d18a  release/bench/sweep-coremark.txt
b7e7adbfd99c4b2c1c2e5ea653273976d3f98fd179972597a4329938df50af80  release/bench/sweep-decode.txt
20f4ad176d148652b8c641df0d4d568636f0105285e2114dcd802e65c2031231  release/bench/sweep-frames.txt
eb6d722fd0f11e7d58e0200733f7f4398035974d0bf74329c01ca4dcefdf1c1a  release/bench/sweep-tiles.txt
d77d1b8f1addcb03ce3a171c8ec46412c4895c8ac318e23d765b2a6771a829a4  release/bin/ccv-sim
8493c99c57bc68751ea194502647a104fa24226fc4d91d772197c7dc38c897e0  release/bin/ccv-sim.txt
26b8562fab39de421dd397fc0f97c5c5fdb1f7bf1998ddd96e97b36710c4bbf7  release/kernels/coremark-derived/kernel.bin
0754581e6758c8ab7e2abf98bbd77641f4fd57d6cd47465522b76da5a83d9500  release/kernels/coremark-derived/kernel.s
0c651ef270ced41afc6a40d386f9019d6971dd7dfd108849003ed8fadefb7a2c  release/kernels/coremark-derived/launch.txt
5bc14da2c8b27a16726aa965817fd4936c5b5d3804c69a4be06ca5897235ffd9  release/kernels/coremark-derived/ops.txt
0ddda9feb5145350dcfd3d94a9eb5028bfbd1d0ad41f12851bfce048c0c7ffc9  release/kernels/layernorm/kernel.bin
d881d8dc76c9b594ec1f203de485ce16f3f6b281d657610e97483bc8400feea5  release/kernels/layernorm/kernel.s
e5769fbef4614ef8aed74537de07a82c9018d4215845ec73a517026f606d6d54  release/kernels/layernorm/launch.txt
8be4de0c8320086709d5cfe8b2ad0cf39abdecbfe215d30603382efb3399b411  release/kernels/layernorm/ops.txt
04b58004e7a20beffded7756823e791b5c6162c8d038489d8b0fcabb2fba8ab5  release/kernels/rope-diverged/kernel.bin
165c09e9a4fea0789c8b1b6413e036e496b47ac5f4efb96de47a61a436fa0cd3  release/kernels/rope-diverged/kernel.s
83f10add70f50dda02e88cee00aad593b5491fbc47f7f70793eb0c07cd75318e  release/kernels/rope-diverged/launch.txt
d3d45cedc98d40912cbfaad5213df1622a7fed69d33b91fb310d53b1d786171e  release/kernels/rope-diverged/ops.txt
04b58004e7a20beffded7756823e791b5c6162c8d038489d8b0fcabb2fba8ab5  release/kernels/rope/kernel.bin
ae6d97340ceae10fed3af6ea0ede225fe8ca5aa6b7e1546b8927c949a46c3a56  release/kernels/rope/kernel.s
12795ff2ace11fc143ad508c1a541846387f492fba37433e1502316ec19c65b3  release/kernels/rope/launch.txt
2497007156e55cf968c095bf5800cb0adce150dfe85961df79762b5643bb78aa  release/kernels/rope/ops.txt
8d1536cb447342d52c5ab7d771a40473a549e45ad3d6bc41b374cb5f10a68a0f  release/verify.log
```
