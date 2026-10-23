	.text
	.file	"scatter.cu"
	.globl	_Z9scatter_fPKjPKfPfi
	.type	_Z9scatter_fPKjPKfPfi,@function
_Z9scatter_fPKjPKfPfi:
	movi r1, 2
	ld.global r2, [r1 + 56]
	srd r0, 0
	setp.le p0, r2, r0
	@p0 bra LBB0_17
	mov r3, r0
	shl r3, 5
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	shl r0, 3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
	pmov p0, -1
LBB0_2:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_2
	shl r0, 2
	or r3, r0, 4
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_4:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_4
	or r3, r0, 8
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_6:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_6
	or r3, r0, 12
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_8:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_8
	or r3, r0, 16
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_10:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_10
	or r3, r0, 20
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_12:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_12
	or r3, r0, 24
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r3
	ld.global r2, [#0, r2, 0, 0]
	shl r2, 2
	ld.global r4, [r1 + 52]
	add r4, r2
	ld.global r5, [r1 + 44]
	add r3, r5, r3
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
LBB0_14:
	ld.global r5, [r1 + 52]
	add r5, r2
	mov r6, r4
	fadd r6, r3
	ld.global r7, [r1 + 48]
	@p0 cas.global r4, [r7, r5, 0, 0], r4, r6, p1
	@!p1 bra LBB0_14
	or r2, r0, 28
	movi r0, 2
	ld.global r1, [r0 + 36]
	add r1, r2
	ld.global r1, [#0, r1, 0, 0]
	shl r1, 2
	ld.global r3, [r0 + 52]
	add r3, r1
	ld.global r4, [r0 + 44]
	add r2, r4, r2
	ld.global r2, [#1, r2, 0, 0]
	ld.global r3, [#2, r3, 0, 0]
LBB0_16:
	ld.global r4, [r0 + 52]
	add r4, r1
	mov r5, r3
	fadd r5, r2
	ld.global r6, [r0 + 48]
	@p0 cas.global r3, [r6, r4, 0, 0], r3, r5, p1
	@!p1 bra LBB0_16
LBB0_17:
	exit
Lfunc_end0:
	.size	_Z9scatter_fPKjPKfPfi, Lfunc_end0-_Z9scatter_fPKjPKfPfi

	.globl	_Z9scatter_iPKjS0_Pji
	.type	_Z9scatter_iPKjS0_Pji,@function
_Z9scatter_iPKjS0_Pji:
	movi r3, 2
	ld.global r1, [r3 + 56]
	srd r0, 0
	setp.le p0, r1, r0
	@p0 bra LBB1_2
	shl r0, 5
	ld.global r1, [r3 + 36]
	add r2, r1, r0
	ld.global r4, [#0, r2, 0, 0]
	shl r4, 2
	ld.global r2, [r3 + 52]
	add r5, r2, r4
	ld.global r4, [r3 + 44]
	add r6, r4, r0
	ld.global r6, [#1, r6, 0, 0]
	ld.global r3, [r3 + 48]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 4
	add r6, r1, r5
	ld.global r6, [#0, r6, 0, 0]
	shl r6, 2
	add r6, r2, r6
	add r5, r4, r5
	ld.global r5, [#1, r5, 0, 0]
	atom.add.global r5, [r3, r6, 0, 0], r5
	or r5, r0, 8
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 12
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 16
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 20
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 24
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.global r5, [r3, r5, 0, 0], r6
	or r0, r0, 28
	add r4, r0
	add r0, r1, r0
	ld.global r0, [#0, r0, 0, 0]
	shl r0, 2
	add r0, r2, r0
	ld.global r1, [#1, r4, 0, 0]
	atom.add.global r0, [r3, r0, 0, 0], r1
LBB1_2:
	exit
Lfunc_end1:
	.size	_Z9scatter_iPKjS0_Pji, Lfunc_end1-_Z9scatter_iPKjS0_Pji

