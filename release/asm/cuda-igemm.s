	.text
	.file	"igemm.cu"
	.globl	_Z5igemmPiPKiS1_ii
	.type	_Z5igemmPiPKiS1_ii,@function
_Z5igemmPiPKiS1_ii:
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
	pand p0, 0, 3
	@p0 mov r12, r4
	@p3 sub r4, r3, r0
	@p0 mov r3, r4
	@!p3 shfl.idx r3, r3, 0
	setp.le.u p0, r0, r3
	@p3 add r3, r12, 1
	pand p0, 0, 3
	@p0 mov r12, r3
	@!p3 shfl.idx r12, r12, 0
	mul.lo r3, r12, r0
	@p3 sub r6, r1, r3
	@!p3 shfl.idx r6, r6, 0
	srd r5, 0
	mov r0, r5
	shr r0, 2
	f48 r4, 1073741822
	and r13, r0, r4
	mov r4, r5
	shl r4, 1
	and r4, 14
	shl r12, 3
	shl r6, 4
	st.local r6, [180]
	@p3 ld.global r11, [r2 + 56]
	@!p3 shfl.idx r11, r11, 0
	setp.lt p0, r11, 1
	st.local r12, [176]
	st.local r13, [184]
	@p0 bra LBB0_1
	add r2, r5, 96
	shr r2, 4
	shl r1, 4
	st.local r4, [192]
	mov r4, r5
	shr r4, 4
	add r6, r4, 4
	mad.lo r8, r11, r6, r1
	st.local r11, [12]
	add r11, r5, 32
	ld.local r6, [12]
	mad.lo r9, r6, r2, r1
	mov r10, r11
	shr r10, 4
	ld.local r6, [12]
	mad.lo r7, r6, r10, r1
	ld.local r6, [12]
	mad.acc r1, r6, r4
	shl r3, 4
	sub r6, r1, r3
	sub r7, r3
	sub r8, r3
	sub r9, r3
	and r1, r5, 7
	add r3, r12, r1
	shl r1, 2
	shr r11, 3
	ld.local r12, [12]
	mad.lo r12, r12, r3, r11
	st.local r12, [160]
	shl r11, 5
	mov r12, r5
	shr r12, 3
	ld.local r14, [12]
	mad.lo r3, r14, r3, r12
	st.local r3, [148]
	shl r12, 5
	or r3, r12, r1
	st.local r3, [152]
	or r1, r11, r1
	st.local r1, [164]
	shl r4, 6
	shl r2, 6
	shl r10, 6
	and r1, r5, 15
	st.local r1, [144]
	shl r1, 2
	or r3, r10, r1
	or r10, r2, r1
	or r4, r1
	movi r14, 0
	ld.local r15, [12]
	shl r15, 3
	ld.local r11, [192]
	mov r2, r11
	shl r2, 2
	or r1, r2, 708
	st.local r1, [16]
	or r1, r2, 704
	st.local r1, [20]
	shl r13, 2
	add r1, r13, 224
	st.local r1, [28]
	or r1, r2, 644
	st.local r1, [32]
	or r1, r2, 640
	st.local r1, [36]
	add r1, r13, 192
	st.local r1, [40]
	or r1, r2, 580
	st.local r1, [44]
	or r1, r2, 576
	st.local r1, [48]
	add r1, r13, 160
	st.local r1, [52]
	or r1, r2, 516
	st.local r1, [56]
	or r1, r2, 512
	st.local r1, [60]
	add r1, r13, 128
	st.local r1, [64]
	or r1, r2, 452
	st.local r1, [68]
	or r1, r2, 448
	st.local r1, [72]
	add r1, r13, 96
	st.local r1, [76]
	or r1, r2, 388
	st.local r1, [80]
	or r1, r2, 384
	st.local r1, [84]
	add r1, r13, 64
	st.local r1, [88]
	or r1, r2, 324
	st.local r1, [92]
	or r1, r2, 320
	st.local r1, [96]
	st.local r13, [24]
	add r1, r13, 32
	st.local r1, [100]
	or r1, r2, 260
	st.local r1, [104]
	or r1, r2, 256
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
	add r0, r4, 256
	st.local r0, [156]
	add r0, r10, 256
	st.local r0, [188]
	or r4, r4, 256
	add r0, r4, 256
	st.local r0, [172]
	add r0, r3, 256
	st.local r0, [168]
	movi r10, 0
	movi r3, 0
	movi r13, 0
	movi r4, 0
	mov r2, r11
	bra.short LBB0_3
