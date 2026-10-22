	.text
	.file	"ptrlist.cu"
	.type	_Z7reverseP4node,@function
_Z7reverseP4node:
	mov r3, r2
	shl r0, r1, 16
	and r2, r0, r3
	add r4, r0, r3
	or r0, r3
	andn r0, r4
	or r0, r2, r0
	shr r0, r0, 31
	shr r2, r1, 16
	add r0, r2, r0
	or r0, r4, r0
	setp.eq p0, r0, 0
	@p0 bra LBB0_1
	movi r5, 0
	movi r4, 65535
	movi r6, 0
LBB0_3:
	mov r2, r3
	mov r0, r1
	shl r1, r5, 16
	and r3, r1, r6
	add r7, r1, r6
	or r1, r6
	andn r1, r7
	or r1, r3, r1
	shr r1, r1, 31
	shr r3, r5, 16
	add r1, r3, r1
	ld.global r3, [r0, r2, 0, 0]
	st.global r7, [r0, r2, 0, 0]
	ld.global r5, [r0, r2, 0, 4]
	st.global r1, [r0, r2, 0, 4]
	shr r1, r3, 16
	shl r6, r5, 16
	or r1, r6, r1
	and r5, r4
	or r5, r3, r5
	and r3, r4
	setp.ne p0, r5, 0
	mov r5, r0
	mov r6, r2
	@p0 bra LBB0_3
	mov r1, r0
	ret 224
LBB0_1:
	movi r0, 0
	movi r2, 0
	mov r1, r0
	ret 224
Lfunc_end0:
	.size	_Z7reverseP4node, Lfunc_end0-_Z7reverseP4node

	.type	_Z5tallyPK4nodeP3acc,@function
_Z5tallyPK4nodeP3acc:
	shl r0, r1, 16
	and r5, r0, r2
	add r6, r0, r2
	or r0, r2
	andn r0, r6
	or r0, r5, r0
	shr r0, r0, 31
	shr r5, r1, 16
	add r0, r5, r0
	or r0, r6, r0
	setp.eq p0, r0, 0
	@p0 bra LBB1_4
	ld.global r0, [r3, r4, 0, 4]
	ld.global r5, [r3, r4, 0, 0]
	movi r6, 65535
LBB1_2:
	ld.global r7, [r1, r2, 0, 0]
	shr r8, r7, 16
	ld.global r9, [r1, r2, 0, 4]
	shl r10, r9, 16
	or r8, r10, r8
	and r9, r6
	or r9, r7, r9
	and r7, r6
	ld.global r1, [r1, r2, 0, 8]
	add r5, r1
	add r0, 1
	setp.ne p0, r9, 0
	mov r1, r8
	mov r2, r7
	@p0 bra LBB1_2
	st.global r0, [r3, r4, 0, 4]
	st.global r5, [r3, r4, 0, 0]
LBB1_4:
	ret 224
Lfunc_end1:
	.size	_Z5tallyPK4nodeP3acc, Lfunc_end1-_Z5tallyPK4nodeP3acc

	.type	_Z4findP4nodei,@function
_Z4findP4nodei:
	mov r0, r1
	shl r1, r0, 16
	and r4, r1, r2
	add r5, r1, r2
	or r1, r2
	andn r1, r5
	or r1, r4, r1
	shr r1, r1, 31
	shr r4, r0, 16
	add r1, r4, r1
	or r4, r5, r1
	movi r1, 0
	setp.eq p0, r4, 0
	@p0 bra LBB2_5
	movi r4, 65535
LBB2_2:
	ld.global r5, [r0, r2, 0, 8]
	setp.eq p0, r5, r3
	@p0 bra LBB2_3
	ld.global r5, [r0, r2, 0, 4]
	ld.global r2, [r0, r2, 0, 0]
	shr r0, r2, 16
	shl r6, r5, 16
	or r0, r6, r0
	and r5, r4
	or r5, r2, r5
	and r2, r4
	setp.ne p0, r5, 0
	@p0 bra LBB2_2
LBB2_5:
	movi r2, 0
	ret 224
LBB2_3:
	mov r1, r0
	ret 224
Lfunc_end2:
	.size	_Z4findP4nodei, Lfunc_end2-_Z4findP4nodei

	.globl	_Z7ptrlistP4nodePi
	.type	_Z7ptrlistP4nodePi,@function
