	.text
	.file	"sgemm.cu"
	.globl	_Z5sgemmPfPKfS1_ii
	.type	_Z5sgemmPfPKfS1_ii,@function
_Z5sgemmPfPKfS1_ii:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 0
	add r15, r14
	pmov p3, 1
	movi r4, 2
	@p3 ld.global r1, [r4 + 60]
	@!p3 shfl.idx r1, r1, 0
	rcp.u32 r0, r1
	mul.lo r2, r0, r1
	neg r2, r2
	@p3 mul.hi.u r2, r0, r2
	@p3 add r2, r0, r2
	srd r0, 1
	@p3 mul.hi.u r13, r0, r2
	@!p3 shfl.idx r13, r13, 0
	mul.lo r2, r13, r1
	@p3 sub r2, r0, r2
	@!p3 shfl.idx r2, r2, 0
	setp.le.u p0, r1, r2
	@p3 add r3, r13, 1
	pand p1, 0, 3
	@p1 mov r13, r3
	@p3 sub r3, r2, r1
	@p0 mov r2, r3
	setp.le.u p0, r1, r2
	@p3 add r2, r13, 1
	@p0 mov r13, r2
	mul.lo r3, r13, r1
	@p3 sub r5, r0, r3
	@!p3 shfl.idx r5, r5, 0
	srd r6, 0
	mov r1, r6
	shr r1, 2
	f48 r2, 1073741822
	and r12, r1, r2
	mov r2, r6
	shl r2, 1
	and r7, r2, 14
	shl r13, 3
	shl r5, 4
	st.global r5, [r15 + -176]
	@p3 ld.global r14, [r4 + 56]
	@!p3 shfl.idx r14, r14, 0
	setp.lt p0, r14, 1
	st.global r13, [r15 + -172]
	st.global r14, [r15 + -4]
	st.global r7, [r15 + -168]
	@p0 bra LBB0_1
	add r2, r6, 96
	shr r2, 4
	shl r0, 4
	mov r5, r6
	shr r5, 4
	add r4, r5, 4
	mad.lo r4, r14, r4, r0
	add r11, r6, 32
	mad.lo r10, r14, r2, r0
	st.global r12, [r15 + -8]
	mov r12, r11
	shr r12, 4
	mad.lo r8, r14, r12, r0
	mad.acc r0, r14, r5
	shl r3, 4
	sub r7, r0, r3
	sub r8, r3
	sub r9, r4, r3
	sub r10, r3
	and r0, r6, 7
	add r3, r13, r0
	shl r0, 2
	shr r11, 3
	mad.lo r4, r14, r3, r11
	st.global r4, [r15 + -152]
	shl r11, 5
	mov r4, r6
	shr r4, 3
	mad.lo r3, r14, r3, r4
	st.global r3, [r15 + -140]
	shl r4, 5
	or r3, r4, r0
	st.global r3, [r15 + -144]
	or r0, r11, r0
	st.global r0, [r15 + -156]
	shl r12, 6
	shl r5, 6
	shl r2, 6
	and r0, r6, 15
	st.global r0, [r15 + -136]
	shl r0, 2
	or r4, r2, r0
	or r11, r5, r0
	or r2, r12, r0
	movi r5, 0
	movi r0, 0
	mov r3, r14
	shl r3, 3
	ld.global r13, [r15 + -168]
	shl r13, 2
	or r12, r13, 708
	st.global r12, [r15 + -12]
	or r12, r13, 704
	st.global r12, [r15 + -16]
	ld.global r12, [r15 + -8]
	shl r12, 2
	add r14, r12, 224
	st.global r14, [r15 + -24]
	or r14, r13, 644
	st.global r14, [r15 + -28]
	or r14, r13, 640
	st.global r14, [r15 + -32]
	add r14, r12, 192
	st.global r14, [r15 + -36]
	or r14, r13, 580
	st.global r14, [r15 + -40]
	or r14, r13, 576
	st.global r14, [r15 + -44]
	add r14, r12, 160
	st.global r14, [r15 + -48]
	or r14, r13, 516
	st.global r14, [r15 + -52]
	or r14, r13, 512
	st.global r14, [r15 + -56]
	add r14, r12, 128
	st.global r14, [r15 + -60]
	or r14, r13, 452
	st.global r14, [r15 + -64]
	or r14, r13, 448
	st.global r14, [r15 + -68]
	add r14, r12, 96
	st.global r14, [r15 + -72]
	or r14, r13, 388
	st.global r14, [r15 + -76]
	or r14, r13, 384
	st.global r14, [r15 + -80]
	add r14, r12, 64
	st.global r14, [r15 + -84]
	or r14, r13, 324
	st.global r14, [r15 + -88]
	or r14, r13, 320
	st.global r14, [r15 + -92]
	st.global r12, [r15 + -20]
	add r12, r12, 32
	st.global r12, [r15 + -96]
	or r12, r13, 260
	st.global r12, [r15 + -100]
	or r12, r13, 256
	st.global r12, [r15 + -104]
	shl r1, 2
	or r14, r1, 4
	add r1, r14, 224
	st.global r1, [r15 + -108]
	add r1, r14, 192
	st.global r1, [r15 + -112]
	add r1, r14, 160
	st.global r1, [r15 + -116]
	add r1, r14, 128
	st.global r1, [r15 + -120]
	add r1, r14, 96
	st.global r1, [r15 + -124]
	add r1, r14, 64
	st.global r1, [r15 + -128]
	add r1, r14, 32
	st.global r1, [r15 + -132]
	add r1, r11, 256
	st.global r1, [r15 + -148]
	add r1, r4, 256
	st.global r1, [r15 + -180]
	or r4, r11, 256
	add r1, r4, 256
	st.global r1, [r15 + -164]
	add r1, r2, 256
	st.global r1, [r15 + -160]
	movi r4, 0
	movi r2, 0
	movi r11, 0
	bra.short LBB0_3
