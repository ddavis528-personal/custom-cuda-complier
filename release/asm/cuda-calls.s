	.text
.Lccv_text:
	.file	"calls.cu"
	.type	_Z6add_atiiPKi,@function
_Z6add_atiiPKi:
	ld.global r0, [r3, r4, 0, 0]
	add r1, r2, r1
	add r1, r0
	ret 224
Lfunc_end0:
	.size	_Z6add_atiiPKi, Lfunc_end0-_Z6add_atiiPKi

	.type	_Z9sub_frameiiPKi,@function
_Z9sub_frameiiPKi:
	sub r0, r1, r2
	st.global r0, [r15 + -16]
	mov r0, r1
	shl r0, 2
	sub r0, r2
	st.global r0, [r15 + -4]
	mul.lo r0, r1, 3
	sub r0, r2
	st.global r0, [r15 + -8]
	shl r1, 1
	sub r0, r1, r2
	st.global r0, [r15 + -12]
	ld.global r0, [r3, r4, 0, 4]
	and r1, r2, 3
	ld.global r1, [r15, r1, 1, -16]
	sub r1, r0
	ret 224
Lfunc_end1:
	.size	_Z9sub_frameiiPKi, Lfunc_end1-_Z9sub_frameiiPKi

	.type	_Z3mixiiii,@function
_Z3mixiiii:
	movi r0, 3
	mad.lo r0, r1, r0, r2
	sub r1, r3, r4
	xor r1, r0
	ret 224
Lfunc_end2:
	.size	_Z3mixiiii, Lfunc_end2-_Z3mixiiii

	.type	_Z9half_steps,@function
_Z9half_steps:
	chwidth r7, 1
	add r7, r1, 3
	cvt.sint.sint r1, r7
	chwidth r7, 0
	ret 224
Lfunc_end3:
	.size	_Z9half_steps, Lfunc_end3-_Z9half_steps

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
Lfunc_end4:
	.size	_Z5chainii, Lfunc_end4-_Z5chainii

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
Lfunc_end5:
	.size	_Z7scratchii, Lfunc_end5-_Z7scratchii

	.type	_Z7narrow3sss,@function
_Z7narrow3sss:
	chwidth.multi 192, 1
	add r7, r2, r1
	sub r6, r3, r1
	xor r7, r6, r7
	chwidth r6, 0
	add r7, r7, r3
	cvt.sint.sint r1, r7
	chwidth r7, 0
	ret 224
Lfunc_end6:
	.size	_Z7narrow3sss, Lfunc_end6-_Z7narrow3sss

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
Lfunc_end7:
	.size	_Z4sum3PKii, Lfunc_end7-_Z4sum3PKii

	.type	_Z8sum3_viaPKii,@function
_Z8sum3_viaPKii:
	mov r4, r14
	add r2, 4
	call r14, _Z4sum3PKii
	mov r14, r4
	ret 224
Lfunc_end8:
	.size	_Z8sum3_viaPKii, Lfunc_end8-_Z8sum3_viaPKii

	.type	_Z7advancePii,@function
_Z7advancePii:
	shl r3, 2
	add r2, r3
	ret 224
Lfunc_end9:
	.size	_Z7advancePii, Lfunc_end9-_Z7advancePii

	.type	_Z4manyiiiiiiisi,@function
_Z4manyiiiiiiisi:
	chwidth r7, 1
	movi r0, 3
	mad.lo r0, r3, r0, r1
	shl r4, 2
	shl r2, 1
	add r1, r2, r4
	sub r0, r1
	movi r1, 5
	mad.acc r0, r5, r1
	f48 r1, 4294967290
	mad.acc r0, r6, r1
	movi r1, 7
	ld.global r2, [r15 + -4]
	mad.acc r0, r2, r1
	ld.global r7, [r15 + -8]
	cvt.sint.sint r1, r7
	chwidth r7, 0
	shl r1, 3
	sub r0, r1
	movi r1, 9
	ld.global r2, [r15 + -12]
	mad.lo r1, r2, r1, r0
	ret 224
Lfunc_end10:
	.size	_Z4manyiiiiiiisi, Lfunc_end10-_Z4manyiiiiiiisi

	.type	_Z5many2iiiiiiii,@function
_Z5many2iiiiiiii:
	st.global r8, [r15 + -24]
	st.global r9, [r15 + -28]
	st.global r10, [r15 + -32]
	mov r8, r14
	mov r0, r4
	mov r7, r3
	st.global r1, [r15 + -8]
	st.global r2, [r15 + -4]
	ld.global r9, [r15 + -16]
	ld.global r10, [r15 + -20]
	add r1, r10, r9
	st.global r1, [r15 + -12]
	mov r1, r10
	mov r2, r9
	mov r3, r6
	mov r4, r5
	mov r5, r0
	mov r6, r7
	call r14, _Z4manyiiiiiiisi
	mad.acc r1, r10, r9
	mov r14, r8
	ld.global r10, [r15 + -32]
	ld.global r9, [r15 + -28]
	ld.global r8, [r15 + -24]
	ret 224
Lfunc_end11:
	.size	_Z5many2iiiiiiii, Lfunc_end11-_Z5many2iiiiiiii

	.type	_Z4pickiiiiiPKi,@function
_Z4pickiiiiiPKi:
	add r0, r3, r5
	add r2, r4
	sub r0, r2, r0
	and r1, 3
	shl r1, 2
	ld.global r2, [r15 + -4]
	add r1, r2, r1
	ld.global r1, [r6, r1, 0, 0]
	add r1, r0, r1
	ret 224
