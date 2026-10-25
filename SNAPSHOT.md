# Snapshot snapshot-2026-10-24-e63f9d3

**A generated, read-only snapshot. Do not edit or merge it.** The source
is `ccr-ea1c4e17-tem30u` at `e63f9d34c2564c0d5bb9810b607acf5aea6707dc`; this branch is rebuilt from source by
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
| Source | `ccr-ea1c4e17-tem30u` @ `e63f9d34c2564c0d5bb9810b607acf5aea6707dc` |
| Built | 2026-10-24 (UTC) |
| Gate | `tools/verify.sh`: VERIFY: PASS |
| clang | Ubuntu clang version 18.1.3 (1ubuntu1) |
| LLVM | 18.1.3 |
| Platform | x86_64, ldd (Ubuntu GLIBC 2.39-0ubuntu8.9) 2.39 |
| Kernels not compiled at default parameters | test/cuda/barcount.cu test/cuda/fp4.cu test/cuda/fp8.cu |

## Manifest of release/

```
e9f5d9c97491d89ebd839b31a183bb3faf65ef774f6e800b1582ff826200b336  release/asm/bench-dot.s
0445f71471cdad0ad4cc8aa38acee4fd4961a4235fb25e9735c1d06314958a5f  release/asm/bench-reduce.s
3d07bb0eae19b6cc326464e99486409c86e2743bab529ae2be3f939f120ac20c  release/asm/bench-saxpy.s
ff0a6ccd5cb0841f5a9bed9417e366910ec6626676a1bbee5ca7ccf22b97eaf0  release/asm/bench-transpose.s
507b9a5ef42b84011aefc6d03cc2079b70f9dded4f33914747f59f11dba7e431  release/asm/bench-vadd.s
cada304c6244c22ac7ff8a7ca00572e4b4ab74283e78175ef73ad8592a66d4a6  release/asm/bench-vadd16.s
b3b8304c3c444dcba021f4ee01a2df2cd62e100b705de1b23ac627ba06cc14f5  release/asm/bench-vadd16_loop.s
1ab4360d07e9db8b92b340ce99306c8bfe7392e51ac96c61a3e69e445c895d02  release/asm/bench-vadd_loop.s
ce633b5713036d7524e482dc2f7870435037bfaa79302180f904d5cff0fe285c  release/asm/cuda-argorder.s
ceac272e48381e4db55ac4cd3d2653de7f5ab86a1159602e695ef2e00430f8a8  release/asm/cuda-atomics.s
017a16a255aa2008ed9899b0ca7aadd6f3a40f3f80178708a5835218bb09c272  release/asm/cuda-bytes.s
1f26d7ee153520931e5eb272ef77d1c8d75cf8fa6a33ef5ef9c790edf555d872  release/asm/cuda-byval.s
0d9a8cb56aef1b8c8d3dd356ce781b7996568826995444e81a49b1eb8248dcec  release/asm/cuda-calls.s
b0884b117bd4bf68ca9bb1ba2b72a78fae453157cb8312c8ee19abc1a02a1bf8  release/asm/cuda-cta-reduce.s
3c19ff201a515a8e7504e94d6370f3ae3427848d217ff2e575014799970837ff  release/asm/cuda-divconst.s
c0a3175bcf36b3b9a65b50d78fade10df23ff64e851bb2866a6a899f9900f362  release/asm/cuda-dp4.s
8f8ea379638fe9c0c5477ca4edc59bee0e2140e845c6b581983f8d6f149f024b  release/asm/cuda-fused.s
5f48fd53df460cea398bcc9c32961919a304163d74aac72ef309e5b59afb98db  release/asm/cuda-gemv.s
e3d98220dec36b9082057a5c921d03baa84b309f9f910385ec7d4f0f0b1b225f  release/asm/cuda-gemv8.s
73f0fb2e3b5733c33c5c4f7de2a0a71070d1de24271c689bef9222e67abe6cca  release/asm/cuda-globals.s
24b88537587b27eb63af5f0ae34c2368588139fad9283efc77d308f2e82c158e  release/asm/cuda-hash64.s
56c5f6e7462c7055f26fe7c4cf9e1b16dc5f832b6a543e807667a8dc13ee29f6  release/asm/cuda-igemm.s
cc381121b5dedda68e70a176b72d8d91dee837891dd3104e9f6f743dda0ad573  release/asm/cuda-int64.s
f648d1a15e56c231f8e641c259112a09e452c6eed741e6bd1f3667728ce760fb  release/asm/cuda-ptrlist.s
a1a46d39eb75272a8d61e2ced4f9e44cf16e210700da850182c1a93b8e357329  release/asm/cuda-ptrmem.s
05488e7011400262be37232f57f34c5cb4448c87685fd5de62315ccd3977dc57  release/asm/cuda-reduce.s
f3c651b17dd3a8f6ed20445f43005aba851eb2ce7d648e3d61685391e6df2f07  release/asm/cuda-scatter.s
e4703fb1c0b5a880ab1554c695dc2dc0f81743a655255af45ad7aa0f2e054526  release/asm/cuda-sfu.s
4e28f920d2d25a1a2943611243f41a0a72bddf00d7cc895ad4e0b6df2cafaa27  release/asm/cuda-sgemm.s
1b38a19d06d2db75cb19303a3cb990abecade207eb7b83d60346f4919adab75a  release/asm/cuda-spinwait.s
56f8bc23746061159d146f248d605bdd2f430be318ba29477aa4c946533bc993  release/asm/cuda-vadd-aligned.s
f540a502bf7063cfb75450053c5163bc8986871d7cb0aa9bc2b8ee8cb9637a3c  release/asm/cuda-vadd.s
d9e3e29cdc3a7411b972a4fbef69a2bed68355798daf5f65bbf21a7cc8ae9c02  release/bench/bench.json
718ae7f2f5b7ea13cf7af347850b325d3156c4afa4592a3f0c471ac35d9e9337  release/bench/bench.txt
7f482c4f970a8526328886a67b04f998e134c4e0ed9a6e8194b309d48b142839  release/bench/sweep-coremark.txt
0529582a0572b0828fefa8b9e57ba448529f16369affe535b1acbb20816662de  release/bench/sweep-decode.txt
19dc6a0419a0eaf6cfbabd8c6afd2f30a8636fd8a4c6676bc6025141eb90b16f  release/bench/sweep-frames.txt
28c14ebc8397a6ec18b69bcb5ebe93a64c94cd04b97c971dd526f78ff72f423b  release/bench/sweep-tiles.txt
d7303feb386ed15e365b64f67d75360f25293d59f3ffb96b5e6e51b116f4a7f5  release/bin/ccv-sim
03a6fdfcc96075b2af7a843f5ec5770f143da923146db0c8461f2a34ae90af86  release/bin/ccv-sim.txt
dca2e02e33501b1bf87e053adfec123cfe804d9c8729d91d78f1e597a32373b3  release/kernels/coremark-derived-pl/kernel.bin
29bd1ce33bb5e6a890ee3cee0bd2ac121aa5816bdd0a7796b1b170be2fbc6312  release/kernels/coremark-derived-pl/kernel.s
9b5ac7519b9437941463c1eb76db94d919d20afedca8f28a3c4395f4417088ad  release/kernels/coremark-derived-pl/launch.txt
4663d1bdf871c564a6c49980f52651597e13b25e8987770a701866e80c2d4f98  release/kernels/coremark-derived-pl/ops.txt
4bdfe9d82139f579e0332cfedca3f35027d097b7665c882512fdb1f86a985819  release/kernels/coremark-derived/kernel.bin
0b8ac17a2ab14f16fd36e7c5cae02eafd20224cc55c4f7133ec5688dd435aa25  release/kernels/coremark-derived/kernel.s
a8864f78f739ccd8e1fb7b0f3ca3ab081e20de092e4970dc27e8975812280063  release/kernels/coremark-derived/launch.txt
2c4a24944619aadca94641d1a5c64728b46bcc315904f0dfac02e4a637da44ed  release/kernels/coremark-derived/ops.txt
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
419b681a6aaffc48e4a6518e90c47ecbc81ad2bd8359058c388adca8cd9f70d4  release/verify.log
```
