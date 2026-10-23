	.text
	.file	"sgemm.cu"
	.globl	_Z5sgemmPfPKfS1_ii
	.type	_Z5sgemmPfPKfS1_ii,@function
_Z5sgemmPfPKfS1_ii:
	pmov p3, 1
	movi r4, 2
	@p3 ld.global r0, [r4 + 60]
	@!p3 shfl.idx r0, r0, 0
	rcp.u32 r1, r0
	mul.lo r2, r1, r0
	neg r2, r2
	@p3 mul.hi.u r2, r1, r2
	@p3 add r2, r1, r2
	srd r1, 1
	@p3 mul.hi.u r12, r1, r2
	@!p3 shfl.idx r12, r12, 0
	mul.lo r2, r12, r0
	@p3 sub r2, r1, r2
	@!p3 shfl.idx r2, r2, 0
	setp.le.u p0, r0, r2
	@p3 add r3, r12, 1
	pand p0, 0, 3
	@p0 mov r12, r3
	@p3 sub r3, r2, r0
	@p0 mov r2, r3
	@!p3 shfl.idx r2, r2, 0
	setp.le.u p0, r0, r2
	@p3 add r2, r12, 1
	pand p0, 0, 3
	@p0 mov r12, r2
	@!p3 shfl.idx r12, r12, 0
	mul.lo r3, r12, r0
	@p3 sub r5, r1, r3
	@!p3 shfl.idx r5, r5, 0
	srd r6, 0
	mov r0, r6
	shr r0, 2
	f48 r2, 1073741822
	and r14, r0, r2
	mov r2, r6
	shl r2, 1
	and r15, r2, 14
	shl r12, 3
	shl r5, 4
	st.local r5, [180]
	@p3 ld.global r13, [r4 + 56]
	@!p3 shfl.idx r13, r13, 0
	setp.lt p0, r13, 1
	st.local r12, [176]
	st.local r15, [184]
	@p0 bra LBB0_1
	add r2, r6, 96
	shr r2, 4
	shl r1, 4
	mov r4, r6
	shr r4, 4
	add r5, r4, 4
	mad.lo r9, r13, r5, r1
	add r11, r6, 32
	mad.lo r10, r13, r2, r1
	mov r5, r11
	shr r5, 4
	mad.lo r8, r13, r5, r1
	mad.acc r1, r13, r4
	shl r3, 4
	sub r7, r1, r3
	sub r8, r3
	sub r9, r3
	sub r10, r3
	and r1, r6, 7
	add r3, r12, r1
	shl r1, 2
	shr r11, 3
	mad.lo r12, r13, r3, r11
	st.local r12, [160]
	shl r11, 5
	mov r12, r6
	shr r12, 3
	mad.lo r3, r13, r3, r12
	st.local r3, [148]
	shl r12, 5
	or r3, r12, r1
	st.local r3, [152]
	or r1, r11, r1
	st.local r1, [164]
	shl r5, 6
	shl r4, 6
	shl r2, 6
	and r1, r6, 15
	st.local r1, [144]
	shl r1, 2
	or r11, r2, r1
	or r2, r4, r1
	or r1, r5, r1
	st.local r1, [168]
	movi r4, 0
	movi r12, 0
	mov r3, r13
	shl r3, 3
	mov r1, r15
	shl r1, 2
	or r15, r1, 708
	st.local r15, [16]
	or r15, r1, 704
	st.local r15, [20]
	mov r15, r14
	shl r15, 2
	add r5, r15, 224
	st.local r5, [28]
	or r5, r1, 644
	st.local r5, [32]
	or r5, r1, 640
	st.local r5, [36]
	add r5, r15, 192
	st.local r5, [40]
	or r5, r1, 580
	st.local r5, [44]
	or r5, r1, 576
	st.local r5, [48]
	add r5, r15, 160
	st.local r5, [52]
	or r5, r1, 516
	st.local r5, [56]
	or r5, r1, 512
	st.local r5, [60]
	add r5, r15, 128
	st.local r5, [64]
	or r5, r1, 452
	st.local r5, [68]
	or r5, r1, 448
	st.local r5, [72]
	add r5, r15, 96
	st.local r5, [76]
	or r5, r1, 388
	st.local r5, [80]
	or r5, r1, 384
	st.local r5, [84]
	add r5, r15, 64
	st.local r5, [88]
	or r5, r1, 324
	st.local r5, [92]
	or r5, r1, 320
	st.local r5, [96]
	st.local r15, [24]
	add r5, r15, 32
	st.local r5, [100]
	or r5, r1, 260
	st.local r5, [104]
	or r1, r1, 256
	st.local r1, [108]
	shl r0, 2
	or r0, 4
	add r1, r0, 224
	st.local r1, [116]
	add r1, r0, 192
	st.local r1, [120]
	add r1, r0, 160
	st.local r1, [124]
	add r1, r0, 128
	st.local r1, [128]
	add r1, r0, 96
	st.local r1, [132]
	add r1, r0, 64
	st.local r1, [136]
	st.local r0, [112]
	add r0, r0, 32
	st.local r0, [140]
	add r0, r2, 256
	st.local r0, [156]
	add r0, r11, 256
	st.local r0, [188]
	or r11, r2, 256
	add r0, r11, 256
	st.local r0, [172]
	ld.local r0, [168]
	add r0, r0, 256
	st.local r0, [168]
	movi r15, 0
	movi r2, 0
	movi r11, 0
	st.local r13, [12]
	bra.short LBB0_3
