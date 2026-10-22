	.text
	.file	"globals.cu"
	.type	_Z10via_calleei,@function
_Z10via_calleei:
	chwidth r7, 1
	f48 r0, 1431655766
	mul.hi.s r0, r1, r0
	shr r2, r0, 31
	add r0, r2
	mul.lo r0, r0, 3
	sub r0, r1, r0
	shl r0, 3
	movi r1, 2
	ld.global r1, [r1 + 28]
	ld.global r2, [r1, r0, 0, 28]
	ld.global r7, [r1, r0, 0, 24]
	cvt.sint.sint r0, r7
	chwidth r7, 0
	ld.global r1, [r1 + 208]
	mad.acc r1, r2, r0
	ret 224
Lfunc_end0:
	.size	_Z10via_calleei, Lfunc_end0-_Z10via_calleei

	.globl	_Z7globalsPi
	.type	_Z7globalsPi,@function
_Z7globalsPi:
	movi r0, 2
	ld.global r4, [r0 + 28]
	srd r3, 0
	and r5, r3, 1
	mov r1, r5
	shl r1, 3
	ld.global r2, [r4, r1, 0, 52]
	shl r2, r2, 16
	ld.global r1, [r4, r1, 0, 48]
	shr r6, r1, 16
	or r2, r6
	movi r6, 65535
	and r1, r6
	and r6, r3, 3
	shl r6, 2
	add r1, r6
	ld.global r6, [r2, r1, 0, 0]
	ld.global r0, [r0 + 36]
	mov r1, r3
	shl r1, 3
	add r8, r0, r1
	mov r1, r3
	call r14, _Z10via_calleei
	add r0, r1, r6
	ld.global r1, [r4, r3, 1, 80]
	add r0, r1
	st.global r0, [r4, r3, 1, 80]
	st.global r0, [#0, r8, 0, 0]
	ld.global r0, [r4, r5, 1, 16]
	cvt.f32.s32 r1, r3
	fmul r0, r1
	add r1, r8, 4
	cvt.s32.f32 r0, r0
	st.global r0, [#0, r1, 0, 0]
	exit
Lfunc_end1:
	.size	_Z7globalsPi, Lfunc_end1-_Z7globalsPi

	.type	__ccv_data,@object
	.section	.ccv_data,"a",@progbits
	.globl	__ccv_data
	.p2align	3, 0x0
__ccv_data:
	.asciz	"\001\000\000\000\002\000\000\000\003\000\000\000\004\000\000\000\000\000\000?\000\000\000@\001\000\000\000\371\377\377\377\376\377\000\000\t\000\000\000\003\000\000\000d\000\000\000\000\000\000\000\000\000\000\000@\000\000\000\000\000\000\000\n\000\000\000\024\000\000\000\036\000\000\000(\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\005\000\000\000\000\000\000"
	.size	__ccv_data, 216

	.type	__ccv_reloc,@object
	.section	.ccv_reloc,"a",@progbits
	.globl	__ccv_reloc
	.p2align	3, 0x0
__ccv_reloc:
	.long	48
	.long	56
	.size	__ccv_reloc, 8