_Z7ptrlistP4nodePi:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 0
	add r15, r14
	srd r1, 0
	mov r0, r1
	mov r14, r1
	st.global r14, [r15 + -24]
	shl r0, 7
	movi r3, 2
	ld.global r1, [r3 + 36]
	st.global r1, [r15 + -12]
	add r2, r1, r0
	add r0, r2, 32
	ld.global r1, [r3 + 32]
	shl r11, r1, 16
	add r5, r11, r0
	or r3, r11, r0
	andn r3, r5
	and r0, r11, r0
	or r3, r0, r3
	add r0, r2, 16
	add r7, r11, r0
	or r4, r11, r0
	andn r4, r7
	and r0, r11, r0
	or r6, r0, r4
	add r0, r2, 80
	add r9, r11, r0
	or r4, r11, r0
	andn r4, r9
	and r0, r11, r0
	or r4, r0, r4
	add r0, r2, 64
	add r10, r11, r0
	or r8, r11, r0
	andn r8, r10
	and r0, r11, r0
	or r8, r0, r8
	add r0, r2, 48
	add r12, r11, r0
	or r13, r11, r0
	andn r13, r12
	and r0, r11, r0
	or r13, r0, r13
	mul.lo r0, r14, 10
	or r14, r0, 1
	st.global r14, [#0, r2, 0, 24]
	add r14, r0, 2
	st.global r14, [#0, r2, 0, 40]
	add r14, r0, 3
	st.global r14, [#0, r2, 0, 56]
	add r14, r0, 4
	st.global r14, [#0, r2, 0, 72]
	add r14, r0, 5
	st.global r14, [#0, r2, 0, 88]
	st.global r7, [#0, r2, 0, 0]
	st.global r5, [#0, r2, 0, 16]
	st.global r12, [#0, r2, 0, 32]
	st.global r10, [#0, r2, 0, 48]
	st.global r9, [#0, r2, 0, 64]
	shr r5, r6, 31
	shr r6, r1, 16
	add r5, r6, r5
	st.global r5, [#0, r2, 0, 4]
	shr r3, r3, 31
	add r3, r6, r3
	st.global r3, [#0, r2, 0, 20]
	shr r3, r13, 31
	add r3, r6, r3
	st.global r3, [#0, r2, 0, 36]
	shr r3, r8, 31
	add r3, r6, r3
	st.global r3, [#0, r2, 0, 52]
	shr r3, r4, 31
	add r3, r6, r3
	st.global r3, [#0, r2, 0, 68]
	add r3, r2, 96
	add r4, r11, r3
	or r5, r11, r3
	andn r5, r4
	and r3, r11, r3
	or r3, r5
	st.global r0, [#0, r2, 0, 8]
	movi r5, 2
	ld.global r5, [r5 + 44]
	st.global r5, [r15 + -28]
	add r5, r0, 6
	st.global r5, [#0, r2, 0, 104]
	shr r3, r3, 31
	add r3, r6, r3
	st.global r3, [#0, r2, 0, 84]
	st.global r4, [#0, r2, 0, 80]
	add r3, r2, 112
	and r4, r11, r3
	add r5, r11, r3
	or r3, r11, r3
	add r0, 7
	st.global r0, [#0, r2, 0, 120]
	andn r0, r3, r5
	or r0, r4, r0
	shr r0, r0, 31
	st.global r6, [r15 + -16]
	add r0, r6, r0
	st.global r0, [#0, r2, 0, 100]
	st.global r5, [#0, r2, 0, 96]
	movi r8, 0
	st.global r8, [#0, r2, 0, 116]
	st.global r8, [#0, r2, 0, 112]
	call r14, _Z7reverseP4node
	mov r12, r1
	mov r13, r2
	st.global r8, [r15 + -4]
	st.global r8, [r15 + -8]
	add r3, r15, -1
	movi r4, 65528
	call r14, _Z5tallyPK4nodeP3acc
	ld.global r10, [r15 + -24]
	and r0, r10, 7
	movi r1, 10
	mad.lo r3, r10, r1, r0
	mov r1, r12
	mov r2, r13
	call r14, _Z4findP4nodei
	mov r8, r1
	mov r7, r2
	f48 r9, 4294967295
	st.global r12, [r15 + -20]
	mov r1, r12
	mov r2, r13
	f48 r3, 4294967295
	call r14, _Z4findP4nodei
	mov r0, r10
	shl r0, 4
	ld.global r3, [r15 + -28]
	add r0, r3, r0
	ld.global r3, [r15 + -8]
	st.global r3, [#1, r0, 0, 0]
	add r0, 4
	ld.global r3, [r15 + -4]
	st.global r3, [#1, r0, 0, 0]
	shl r0, r8, 16
	add r3, r0, r7
	or r4, r0, r7
	andn r4, r3
	and r0, r7
	or r0, r4
	shr r0, r0, 31
	shr r4, r8, 16
	add r0, r4, r0
	mov r4, r10
	or r3, r0
	mov r0, r4
	shl r0, 2
	shl r4, 3
	setp.eq p0, r3, 0
	@p0 bra LBB3_2
	ld.global r9, [r8, r7, 0, 8]
LBB3_2:
	shl r0, 2
	movi r3, 2
	ld.global r3, [r3 + 44]
	add r0, r3, r0
	add r3, r0, 8
	st.global r9, [#1, r3, 0, 0]
	shl r4, 4
	ld.global r3, [r15 + -12]
	add r3, r4
	add r3, r3, 112
	and r4, r11, r3
	add r5, r11, r3
	or r3, r11, r3
	andn r3, r5
	or r3, r4, r3
	ld.global r9, [r15 + -20]
	shl r4, r9, 16
	and r6, r4, r13
	add r8, r4, r13
	or r4, r13
	andn r4, r8
	or r4, r6, r4
	xor r5, r8, r5
	shr r4, r4, 31
	shr r6, r9, 16
	add r4, r6, r4
	shr r3, r3, 31
	ld.global r6, [r15 + -16]
	add r3, r6, r3
	shl r6, r1, 16
	and r8, r6, r2
	add r9, r6, r2
	or r2, r6, r2
	xor r3, r4, r3
	or r3, r5, r3
	andn r2, r9
	or r2, r8, r2
	shr r2, r2, 31
	shr r1, r1, 16
	add r1, r2
	or r1, r9, r1
	setp.eq p0, r3, 0
	setp.eq p1, r1, 0
	movi r1, 1
	movi r2, 0
	@p1 mov r2, r1
	movi r3, 0
	@p0 mov r3, r1
	shl r3, 1
	or r1, r3, r2
	shl r7, 2
	add r2, r7, 32
	and r2, r2, 60
	or r1, r2
	add r0, 12
	st.global r1, [#1, r0, 0, 0]
	exit
Lfunc_end3:
	.size	_Z7ptrlistP4nodePi, Lfunc_end3-_Z7ptrlistP4nodePi