LBB0_7:
	bar.arrive 0
	bar.wait 0
	ld.local r0, [104]
	ld.shared r5, [r0 + 0]
	ld.local r0, [108]
	ld.shared r13, [r0 + 0]
	ld.local r0, [24]
	ld.shared r0, [r0 + 0]
	ffma.acc.f0 r11, r0, r13
	ffma.f0 r0, r0, r5, r2
	ld.local r2, [112]
	ld.shared r2, [r2 + 0]
	ffma.f0 r13, r2, r13, r15
	ffma.f0 r2, r2, r5, r12
	ld.local r5, [96]
	ld.shared r5, [r5 + 0]
	ld.local r12, [92]
	ld.shared r12, [r12 + 0]
	ld.local r14, [140]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r2, r15, r12
	ffma.acc.f0 r13, r15, r5
	ld.local r14, [100]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r0, r15, r12
	ffma.f0 r5, r15, r5, r11
	ld.local r11, [80]
	ld.shared r11, [r11 + 0]
	ld.local r12, [84]
	ld.shared r12, [r12 + 0]
	ld.local r14, [88]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r5, r15, r12
	ffma.acc.f0 r0, r15, r11
	ld.local r14, [136]
	ld.shared r15, [r14 + 0]
	ffma.f0 r12, r15, r12, r13
	ffma.acc.f0 r2, r15, r11
	ld.local r11, [72]
	ld.shared r11, [r11 + 0]
	ld.local r13, [68]
	ld.shared r13, [r13 + 0]
	ld.local r14, [132]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r2, r15, r13
	ffma.acc.f0 r12, r15, r11
	ld.local r14, [76]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r0, r15, r13
	ffma.acc.f0 r5, r15, r11
	ld.local r11, [56]
	ld.shared r11, [r11 + 0]
	ld.local r13, [60]
	ld.shared r13, [r13 + 0]
	ld.local r14, [64]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r5, r15, r13
	ffma.acc.f0 r0, r15, r11
	ld.local r14, [128]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r12, r15, r13
	ffma.acc.f0 r2, r15, r11
	ld.local r11, [48]
	ld.shared r11, [r11 + 0]
	ld.local r13, [44]
	ld.shared r13, [r13 + 0]
	ld.local r14, [124]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r2, r15, r13
	ffma.acc.f0 r12, r15, r11
	ld.local r14, [52]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r0, r15, r13
	ffma.acc.f0 r5, r15, r11
	ld.local r11, [32]
	ld.shared r11, [r11 + 0]
	ld.local r13, [36]
	ld.shared r13, [r13 + 0]
	ld.local r14, [40]
	ld.shared r15, [r14 + 0]
	ffma.acc.f0 r5, r15, r13
	ffma.acc.f0 r0, r15, r11
	ld.local r14, [120]
	ld.shared r15, [r14 + 0]
	ffma.f0 r13, r15, r13, r12
	ffma.acc.f0 r2, r15, r11
	ld.local r11, [20]
	ld.shared r11, [r11 + 0]
	ld.local r12, [16]
	ld.shared r14, [r12 + 0]
	ld.local r12, [116]
	ld.shared r15, [r12 + 0]
	ffma.f0 r12, r15, r14, r2
	ffma.f0 r15, r15, r11, r13
	ld.local r2, [28]
	ld.shared r13, [r2 + 0]
	ffma.f0 r2, r13, r14, r0
	ffma.f0 r11, r13, r11, r5
	add r7, r3
	add r8, r3
	add r9, r3
	add r10, r3
	@p3 add r4, r4, 8
	@!p3 shfl.idx r4, r4, 0
	ld.local r13, [12]
	setp.lt p0, r4, r13
	bar.arrive 0
	bar.wait 0
	mov r14, r1
	@!p0 bra LBB0_8