Lfunc_end12:
	.size	_Z4pickiiiiiPKi, Lfunc_end12-_Z4pickiiiiiPKi

	.type	_Z5applyPFiiiPKiEiiS0_,@function
_Z5applyPFiiiPKiEiiS0_:
	st.global r8, [r15 + -20]
	st.global r9, [r15 + -24]
	mov r8, r14
	mov r9, r2
	mov r7, r1
	mov r1, r9
	mov r2, r3
	mov r3, r4
	mov r4, r5
	call r14, .Lccv_icall__Z5applyPFiiiPKiEiiS0_
	shl r1, 1
	add r1, r9
	mov r14, r8
	ld.global r9, [r15 + -24]
	ld.global r8, [r15 + -20]
	ret 224
.Lccv_icall__Z5applyPFiiiPKiEiiS0_:
	ret 112
Lfunc_end13:
	.size	_Z5applyPFiiiPKiEiiS0_, Lfunc_end13-_Z5applyPFiiiPKiEiiS0_

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
	@p0 bra LBB14_2
	mov r1, r8
	shl r1, 2
	ld.global r9, [r0 + 36]
	add r1, r9, r1
	ld.global r11, [#0, r1, 0, 0]
	ld.global r1, [r0 + 44]
	st.global r1, [r15 + -56]
	ld.global r13, [r0 + 40]
	ld.global r10, [r0 + 32]
	add r12, r11, 1
	mov r1, r12
	movi r2, 2
	call r14, _Z5chainii
	st.global r1, [r15 + -52]
	add r1, r11, 2
	movi r2, 3
	call r14, _Z5chainii
	st.global r1, [r15 + -64]
	add r1, r11, 3
	movi r2, 4
	call r14, _Z5chainii
	st.global r1, [r15 + -68]
	mul.lo r0, r11, 7
	add r1, r0, 3
	st.global r1, [r15 + -36]
	add r1, r0, 2
	st.global r1, [r15 + -40]
	add r1, r0, 1
	st.global r1, [r15 + -44]
	st.global r0, [r15 + -48]
	mov r1, r11
	movi r2, 1
	call r14, _Z5chainii
	st.global r1, [r15 + -72]
	mov r1, r11
	mov r2, r8
	call r14, _Z7scratchii
	st.global r1, [r15 + -76]
	mov r2, r11
	shr r2, 3
	mov r1, r11
	mov r3, r8
	call r14, _Z7narrow3sss
	st.global r1, [r15 + -80]
	and r3, r8, 7
	mov r1, r10
	mov r2, r9
	call r14, _Z8sum3_viaPKii
	st.global r1, [r15 + -84]
	mov r1, r13
	ld.global r2, [r15 + -56]
	mov r3, r8
	call r14, _Z7advancePii
	st.global r1, [r15 + -56]
	st.global r2, [r15 + -60]
	mov r0, r11
	sra r0, 2
	st.global r0, [r15 + -20]
	add r0, r8, 11
	st.global r0, [r15 + -16]
	xor r13, r11, r8
	add r6, r11, -7
	mul.lo r5, r8, 3
	mov r1, r11
	mov r2, r8
	mov r3, r13
	mov r4, r12
	call r14, _Z5many2iiiiiiii
	and r0, r8, 1
	setp.ne p0, r0, 0
	movi r0, (_Z6add_atiiPKi-.Lccv_text)+4096
	movi r12, (_Z9sub_frameiiPKi-.Lccv_text)+4096
	@p0 mov r12, r0
	mul.lo r3, r8, 5
	sub r0, r11, r3
	mul.lo r2, r8, r8
	sub r4, r13, r2
	add r5, r11, 99
	mad.lo r0, r0, r5, r4
	mul.lo r4, r11, 3
	mad.acc r0, r4, r13
	xor r4, r5
	add r0, r4
	ld.global r4, [r15 + -52]
	ld.global r5, [r15 + -72]
	add r4, r5
	ld.global r5, [r15 + -64]
	add r4, r5, r4
	ld.global r5, [r15 + -68]
	add r4, r5, r4
	add r0, r4
	movi r4, 3
	ld.global r5, [r15 + -76]
	mad.acc r0, r5, r4
	ld.global r4, [r15 + -84]
	add r0, r4
	ld.global r5, [r15 + -80]
	chwidth r5, 1
	cvt.sint.sint r4, r5
	chwidth r5, 0
	mad.acc r0, r2, r4
	add r2, r9, 8
	st.global r2, [r15 + -4]
	add r7, r0, r1
	mov r5, r11
	sra r5, 4
	mov r1, r8
	mov r2, r11
	movi r4, 13
	mov r6, r10
	call r14, _Z4pickiiiiiPKi
	add r13, r7, r1
	add r5, r9, 16
	mov r1, r12
	mov r2, r11
	mov r3, r8
	mov r4, r10
	call r14, _Z5applyPFiiiPKiEiiS0_
	add r13, r1
	and r2, r11, 15
	mov r7, r12
	mov r1, r8
	mov r3, r10
	mov r4, r9
	call r14, .Lccv_icall__Z5callsPKiPii
	add r0, r13, r1
	add r1, r8, 1
	and r1, 3
	ld.global r1, [r15, r1, 1, -48]
	add r0, r1
	ld.global r1, [r15 + -56]
	ld.global r2, [r15 + -60]
	st.global r0, [r1, r2, 0, 0]
LBB14_2:
	exit
.Lccv_icall__Z5callsPKiPii:
	ret 112
Lfunc_end14:
	.size	_Z5callsPKiPii, Lfunc_end14-_Z5callsPKiPii

