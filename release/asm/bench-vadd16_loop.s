	.text
	.file	"vadd16_loop.cu"
	.globl	_Z11vadd16_loopPsPKsS1_i
	.type	_Z11vadd16_loopPsPKsS1_i,@function
_Z11vadd16_loopPsPKsS1_i:
	chwidth.multi 24576, 1
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.acc r2, r3, r1
	ld.global r3, [r0 + 56]
	setp.le.u p0, r3, r2
	@p0 bra LBB0_2
LBB0_1:
	mov r4, r2
	shl r4, 1
	ld.global r5, [r0 + 44]
	add r5, r4
	ld.global r14, [#2, r5, 0, 0]
	ld.global r5, [r0 + 52]
	add r5, r4
	ld.global r13, [#4, r5, 0, 0]
	add r14, r13, r14
	ld.global r5, [r0 + 36]
	add r4, r5, r4
	st.global r14, [#0, r4, 0, 0]
	add r2, r1
	setp.lt.u p0, r2, r3
	@p0 bra LBB0_1
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z11vadd16_loopPsPKsS1_i, Lfunc_end0-_Z11vadd16_loopPsPKsS1_i

