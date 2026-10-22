	.text
	.file	"ptrmem.cu"
	.globl	_Z6ptrmemPPfS0_S_
	.type	_Z6ptrmemPPfS0_S_,@function
_Z6ptrmemPPfS0_S_:
	srd r0, 0
	and r1, r0, 3
	shl r1, 3
	movi r2, 2
	ld.global r3, [r2 + 36]
	add r1, r3, r1
	ld.global r3, [#0, r1, 0, 4]
	ld.global r1, [#0, r1, 0, 0]
	shr r4, r1, 16
	shl r5, r3, 16
	or r4, r5, r4
	mov r5, r0
	shl r5, 2
	ld.global r6, [r2 + 52]
	add r5, r6, r5
	movi r6, 65535
	and r7, r1, r6
	and r8, r0, -4
	add r7, r8
	ld.global r4, [r4, r7, 0, 0]
	fadd r4, r4
	st.global r4, [#2, r5, 0, 0]
	shl r0, 3
	ld.global r2, [r2 + 44]
	add r0, r2, r0
	f48 r2, 4294901760
	and r2, r1, r2
	add r4, r7, 16
	add r2, r4
	st.global r2, [#1, r0, 0, 0]
	or r5, r1, r4
	andn r2, r5, r2
	and r1, r4
	or r1, r2
	and r2, r3, r6
	shr r1, r1, 31
	add r1, r2, r1
	st.global r1, [#1, r0, 0, 4]
	exit
Lfunc_end0:
	.size	_Z6ptrmemPPfS0_S_, Lfunc_end0-_Z6ptrmemPPfS0_S_

