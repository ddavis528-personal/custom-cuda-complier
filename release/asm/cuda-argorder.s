	.text
	.file	"argorder.cu"
	.globl	_Z8argorderPfiPKffS1_
	.type	_Z8argorderPfiPKffS1_,@function
_Z8argorderPfiPKffS1_:
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r1, r3, r1, r2
	ld.global r2, [r0 + 56]
	setp.le.u p0, r2, r1
	@p0 bra LBB0_2
	shl r1, 2
	ld.global r2, [r0 + 52]
	add r2, r1
	ld.global r2, [#2, r2, 0, 0]
	ld.global r3, [r0 + 44]
	add r3, r1
	ld.global r3, [#1, r3, 0, 0]
	ld.global r4, [r0 + 60]
	ffma.acc.f0 r2, r3, r4
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r2, [#0, r0, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z8argorderPfiPKffS1_, Lfunc_end0-_Z8argorderPfiPKffS1_

