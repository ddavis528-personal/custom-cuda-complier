	.text
	.file	"scatter.cu"
	.globl	_Z9scatter_fPKjPKfPfi
	.type	_Z9scatter_fPKjPKfPfi,@function
_Z9scatter_fPKjPKfPfi:
	movi r3, 2
	ld.global r1, [r3 + 56]
	srd r0, 0
	setp.le p0, r1, r0
	@p0 bra LBB0_2
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
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 4
	add r6, r1, r5
	ld.global r6, [#0, r6, 0, 0]
	shl r6, 2
	add r6, r2, r6
	add r5, r4, r5
	ld.global r5, [#1, r5, 0, 0]
	atom.add.f32.global r5, [r3, r6, 0, 0], r5
	or r5, r0, 8
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 12
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 16
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 20
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r5, r0, 24
	add r6, r4, r5
	add r5, r1, r5
	ld.global r5, [#0, r5, 0, 0]
	shl r5, 2
	add r5, r2, r5
	ld.global r6, [#1, r6, 0, 0]
	atom.add.f32.global r5, [r3, r5, 0, 0], r6
	or r0, r0, 28
	add r4, r0
	add r0, r1, r0
	ld.global r0, [#0, r0, 0, 0]
	shl r0, 2
	add r0, r2, r0
	ld.global r1, [#1, r4, 0, 0]
	atom.add.f32.global r0, [r3, r0, 0, 0], r1
LBB0_2:
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

