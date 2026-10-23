	.text
	.file	"gemv8.cu"
	.globl	_Z5gemv8PiPKiS1_i
	.type	_Z5gemv8PiPKiS1_i,@function
_Z5gemv8PiPKiS1_i:
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
	mov r6, r2
	shl r6, 2
	movi r11, 104
	movi r12, 108
	movi r13, 112
	movi r14, 116
	movi r15, 120
	movi r1, 124
	movi r5, 0
	movi r8, 0
	bra.short LBB0_4
LBB0_6:
	add r7, r4, r5
	shl r7, 2
	bar.arrive 0
	bar.wait 0
	ld.global r9, [r0 + 44]
	add r7, r9
	movi r9, 0
	ld.shared r9, [r9 + 0]
	ld.global r10, [#1, r7, 0, 0]
	dp4.acc r8, r9, r10
	add r9, r7, 4
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 4
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 8
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 8
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 12
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 12
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 16
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 16
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 20
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 20
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 24
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 24
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 28
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 28
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 32
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 32
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 36
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 36
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 40
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 40
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 44
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 44
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 48
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 48
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 52
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 52
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 56
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 56
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 60
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 60
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 64
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 64
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 68
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 68
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 72
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 72
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 76
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 76
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 80
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 80
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 84
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 84
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 88
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 88
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 92
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 92
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 96
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 96
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 100
	ld.global r9, [#1, r9, 0, 0]
	movi r10, 100
	ld.shared r10, [r10 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 104
	ld.global r9, [#1, r9, 0, 0]
	ld.shared r10, [r11 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 108
	ld.global r9, [#1, r9, 0, 0]
	ld.shared r10, [r12 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 112
	ld.global r9, [#1, r9, 0, 0]
	ld.shared r10, [r13 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 116
	ld.global r9, [#1, r9, 0, 0]
	ld.shared r10, [r14 + 0]
	dp4.acc r8, r10, r9
	add r9, r7, 120
	ld.global r9, [#1, r9, 0, 0]
	ld.shared r10, [r15 + 0]
	dp4.acc r8, r10, r9
	add r7, r7, 124
	ld.global r7, [#1, r7, 0, 0]
	ld.shared r9, [r1 + 0]
	dp4.acc r8, r9, r7
	add r5, r5, 32
	setp.lt p0, r5, r3
	bar.arrive 0
	bar.wait 0
	@!p0 bra LBB0_2
LBB0_4:
	movi r7, 31
	setp.lt.u p0, r7, r2
	@p0 bra LBB0_6
	add r7, r2, r5
	shl r7, 2
	ld.global r9, [r0 + 52]
	add r7, r9, r7
	ld.global r7, [#2, r7, 0, 0]
	st.shared r7, [r6 + 0]
	bra.short LBB0_6
LBB0_1:
	movi r8, 0
LBB0_2:
	ld.local r1, [12]
	shl r1, 2
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r8, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z5gemv8PiPKiS1_i, Lfunc_end0-_Z5gemv8PiPKiS1_i