LBB0_7:
	bar.arrive 0
	bar.wait 0
	ld.global r1, [r15 + -100]
	ld.shared r1, [r1 + 0]
	ld.global r12, [r15 + -104]
	ld.shared r13, [r12 + 0]
	ld.global r12, [r15 + -20]
	ld.shared r12, [r12 + 0]
	ffma.acc.f0 r11, r12, r13
	ffma.acc.f0 r2, r12, r1
	ld.shared r12, [r14 + 0]
	ffma.acc.f0 r4, r12, r13
	ffma.acc.f0 r0, r12, r1
	ld.global r1, [r15 + -92]
	ld.shared r1, [r1 + 0]
	ld.global r12, [r15 + -88]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -132]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r0, r13, r12
	ffma.acc.f0 r4, r13, r1
	ld.global r13, [r15 + -96]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r2, r13, r12
	ffma.f0 r1, r13, r1, r11
	ld.global r11, [r15 + -76]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -80]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -84]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r1, r13, r12
	ffma.acc.f0 r2, r13, r11
	ld.global r13, [r15 + -128]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r4, r13, r12
	ffma.acc.f0 r0, r13, r11
	ld.global r11, [r15 + -68]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -64]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -124]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r0, r13, r12
	ffma.acc.f0 r4, r13, r11
	ld.global r13, [r15 + -72]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r2, r13, r12
	ffma.acc.f0 r1, r13, r11
	ld.global r11, [r15 + -52]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -56]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -60]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r1, r13, r12
	ffma.acc.f0 r2, r13, r11
	ld.global r13, [r15 + -120]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r4, r13, r12
	ffma.acc.f0 r0, r13, r11
	ld.global r11, [r15 + -44]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -40]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -116]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r0, r13, r12
	ffma.acc.f0 r4, r13, r11
	ld.global r13, [r15 + -48]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r2, r13, r12
	ffma.acc.f0 r1, r13, r11
	ld.global r11, [r15 + -28]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -32]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -36]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r1, r13, r12
	ffma.acc.f0 r2, r13, r11
	ld.global r13, [r15 + -112]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r4, r13, r12
	ffma.acc.f0 r0, r13, r11
	ld.global r11, [r15 + -16]
	ld.shared r11, [r11 + 0]
	ld.global r12, [r15 + -12]
	ld.shared r12, [r12 + 0]
	ld.global r13, [r15 + -108]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r0, r13, r12
	ffma.acc.f0 r4, r13, r11
	ld.global r13, [r15 + -24]
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r2, r13, r12
	ffma.f0 r11, r13, r11, r1
	add r7, r3
	add r8, r3
	add r9, r3
	add r10, r3
	@p3 add r5, r5, 8
	@!p3 shfl.idx r5, r5, 0
	ld.global r1, [r15 + -4]
	setp.lt p0, r5, r1
	bar.arrive 0
	bar.wait 0
	ld.global r12, [r15 + -8]
	@!p0 bra LBB0_8
