	.text
	.file	"vadd16_loop.cu"
	.globl	_Z11vadd16_loopPsPKsS1_i
	.type	_Z11vadd16_loopPsPKsS1_i,@function
_Z11vadd16_loopPsPKsS1_i:
	chwidth.multi 12288, 1
	movi r8, 2
	ld.global r0, [r8]
	srd r1, 0
	srd r2, 1
	mad.acc r1, r2, r0
	ld.global r2, [r8 + 52]
	ld.global r3, [r8 + 48]
	ld.global r4, [r8 + 44]
	ld.global r5, [r8 + 40]
	ld.global r6, [r8 + 36]
	ld.global r7, [r8 + 32]
	ld.global r8, [r8 + 56]
	setp.le.u p0, r8, r1
	@p0 bra LBB0_2
LBB0_1:
	mov r9, r1
	shl r9, 1
	add r10, r4, r9
	ld.global.u16 r13, [r5, r10, 0, 0]
	add r10, r2, r9
	ld.global.u16 r12, [r3, r10, 0, 0]
	add r13, r12, r13
	add r9, r6, r9
	st.global.16 r13, [r7, r9, 0, 0]
	add r1, r0
	setp.lt.u p0, r1, r8
	@p0 bra LBB0_1
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z11vadd16_loopPsPKsS1_i, Lfunc_end0-_Z11vadd16_loopPsPKsS1_i

