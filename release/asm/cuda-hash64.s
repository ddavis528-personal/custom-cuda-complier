	.text
	.file	"hash64.cu"
	.globl	_Z6hash64PKjPKhPji
	.type	_Z6hash64PKjPKhPji,@function
_Z6hash64PKjPKhPji:
	movi r0, 2
	ld.global r0, [r0 + 56]
	srd r3, 0
	setp.le p0, r0, r3
	@p0 bra LBB0_2
	mov r0, r3
	shl r0, 2
	movi r1, 2
	ld.global r1, [r1 + 36]
	add r0, r1, r0
	ld.global r1, [#0, r0, 0, 0]
	f48 r0, 2135587861
	add r4, r3, r0
	setp.lt.u p0, r4, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r2, 2654435769
	add r12, r0, r2
	f48 r0, 2064213139
	add r9, r3, r0
	setp.lt.u p0, r9, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r2, 1401181202
	add r5, r0, r2
	st.local r5, [12]
	f48 r0, 4199801000
	add r10, r3, r0
	setp.lt.u p0, r10, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r2, 4055616971
	add r7, r0, r2
	st.local r7, [16]
	mov r0, r5
	shl r0, 2
	shr r2, r9, 30
	or r0, r2, r0
	st.local r0, [20]
	mov r0, r12
	shl r0, 2
	shr r2, r4, 30
	or r0, r2, r0
	st.local r0, [24]
	f48 r0, 4271175722
	add r0, r3, r0
	st.local r0, [28]
	setp.lt.u p0, r0, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r2, 1013904242
	add r14, r0, r2
	f48 r0, 4223592574
	add r15, r3, r0
	setp.lt.u p0, r15, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r2, 3041712728
	add r2, r0, r2
	f48 r0, 2111796287
	add r0, r3, r0
	st.local r0, [48]
	setp.lt.u p0, r0, r3
	mov r0, r1
	@p0 add r0, r0, 1
	f48 r5, 3668340012
	add r6, r0, r5
	st.local r6, [32]
	mov r0, r7
	shl r0, 2
	shr r5, r10, 30
	or r0, r5, r0
	st.local r0, [36]
	f48 r0, 2088004713
	add r0, r3, r0
	setp.lt.u p0, r0, r3
	mov r5, r1
	@p0 add r5, r5, 1
	add r7, r5, 387276959
	mov r11, r7
	shl r11, 2
	shr r13, r0, 30
	or r5, r13, r11
	st.local r5, [56]
	f48 r11, 4247384148
	add r5, r3, r11
	st.local r5, [52]
	setp.lt.u p0, r5, r3
	@p0 add r1, r1, 1
	mov r13, r2
	shl r13, 2
	shr r8, r15, 30
	or r8, r13
	shr r13, r12, 30
	xor r5, r13, r12
	st.local r5, [64]
	mov r12, r14
	shl r12, 2
	ld.local r5, [28]
	shr r13, r5, 30
	or r11, r13, r12
	st.local r11, [72]
	ld.local r11, [24]
	xor r4, r11, r4
	ld.local r11, [20]
	xor r13, r11, r9
	shr r9, r14, 30
	xor r9, r14
	st.local r9, [40]
	ld.local r11, [12]
	shr r9, r11, 30
	xor r9, r11
	st.local r9, [60]
	shr r9, r2, 30
	xor r2, r9, r2
	st.local r2, [68]
	xor r15, r8, r15
	f48 r8, 2027808485
	add r2, r1, r8
	st.local r2, [44]
	ld.local r1, [56]
	xor r14, r1, r0
	ld.local r0, [36]
	xor r0, r10
	st.local r0, [20]
	shl r6, 2
	ld.local r10, [48]
	shr r1, r10, 30
	or r0, r1, r6
	st.local r0, [56]
	shl r3, 4
	movi r0, 2
	ld.global r8, [r0 + 52]
	ld.global r1, [r0 + 44]
	add r0, r1, r3
	st.local r0, [24]
	add r0, r8, r3
	st.local r0, [12]
	f48 r12, 3210233709
	f48 r9, 484763065
	mul.hi.u r3, r4, r9
	mad.acc r3, r4, r12
	ld.local r0, [64]
	mad.lo r0, r0, r9, r3
	ld.local r1, [72]
	xor r11, r1, r5
	shr r6, r7, 30
	xor r1, r6, r7
	st.local r1, [64]
	shl r2, 2
	ld.local r7, [52]
	shr r8, r7, 30
	or r1, r8, r2
	st.local r1, [72]
	mul.hi.u r8, r15, r9
	mad.acc r8, r15, r12
	ld.local r1, [68]
	mad.lo r6, r1, r9, r8
	st.local r6, [36]
	mul.hi.u r2, r13, r9
	mad.acc r2, r13, r12
	ld.local r1, [60]
	mad.lo r3, r1, r9, r2
	st.local r3, [28]
	ld.local r5, [16]
	shr r2, r5, 30
	xor r1, r2, r5
	st.local r1, [16]
	mul.hi.u r2, r11, r9
	mad.acc r2, r11, r12
	ld.local r1, [40]
	mad.acc r2, r1, r9
	mul.lo r5, r4, r9
	mov r4, r0
	shl r4, 5
	shr r8, r5, 27
	or r1, r8, r4
	st.local r1, [60]
	mul.hi.u r4, r14, r9
	mad.acc r4, r14, r12
	ld.local r1, [64]
	mad.lo r1, r1, r9, r4
	st.local r1, [40]
	ld.local r4, [56]
	xor r4, r10
	ld.local r8, [72]
	xor r8, r7
	shr r7, r0, 27
	xor r0, r7, r0
	st.local r0, [48]
	ld.local r7, [20]
	mul.hi.u r0, r7, r9
	mad.acc r0, r7, r12
	ld.local r7, [16]
	mad.acc r0, r7, r9
	st.local r0, [16]
	mul.lo r7, r13, r9
	st.local r7, [52]
	shl r3, 5
	shr r7, r7, 27
	or r0, r7, r3
	st.local r0, [56]
	mul.lo r7, r15, r9
	shl r6, 5
	shr r10, r7, 27
	or r6, r10, r6
	mul.lo r14, r9
	shl r1, 5
	shr r10, r14, 27
	or r0, r10, r1
	st.local r0, [64]
	ld.local r0, [60]
	xor r13, r0, r5
	mul.lo r0, r11, r9
	mov r3, r2
	shl r3, 5
	shr r5, r0, 27
	or r3, r5, r3
	ld.local r1, [44]
	shr r5, r1, 30
	xor r5, r1
	mul.hi.u r10, r8, r9
	mad.acc r10, r8, r12
	mul.hi.u r11, r4, r9
	mad.lo r12, r4, r12, r11
	ld.local r15, [32]
	shr r11, r15, 30
	xor r15, r11, r15
	shr r11, r2, 27
	xor r1, r11, r2
	st.local r1, [44]
	mad.lo r5, r5, r9, r10
	xor r10, r3, r0
	f48 r1, 2496678331
	f48 r2, 321982955
	mul.hi.u r0, r13, r2
	mad.acc r0, r13, r1
	f48 r11, 2496678331
	ld.local r1, [48]
	mad.acc r0, r1, r2
	mad.lo r15, r15, r9, r12
	ld.local r1, [64]
	xor r1, r14
	st.local r1, [32]
	xor r14, r6, r7
	ld.local r1, [52]
	ld.local r3, [56]
	xor r1, r3, r1
	ld.local r3, [20]
	mul.lo r7, r3, r9
	ld.local r3, [16]
	shl r3, 5
	shr r6, r7, 27
	or r3, r6, r3
	st.local r3, [20]
	mul.lo r3, r8, r9
	mul.lo r8, r4, r9
	mul.hi.u r4, r10, r2
	mad.acc r4, r10, r11
	ld.local r6, [44]
	mad.lo r6, r6, r2, r4
	shr r4, r5, 27
	xor r4, r5
	shl r5, 5
	shr r9, r3, 27
	or r5, r9, r5
	xor r3, r5, r3
	mul.hi.u r5, r3, r2
	mad.acc r5, r3, r11
	f48 r12, 2496678331
	mad.lo r11, r4, r2, r5
	shr r5, r6, 31
	xor r4, r5, r6
	st.local r4, [44]
	shl r6, 1
	mul.lo r10, r2
	shr r5, r10, 31
	or r4, r5, r6
	st.local r4, [48]
	shr r5, r0, 31
	xor r4, r5, r0
	st.local r4, [56]
	shl r0, 1
	mul.lo r4, r13, r2
	shr r5, r4, 31
	or r0, r5, r0
	st.local r0, [60]
	ld.local r0, [40]
	shr r5, r0, 27
	xor r6, r5, r0
	ld.local r0, [36]
	shr r5, r0, 27
	xor r5, r0
	ld.local r0, [28]
	shr r13, r0, 27
	xor r13, r0
	shr r9, r15, 27
	xor r9, r15
	shl r15, 5
	shr r0, r8, 27
	or r0, r15
	xor r8, r0, r8
	ld.local r0, [20]
	xor r7, r0, r7
	st.local r1, [52]
	mul.hi.u r0, r1, r2
	mad.acc r0, r1, r12
	mad.lo r15, r13, r2, r0
	mul.hi.u r0, r14, r2
	mad.acc r0, r14, r12
	mov r12, r14
	mad.lo r5, r5, r2, r0
	ld.local r1, [32]
	mul.hi.u r0, r1, r2
	f48 r14, 2496678331
	mad.acc r0, r1, r14
	mad.lo r6, r6, r2, r0
	ld.local r0, [44]
	ld.local r13, [56]
	add r13, r0, r13
	mul.hi.u r0, r8, r2
	mad.acc r0, r8, r14
	mad.lo r9, r9, r2, r0
	ld.local r0, [60]
	xor r0, r4
	st.local r0, [36]
	ld.local r0, [48]
	xor r0, r10
	mul.lo r10, r3, r2
	mov r3, r11
	shl r3, 1
	shr r4, r10, 31
	or r3, r4, r3
	st.local r3, [40]
	mul.hi.u r3, r7, r2
	mad.acc r3, r7, r14
	st.local r3, [44]
	ld.local r4, [16]
	shr r3, r4, 27
	xor r3, r4
	shr r4, r11, 31
	xor r4, r11
	st.local r4, [16]
	mul.lo r1, r2
	mov r4, r6
	shl r4, 1
	shr r14, r1, 31
	or r4, r14, r4
	st.local r4, [20]
	mul.lo r4, r12, r2
	mov r14, r5
	shl r14, 1
	shr r11, r4, 31
	or r11, r14
	st.local r11, [28]
	ld.local r11, [52]
	mul.lo r11, r2
	mov r14, r15
	shl r14, 1
	shr r12, r11, 31
	or r12, r14
	ld.local r14, [40]
	xor r10, r14, r10
	ld.local r14, [44]
	mad.acc r14, r3, r2
	mul.lo r3, r8, r2
	mul.lo r2, r7, r2
	ld.local r7, [36]
	add r7, r0, r7
	setp.lt.u p0, r7, r0
	@p0 add r13, r13, 1
	shr r0, r9, 31
	xor r0, r9
	add r0, r13
	shl r9, 1
	shr r8, r3, 31
	or r8, r9
	xor r3, r8, r3
	add r7, r3, r7
	setp.lt.u p0, r7, r3
	@p0 add r0, r0, 1
	shr r3, r15, 31
	xor r3, r15
	shr r8, r5, 31
	xor r5, r8, r5
	shr r8, r6, 31
	xor r6, r8, r6
	ld.local r8, [16]
	add r8, r0
	xor r9, r12, r11
	ld.local r0, [28]
	xor r4, r0, r4
	ld.local r0, [20]
	xor r11, r0, r1
	chwidth r1, 2
	shr r0, r14, 31
	xor r12, r0, r14
	shl r14, 1
	shr r0, r2, 31
	or r0, r14
	xor r0, r2
	st.local r0, [40]
	add r2, r10, r7
	setp.lt.u p0, r2, r10
	@p0 add r8, r8, 1
	add r6, r8
	chwidth r8, 2
	add r2, r11, r2
	setp.lt.u p0, r2, r11
	chwidth r7, 2
	@p0 add r6, r6, 1
	add r5, r6
	chwidth r6, 2
	add r2, r4, r2
	setp.lt.u p0, r2, r4
	@p0 add r5, r5, 1
	add r3, r5
	chwidth r5, 2
	add r11, r9, r2
	setp.lt.u p0, r11, r9
	chwidth r9, 2
	@p0 add r3, r3, 1
	add r10, r12, r3
	ld.local r0, [24]
	add r2, r0, 15
	ld.global r1, [#1, r2, 0, 0]
	chwidth r1, 0
	st.local r1, [16]
	chwidth r1, 2
	add r2, r0, 14
	ld.global r1, [#1, r2, 0, 0]
	chwidth r1, 0
	st.local r1, [20]
	chwidth r1, 2
	add r2, r0, 13
	ld.global r1, [#1, r2, 0, 0]
	chwidth r1, 0
	st.local r1, [28]
	chwidth r1, 2
	add r2, r0, 12
	ld.global r1, [#1, r2, 0, 0]
	chwidth r1, 0
	st.local r1, [32]
	chwidth r1, 2
	add r2, r0, 11
	ld.global r1, [#1, r2, 0, 0]
	chwidth r1, 0
	st.local r1, [36]
	add r2, r0, 10
	ld.global r7, [#1, r2, 0, 0]
	chwidth r7, 0
	add r2, r0, 9
	ld.global r8, [#1, r2, 0, 0]
	chwidth r8, 0
	add r2, r0, 8
	ld.global r9, [#1, r2, 0, 0]
	chwidth r9, 0
	add r2, r0, 7
	ld.global r6, [#1, r2, 0, 0]
	chwidth r6, 0
	chwidth r2, 2
	add r12, r0, 6
	ld.global r5, [#1, r12, 0, 0]
	chwidth r5, 0
	add r12, r0, 5
	ld.global r2, [#1, r12, 0, 0]
	chwidth r2, 0
	add r12, r0, 4
	chwidth r12, 2
	ld.global r12, [#1, r12, 0, 0]
	chwidth r12, 0
	add r13, r0, 3
	chwidth r13, 2
	ld.global r13, [#1, r13, 0, 0]
	chwidth r13, 0
	add r14, r0, 2
	chwidth r14, 2
	mov r1, r0
	chwidth r0, 2
	ld.global r14, [#1, r14, 0, 0]
	chwidth r14, 0
	add r15, r1, 1
	chwidth r1, 2
	ld.global r0, [#1, r15, 0, 0]
	chwidth r0, 0
	ld.global r1, [#1, r1, 0, 0]
	chwidth r1, 0
	ld.local r3, [40]
	add r11, r3, r11
	ld.local r15, [12]
	st.global r11, [#2, r15, 0, 0]
	setp.lt.u p0, r11, r3
	@p0 add r10, r10, 1
	add r11, r15, 4
	mov r3, r15
	st.global r10, [#2, r11, 0, 0]
	f48 r10, 2216829733
	xor r15, r1, r10
	mul.lo r1, r15, 435
	xor r4, r1, r0
	mul.lo r1, r4, 435
	xor r14, r1, r14
	mul.lo r1, r14, 435
	xor r13, r1, r13
	mul.lo r1, r13, 435
	xor r12, r1, r12
	mul.lo r1, r12, 435
	xor r11, r1, r2
	mul.lo r1, r11, 435
	xor r1, r5
	mul.lo r2, r1, 435
	xor r10, r2, r6
	mul.lo r2, r10, 435
	xor r9, r2, r9
	mul.lo r2, r9, 435
	xor r8, r2, r8
	mul.lo r2, r8, 435
	xor r7, r2, r7
	mul.lo r2, r7, 435
	ld.local r0, [36]
	xor r6, r2, r0
	mul.lo r2, r6, 435
	ld.local r0, [32]
	xor r5, r2, r0
	mul.lo r2, r5, 435
	ld.local r0, [28]
	xor r0, r2, r0
	st.local r0, [24]
	mul.lo r2, r0, 435
	ld.local r0, [20]
	xor r0, r2, r0
	st.local r0, [20]
	mul.lo r2, r0, 435
	ld.local r0, [16]
	xor r0, r2, r0
	st.local r0, [16]
	add r2, r3, 8
	mul.lo r3, r0, 435
	st.global r3, [#2, r2, 0, 0]
	movi r2, 435
	mul.hi.u r3, r4, r2
	shl r4, 8
	add r0, r3, r4
	mul.hi.u r3, r15, r2
	shl r15, 8
	or r3, r15
	mad.acc r0, r3, r2
	mul.hi.u r3, r14, r2
	shl r14, 8
	add r3, r14
	mad.lo r0, r0, r2, r3
	mul.hi.u r3, r13, r2
	shl r13, 8
	add r3, r13
	mad.lo r0, r0, r2, r3
	mul.hi.u r3, r12, r2
	shl r12, 8
	add r3, r12
	mad.lo r0, r0, r2, r3
	mul.hi.u r3, r11, r2
	shl r11, 8
	add r3, r11
	mad.lo r0, r0, r2, r3
	mul.hi.u r3, r1, r2
	shl r1, 8
	add r1, r3, r1
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r10, r2
	shl r10, 8
	add r1, r10
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r9, r2
	shl r9, 8
	add r1, r9
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r8, r2
	shl r8, 8
	add r1, r8
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r7, r2
	shl r7, 8
	add r1, r7
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r6, r2
	shl r6, 8
	add r1, r6
	mad.lo r0, r0, r2, r1
	mul.hi.u r1, r5, r2
	shl r5, 8
	add r1, r5
	mad.lo r0, r0, r2, r1
	ld.local r3, [24]
	mul.hi.u r1, r3, r2
	shl r3, 8
	add r1, r3
	mad.lo r0, r0, r2, r1
	ld.local r3, [20]
	mul.hi.u r1, r3, r2
	shl r3, 8
	add r1, r3
	mad.lo r0, r0, r2, r1
	ld.local r3, [16]
	mul.hi.u r1, r3, r2
	shl r3, 8
	add r1, r3
	mad.lo r0, r0, r2, r1
	f48 r1, 1375942116
	add r0, r1
	ld.local r1, [12]
	add r1, 12
	st.global r0, [#2, r1, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z6hash64PKjPKhPji, Lfunc_end0-_Z6hash64PKjPKhPji