LBB0_3:
	movi r1, 63
	setp.lt.u p0, r1, r6
	@p0 bra LBB0_5
	ld.global r1, [r15 + -140]
	add r13, r1, r5
	shl r13, 2
	movi r1, 2
	ld.global r1, [r1 + 44]
	add r1, r13
	ld.global r1, [#1, r1, 0, 0]
	ld.global r12, [r15 + -144]
	st.shared r1, [r12 + 0]
	setp.lt.u p0, r6, 32
	@!p0 bra LBB0_5
	ld.global r1, [r15 + -152]
	add r1, r5
	shl r1, 2
	movi r12, 2
	ld.global r13, [r12 + 44]
	add r1, r13, r1
	ld.global r1, [#1, r1, 0, 0]
	ld.global r12, [r15 + -156]
	st.shared r1, [r12 + 0]
LBB0_5:
	movi r1, 127
	setp.lt.u p0, r1, r6
	@p0 bra LBB0_7
	ld.global r1, [r15 + -136]
	add r1, r7
	shl r1, 2
	movi r12, 2
	ld.global r13, [r12 + 52]
	add r1, r13, r1
	ld.global r1, [#2, r1, 0, 0]
	ld.global r12, [r15 + -148]
	st.shared r1, [r12 + 0]
	setp.lt.u p0, r6, 96
	@!p0 bra LBB0_7
	ld.global r1, [r15 + -136]
	add r1, r8
	shl r1, 2
	movi r12, 2
	ld.global r12, [r12 + 52]
	add r1, r12, r1
	ld.global r1, [#2, r1, 0, 0]
	ld.global r12, [r15 + -160]
	st.shared r1, [r12 + 0]
	movi r1, 63
	setp.lt.u p0, r1, r6
	@p0 bra LBB0_7
	ld.global r1, [r15 + -136]
	add r1, r9
	shl r1, 2
	movi r12, 2
	ld.global r12, [r12 + 52]
	add r1, r12, r1
	ld.global r1, [#2, r1, 0, 0]
	ld.global r12, [r15 + -164]
	st.shared r1, [r12 + 0]
	movi r1, 31
	setp.lt.u p0, r1, r6
	@p0 bra LBB0_7
	ld.global r1, [r15 + -136]
	add r1, r10
	shl r1, 2
	movi r12, 2
	ld.global r12, [r12 + 52]
	add r1, r12, r1
	ld.global r1, [#2, r1, 0, 0]
	ld.global r12, [r15 + -180]
	st.shared r1, [r12 + 0]
	bra.short LBB0_7
LBB0_1:
	movi r0, 0
	movi r4, 0
	movi r2, 0
	movi r11, 0
LBB0_8:
	ld.global r1, [r15 + -176]
	ld.global r3, [r15 + -168]
	or r1, r3, r1
	ld.global r3, [r15 + -172]
	add r3, r12
	ld.global r7, [r15 + -4]
	mad.lo r5, r3, r7, r1
	shl r5, 2
	movi r6, 2
	@p3 ld.global r6, [r6 + 36]
	@!p3 shfl.idx r6, r6, 0
	add r5, r6, r5
	st.global r11, [#0, r5, 0, 0]
	add r5, 4
	st.global r2, [#0, r5, 0, 0]
	or r2, r3, 1
	mad.acc r1, r2, r7
	shl r1, 2
	add r1, r6, r1
	st.global r4, [#0, r1, 0, 0]
	add r1, 4
	st.global r0, [#0, r1, 0, 0]
	exit
Lfunc_end0:
	.size	_Z5sgemmPfPKfS1_ii, Lfunc_end0-_Z5sgemmPfPKfS1_ii

