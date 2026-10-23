# Snapshot snapshot-2026-10-23-f863b76

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `ccr-ea1c4e17-tem30u` at `f863b76b3d5ffb60065cddc8cac578bb80095689`; this branch is rebuilt from source by
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
| Source | `ccr-ea1c4e17-tem30u` @ `f863b76b3d5ffb60065cddc8cac578bb80095689` |
| Built | 2026-10-23 (UTC) |
| Gate | `tools/verify.sh`: VERIFY: PASS |
| clang | Ubuntu clang version 18.1.3 (1ubuntu1) |
| LLVM | 18.1.3 |
| Platform | x86_64, ldd (Ubuntu GLIBC 2.39-0ubuntu8.9) 2.39 |
| Kernels not compiled at default parameters | test/cuda/fp4.cu test/cuda/fp8.cu |

## Manifest of release/

```
e9f5d9c97491d89ebd839b31a183bb3faf65ef774f6e800b1582ff826200b336  release/asm/bench-dot.s
0445f71471cdad0ad4cc8aa38acee4fd4961a4235fb25e9735c1d06314958a5f  release/asm/bench-reduce.s
3d07bb0eae19b6cc326464e99486409c86e2743bab529ae2be3f939f120ac20c  release/asm/bench-saxpy.s
ff0a6ccd5cb0841f5a9bed9417e366910ec6626676a1bbee5ca7ccf22b97eaf0  release/asm/bench-transpose.s
507b9a5ef42b84011aefc6d03cc2079b70f9dded4f33914747f59f11dba7e431  release/asm/bench-vadd.s
d1825cc689f6094e35e3a24b144576c67d44e6995960739a3f95e7d9ef2162f5  release/asm/bench-vadd16.s
dd05714aa352e4b46c5fa8aaaa531d4c219c2a44ca1fc1a83f131bb72d4df5b5  release/asm/bench-vadd16_loop.s
1ab4360d07e9db8b92b340ce99306c8bfe7392e51ac96c61a3e69e445c895d02  release/asm/bench-vadd_loop.s
ce633b5713036d7524e482dc2f7870435037bfaa79302180f904d5cff0fe285c  release/asm/cuda-argorder.s
21ac1440dff7b28608b94d0b5bf1efa8fa77b80420938bcbed86abbe139d45e5  release/asm/cuda-atomics.s
0116de90126825a9c05ce79635fa600b35ff9f1b8305111cc0f46b853b1fc865  release/asm/cuda-bytes.s
1f26d7ee153520931e5eb272ef77d1c8d75cf8fa6a33ef5ef9c790edf555d872  release/asm/cuda-byval.s
af3128bff7c030f933359bd2f54ffab4eafb444001dc32b60f857e34f3626996  release/asm/cuda-calls.s
b0884b117bd4bf68ca9bb1ba2b72a78fae453157cb8312c8ee19abc1a02a1bf8  release/asm/cuda-cta-reduce.s
3c19ff201a515a8e7504e94d6370f3ae3427848d217ff2e575014799970837ff  release/asm/cuda-divconst.s
c0a3175bcf36b3b9a65b50d78fade10df23ff64e851bb2866a6a899f9900f362  release/asm/cuda-dp4.s
8f8ea379638fe9c0c5477ca4edc59bee0e2140e845c6b581983f8d6f149f024b  release/asm/cuda-fused.s
5f48fd53df460cea398bcc9c32961919a304163d74aac72ef309e5b59afb98db  release/asm/cuda-gemv.s
e3d98220dec36b9082057a5c921d03baa84b309f9f910385ec7d4f0f0b1b225f  release/asm/cuda-gemv8.s
664d5e1b49848b8b3d24b46ac785ebb7b9fdd4559b4a3fdec18087e78a68ba05  release/asm/cuda-globals.s
5ae6c540aa97796702ad53e5a5d2dc89cc13124b00b907d45596b0f2487f9ba2  release/asm/cuda-hash64.s
56c5f6e7462c7055f26fe7c4cf9e1b16dc5f832b6a543e807667a8dc13ee29f6  release/asm/cuda-igemm.s
cc381121b5dedda68e70a176b72d8d91dee837891dd3104e9f6f743dda0ad573  release/asm/cuda-int64.s
f648d1a15e56c231f8e641c259112a09e452c6eed741e6bd1f3667728ce760fb  release/asm/cuda-ptrlist.s
a1a46d39eb75272a8d61e2ced4f9e44cf16e210700da850182c1a93b8e357329  release/asm/cuda-ptrmem.s
05488e7011400262be37232f57f34c5cb4448c87685fd5de62315ccd3977dc57  release/asm/cuda-reduce.s
3c8210bf60499ccedaa8977e6b4692e74653c5b4792f67f83af49547a253000a  release/asm/cuda-scatter.s
e4703fb1c0b5a880ab1554c695dc2dc0f81743a655255af45ad7aa0f2e054526  release/asm/cuda-sfu.s
4e28f920d2d25a1a2943611243f41a0a72bddf00d7cc895ad4e0b6df2cafaa27  release/asm/cuda-sgemm.s
1b38a19d06d2db75cb19303a3cb990abecade207eb7b83d60346f4919adab75a  release/asm/cuda-spinwait.s
56f8bc23746061159d146f248d605bdd2f430be318ba29477aa4c946533bc993  release/asm/cuda-vadd-aligned.s
f540a502bf7063cfb75450053c5163bc8986871d7cb0aa9bc2b8ee8cb9637a3c  release/asm/cuda-vadd.s
244b084a07dcb12950d6548fbdb3ddff536707dd962ca8da8a63ca4f574f6008  release/bench/bench.json
9ff74d90bf22133e1b98224e3933e72a4fdd730ed70e604cf71ac49e0616ed58  release/bench/bench.txt
6b7dd81bc4973ca41fbdf31614c842bc03b9727442ae0ae1b3fa624dd688e812  release/bench/sweep-coremark.txt
0529582a0572b0828fefa8b9e57ba448529f16369affe535b1acbb20816662de  release/bench/sweep-decode.txt
9a44a3bd44d1779d620cf74ef9cb0ca498d0cdbb8c6da69c305d85a2bad975d9  release/bench/sweep-frames.txt
28c14ebc8397a6ec18b69bcb5ebe93a64c94cd04b97c971dd526f78ff72f423b  release/bench/sweep-tiles.txt
14a8ff336dc0a204dd3c249426cb08b1d5feb663894da7dcc3da280ef633ac2f  release/bin/ccv-sim
7c1eecb0be0b9c60f87221564c7e14baf9773a010beb6a0616a97ae86d4ac6cc  release/bin/ccv-sim.txt
a462bf4ec724698e923e08de91c0acabb427af1a7a5e62f96936f3174d0fc725  release/kernels/coremark-derived/kernel.bin
608044bafe0a8bebd88e5006cabf0aa6c7147f152fe1a3db927e89edf7d57e24  release/kernels/coremark-derived/kernel.s
6ba104efb4f63121017354429d86bafc49b55612259a53579a0613ceb9671cfb  release/kernels/coremark-derived/launch.txt
2f3640da8addc9d7c544d56dd60918a2d4a0db5ded88e30e557e796d7fac9c43  release/kernels/coremark-derived/ops.txt
0ddda9feb5145350dcfd3d94a9eb5028bfbd1d0ad41f12851bfce048c0c7ffc9  release/kernels/layernorm/kernel.bin
d881d8dc76c9b594ec1f203de485ce16f3f6b281d657610e97483bc8400feea5  release/kernels/layernorm/kernel.s
e5769fbef4614ef8aed74537de07a82c9018d4215845ec73a517026f606d6d54  release/kernels/layernorm/launch.txt
8be4de0c8320086709d5cfe8b2ad0cf39abdecbfe215d30603382efb3399b411  release/kernels/layernorm/ops.txt
4bddc1e8455d2804aba4f611563a578cb8be84807cef847c18746218461301a0  release/kernels/rope-diverged/kernel.bin
ce8e645c8b285ff035aa6d701ee7dc1207459bf060c85e27f4239d48b84d580b  release/kernels/rope-diverged/kernel.s
83f10add70f50dda02e88cee00aad593b5491fbc47f7f70793eb0c07cd75318e  release/kernels/rope-diverged/launch.txt
009e0820430329d6043d0314e7cbeb6c80067c3386f42aedffba9d1aaf01d728  release/kernels/rope-diverged/ops.txt
4bddc1e8455d2804aba4f611563a578cb8be84807cef847c18746218461301a0  release/kernels/rope/kernel.bin
ba1f77ebad84a1da78c82e9c3ef4f1e466cb8da7d8634dc0f234f7303a1ab069  release/kernels/rope/kernel.s
12795ff2ace11fc143ad508c1a541846387f492fba37433e1502316ec19c65b3  release/kernels/rope/launch.txt
1fd038c15e2c80787853fb2af63019b6d6fa9e86459b373fee9974181eb0c477  release/kernels/rope/ops.txt
55b19053e309d8cda37ccd06bb3a588a5296da1d37e95976a171eedc9b99bcc4  release/verify.log
```
