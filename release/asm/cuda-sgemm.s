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
	movi r2, 2
	@p3 ld.global r0, [r2 + 60]
	@!p3 shfl.idx r0, r0, 0
	rcp.u32 r1, r0
	mul.lo r3, r1, r0
	neg r3, r3
	@p3 mul.hi.u r3, r1, r3
	@p3 add r3, r1, r3
	srd r1, 1
	@p3 mul.hi.u r12, r1, r3
	@!p3 shfl.idx r12, r12, 0
	mul.lo r3, r12, r0
	@p3 sub r3, r1, r3
	@!p3 shfl.idx r3, r3, 0
	setp.le.u p0, r0, r3
	@p3 add r4, r12, 1
	pand p1, 0, 3
	@p1 mov r12, r4
	@p3 sub r4, r3, r0
	@p0 mov r3, r4
	setp.le.u p0, r0, r3
	@p3 add r3, r12, 1
	@p0 mov r12, r3
	mul.lo r3, r12, r0
	@p3 sub r6, r1, r3
	@!p3 shfl.idx r6, r6, 0
	srd r14, 0
	mov r0, r14
	shr r0, 2
	f48 r4, 1073741822
	and r13, r0, r4
	mov r4, r14
	shl r4, 1
	and r4, 14
	shl r12, 3
	shl r6, 4
	st.global r6, [r15 + -180]
	@p3 ld.global r10, [r2 + 56]
	@!p3 shfl.idx r10, r10, 0
	setp.lt p0, r10, 1
	st.global r12, [r15 + -176]
	@p0 bra LBB0_1
	add r2, r14, 96
	shr r2, 4
	shl r1, 4
	st.global r4, [r15 + -8]
	mov r4, r14
	shr r4, 4
	add r6, r4, 4
	mad.lo r8, r10, r6, r1
	add r11, r14, 32
	mad.lo r9, r10, r2, r1
	st.global r10, [r15 + -4]
	mov r10, r11
	shr r10, 4
	ld.global r5, [r15 + -4]
	mad.lo r7, r5, r10, r1
	ld.global r5, [r15 + -4]
	mad.acc r1, r5, r4
	shl r3, 4
	sub r6, r1, r3
	sub r7, r3
	sub r8, r3
	sub r9, r3
	and r1, r14, 7
	add r3, r12, r1
	shl r1, 2
	shr r11, 3
	ld.global r5, [r15 + -4]
	mad.lo r5, r5, r3, r11
	st.global r5, [r15 + -160]
	shl r11, 5
	mov r12, r14
	shr r12, 3
	ld.global r5, [r15 + -4]
	mad.lo r3, r5, r3, r12
	st.global r3, [r15 + -148]
	shl r12, 5
	or r3, r12, r1
	st.global r3, [r15 + -152]
	or r1, r11, r1
	st.global r1, [r15 + -164]
	shl r10, 6
	shl r4, 6
	shl r2, 6
	st.global r14, [r15 + -12]
	and r1, r14, 15
	st.global r1, [r15 + -144]
	shl r1, 2
	or r12, r2, r1
	or r11, r4, r1
	or r10, r1
	movi r2, 0
	movi r14, 0
	ld.global r3, [r15 + -4]
	shl r3, 3
	ld.global r1, [r15 + -8]
	shl r1, 2
	or r4, r1, 708
	st.global r4, [r15 + -16]
	or r4, r1, 704
	st.global r4, [r15 + -20]
	mov r4, r13
	shl r4, 2
	add r5, r4, 224
	st.global r5, [r15 + -28]
	or r5, r1, 644
	st.global r5, [r15 + -32]
	or r5, r1, 640
	st.global r5, [r15 + -36]
	add r5, r4, 192
	st.global r5, [r15 + -40]
	or r5, r1, 580
	st.global r5, [r15 + -44]
	or r5, r1, 576
	st.global r5, [r15 + -48]
	add r5, r4, 160
	st.global r5, [r15 + -52]
	or r5, r1, 516
	st.global r5, [r15 + -56]
	or r5, r1, 512
	st.global r5, [r15 + -60]
	add r5, r4, 128
	st.global r5, [r15 + -64]
	or r5, r1, 452
	st.global r5, [r15 + -68]
	or r5, r1, 448
	st.global r5, [r15 + -72]
	add r5, r4, 96
	st.global r5, [r15 + -76]
	or r5, r1, 388
	st.global r5, [r15 + -80]
	or r5, r1, 384
	st.global r5, [r15 + -84]
	add r5, r4, 64
	st.global r5, [r15 + -88]
	or r5, r1, 324
	st.global r5, [r15 + -92]
	or r5, r1, 320
	st.global r5, [r15 + -96]
	st.global r4, [r15 + -24]
	add r4, r4, 32
	st.global r4, [r15 + -100]
	or r4, r1, 260
	st.global r4, [r15 + -104]
	or r1, r1, 256
	st.global r1, [r15 + -108]
	shl r0, 2
	or r0, 4
	add r1, r0, 224
	st.global r1, [r15 + -116]
	add r1, r0, 192
	st.global r1, [r15 + -120]
	add r1, r0, 160
	st.global r1, [r15 + -124]
	add r1, r0, 128
	st.global r1, [r15 + -128]
	add r1, r0, 96
	st.global r1, [r15 + -132]
	add r1, r0, 64
	st.global r1, [r15 + -136]
	st.global r0, [r15 + -112]
	add r0, r0, 32
	st.global r0, [r15 + -140]
	add r0, r11, 256
	st.global r0, [r15 + -156]
	add r0, r12, 256
	st.global r0, [r15 + -184]
	or r0, r11, 256
	add r0, r0, 256
	st.global r0, [r15 + -172]
	add r0, r10, 256
	st.global r0, [r15 + -168]
	movi r11, 0
	movi r12, 0
	movi r0, 0
	bra.short LBB0_3
