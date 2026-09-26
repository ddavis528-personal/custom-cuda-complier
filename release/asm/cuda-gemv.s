	.text
	.file	"gemv.cu"
	.globl	_Z4gemvPfPKfS1_i
	.type	_Z4gemvPfPKfS1_i,@function
_Z4gemvPfPKfS1_i:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 0
	add r15, r14
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r4, r3, r1, r2
	ld.global r3, [r0 + 56]
	setp.lt p0, r3, 1
	st.global r4, [r15 + -4]
	@p0 bra LBB0_1
	mul.lo r4, r3
	movi r6, 0
	mov r7, r2
	shl r7, 2
	movi r8, 108
	movi r9, 112
	movi r10, 116
	movi r11, 120
	movi r12, 124
	movi r14, 0
	bra.short LBB0_4
LBB0_6:
	add r1, r4, r6
	shl r1, 2
	bar.arrive 0
	bar.wait 0
	ld.global r13, [r0 + 44]
	add r13, r1, r13
	movi r1, 0
	ld.shared r1, [r1 + 0]
	ld.global r5, [#2, r13, 0, 0]
	ffma.f0 r1, r5, r1, r14
	add r5, r13, 4
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 4
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 8
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 8
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 12
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 12
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 16
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 16
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 20
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 20
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 24
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 24
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 28
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 28
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 32
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 32
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 36
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 36
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 40
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 40
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 44
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 44
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 48
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 48
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 52
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 52
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 56
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 56
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 60
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 60
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 64
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 64
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 68
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 68
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 72
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 72
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 76
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 76
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 80
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 80
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 84
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 84
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 88
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 88
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 92
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 92
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 96
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 96
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 100
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 100
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 104
	ld.global r5, [#2, r5, 0, 0]
	movi r14, 104
	ld.shared r14, [r14 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 108
	ld.global r5, [#2, r5, 0, 0]
	ld.shared r14, [r8 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 112
	ld.global r5, [#2, r5, 0, 0]
	ld.shared r14, [r9 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 116
	ld.global r5, [#2, r5, 0, 0]
	ld.shared r14, [r10 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 120
	ld.global r5, [#2, r5, 0, 0]
	ld.shared r14, [r11 + 0]
	ffma.acc.f0 r1, r5, r14
	add r5, r13, 124
	ld.global r5, [#2, r5, 0, 0]
	ld.shared r13, [r12 + 0]
	ffma.f0 r14, r5, r13, r1
	add r6, r6, 32
	setp.lt p0, r6, r3
	bar.arrive 0
	bar.wait 0
	@!p0 bra LBB0_2
LBB0_4:
	movi r1, 31
	setp.lt.u p0, r1, r2
	@p0 bra LBB0_6
	add r13, r2, r6
	shl r13, 2
	ld.global r1, [r0 + 52]
	add r1, r13
	ld.global r1, [#4, r1, 0, 0]
	st.shared r1, [r7 + 0]
	bra.short LBB0_6
LBB0_1:
	movi r14, 0
LBB0_2:
	ld.global r1, [r15 + -4]
	shl r1, 2
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r14, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z4gemvPfPKfS1_i, Lfunc_end0-_Z4gemvPfPKfS1_i

