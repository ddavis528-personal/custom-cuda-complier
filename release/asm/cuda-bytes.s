	.text
	.file	"bytes.cu"
	.globl	_Z5bytesPKaPKhPhPiPKsPs
	.type	_Z5bytesPKaPKhPhPiPKsPs,@function
_Z5bytesPKaPKhPhPiPKsPs:
	chwidth.multi 12288, 1
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 2
	add r15, r14
	movi r2, 0
	srd r0, 0
	mul.lo r3, r0, 3
	movi r5, 2
	ld.global r1, [r5 + 76]
	st.local r1, [40]
	ld.global r1, [r5 + 72]
	st.local r1, [36]
	ld.global r1, [r5 + 68]
	st.local r1, [20]
	ld.global r1, [r5 + 64]
	st.local r1, [16]
	ld.global r10, [r5 + 52]
	ld.global r1, [r5 + 48]
	st.local r1, [32]
	ld.global r14, [r5 + 44]
	ld.global r1, [r5 + 40]
	add r4, r0, 3
	and r6, r4, 15
	add r4, r0, 2
	and r7, r4, 15
	add r4, r0, 1
	and r9, r4, 15
	ld.global r4, [r5 + 36]
	add r9, r4, r9
	add r7, r4, r7
	add r6, r4, r6
	and r11, r0, 15
	add r11, r4, r11
	ld.global r5, [r5 + 32]
	ld.global.s8 r8, [r5, r11, 0, 0]
	st.local r8, [28]
	ld.global.s8 r6, [r5, r6, 0, 0]
	st.local r6, [12]
	ld.global.s8 r6, [r5, r7, 0, 0]
	st.local r6, [24]
	ld.global.s8 r9, [r5, r9, 0, 0]
	movi r6, 128
	movi r11, 0
LBB0_1:
	add r7, r3, r2
	and r7, 15
	add r7, r4, r7
	ld.global.u8 r7, [r5, r7, 0, 0]
	xor r7, r11, r7
	and r11, r7, 128
	setp.eq p0, r11, 0
	shl r7, 1
	and r7, r7, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	setp.lt.u p0, r11, r6
	shl r11, 1
	and r7, r11, 254
	xor r11, r7, 7
	@p0 mov r11, r7
	add r2, 1
	setp.eq p0, r2, 4
	@!p0 bra LBB0_1
	movi r2, 0
	and r3, r0, 3
	movi r4, 65520
LBB0_3:
	add r5, r3, r2
	add r6, r14, r5
	ld.global.u8 r6, [r1, r6, 0, 0]
	setp.eq p0, r6, 0
	@p0 bra LBB0_4
	add r13, r6, 0
	add r6, r4, r2
	add r7, r15, -1
	st.global.8 r13, [r7, r6, 0, 0]
	add r6, r5, r14
	add r5, r6, 1
	ld.global.u8 r7, [r1, r5, 0, 0]
	add r5, r2, 1
	setp.eq p0, r7, 0
	@p0 bra LBB0_9
	add r13, r7, 0
	add r5, r4, r5
	add r7, r15, -1
	st.global.8 r13, [r7, r5, 0, 0]
	add r5, r6, 2
	ld.global.u8 r6, [r1, r5, 0, 0]
	add r5, r2, 2
	setp.eq p0, r6, 0
	@p0 bra LBB0_9
	add r13, r6, 0
	add r5, r4, r5
	add r6, r15, -1
	st.global.8 r13, [r6, r5, 0, 0]
	add r2, 3
	setp.eq p0, r2, 15
	@!p0 bra LBB0_3
	movi r5, 15
	bra.short LBB0_9
LBB0_4:
	mov r5, r2
LBB0_9:
	movi r3, 65520
	add r1, r3, r5
	add r2, r15, -1
	movi r4, 0
	st.global.8 r4, [r2, r1, 0, 0]
	f48 r2, 4294967294
	f48 r1, 4294966296
	add r5, r15, -1
LBB0_10:
	add r4, r2, r3
	add r4, 2
	ld.global.u8 r4, [r5, r4, 0, 0]
	add r1, r1, 1000
	add r2, 1
	setp.ne p0, r4, 0
	@p0 bra LBB0_10
	add r3, r10, r0
	mul.lo r4, r0, 7
	add r13, r4, 0
	add r13, r13, 1
	add r4, r13, 0
	ld.local r5, [32]
	st.global.8 r4, [r5, r3, 0, 0]
	mov r3, r0
	shl r3, 1
	ld.local r4, [20]
	add r4, r3
	ld.local r5, [16]
	ld.global.u16 r12, [r5, r4, 0, 0]
	add r13, r0, 0
	add r4, r12, 0
	setp.eq p0, r4, 0
	@p0 bra LBB0_13
	ld.local r4, [40]
	add r3, r4, r3
	ld.local r4, [36]
	st.global.16 r12, [r4, r3, 0, 0]
LBB0_13:
	add r13, r13, -56
	add r3, r13, 0
	movi r4, 0
	st.shared.8 r3, [r0, r4, 0, 0]
	ld.local r3, [28]
	add r3, r9
	movi r5, 31
	sub r5, r0
	bar.arrive 0
	bar.wait 0
	ld.shared.u8 r4, [r5, r4, 0, 0]
	ld.local r5, [24]
	add r3, r5
	ld.local r5, [12]
	add r3, r5
	shl r0, 4
	movi r5, 2
	ld.global r5, [r5 + 60]
	add r0, r5, r0
	st.global r3, [#3, r0, 0, 0]
	add r3, r0, 4
	st.global r11, [#3, r3, 0, 0]
	movi r3, 65520
	add r2, r3, r2
	add r3, r15, -1
	ld.global.u8 r2, [r3, r2, 0, 0]
	add r1, r2, r1
	add r2, r0, 8
	st.global r1, [#3, r2, 0, 0]
	add r0, 12
	st.global r4, [#3, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z5bytesPKaPKhPhPiPKsPs, Lfunc_end0-_Z5bytesPKaPKhPhPiPKsPs