LBB0_7:
	bar.arrive 0
	bar.wait 0
	ld.global r1, [r15 + -104]
	ld.shared r1, [r1 + 0]
	ld.global r4, [r15 + -108]
	ld.shared r10, [r4 + 0]
	ld.global r4, [r15 + -24]
	ld.shared r13, [r4 + 0]
	ffma.acc.f0 r0, r13, r10
	ffma.acc.f0 r12, r13, r1
	ld.global r4, [r15 + -112]
	ld.shared r13, [r4 + 0]
	ffma.f0 r10, r13, r10, r11
	ffma.f0 r1, r13, r1, r14
	ld.global r4, [r15 + -96]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -92]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -140]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r1, r14, r13
	ffma.acc.f0 r10, r14, r11
	ld.global r4, [r15 + -100]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r12, r14, r13
	ffma.acc.f0 r0, r14, r11
	ld.global r4, [r15 + -80]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -84]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -88]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r0, r14, r13
	ffma.acc.f0 r12, r14, r11
	ld.global r4, [r15 + -136]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r10, r14, r13
	ffma.acc.f0 r1, r14, r11
	ld.global r4, [r15 + -72]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -68]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -132]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r1, r14, r13
	ffma.acc.f0 r10, r14, r11
	ld.global r4, [r15 + -76]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r12, r14, r13
	ffma.acc.f0 r0, r14, r11
	ld.global r4, [r15 + -56]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -60]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -64]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r0, r14, r13
	ffma.acc.f0 r12, r14, r11
	ld.global r4, [r15 + -128]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r10, r14, r13
	ffma.acc.f0 r1, r14, r11
	ld.global r4, [r15 + -48]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -44]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -124]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r1, r14, r13
	ffma.acc.f0 r10, r14, r11
	ld.global r4, [r15 + -52]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r12, r14, r13
	ffma.acc.f0 r0, r14, r11
	ld.global r4, [r15 + -32]
	ld.shared r11, [r4 + 0]
	ld.global r4, [r15 + -36]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -40]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r0, r14, r13
	ffma.acc.f0 r12, r14, r11
	ld.global r4, [r15 + -120]
	ld.shared r14, [r4 + 0]
	ffma.acc.f0 r10, r14, r13
	ffma.acc.f0 r1, r14, r11
	ld.global r4, [r15 + -20]
	ld.shared r13, [r4 + 0]
	ld.global r4, [r15 + -16]
	ld.shared r4, [r4 + 0]
	ld.global r11, [r15 + -116]
	ld.shared r11, [r11 + 0]
	ffma.f0 r14, r11, r4, r1
	ffma.f0 r11, r11, r13, r10
	ld.global r1, [r15 + -28]
	ld.shared r1, [r1 + 0]
	ffma.acc.f0 r12, r1, r4
	ffma.acc.f0 r0, r1, r13
	add r6, r3
	add r7, r3
	add r8, r3
	add r9, r3
	@p3 add r2, r2, 8
	@!p3 shfl.idx r2, r2, 0
	ld.global r10, [r15 + -4]
	setp.lt p0, r2, r10
	bar.arrive 0
	bar.wait 0
	mov r13, r5
	ld.global r4, [r15 + -8]
	@!p0 bra LBB0_8