LBB0_3:
	movi r0, 63
	setp.lt.u p0, r0, r6
	@p0 bra LBB0_5
	ld.local r0, [148]
	add r5, r0, r4
	shl r5, 2
	movi r0, 2
	ld.global r13, [r0 + 44]
	add r5, r13, r5
	ld.global r5, [#1, r5, 0, 0]
	ld.local r0, [152]
	st.shared r5, [r0 + 0]
	setp.lt.u p0, r6, 32
	@!p0 bra LBB0_5
	ld.local r0, [160]
	add r5, r0, r4
	shl r5, 2
	movi r0, 2
	ld.global r13, [r0 + 44]
	add r5, r13, r5
	ld.global r5, [#1, r5, 0, 0]
	ld.local r0, [164]
	st.shared r5, [r0 + 0]
LBB0_5:
	mov r1, r14
	movi r0, 127
	setp.lt.u p0, r0, r6
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r5, r0, r7
	shl r5, 2
	movi r0, 2
	ld.global r13, [r0 + 52]
	add r5, r13, r5
	ld.global r5, [#2, r5, 0, 0]
	ld.local r0, [156]
	st.shared r5, [r0 + 0]
	setp.lt.u p0, r6, 96
	@!p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r8
	shl r0, 2
	movi r5, 2
	ld.global r5, [r5 + 52]
	add r0, r5, r0
	ld.global r0, [#2, r0, 0, 0]
	ld.local r5, [168]
	st.shared r0, [r5 + 0]
	movi r0, 63
	setp.lt.u p0, r0, r6
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r9
	shl r0, 2
	movi r5, 2
	ld.global r5, [r5 + 52]
	add r0, r5, r0
	ld.global r0, [#2, r0, 0, 0]
	ld.local r5, [172]
	st.shared r0, [r5 + 0]
	movi r0, 31
	setp.lt.u p0, r0, r6
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r10
	shl r0, 2
	movi r5, 2
	ld.global r5, [r5 + 52]
	add r0, r5, r0
	ld.global r0, [#2, r0, 0, 0]
	ld.local r5, [188]
	st.shared r0, [r5 + 0]
	bra.short LBB0_7
LBB0_1:
	movi r12, 0
	movi r15, 0
	movi r2, 0
	movi r11, 0
LBB0_8:
	ld.local r0, [180]
	ld.local r1, [184]
	or r0, r1, r0
	ld.local r1, [176]
	add r1, r14
	mad.lo r3, r1, r13, r0
	shl r3, 2
	movi r4, 2
	@p3 ld.global r4, [r4 + 36]
	@!p3 shfl.idx r4, r4, 0
	add r3, r4, r3
	st.global r11, [#0, r3, 0, 0]
	add r3, 4
	st.global r2, [#0, r3, 0, 0]
	or r1, 1
	mad.acc r0, r1, r13
	shl r0, 2
	add r0, r4, r0
	st.global r15, [#0, r0, 0, 0]
	add r0, 4
	st.global r12, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z5sgemmPfPKfS1_ii, Lfunc_end0-_Z5sgemmPfPKfS1_ii

