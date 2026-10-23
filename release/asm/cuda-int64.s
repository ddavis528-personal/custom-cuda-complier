	.text
	.file	"int64.cu"
	.globl	_Z8int64opsPKjS0_Pji
	.type	_Z8int64opsPKjS0_Pji,@function
_Z8int64opsPKjS0_Pji:
	movi r1, 2
	ld.global r5, [r1 + 56]
	srd r12, 0
	setp.le p0, r5, r12
	@p0 bra LBB0_34
	mov r3, r12
	shl r3, 2
	ld.global r0, [r1 + 44]
	add r0, r3
	ld.global r0, [#1, r0, 0, 0]
	ld.global r2, [r1 + 36]
	add r1, r2, r3
	ld.global r11, [#0, r1, 0, 0]
	clz r6, r11
	setp.ne p0, r11, 0
	clz r4, r0
	add r3, r4, 32
	@p0 mov r3, r6
	sra r6, r5, 31
	xor r5, r6
	sub r5, r6
	add r6, r12, 1
	sra r7, r6, 31
	xor r8, r6, r7
	sub r7, r8, r7
	rcp.u32 r8, r5
	mul.lo r9, r8, r5
	neg r9, r9
	mul.hi.u r9, r8, r9
	add r8, r9
	mul.hi.u r8, r7, r8
	mul.lo r9, r8, r5
	sub r9, r7, r9
	setp.le.u p0, r5, r9
	add r10, r8, 1
	@p0 mov r8, r10
	sub r10, r9, r5
	@p0 mov r9, r10
	setp.le.u p0, r5, r9
	add r9, r8, 1
	@p0 mov r8, r9
	mul.lo r5, r8, r5
	sub r5, r7, r5
	setp.lt p0, r6, 0
	neg r6, r5
	@p0 mov r5, r6
	shl r5, 2
	add r2, r5
	ld.global r10, [#0, r2, 0, 0]
	or r13, r10, 1
	clz r2, r13
	or r2, r2, 32
	setp.ne p0, r0, 0
	@p0 mov r2, r4
	and r4, r0, 63
	movi r5, 32
	sub r5, r4
	shl r6, r11, r4
	shr r7, r0, r5
	or r6, r7
	add r7, r4, -32
	shl r9, r0, r7
	setp.lt.u p0, r4, 32
	@p0 mov r9, r6
	shl r5, r11, r5
	shr r6, r0, r4
	or r5, r6, r5
	shr r6, r11, r7
	@p0 mov r6, r5
	sra r1, r11, r7
	@p0 mov r1, r5
	setp.eq p1, r4, 0
	@p1 mov r1, r0
	st.local r1, [28]
	@p1 mov r6, r0
	st.local r6, [36]
	@p1 mov r9, r11
	st.local r9, [32]
	sra r5, r11, r4
	sra r1, r11, 31
	@p0 mov r1, r5
	st.local r1, [40]
	shl r5, r0, r4
	shr r4, r11, r4
	movi r6, 0
	movi r1, 0
	@p0 mov r1, r4
	st.local r1, [44]
	movi r1, 0
	@p0 mov r1, r5
	st.local r1, [48]
	setp.eq p0, r11, r0
	st.pred.local 1, [12]
	setp.lt p0, r11, r0
	st.pred.local 1, [20]
	setp.lt.u p2, r0, r10
	pxor p1, 2, 0
	st.pred.local 4, [52]
	ld.pred.local 1, [12]
	pand p0, 0, 1
	st.pred.local 1, [64]
	setp.lt.u p1, r11, r0
	pxor p2, 2, 1
	ld.pred.local 1, [12]
	pand p0, 0, 2
	st.pred.local 1, [12]
	setp.lt.u p0, r2, r3
	st.pred.local 1, [52]
	sub r2, r3
	or r3, r0, r11
	setp.eq p0, r3, 0
	or r3, r13, r0
	setp.eq p2, r3, 0
	por p0, 2, 0
	st.pred.local 1, [56]
	ld.pred.local 1, [12]
	pxor p0, 1, 0
	st.pred.local 1, [12]
	ld.pred.local 1, [20]
	ld.pred.local 2, [60]
	pxor p0, 0, 1
	st.pred.local 1, [20]
	add r1, r0, r11
	add r3, r10, r0
	st.local r3, [76]
	setp.lt.u p2, r3, r10
	@p2 add r1, r1, 1
	st.local r1, [68]
	sub r1, r11, r0
	ld.pred.local 1, [60]
	@p0 add r1, r1, -1
	st.local r1, [72]
	movi r1, 63
	setp.lt.u p2, r1, r2
	movi r3, 0
	ld.pred.local 1, [52]
	@p0 add r3, r3, -1
	setp.ne p0, r3, 0
	pxor p2, 2, 0
	setp.eq p1, r3, 0
	pand p1, 1, 2
	pxor p0, 0, 1
	ld.pred.local 2, [52]
	por p2, 1, 0
	mov r1, r10
	ld.pred.local 1, [20]
	@p0 mov r1, r0
	st.local r1, [56]
	mov r1, r0
	@p0 mov r1, r11
	st.local r1, [52]
	mov r1, r10
	ld.pred.local 1, [12]
	@p0 mov r1, r0
	st.local r1, [64]
	mov r1, r0
	@p0 mov r1, r11
	st.local r1, [60]
	mov r1, r11
	@p2 mov r1, r6
	mov r14, r0
	@p2 mov r14, r6
	st.local r13, [12]
	st.local r10, [16]
	st.local r12, [24]
	@p2 bra LBB0_8
	xor r4, r2, 63
	or r4, r3
	setp.eq p0, r4, 0
	@p0 bra LBB0_8
	movi r4, 63
	sub r5, r4, r2
	movi r7, 32
	sub r4, r7, r5
	shr r4, r0, r4
	shl r6, r11, r5
	or r6, r4
	movi r4, 31
	sub r4, r2
	shl r4, r0, r4
	setp.lt.u p0, r5, 32
	@p0 mov r4, r6
	setp.eq p1, r5, 0
	@p1 mov r4, r11
	shl r6, r0, r5
	movi r8, 0
	movi r5, 0
	@p0 mov r5, r6
	add r6, r2, 1
	setp.eq p0, r6, 0
	@p0 add r3, r3, 1
	or r2, r6, r3
	setp.eq p0, r2, 0
	@!p0 bra LBB0_4
	movi r7, 0
	bra.short LBB0_7
LBB0_4:
	sub r2, r7, r6
	shl r2, r11, r2
	shr r7, r0, r6
	or r2, r7, r2
	add r7, r6, -32
	shr r9, r11, r7
	setp.lt.u p0, r6, 32
	@p0 mov r9, r2
	setp.eq p1, r6, 0
	@p1 mov r9, r0
	mov r1, r11
	shr r2, r11, r6
	movi r7, 0
	movi r11, 0
	@p0 mov r11, r2
	setp.eq p0, r13, 0
	mov r2, r0
	@p0 add r2, r2, -1
	add r10, r13, -1
LBB0_5:
	shl r11, 1
	shr r15, r9, 31
	or r11, r15
	shl r9, 1
	shr r15, r4, 31
	or r9, r15
	setp.lt.u p0, r10, r9
	sub r15, r2, r11
	@p0 add r15, r15, -1
	sra r15, r15, 31
	and r14, r15, r0
	sub r11, r14
	shl r4, 1
	shr r14, r5, 31
	or r4, r14
	and r14, r15, r13
	setp.lt.u p0, r9, r14
	sub r9, r14
	shl r5, 1
	or r5, r8, r5
	or r4, r7, r4
	setp.eq p1, r6, 0
	@p1 add r3, r3, -1
	@p0 add r11, r11, -1
	add r6, r6, -1
	or r13, r6, r3
	and r8, r15, 1
	setp.eq p0, r13, 0
	ld.local r13, [12]
	@!p0 bra LBB0_5
	mov r11, r1
	ld.local r12, [24]
LBB0_7:
	shr r2, r5, 31
	shl r5, 1
	or r14, r8, r5
	shl r4, 1
	or r2, r4, r2
	or r1, r7, r2
LBB0_8:
	ld.local r2, [16]
	mul.hi.u r2, r2, r0
	st.local r2, [96]
	sra r15, r11, 31
	xor r2, r15, r11
	sub r10, r2, r15
	xor r3, r15, r0
	setp.lt.u p0, r3, r15
	st.local r10, [88]
	@p0 add r10, r10, -1
	st.local r3, [112]
	sub r9, r3, r15
	clz r2, r9
	add r4, r2, 32
	clz r2, r10
	setp.ne p0, r10, 0
	st.local r4, [108]
	mov r3, r4
	@p0 mov r3, r2
	sra r2, r0, 31
	xor r4, r2, r0
	sub r4, r2
	xor r5, r2, r13
	setp.lt.u p0, r5, r2
	@p0 add r4, r4, -1
	sub r7, r5, r2
	clz r5, r7
	add r5, r5, 32
	clz r6, r4
	setp.ne p0, r4, 0
	@p0 mov r5, r6
	mul.hi.u r6, r14, r13
	mad.acc r6, r14, r0
	mad.acc r6, r1, r13
	mul.lo r8, r14, r13
	st.local r8, [116]
	setp.lt.u p2, r0, r8
	setp.lt.u p0, r5, r3
	st.pred.local 1, [92]
	sub r3, r5, r3
	sub r6, r11, r6
	or r5, r9, r10
	setp.eq p1, r5, 0
	or r5, r7, r4
	setp.eq p0, r5, 0
	por p0, 0, 1
	st.pred.local 1, [120]
	@p2 add r6, r6, -1
	st.local r6, [84]
	st.local r15, [104]
	xor r2, r15
	st.local r2, [100]
	movi r2, 63
	setp.lt.u p0, r2, r3
	movi r5, 0
	ld.pred.local 2, [88]
	@p1 add r5, r5, -1
	setp.ne p2, r5, 0
	pxor p0, 0, 2
	setp.eq p1, r5, 0
	pand p0, 1, 0
	pxor p0, 2, 0
	ld.pred.local 2, [116]
	por p0, 1, 0
	mov r2, r9
	movi r8, 0
	@p0 mov r2, r8
	mov r6, r10
	@p0 mov r6, r8
	st.local r9, [92]
	st.local r1, [80]
	st.local r14, [20]
	@p0 bra LBB0_9
	xor r8, r3, 63
	or r8, r5
	setp.eq p0, r8, 0
	mov r15, r12
	ld.local r12, [16]
	@p0 bra LBB0_17
	movi r1, 63
	sub r1, r3
	movi r8, 32
	sub r2, r8, r1
	shr r2, r9, r2
	shl r6, r10, r1
	or r2, r6, r2
	movi r6, 31
	sub r6, r3
	shl r13, r9, r6
	setp.lt.u p0, r1, 32
	@p0 mov r13, r2
	setp.eq p1, r1, 0
	@p1 mov r13, r10
	shl r1, r9, r1
	movi r2, 0
	movi r14, 0
	@p0 mov r14, r1
	add r6, r3, 1
	setp.eq p0, r6, 0
	@p0 add r5, r5, 1
	or r1, r6, r5
	setp.eq p0, r1, 0
	@!p0 bra LBB0_10
	movi r10, 0
	bra.short LBB0_13
LBB0_9:
	mov r15, r12
	ld.local r12, [16]
	bra.short LBB0_17
LBB0_10:
	st.local r11, [144]
	sub r1, r8, r6
	shl r1, r10, r1
	shr r2, r9, r6
	or r1, r2, r1
	add r2, r6, -32
	shr r8, r10, r2
	setp.lt.u p0, r6, 32
	@p0 mov r8, r1
	setp.eq p1, r6, 0
	@p1 mov r8, r9
	shr r1, r10, r6
	movi r10, 0
	movi r11, 0
	@p0 mov r11, r1
	setp.eq p0, r7, 0
	mov r3, r4
	@p0 add r3, r3, -1
	add r9, r7, -1
	movi r2, 0
LBB0_11:
	shl r11, 1
	shr r15, r8, 31
	or r11, r15
	shl r8, 1
	shr r15, r13, 31
	or r8, r15
	setp.lt.u p0, r9, r8
	sub r15, r3, r11
	@p0 add r15, r15, -1
	sra r15, r15, 31
	and r12, r15, r4
	sub r11, r12
	shl r13, 1
	shr r12, r14, 31
	or r12, r13, r12
	and r13, r15, r7
	setp.lt.u p0, r8, r13
	sub r8, r13
	shl r14, 1
	or r14, r2, r14
	or r13, r10, r12
	setp.eq p1, r6, 0
	@p1 add r5, r5, -1
	@p0 add r11, r11, -1
	add r6, r6, -1
	or r1, r6, r5
	and r2, r15, 1
	setp.eq p0, r1, 0
	@!p0 bra LBB0_11
	ld.local r11, [144]
	ld.local r12, [16]
	ld.local r15, [24]
	ld.local r9, [92]
LBB0_13:
	shr r3, r14, 31
	shl r14, 1
	or r2, r14
	shl r13, 1
	or r3, r13, r3
	or r6, r10, r3
	ld.local r14, [20]
LBB0_17:
	mov r13, r15
	shl r1, r11, 25
	st.local r1, [120]
	mov r1, r0
	shr r1, 7
	st.local r1, [124]
	ld.local r1, [96]
	mad.acc r1, r12, r11
	st.local r1, [128]
	clz r1, r0
	add r1, r1, 32
	clz r3, r11
	setp.ne p0, r11, 0
	@p0 mov r1, r3
	movi r3, 54
	setp.lt.u p0, r3, r1
	sub r4, r3, r1
	movi r1, 63
	setp.lt.u p1, r1, r4
	movi r15, 0
	movi r5, 0
	@p0 add r5, r5, -1
	setp.ne p0, r5, 0
	pxor p1, 1, 0
	setp.eq p2, r5, 0
	pand p1, 2, 1
	ld.local r7, [100]
	xor r1, r2, r7
	sub r10, r1, r7
	ld.local r3, [12]
	mul.hi.u r2, r10, r3
	mad.acc r2, r10, r0
	setp.lt.u p2, r1, r7
	xor r1, r6, r7
	sub r1, r7
	@p2 add r1, r1, -1
	pxor p0, 0, 1
	st.local r1, [100]
	mad.lo r1, r1, r3, r2
	sub r8, r11, r1
	mul.lo r1, r10, r3
	st.local r1, [140]
	setp.lt.u p1, r0, r1
	@p1 add r8, r8, -1
	or r1, r0, r11
	setp.eq p1, r1, 0
	por p0, 1, 0
	movi r7, 1000
	mov r2, r0
	@p0 mov r2, r15
	mov r6, r11
	@p0 mov r6, r15
	st.local r8, [12]
	st.local r10, [96]
	@p0 bra LBB0_18
	xor r1, r4, 63
	or r1, r5
	setp.eq p0, r1, 0
	mov r15, r13
	@p0 bra LBB0_26
	movi r1, 63
	sub r1, r4
	movi r8, 32
	sub r2, r8, r1
	shr r2, r0, r2
	shl r3, r11, r1
	or r2, r3, r2
	movi r3, 31
	sub r3, r4
	shl r12, r0, r3
	setp.lt.u p0, r1, 32
	@p0 mov r12, r2
	setp.eq p1, r1, 0
	@p1 mov r12, r11
	shl r1, r0, r1
	movi r2, 0
	movi r6, 0
	@p0 mov r6, r1
	add r10, r4, 1
	setp.eq p0, r10, 0
	@p0 add r5, r5, 1
	or r1, r10, r5
	setp.eq p0, r1, 0
	@!p0 bra LBB0_19
	movi r14, 0
	bra.short LBB0_22
LBB0_18:
	mov r15, r13
	bra.short LBB0_26
LBB0_19:
	sub r1, r8, r10
	shl r1, r11, r1
	shr r2, r0, r10
	or r1, r2, r1
	add r2, r10, -32
	shr r8, r11, r2
	setp.lt.u p0, r10, 32
	@p0 mov r8, r1
	setp.eq p1, r10, 0
	@p1 mov r8, r0
	st.local r11, [144]
	shr r1, r11, r10
	movi r14, 0
	movi r15, 0
	@p0 mov r15, r1
	setp.eq p0, r7, 0
	movi r4, 0
	@p0 add r4, r4, -1
	add r9, r7, -1
	movi r2, 0
LBB0_20:
	shl r15, 1
	shr r1, r8, 31
	or r15, r1
	shl r8, 1
	shr r1, r12, 31
	or r1, r8, r1
	setp.lt.u p0, r9, r1
	sub r8, r4, r15
	@p0 add r8, r8, -1
	shl r12, 1
	shr r11, r6, 31
	or r11, r12, r11
	sra r3, r8, 31
	and r8, r3, r7
	setp.lt.u p0, r1, r8
	sub r8, r1, r8
	shl r6, 1
	or r6, r2, r6
	or r12, r14, r11
	setp.eq p1, r10, 0
	@p1 add r5, r5, -1
	@p0 add r15, r15, -1
	add r10, r10, -1
	or r1, r10, r5
	and r2, r3, 1
	setp.eq p0, r1, 0
	@!p0 bra LBB0_20
	ld.local r11, [144]
	ld.local r15, [24]
	ld.local r9, [92]
LBB0_22:
	shr r1, r6, 31
	shl r6, 1
	or r2, r6
	shl r12, 1
	or r1, r12, r1
	or r6, r14, r1
	ld.local r12, [16]
	ld.local r14, [20]
	ld.local r8, [12]
	ld.local r10, [96]
LBB0_26:
	ld.local r1, [120]
	ld.local r3, [124]
	or r1, r3, r1
	st.local r1, [124]
	ld.local r1, [128]
	mad.acc r1, r0, r0
	st.local r1, [128]
	mul.lo r1, r12, r0
	st.local r1, [132]
	sub r1, r0, r12
	st.local r1, [136]
	ld.local r1, [116]
	sub r1, r0, r1
	st.local r1, [120]
	ld.local r1, [140]
	sub r1, r0, r1
	st.local r1, [116]
	ld.local r4, [104]
	ld.local r1, [112]
	setp.lt.u p0, r1, r4
	ld.local r13, [88]
	@p0 add r13, r13, -1
	clz r1, r13
	setp.ne p0, r13, 0
	ld.local r5, [108]
	@p0 mov r5, r1
	mul.hi.u r1, r7, r2
	mad.acc r1, r7, r6
	sub r1, r11, r1
	mul.lo r2, r7, r2
	setp.lt.u p0, r0, r2
	@p0 add r1, r1, -1
	sub r1, r0, r2
	st.local r1, [88]
	movi r1, 61
	setp.lt.u p0, r1, r5
	sub r2, r1, r5
	movi r1, 63
	setp.lt.u p1, r1, r2
	movi r3, 0
	@p0 add r3, r3, -1
	setp.ne p0, r3, 0
	pxor p1, 1, 0
	setp.eq p2, r3, 0
	pand p1, 2, 1
	pxor p0, 0, 1
	or r1, r9, r13
	setp.eq p1, r1, 0
	por p0, 1, 0
	not r1, r4
	st.local r1, [104]
	movi r1, 0
	@p0 mov r9, r1
	mov r7, r13
	@p0 mov r7, r1
	@p0 bra LBB0_33
	xor r1, r2, 63
	or r1, r3
	setp.eq p0, r1, 0
	@p0 bra LBB0_33
	movi r1, 63
	sub r1, r2
	movi r5, 32
	sub r6, r5, r1
	ld.local r4, [92]
	shr r6, r4, r6
	shl r7, r13, r1
	or r7, r6
	movi r6, 31
	sub r6, r2
	shl r6, r4, r6
	setp.lt.u p0, r1, 32
	@p0 mov r6, r7
	setp.eq p1, r1, 0
	@p1 mov r6, r13
	shl r1, r4, r1
	movi r10, 0
	movi r7, 0
	@p0 mov r7, r1
	add r9, r2, 1
	setp.eq p0, r9, 0
	@p0 add r3, r3, 1
	or r1, r9, r3
	setp.eq p0, r1, 0
	@!p0 bra LBB0_29
	movi r8, 0
	bra.short LBB0_32
LBB0_29:
	st.local r11, [144]
	movi r2, 7
	sub r1, r5, r9
	shl r1, r13, r1
	shr r5, r4, r9
	or r1, r5, r1
	add r5, r9, -32
	shr r15, r13, r5
	setp.lt.u p0, r9, 32
	@p0 mov r15, r1
	setp.eq p1, r9, 0
	@p1 mov r15, r4
	shr r1, r13, r9
	movi r8, 0
	movi r11, 0
	@p0 mov r11, r1
	setp.eq p0, r2, 0
	movi r14, 0
	@p0 add r14, r14, -1
	add r5, r2, -1
	movi r10, 0
LBB0_30:
	shl r11, 1
	shr r1, r15, 31
	or r11, r1
	shl r15, 1
	shr r1, r6, 31
	or r1, r15, r1
	setp.lt.u p0, r5, r1
	sub r15, r14, r11
	@p0 add r15, r15, -1
	shl r6, 1
	shr r13, r7, 31
	or r6, r13
	sra r13, r15, 31
	and r15, r13, r2
	setp.lt.u p0, r1, r15
	sub r15, r1, r15
	shl r7, 1
	or r7, r10, r7
	or r6, r8, r6
	setp.eq p1, r9, 0
	@p1 add r3, r3, -1
	@p0 add r11, r11, -1
	add r9, r9, -1
	or r1, r9, r3
	and r10, r13, 1
	setp.eq p0, r1, 0
	@!p0 bra LBB0_30
	ld.local r11, [144]
	ld.local r12, [16]
	ld.local r15, [24]
	ld.local r14, [20]
LBB0_32:
	shr r1, r7, 31
	shl r7, 1
	or r9, r10, r7
	shl r6, 1
	or r1, r6, r1
	or r7, r8, r1
	ld.local r8, [12]
	ld.local r10, [96]
LBB0_33:
	movi r3, 2
	ld.global r1, [r3 + 52]
	movi r2, 136
	mad.lo r2, r15, r2, r1
	ld.local r5, [76]
	st.global r5, [#2, r2, 0, 0]
	add r5, r2, 4
	ld.local r6, [68]
	st.global r6, [#2, r5, 0, 0]
	add r5, r2, 8
	ld.local r4, [136]
	st.global r4, [#2, r5, 0, 0]
	add r2, 12
	ld.local r5, [72]
	st.global r5, [#2, r2, 0, 0]
	mul.lo r6, r15, 136
	add r2, r6, 16
	add r1, r2
	ld.local r4, [132]
	st.global r4, [#2, r1, 0, 0]
	ld.global r1, [r3 + 52]
	add r1, r2
	add r1, 4
	ld.local r2, [128]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 24
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r4, [124]
	st.global r4, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	mov r2, r11
	shr r2, 7
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 32
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r5, [48]
	st.global r5, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [32]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 40
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r5, [36]
	st.global r5, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [44]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 48
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r5, [28]
	st.global r5, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [40]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 56
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r5, [64]
	st.global r5, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [60]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 64
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r5, [56]
	st.global r5, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [52]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 72
	ld.global r2, [r3 + 52]
	add r2, r1
	st.global r14, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [80]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 80
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r4, [120]
	st.global r4, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [84]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 88
	ld.global r2, [r3 + 52]
	add r2, r1
	st.global r10, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	ld.local r2, [100]
	st.global r2, [#2, r1, 0, 0]
	add r1, r6, 96
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r4, [116]
	st.global r4, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	st.global r8, [#2, r1, 0, 0]
	add r1, r6, 104
	ld.global r2, [r3 + 52]
	add r2, r1
	ld.local r4, [88]
	st.global r4, [#2, r2, 0, 0]
	ld.global r2, [r3 + 52]
	add r1, r2, r1
	add r1, 4
	movi r2, 0
	st.global r2, [#2, r1, 0, 0]
	ld.local r4, [104]
	xor r1, r9, r4
	add r5, r6, 112
	ld.global r8, [r3 + 52]
	add r8, r5
	sub r9, r1, r4
	st.global r9, [#2, r8, 0, 0]
	setp.lt.u p0, r1, r4
	xor r1, r7, r4
	sub r1, r4
	@p0 add r1, r1, -1
	ld.global r4, [r3 + 52]
	add r4, r5
	add r4, 4
	st.global r1, [#2, r4, 0, 0]
	xor r1, r0, r12
	xor r4, r11, r0
	or r1, r4
	setp.eq p0, r1, 0
	movi r1, 0
	@p0 add r1, r1, 1
	add r4, r6, 120
	ld.global r5, [r3 + 52]
	add r5, r4
	st.global r1, [#2, r5, 0, 0]
	ld.global r1, [r3 + 52]
	add r1, r4
	add r1, 4
	st.global r2, [#2, r1, 0, 0]
	mad.lo r1, r0, r11, r0
	add r2, r6, 128
	ld.global r4, [r3 + 52]
	add r4, r2
	st.global r1, [#2, r4, 0, 0]
	mul.lo r4, r0, r11
	setp.lt.u p0, r1, r4
	mul.hi.u r0, r0, r11
	add r0, r11
	@p0 add r0, r0, 1
	ld.global r1, [r3 + 52]
	add r1, r2
	add r1, 4
	st.global r0, [#2, r1, 0, 0]
LBB0_34:
	exit
Lfunc_end0:
	.size	_Z8int64opsPKjS0_Pji, Lfunc_end0-_Z8int64opsPKjS0_Pji

