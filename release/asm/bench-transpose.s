	.text
	.file	"transpose.cu"
	.globl	_Z9transposePfPKfi
	.type	_Z9transposePfPKfi,@function
_Z9transposePfPKfi:
	pmov p3, 1
	movi r0, 2
	@p3 ld.global r1, [r0 + 48]
	@!p3 shfl.idx r1, r1, 0
	@p3 sra r2, r1, 31
	@p3 shr r2, r2, 28
	@p3 add r3, r1, r2
	@!p3 shfl.idx r3, r3, 0
	sra r3, 4
	rcp.u32 r2, r3
	mul.lo r4, r2, r3
	neg r4, r4
	@p3 mul.hi.u r4, r2, r4
	@p3 add r2, r2, r4
	srd r4, 1
	@p3 mul.hi.u r2, r4, r2
	@!p3 shfl.idx r2, r2, 0
	mul.lo r5, r2, r3
	@p3 sub r5, r4, r5
	@!p3 shfl.idx r5, r5, 0
	setp.le.u p0, r3, r5
	@p3 add r6, r2, 1
	pand p1, 0, 3
	@p1 mov r2, r6
	@p3 sub r6, r5, r3
	@p0 mov r5, r6
	setp.le.u p0, r3, r5
	@p3 add r5, r2, 1
	@p0 mov r2, r5
	mul.lo r3, r2, r3
	@p3 sub r4, r4, r3
	@!p3 shfl.idx r4, r4, 0
	srd r3, 0
	and r5, r3, 15
	shr r3, 4
	shl r4, 4
	shl r2, 4
	add r6, r2, r3
	or r7, r4, r5
	mad.lo r6, r6, r1, r7
	shl r6, 2
	@p3 ld.global r7, [r0 + 44]
	@!p3 shfl.idx r7, r7, 0
	add r6, r7, r6
	ld.global r6, [#2, r6, 0, 0]
	mul.lo r7, r3, 68
	st.shared r6, [r7, r5, 1, 0]
	or r2, r5
	add r4, r3
	mad.lo r1, r4, r1, r2
	@p3 ld.global r0, [r0 + 36]
	@!p3 shfl.idx r0, r0, 0
	shl r1, 2
	add r0, r1
	mul.lo r1, r5, 68
	bar.arrive 0
	bar.wait 0
	ld.shared r1, [r1, r3, 1, 0]
	st.global r1, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z9transposePfPKfi, Lfunc_end0-_Z9transposePfPKfi

