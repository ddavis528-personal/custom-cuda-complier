	.text
	.file	"ptrmem.cu"
	.globl	_Z6ptrmemPPfS0_S_
	.type	_Z6ptrmemPPfS0_S_,@function
_Z6ptrmemPPfS0_S_:
	srd r0, 0
	and r2, r0, 3
	shl r2, 3
	movi r1, 2
	ld.global r3, [r1 + 36]
	add r2, r3, r2
	ld.global r3, [#0, r2, 0, 4]
	ld.global r2, [#0, r2, 0, 0]
	shr r4, r2, 16
	shl r5, r3, 16
	or r4, r5, r4
	mov r5, r0
	shl r5, 2
	ld.global r6, [r1 + 52]
	add r5, r6, r5
	movi r6, 65535
	and r7, r2, r6
	and r8, r0, -4
	add r7, r8
	ld.global r4, [r4, r7, 0, 0]
	fadd r4, r4
	st.global r4, [#2, r5, 0, 0]
	and r3, r6
	f48 r4, 4294901760
	and r2, r4
	add r4, r7, r2
	add r4, r4, 16
	setp.lt.u p0, r4, r2
	add r2, r3, 1
	@p0 mov r3, r2
	shl r0, 3
	ld.global r1, [r1 + 44]
	add r0, r1, r0
	st.global r4, [#1, r0, 0, 0]
	st.global r3, [#1, r0, 0, 4]
	exit
Lfunc_end0:
	.size	_Z6ptrmemPPfS0_S_, Lfunc_end0-_Z6ptrmemPPfS0_S_

