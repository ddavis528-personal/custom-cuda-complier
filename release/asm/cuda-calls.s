	.text
	.file	"calls.cu"
	.type	_Z3mixiiii,@function
_Z3mixiiii:
	movi r0, 3
	mad.lo r0, r1, r0, r2
	sub r1, r3, r4
	xor r1, r0
	ret 224
Lfunc_end0:
	.size	_Z3mixiiii, Lfunc_end0-_Z3mixiiii

	.type	_Z9half_steps,@function
_Z9half_steps:
	chwidth.multi 130, 1
	add r7, r1, 3
	chwidth r1, 0
	cvt.sint.sint r1, r7
	chwidth r7, 0
	ret 224
Lfunc_end1:
	.size	_Z9half_steps, Lfunc_end1-_Z9half_steps

	.type	_Z5chainii,@function
_Z5chainii:
	mov r5, r14
	mov r6, r1
	add r3, r6, 7
	add r4, r2, -2
	call r14, _Z3mixiiii
	mad.lo r0, r2, r6, r1
	mov r1, r6
	call r14, _Z9half_steps
	chwidth r1, 1
	cvt.sint.sint r2, r1
	chwidth r1, 0
	add r1, r0, r2
	mov r14, r5
	ret 224
Lfunc_end2:
	.size	_Z5chainii, Lfunc_end2-_Z5chainii

	.type	_Z7scratchii,@function
_Z7scratchii:
	mul.lo r0, r1, 5
	add r0, r0, 100
	st.global r0, [r15 + -4]
	mov r0, r1
	shl r0, 2
	add r0, r0, 100
	st.global r0, [r15 + -8]
	mul.lo r0, r1, 3
	add r0, r0, 100
	st.global r0, [r15 + -12]
	shl r1, 1
	add r0, r1, 100
	st.global r0, [r15 + -16]
	and r0, r2, 3
	ld.global r1, [r15, r0, 1, -16]
	ret 224
Lfunc_end3:
	.size	_Z7scratchii, Lfunc_end3-_Z7scratchii

	.type	_Z7narrow3sss,@function
_Z7narrow3sss:
	chwidth.multi 206, 1
	add r7, r2, r1
	chwidth r2, 0
	sub r6, r3, r1
	chwidth r1, 0
	xor r7, r6, r7
	chwidth r6, 0
	add r7, r7, r3
	chwidth r3, 0
	cvt.sint.sint r1, r7
	chwidth r7, 0
	ret 224
Lfunc_end4:
	.size	_Z7narrow3sss, Lfunc_end4-_Z7narrow3sss

	.type	_Z4sum3PKii,@function
_Z4sum3PKii:
	shl r3, 2
	add r0, r2, r3
	ld.global r2, [r1, r0, 0, 0]
	ld.global r3, [r1, r0, 0, 4]
	add r2, r3, r2
	ld.global r0, [r1, r0, 0, 8]
	add r1, r2, r0
	ret 224
Lfunc_end5:
	.size	_Z4sum3PKii, Lfunc_end5-_Z4sum3PKii

	.type	_Z8sum3_viaPKii,@function
_Z8sum3_viaPKii:
	mov r4, r14
	add r2, 4
	call r14, _Z4sum3PKii
	mov r14, r4
	ret 224
Lfunc_end6:
	.size	_Z8sum3_viaPKii, Lfunc_end6-_Z8sum3_viaPKii

	.type	_Z7advancePii,@function
_Z7advancePii:
	shl r3, 2
	add r2, r3
	ret 224
Lfunc_end7:
	.size	_Z7advancePii, Lfunc_end7-_Z7advancePii

	.globl	_Z5callsPKiPii
	.type	_Z5callsPKiPii,@function
_Z5callsPKiPii:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 0
	add r15, r14
	movi r0, 2
	ld.global r1, [r0 + 48]
	srd r8, 0
	setp.le p0, r1, r8
	@p0 bra LBB8_2
	mov r1, r8
	shl r1, 2
	ld.global r2, [r0 + 36]
	st.global r2, [r15 + -44]
	add r1, r2, r1
	ld.global r13, [#0, r1, 0, 0]
	ld.global r1, [r0 + 44]
	st.global r1, [r15 + -36]
	ld.global r1, [r0 + 40]
	st.global r1, [r15 + -40]
	ld.global r0, [r0 + 32]
	st.global r0, [r15 + -48]
	add r1, r13, 1
	movi r2, 2
	call r14, _Z5chainii
	st.global r1, [r15 + -52]
	add r1, r13, 2
	movi r2, 3
	call r14, _Z5chainii
	mov r10, r1
	add r1, r13, 3
	movi r2, 4
	call r14, _Z5chainii
	mov r12, r1
	mul.lo r0, r13, 7
	add r1, r0, 3
	st.global r1, [r15 + -20]
	add r1, r0, 2
	st.global r1, [r15 + -24]
	add r1, r0, 1
	st.global r1, [r15 + -28]
	st.global r0, [r15 + -32]
	f48 r0, 4294967291
	mad.lo r0, r8, r0, r13
	xor r1, r13, r8
	mul.lo r9, r8, r8
	sub r2, r1, r9
	add r3, r13, 99
	mad.lo r0, r0, r3, r2
	mul.lo r2, r13, 3
	mad.acc r0, r2, r1
	xor r1, r2, r3
	add r11, r0, r1
	mov r1, r13
	movi r2, 1
	call r14, _Z5chainii
	ld.global r0, [r15 + -52]
	add r0, r1
	add r0, r10, r0
	add r0, r12, r0
	add r3, r11, r0
	mov r1, r13
	mov r2, r8
	call r14, _Z7scratchii
	movi r0, 3
	mad.lo r10, r1, r0, r3
	mov r2, r13
	shr r2, 3
	mov r1, r13
	mov r3, r8
	call r14, _Z7narrow3sss
	mov r5, r1
	chwidth r5, 1
	and r3, r8, 7
	ld.global r1, [r15 + -48]
	ld.global r2, [r15 + -44]
	call r14, _Z8sum3_viaPKii
	add r0, r10, r1
	cvt.sint.sint r1, r5
	chwidth r5, 0
	mad.acc r0, r9, r1
	ld.global r1, [r15 + -40]
	ld.global r2, [r15 + -36]
	mov r3, r8
	call r14, _Z7advancePii
	add r3, r8, 1
	and r3, 3
	ld.global r3, [r15, r3, 1, -32]
	add r0, r3
	st.global r0, [r1, r2, 0, 0]
LBB8_2:
	exit
Lfunc_end8:
	.size	_Z5callsPKiPii, Lfunc_end8-_Z5callsPKiPii

