	.text
	.file	"bytes.cu"
	.globl	_Z5bytesPKaPKhPhPiPKsPs
	.type	_Z5bytesPKaPKhPhPiPKsPs,@function
_Z5bytesPKaPKhPhPiPKsPs:
	movi r15, 2
	ld.global r15, [r15 + 24]
	srd r14, 2
	add r15, r14
	movi r14, 0
	srd r0, 0
	mul.lo r1, r0, 3
	movi r3, 2
	ld.global r2, [r3 + 76]
	st.local r2, [32]
	ld.global r2, [r3 + 72]
	st.local r2, [28]
	ld.global r2, [r3 + 68]
	st.local r2, [16]
	ld.global r2, [r3 + 64]
	st.local r2, [12]
	ld.global r9, [r3 + 52]
	ld.global r7, [r3 + 48]
	ld.global r11, [r3 + 44]
	ld.global r12, [r3 + 40]
	add r2, r0, 3
	and r4, r2, 15
	add r2, r0, 2
	and r5, r2, 15
	add r2, r0, 1
	and r6, r2, 15
	ld.global r2, [r3 + 36]
	add r10, r2, r6
	add r5, r2, r5
	add r4, r2, r4
	and r6, r0, 15
	add r6, r2, r6
	ld.global r3, [r3 + 32]
	ld.global.s8 r8, [r3, r6, 0, 0]
	ld.global.s8 r4, [r3, r4, 0, 0]
	st.local r4, [20]
	ld.global.s8 r4, [r3, r5, 0, 0]
	st.local r4, [24]
	ld.global.s8 r10, [r3, r10, 0, 0]
	movi r4, 128
	movi r13, 0
LBB0_1:
	add r5, r1, r14
	and r5, 15
	add r5, r2, r5
	ld.global.u8 r5, [r3, r5, 0, 0]
	xor r5, r13, r5
	and r13, r5, 128
	setp.eq p0, r13, 0
	shl r5, 1
	and r5, r5, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	setp.lt.u p0, r13, r4
	shl r13, 1
	and r5, r13, 254
	xor r13, r5, 7
	@p0 mov r13, r5
	add r14, 1
	setp.eq p0, r14, 4
	@!p0 bra LBB0_1
	movi r1, 0
	and r2, r0, 3
	movi r3, 65520
LBB0_3:
	add r4, r2, r1
	add r5, r11, r4
	ld.global.u8 r5, [r12, r5, 0, 0]
	setp.eq p0, r5, 0
	@p0 bra LBB0_4
	add r14, r3, r1
	add r6, r15, -1
	st.global.8 r5, [r6, r14, 0, 0]
	add r14, r4, r11
	add r4, r14, 1
	ld.global.u8 r5, [r12, r4, 0, 0]
	add r4, r1, 1
	setp.eq p0, r5, 0
	@p0 bra LBB0_9
	add r4, r3, r4
	add r6, r15, -1
	st.global.8 r5, [r6, r4, 0, 0]
	add r4, r14, 2
	ld.global.u8 r5, [r12, r4, 0, 0]
	add r4, r1, 2
	setp.eq p0, r5, 0
	@p0 bra LBB0_9
	add r4, r3, r4
	add r6, r15, -1
	st.global.8 r5, [r6, r4, 0, 0]
	add r1, 3
	setp.eq p0, r1, 15
	@!p0 bra LBB0_3
	movi r4, 15
	bra.short LBB0_9
LBB0_4:
	mov r4, r1
LBB0_9:
	movi r3, 65520
	add r1, r3, r4
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
	add r3, r9, r0
	mul.lo r4, r0, 7
	add r4, 1
	st.global.8 r4, [r7, r3, 0, 0]
	mov r3, r0
	shl r3, 1
	ld.local r4, [16]
	add r4, r3
	ld.local r5, [12]
	ld.global.u16 r4, [r5, r4, 0, 0]
	setp.eq p0, r4, 0
	@p0 bra LBB0_13
	ld.local r5, [32]
	add r3, r5, r3
	ld.local r5, [28]
	st.global.16 r4, [r5, r3, 0, 0]
LBB0_13:
	add r3, r0, -56
	movi r4, 0
	st.shared.8 r3, [r0, r4, 0, 0]
	add r3, r8, r10
	movi r5, 31
	sub r5, r0
	bar.arrive 0
	bar.wait 0
	ld.shared.u8 r4, [r5, r4, 0, 0]
	ld.local r5, [24]
	add r3, r5
	ld.local r5, [20]
	add r3, r5
	shl r0, 4
	movi r5, 2
	ld.global r5, [r5 + 60]
	add r0, r5, r0
	st.global r3, [#3, r0, 0, 0]
	add r3, r0, 4
	st.global r13, [#3, r3, 0, 0]
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

