	.text
	.file	"frame-escape.cu"
	.type	_Z4bumpPj,@function
_Z4bumpPj:
	ld.global r0, [r1, r2, 0, 0]
	add r0, 1
	st.global r0, [r1, r2, 0, 0]
	ret 224
Lfunc_end0:
	.size	_Z4bumpPj, Lfunc_end0-_Z4bumpPj

	.type	_Z4keepPPjS_,@function
_Z4keepPPjS_:
	shl r0, r3, 16
	add r5, r0, r4
	st.global r5, [r1, r2, 0, 0]
	or r6, r0, r4
	andn r5, r6, r5
	and r0, r4
	or r0, r5
	shr r0, r0, 31
	shr r3, r3, 16
	add r0, r3, r0
	st.global r0, [r1, r2, 0, 4]
	ret 224
Lfunc_end1:
	.size	_Z4keepPPjS_, Lfunc_end1-_Z4keepPPjS_

	.globl	_Z12frame_escapePjPS_
	.type	_Z12frame_escapePjPS_,@function
_Z12frame_escapePjPS_:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 3
	add r15, r14
	pmov p3, 1
	movi r0, 2
	@p3 ld.global r8, [r0 + 36]
	@!p3 shfl.idx r8, r8, 0
	@p3 ld.global r9, [r0 + 44]
	@!p3 shfl.idx r9, r9, 0
	srd r7, 0
	add r0, r7, 3
	st.global r0, [r15 + 20]
	add r0, r7, 2
	st.global r0, [r15 + 16]
	add r0, r7, 1
	st.global r0, [r15 + 12]
	st.global r7, [r15 + 8]
	movi r10, 8
	mov r1, r15
	movi r2, 8
	call r14, _Z4bumpPj
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r3, 3
	add r15, r3
	add r4, r10, 4
	mov r1, r15
	movi r2, 0
	mov r3, r15
	call r14, _Z4keepPPjS_
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r3, 3
	add r15, r3
	add r0, r10, 8
	shl r1, r15, 16
	and r2, r1, r0
	add r3, r1, r0
	or r0, r1, r0
	andn r0, r3
	or r0, r2, r0
	shr r0, r0, 31
	shr r1, r15, 16
	add r0, r1, r0
	mov r1, r7
	shl r1, 3
	or r2, r1, 4
	st.shared r0, [r2 + 0]
	st.shared r3, [r1 + 0]
	add r1, r9, r1
	mov r0, r7
	shl r0, 2
	add r0, r8, r0
	add r2, r10, 12
	shl r3, r15, 16
	and r4, r3, r2
	add r5, r3, r2
	or r2, r3, r2
	andn r2, r5
	st.global r5, [#1, r1, 0, 0]
	or r2, r4, r2
	shr r2, r2, 31
	shr r3, r15, 16
	add r2, r3, r2
	st.global r2, [#1, r1, 0, 4]
	xor r2, r7, 1
	shl r2, 3
	bar.init 0, 0
	bar.arrive 0
	bar.wait 0
	or r3, r2, 4
	ld.shared r3, [r3 + 0]
	shl r3, r3, 16
	ld.shared r2, [r2 + 0]
	shr r4, r2, 16
	or r3, r4
	movi r4, 65535
	and r2, r4
	ld.global r2, [r3, r2, 0, 0]
	@p3 ld.global r3, [r15 + 4]
	@p3 shl r3, r3, 16
	@p3 ld.global r5, [r15 + 0]
	@p3 shr r6, r5, 16
	@p3 or r3, r3, r6
	@!p3 shfl.idx r3, r3, 0
	@p3 and r5, r5, r4
	@!p3 shfl.idx r5, r5, 0
	ld.global r3, [r3, r5, 0, 0]
	@p3 ld.global r5, [r15 + 8]
	@p3 add r3, r3, r5
	@!p3 shfl.idx r3, r3, 0
	add r2, r3, r2
	ld.global r3, [#1, r1, 0, 4]
	shl r3, r3, 16
	ld.global r1, [#1, r1, 0, 0]
	shr r5, r1, 16
	or r3, r5
	and r1, r4
	ld.global r1, [r3, r1, 0, 0]
	add r1, r2, r1
	st.global r1, [#0, r0, 0, 0]
	exit
Lfunc_end2:
	.size	_Z12frame_escapePjPS_, Lfunc_end2-_Z12frame_escapePjPS_