LBB0_3:
	ld.global r4, [r15 + -12]
	movi r1, 63
	setp.lt.u p0, r1, r4
	@p0 bra LBB0_5
	ld.global r1, [r15 + -148]
	add r1, r2
	ld.global r1, [#2, r1, 1, 0]
	ld.global r5, [r15 + -152]
	st.shared r1, [r5 + 0]
	setp.lt.u p0, r4, 32
	@!p0 bra LBB0_5
	ld.global r1, [r15 + -160]
	add r1, r2
	ld.global r1, [#2, r1, 1, 0]
	ld.global r5, [r15 + -164]
	st.shared r1, [r5 + 0]
LBB0_5:
	mov r5, r13
	movi r1, 127
	setp.lt.u p0, r1, r4
	@p0 bra LBB0_7
	ld.global r1, [r15 + -144]
	add r1, r6
	ld.global r1, [#4, r1, 1, 0]
	ld.global r10, [r15 + -156]
	st.shared r1, [r10 + 0]
	setp.lt.u p0, r4, 96
	@!p0 bra LBB0_7
	ld.global r1, [r15 + -144]
	add r1, r7
	ld.global r1, [#4, r1, 1, 0]
	ld.global r10, [r15 + -168]
	st.shared r1, [r10 + 0]
	movi r1, 63
	setp.lt.u p0, r1, r4
	@p0 bra LBB0_7
	ld.global r1, [r15 + -144]
	add r1, r8
	ld.global r1, [#4, r1, 1, 0]
	ld.global r10, [r15 + -172]
	st.shared r1, [r10 + 0]
	movi r1, 31
	setp.lt.u p0, r1, r4
	@p0 bra LBB0_7
	ld.global r1, [r15 + -144]
	add r1, r9
	ld.global r1, [#4, r1, 1, 0]
	ld.global r4, [r15 + -184]
	st.shared r1, [r4 + 0]
	bra.short LBB0_7
LBB0_1:
	movi r14, 0
	movi r11, 0
	movi r12, 0
	movi r0, 0
LBB0_8:
	ld.global r1, [r15 + -180]
	or r1, r4, r1
	ld.global r2, [r15 + -176]
	add r2, r13
	mad.lo r3, r2, r10, r1
	st.global r0, [#0, r3, 1, 0]
	or r0, r3, 1
	st.global r12, [#0, r0, 1, 0]
	or r0, r2, 1
	mad.lo r0, r0, r10, r1
	st.global r11, [#0, r0, 1, 0]
	add r0, 1
	st.global r14, [#0, r0, 1, 0]
	exit
Lfunc_end0:
	.size	_Z5sgemmPfPKfS1_ii, Lfunc_end0-_Z5sgemmPfPKfS1_ii

