	.text
	.file	"gemv.cu"
	.globl	_Z4gemvPfPKfS1_i
	.type	_Z4gemvPfPKfS1_i,@function
_Z4gemvPfPKfS1_i:
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r4, r3, r1, r2
	ld.global r3, [r0 + 56]
	setp.lt p0, r3, 1
	st.local r4, [12]
	@p0 bra LBB0_1
	mul.lo r4, r3
	movi r6, 0
	mov r7, r2
	shl r7, 2
	movi r14, 104
	movi r15, 108
	movi r1, 112
	movi r5, 116
	movi r8, 120
	movi r9, 124
	movi r11, 0
	bra.short LBB0_4
LBB0_6:
	add r10, r4, r6
	shl r10, 2
	bar.arrive 0
	bar.wait 0
	ld.global r12, [r0 + 44]
	add r10, r12
	movi r12, 0
	ld.shared r12, [r12 + 0]
	ld.global r13, [#1, r10, 0, 0]
	ffma.acc.f0 r11, r13, r12
	add r12, r10, 4
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 4
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 8
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 8
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 12
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 12
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 16
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 16
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 20
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 20
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 24
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 24
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 28
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 28
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 32
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 32
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 36
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 36
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 40
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 40
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 44
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 44
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 48
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 48
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 52
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 52
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 56
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 56
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 60
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 60
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 64
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 64
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 68
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 68
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 72
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 72
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 76
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 76
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 80
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 80
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 84
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 84
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 88
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 88
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 92
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 92
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 96
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 96
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 100
	ld.global r12, [#1, r12, 0, 0]
	movi r13, 100
	ld.shared r13, [r13 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 104
	ld.global r12, [#1, r12, 0, 0]
	ld.shared r13, [r14 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 108
	ld.global r12, [#1, r12, 0, 0]
	ld.shared r13, [r15 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 112
	ld.global r12, [#1, r12, 0, 0]
	ld.shared r13, [r1 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 116
	ld.global r12, [#1, r12, 0, 0]
	ld.shared r13, [r5 + 0]
	ffma.acc.f0 r11, r12, r13
	add r12, r10, 120
	ld.global r12, [#1, r12, 0, 0]
	ld.shared r13, [r8 + 0]
	ffma.acc.f0 r11, r12, r13
	add r10, r10, 124
	ld.global r10, [#1, r10, 0, 0]
	ld.shared r12, [r9 + 0]
	ffma.acc.f0 r11, r10, r12
	add r6, r6, 32
	setp.lt p0, r6, r3
	bar.arrive 0
	bar.wait 0
	@!p0 bra LBB0_2
LBB0_4:
	movi r10, 31
	setp.lt.u p0, r10, r2
	@p0 bra LBB0_6
	add r10, r2, r6
	shl r10, 2
	ld.global r12, [r0 + 52]
	add r10, r12, r10
	ld.global r10, [#2, r10, 0, 0]
	st.shared r10, [r7 + 0]
	bra.short LBB0_6
LBB0_1:
	movi r11, 0
LBB0_2:
	ld.local r1, [12]
	shl r1, 2
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r11, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z4gemvPfPKfS1_i, Lfunc_end0-_Z4gemvPfPKfS1_i

