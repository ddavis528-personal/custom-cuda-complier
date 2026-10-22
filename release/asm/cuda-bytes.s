	.text
	.file	"bytes.cu"
	.globl	_Z5bytesPKaPKhPhPiPKsPs
	.type	_Z5bytesPKaPKhPhPiPKsPs,@function
_Z5bytesPKaPKhPhPiPKsPs:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 2
	add r15, r14
	movi r6, 2
	ld.global r1, [r6 + 36]
	srd r0, 0
	add r2, r0, 3
	and r2, 15
	add r2, r1, r2
	chwidth r2, 2
	and r3, r0, 15
	add r3, r1, r3
	add r4, r0, 2
	and r4, 15
	add r5, r0, 1
	and r5, 15
	add r5, r1, r5
	add r4, r1, r4
	chwidth r1, 2
	movi r7, 0
	mul.lo r8, r0, 3
	ld.global r1, [#0, r3, 0, 0]
	chwidth r3, 2
	chwidth r1, 0
	shl r1, r1, 24
	sra r1, r1, 24
	ld.global r2, [#0, r2, 0, 0]
	chwidth r2, 0
	shl r2, r2, 24
	sra r2, r2, 24
	ld.global r3, [#0, r4, 0, 0]
	chwidth r4, 2
	chwidth r3, 0
	shl r3, r3, 24
	sra r3, r3, 24
	ld.global r4, [#0, r5, 0, 0]
	chwidth r4, 0
	shl r4, r4, 24
	sra r4, r4, 24
	movi r9, 128
	movi r5, 0
LBB0_1:
	add r10, r8, r7
	and r10, 15
	ld.global r11, [r6 + 36]
	add r10, r11, r10
	chwidth r10, 2
	ld.global r10, [#0, r10, 0, 0]
	chwidth r10, 0
	xor r5, r10
	and r10, r5, 128
	setp.eq p0, r10, 0
	shl r5, 1
	and r5, r5, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r5, r10, 254
	xor r10, r5, 7
	@p0 mov r10, r5
	setp.lt.u p0, r10, r9
	shl r10, 1
	and r10, r10, 254
	xor r5, r10, 7
	@p0 mov r5, r10
	add r7, 1
	setp.eq p0, r7, 4
	@!p0 bra LBB0_1
	movi r6, 0
	and r7, r0, 3
	movi r8, 2
LBB0_3:
	chwidth r10, 0
	add r10, r7, r6
	ld.global r9, [r8 + 44]
	add r9, r10
	chwidth r9, 2
	ld.global r9, [#1, r9, 0, 0]
	chwidth r9, 0
	and r11, r9, 255
	setp.eq p0, r11, 0
	@p0 bra LBB0_4
	chwidth r9, 2
	st.global r9, [r15, r6, 0, -16]
	chwidth r9, 0
	ld.global r9, [r8 + 44]
	add r11, r10, r9
	add r9, r6, 1
	add r11, 1
	chwidth r11, 2
	ld.global r11, [#1, r11, 0, 0]
	chwidth r11, 0
	and r12, r11, 255
	setp.eq p0, r12, 0
	@p0 bra LBB0_9
	chwidth r11, 2
	st.global r11, [r15, r9, 0, -16]
	chwidth r11, 0
	ld.global r9, [r8 + 44]
	add r10, r9
	add r9, r6, 2
	add r10, 2
	chwidth r10, 2
	ld.global r10, [#1, r10, 0, 0]
	chwidth r10, 0
	and r11, r10, 255
	setp.eq p0, r11, 0
	@p0 bra LBB0_9
	chwidth r10, 2
	st.global r10, [r15, r9, 0, -16]
	add r6, 3
	setp.eq p0, r6, 15
	@!p0 bra LBB0_3
	movi r9, 15
	bra.short LBB0_9
LBB0_4:
	mov r9, r6
LBB0_9:
	movi r6, 0
	chwidth r6, 2
	st.global r6, [r15, r9, 0, -16]
	chwidth r6, 0
	f48 r8, 4294967294
	f48 r6, 4294966296
LBB0_10:
	chwidth.multi 1024, 0
	add r6, r6, 1000
	add r7, r8, 1
	add r8, 2
	chwidth r8, 2
	ld.global r8, [r15, r8, 0, -16]
	chwidth r8, 0
	and r8, r8, 255
	setp.ne p0, r8, 0
	mov r8, r7
	@p0 bra LBB0_10
	movi r8, 2
	ld.global r9, [r8 + 52]
	add r9, r0
	mul.lo r10, r0, 7
	chwidth r10, 1
	add r10, r10, 1
	chwidth r10, 2
	st.global r10, [#2, r9, 0, 0]
	chwidth r10, 0
	ld.global r10, [r8 + 68]
	mov r9, r0
	shl r9, 1
	add r10, r9
	chwidth r10, 1
	ld.global r10, [#4, r10, 0, 0]
	chwidth r10, 0
	setp.eq p0, r10, 0
	@p0 bra LBB0_13
	chwidth r10, 1
	ld.global r11, [r8 + 76]
	add r9, r11, r9
	st.global r10, [#5, r9, 0, 0]
LBB0_13:
	chwidth r14, 1
	add r14, r0, -56
	chwidth r14, 2
	st.shared r14, [r0 + 0]
	add r1, r4
	add r1, r3
	add r1, r2
	bar.arrive 0
	bar.wait 0
	ld.global r2, [r8 + 60]
	mov r3, r0
	shl r3, 4
	add r2, r3
	movi r3, 31
	sub r0, r3, r0
	chwidth r0, 2
	ld.shared r0, [r0 + 0]
	chwidth r0, 0
	st.global r1, [#3, r2, 0, 0]
	add r1, r2, 4
	st.global r5, [#3, r1, 0, 0]
	chwidth r1, 2
	ld.global r1, [r15, r7, 0, -16]
	chwidth r1, 0
	add r1, r6
	add r3, r2, 8
	st.global r1, [#3, r3, 0, 0]
	add r1, r2, 12
	st.global r0, [#3, r1, 0, 0]
	exit
Lfunc_end0:
	.size	_Z5bytesPKaPKhPhPiPKsPs, Lfunc_end0-_Z5bytesPKaPKhPhPiPKsPs

