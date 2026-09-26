	.text
	.file	"vadd16.cu"
	.globl	_Z6vadd16PsPKsS1_i
	.type	_Z6vadd16PsPKsS1_i,@function
_Z6vadd16PsPKsS1_i:
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r1, r3, r1, r2
	ld.global r2, [r0 + 56]
	setp.le.u p0, r2, r1
	@p0 bra LBB0_2
	chwidth.multi 24576, 1
	shl r1, 1
	ld.global r2, [r0 + 44]
	add r2, r1
	ld.global r14, [#2, r2, 0, 0]
	ld.global r2, [r0 + 52]
	add r2, r1
	ld.global r13, [#4, r2, 0, 0]
	add r14, r13, r14
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r14, [#0, r0, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z6vadd16PsPKsS1_i, Lfunc_end0-_Z6vadd16PsPKsS1_i

