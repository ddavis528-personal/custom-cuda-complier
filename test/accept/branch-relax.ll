; F-28: `bra.short` reaches ±256 bytes (§3, Format K point 49), and whether a
; branch fits is a property of the final layout -- so the selector always emits
; the 16-bit form and the assembler relaxes it when it cannot reach. This loop
; body is ~370 bytes, so its latch branch must grow to Format E's 32-bit `bra`.
; tools/check-relaxation.py asserts that it does.
;
; The chain is popcount-based on purpose: an arithmetic one folds to a single
; `add` and the body stops being long enough to prove anything.
declare i32 @llvm.ctpop.i32(i32)
define void @k(i32 %n, i32 %seed) {
entry:
  br label %loop
loop:
  %i = phi i32 [ 0, %entry ], [ %inc, %latch ]
  %acc = phi i32 [ %seed, %entry ], [ %last, %latch ]
  %p0 = call i32 @llvm.ctpop.i32(i32 %acc)
  %v0 = xor i32 %p0, 1
  %p1 = call i32 @llvm.ctpop.i32(i32 %v0)
  %v1 = xor i32 %p1, 8
  %p2 = call i32 @llvm.ctpop.i32(i32 %v1)
  %v2 = xor i32 %p2, 15
  %p3 = call i32 @llvm.ctpop.i32(i32 %v2)
  %v3 = xor i32 %p3, 22
  %p4 = call i32 @llvm.ctpop.i32(i32 %v3)
  %v4 = xor i32 %p4, 29
  %p5 = call i32 @llvm.ctpop.i32(i32 %v4)
  %v5 = xor i32 %p5, 36
  %p6 = call i32 @llvm.ctpop.i32(i32 %v5)
  %v6 = xor i32 %p6, 43
  %p7 = call i32 @llvm.ctpop.i32(i32 %v6)
  %v7 = xor i32 %p7, 50
  %p8 = call i32 @llvm.ctpop.i32(i32 %v7)
  %v8 = xor i32 %p8, 57
  %p9 = call i32 @llvm.ctpop.i32(i32 %v8)
  %v9 = xor i32 %p9, 64
  %p10 = call i32 @llvm.ctpop.i32(i32 %v9)
  %v10 = xor i32 %p10, 71
  %p11 = call i32 @llvm.ctpop.i32(i32 %v10)
  %v11 = xor i32 %p11, 78
  %p12 = call i32 @llvm.ctpop.i32(i32 %v11)
  %v12 = xor i32 %p12, 85
  %p13 = call i32 @llvm.ctpop.i32(i32 %v12)
  %v13 = xor i32 %p13, 92
  %p14 = call i32 @llvm.ctpop.i32(i32 %v13)
  %v14 = xor i32 %p14, 99
  %p15 = call i32 @llvm.ctpop.i32(i32 %v14)
  %v15 = xor i32 %p15, 106
  %p16 = call i32 @llvm.ctpop.i32(i32 %v15)
  %v16 = xor i32 %p16, 113
  %p17 = call i32 @llvm.ctpop.i32(i32 %v16)
  %v17 = xor i32 %p17, 120
  %p18 = call i32 @llvm.ctpop.i32(i32 %v17)
  %v18 = xor i32 %p18, 127
  %p19 = call i32 @llvm.ctpop.i32(i32 %v18)
  %v19 = xor i32 %p19, 134
  %p20 = call i32 @llvm.ctpop.i32(i32 %v19)
  %v20 = xor i32 %p20, 141
  %p21 = call i32 @llvm.ctpop.i32(i32 %v20)
  %v21 = xor i32 %p21, 148
  %p22 = call i32 @llvm.ctpop.i32(i32 %v21)
  %v22 = xor i32 %p22, 155
  %p23 = call i32 @llvm.ctpop.i32(i32 %v22)
  %v23 = xor i32 %p23, 162
  %p24 = call i32 @llvm.ctpop.i32(i32 %v23)
  %v24 = xor i32 %p24, 169
  %p25 = call i32 @llvm.ctpop.i32(i32 %v24)
  %v25 = xor i32 %p25, 176
  %p26 = call i32 @llvm.ctpop.i32(i32 %v25)
  %v26 = xor i32 %p26, 183
  %p27 = call i32 @llvm.ctpop.i32(i32 %v26)
  %v27 = xor i32 %p27, 190
  %p28 = call i32 @llvm.ctpop.i32(i32 %v27)
  %v28 = xor i32 %p28, 197
  %p29 = call i32 @llvm.ctpop.i32(i32 %v28)
  %v29 = xor i32 %p29, 204
  %p30 = call i32 @llvm.ctpop.i32(i32 %v29)
  %v30 = xor i32 %p30, 211
  %p31 = call i32 @llvm.ctpop.i32(i32 %v30)
  %v31 = xor i32 %p31, 218
  %p32 = call i32 @llvm.ctpop.i32(i32 %v31)
  %v32 = xor i32 %p32, 225
  %p33 = call i32 @llvm.ctpop.i32(i32 %v32)
  %v33 = xor i32 %p33, 232
  %p34 = call i32 @llvm.ctpop.i32(i32 %v33)
  %v34 = xor i32 %p34, 239
  %p35 = call i32 @llvm.ctpop.i32(i32 %v34)
  %v35 = xor i32 %p35, 246
  %p36 = call i32 @llvm.ctpop.i32(i32 %v35)
  %v36 = xor i32 %p36, 253
  %p37 = call i32 @llvm.ctpop.i32(i32 %v36)
  %v37 = xor i32 %p37, 260
  %p38 = call i32 @llvm.ctpop.i32(i32 %v37)
  %v38 = xor i32 %p38, 267
  %p39 = call i32 @llvm.ctpop.i32(i32 %v38)
  %v39 = xor i32 %p39, 274
  %last = add i32 %v39, 1
  %inc = add i32 %i, 1
  %c = icmp slt i32 %inc, %n
  br i1 %c, label %latch, label %exit
latch:
  br label %loop
exit:
  %rb = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e = zext i32 %rb to i64
  %w = shl nuw nsw i64 %e, 16
  %p = inttoptr i64 %w to ptr
  %zi = zext i32 %last to i64
  %g = getelementptr inbounds float, ptr %p, i64 %zi
  store float 0.000000e+00, ptr %g, align 4
  ret void
}
!0 = !{}
