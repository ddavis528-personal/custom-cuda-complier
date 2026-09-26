	.text
	.file	"vadd-aligned.cu"
	.globl	_Z4vaddPfPKfS1_i
	.type	_Z4vaddPfPKfS1_i,@function
_Z4vaddPfPKfS1_i:
	movi r1, 2
	ld.global r0, [r1]
	srd r2, 0
	srd r3, 1
	mad.lo r0, r3, r0, r2
	ld.global r1, [r1 + 56]
	setp.le p0, r1, r0
	@p0 bra LBB0_2
	ld.global r1, [#4, r0, 1, 0]
	ld.global r2, [#2, r0, 1, 0]
	fadd r2, r1
	st.global r2, [#0, r0, 1, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z4vaddPfPKfS1_i, Lfunc_end0-_Z4vaddPfPKfS1_i

