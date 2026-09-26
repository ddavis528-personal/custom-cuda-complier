	.text
	.file	"vadd.cu"
	.globl	_Z4vaddPfPKfS1_i
	.type	_Z4vaddPfPKfS1_i,@function
_Z4vaddPfPKfS1_i:
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
	ld.global r2, [#4, r2, 0, 0]
	ld.global r3, [r0 + 44]
	add r3, r1
	ld.global r3, [#2, r3, 0, 0]
	fadd r3, r2
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r3, [#0, r0, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z4vaddPfPKfS1_i, Lfunc_end0-_Z4vaddPfPKfS1_i

