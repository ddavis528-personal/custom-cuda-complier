	.text
	.file	"transpose32.cu"
	.globl	_Z11transpose32PfPKfi
	.type	_Z11transpose32PfPKfi,@function
_Z11transpose32PfPKfi:
	pmov p3, 1
	movi r1, 2
	@p3 ld.global r0, [r1 + 48]
	@!p3 shfl.idx r0, r0, 0
	mov r5, r0
	shr r5, 5
	rcp.u32 r2, r5
	mul.lo r3, r2, r5
	neg r3, r3
	@p3 mul.hi.u r3, r2, r3
	@p3 add r2, r2, r3
	srd r3, 1
	@p3 mul.hi.u r2, r3, r2
	@!p3 shfl.idx r2, r2, 0
	mul.lo r4, r2, r5
	@p3 sub r4, r3, r4
	@!p3 shfl.idx r4, r4, 0
	setp.le.u p0, r5, r4
	@p3 add r6, r2, 1
	pand p0, 0, 3
	@p0 mov r2, r6
	@p3 sub r6, r4, r5
	@p0 mov r4, r6
	@!p3 shfl.idx r4, r4, 0
	setp.le.u p0, r5, r4
	@p3 add r4, r2, 1
	pand p0, 0, 3
	@p0 mov r2, r4
	@!p3 shfl.idx r2, r2, 0
	srd r8, 0
	mov r4, r8
	shr r4, 5
	movi r9, 1023
	setp.lt.u p0, r9, r8
	and r6, r8, 31
	shl r3, 5
	mul.lo r7, r2, r5
	shl r2, 5
	mov r5, r0
	shl r5, 2
	@p0 bra LBB0_3
	add r10, r4, r2
	mad.lo r10, r0, r10, r3
	add r10, r6
	mov r11, r7
	shl r11, 5
	sub r10, r11
	mov r11, r4
LBB0_2:
	ld.global r12, [r1 + 44]
	mov r13, r10
	shl r13, 2
	add r12, r13
	ld.global r12, [#1, r12, 0, 0]
	mul.lo r13, r11, 132
	st.shared r12, [r13, r6, 1, 0]
	add r10, r5
	add r12, r11, 4
	setp.lt.u p0, r11, 28
	mov r11, r12
	@p0 bra LBB0_2
LBB0_3:
	setp.lt.u p0, r9, r8
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_6
	add r1, r4, r3
	shl r7, 5
	sub r1, r7
	mad.lo r0, r0, r1, r2
	add r0, r6
	movi r1, 2
	mul.lo r2, r6, 132
LBB0_5:
	ld.global r3, [r1 + 36]
	mov r6, r0
	shl r6, 2
	add r3, r6
	ld.shared r6, [r2, r4, 1, 0]
	st.global r6, [#0, r3, 0, 0]
	add r0, r5
	add r3, r4, 4
	setp.lt.u p0, r4, 28
	mov r4, r3
	@p0 bra LBB0_5
LBB0_6:
	exit
Lfunc_end0:
	.size	_Z11transpose32PfPKfi, Lfunc_end0-_Z11transpose32PfPKfi