LBB0_7:
	bar.arrive 0
	bar.wait 0
	ld.local r0, [104]
	ld.shared r11, [r0 + 0]
	ld.local r0, [24]
	ld.shared r12, [r0 + 0]
	ld.local r0, [108]
	ld.shared r0, [r0 + 0]
	dp4.acc r13, r0, r12
	dp4.acc r3, r11, r12
	ld.local r1, [112]
	ld.shared r12, [r1 + 0]
	dp4.ss r0, r0, r12, r10
	dp4.ss r10, r11, r12, r14
	ld.local r1, [96]
	ld.shared r11, [r1 + 0]
	ld.local r1, [140]
	ld.shared r12, [r1 + 0]
	ld.local r1, [92]
	ld.shared r14, [r1 + 0]
	dp4.acc r10, r14, r12
	dp4.acc r0, r11, r12
	ld.local r1, [100]
	ld.shared r12, [r1 + 0]
	dp4.acc r3, r14, r12
	dp4.ss r11, r11, r12, r13
	ld.local r1, [80]
	ld.shared r12, [r1 + 0]
	ld.local r1, [88]
	ld.shared r13, [r1 + 0]
	ld.local r1, [84]
	ld.shared r14, [r1 + 0]
	dp4.acc r11, r14, r13
	dp4.acc r3, r12, r13
	ld.local r1, [136]
	ld.shared r13, [r1 + 0]
	dp4.acc r0, r14, r13
	dp4.acc r10, r12, r13
	ld.local r1, [72]
	ld.shared r12, [r1 + 0]
	ld.local r1, [132]
	ld.shared r13, [r1 + 0]
	ld.local r1, [68]
	ld.shared r14, [r1 + 0]
	dp4.acc r10, r14, r13
	dp4.acc r0, r12, r13
	ld.local r1, [76]
	ld.shared r13, [r1 + 0]
	dp4.acc r3, r14, r13
	dp4.acc r11, r12, r13
	ld.local r1, [56]
	ld.shared r12, [r1 + 0]
	ld.local r1, [64]
	ld.shared r13, [r1 + 0]
	ld.local r1, [60]
	ld.shared r14, [r1 + 0]
	dp4.acc r11, r14, r13
	dp4.acc r3, r12, r13
	ld.local r1, [128]
	ld.shared r13, [r1 + 0]
	dp4.acc r0, r14, r13
	dp4.acc r10, r12, r13
	ld.local r1, [48]
	ld.shared r12, [r1 + 0]
	ld.local r1, [124]
	ld.shared r13, [r1 + 0]
	ld.local r1, [44]
	ld.shared r14, [r1 + 0]
	dp4.acc r10, r14, r13
	dp4.acc r0, r12, r13
	ld.local r1, [52]
	ld.shared r13, [r1 + 0]
	dp4.acc r3, r14, r13
	dp4.acc r11, r12, r13
	ld.local r1, [32]
	ld.shared r12, [r1 + 0]
	ld.local r1, [40]
	ld.shared r13, [r1 + 0]
	ld.local r1, [36]
	ld.shared r14, [r1 + 0]
	dp4.acc r11, r14, r13
	dp4.acc r3, r12, r13
	ld.local r1, [120]
	ld.shared r13, [r1 + 0]
	dp4.acc r0, r14, r13
	dp4.acc r10, r12, r13
	ld.local r1, [20]
	ld.shared r12, [r1 + 0]
	ld.local r1, [116]
	ld.shared r13, [r1 + 0]
	ld.local r1, [16]
	ld.shared r1, [r1 + 0]
	dp4.ss r14, r1, r13, r10
	dp4.ss r10, r12, r13, r0
	ld.local r0, [28]
	ld.shared r0, [r0 + 0]
	dp4.acc r3, r1, r0
	dp4.ss r13, r12, r0, r11
	add r6, r15
	add r7, r15
	add r8, r15
	add r9, r15
	@p3 add r4, r4, 8
	@!p3 shfl.idx r4, r4, 0
	ld.local r11, [12]
	setp.lt p0, r4, r11
	bar.arrive 0
	bar.wait 0
	@!p0 bra LBB0_8
LBB0_3:
	movi r0, 63
	setp.lt.u p0, r0, r5
	@p0 bra LBB0_5
	ld.local r0, [148]
	add r11, r0, r4
	ld.global r11, [#1, r11, 1, 0]
	ld.local r0, [152]
	st.shared r11, [r0 + 0]
	setp.lt.u p0, r5, 32
	@!p0 bra LBB0_5
	ld.local r0, [160]
	add r11, r0, r4
	ld.global r11, [#1, r11, 1, 0]
	ld.local r0, [164]
	st.shared r11, [r0 + 0]
LBB0_5:
	movi r0, 127
	setp.lt.u p0, r0, r5
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r11, r0, r6
	ld.global r11, [#2, r11, 1, 0]
	ld.local r0, [156]
	st.shared r11, [r0 + 0]
	setp.lt.u p0, r5, 96
	@!p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r7
	ld.global r0, [#2, r0, 1, 0]
	ld.local r1, [168]
	st.shared r0, [r1 + 0]
	movi r0, 63
	setp.lt.u p0, r0, r5
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r8
	ld.global r0, [#2, r0, 1, 0]
	ld.local r1, [172]
	st.shared r0, [r1 + 0]
	movi r0, 31
	setp.lt.u p0, r0, r5
	@p0 bra LBB0_7
	ld.local r0, [144]
	add r0, r9
	ld.global r0, [#2, r0, 1, 0]
	ld.local r1, [188]
	st.shared r0, [r1 + 0]
	bra.short LBB0_7
LBB0_1:
	movi r14, 0
	movi r10, 0
	movi r3, 0
	movi r13, 0
	mov r2, r4
LBB0_8:
	ld.local r0, [180]
	or r0, r2, r0
	ld.local r1, [176]
	ld.local r2, [184]
	add r1, r2
	mad.lo r2, r1, r11, r0
	st.global r13, [#0, r2, 1, 0]
	or r2, 1
	st.global r3, [#0, r2, 1, 0]
	or r1, 1
	mad.acc r0, r1, r11
	st.global r10, [#0, r0, 1, 0]
	add r0, 1
	st.global r14, [#0, r0, 1, 0]
	exit
Lfunc_end0:
	.size	_Z5igemmPiPKiS1_ii, Lfunc_end0-_Z5igemmPiPKiS1_ii

