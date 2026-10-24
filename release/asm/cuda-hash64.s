	.text
	.file	"hash64.cu"
	.globl	_Z6hash64PKjPKhPji
	.type	_Z6hash64PKjPKhPji,@function
_Z6hash64PKjPKhPji:
	movi r0, 2
	ld.global r0, [r0 + 56]
	srd r2, 0
	setp.le p0, r0, r2
	@p0 bra LBB0_2
	mov r0, r2
	shl r0, 2
	movi r1, 2
	ld.global r1, [r1 + 36]
	add r0, r1, r0
	ld.global r0, [#0, r0, 0, 0]
	f48 r1, 2064213139
	add r1, r2, r1
	st.local r1, [12]
	setp.lt.u p0, r1, r2
	mov r1, r0
	@p0 add r1, r1, 1
	f48 r3, 1401181202
	add r10, r1, r3
	st.local r10, [104]
	f48 r1, 4199801000
	add r1, r2, r1
	st.local r1, [24]
	setp.lt.u p0, r1, r2
	mov r1, r0
	@p0 add r1, r1, 1
	f48 r4, 4055616971
	add r13, r1, r4
	st.local r13, [100]
	f48 r1, 2111796287
	add r3, r2, r1
	setp.lt.u p0, r3, r2
	mov r7, r3
	st.local r7, [40]
	mov r1, r0
	@p0 add r1, r1, 1
	f48 r4, 3668340012
	add r3, r1, r4
	st.local r3, [96]
	f48 r1, 4271175722
	add r15, r2, r1
	setp.lt.u p0, r15, r2
	mov r1, r0
	@p0 add r1, r1, 1
	f48 r5, 1013904242
	add r4, r1, r5
	f48 r1, 4223592574
	add r1, r2, r1
	st.local r1, [32]
	setp.lt.u p0, r1, r2
	mov r1, r0
	@p0 add r1, r1, 1
	f48 r5, 3041712728
	add r1, r5
	st.local r1, [16]
	ld.local r1, [16]
	f48 r1, 2088004713
	add r12, r2, r1
	setp.lt.u p0, r12, r2
	mov r5, r0
	@p0 add r5, r5, 1
	f48 r1, 4247384148
	add r8, r2, r1
	f48 r6, 2135587861
	add r14, r2, r6
	setp.lt.u p0, r14, r2
	mov r6, r0
	@p0 add r6, r6, 1
	setp.lt.u p0, r8, r2
	@p0 add r0, r0, 1
	add r9, r5, 387276959
	mov r5, r9
	shl r5, 2
	shr r11, r12, 30
	or r1, r11, r5
	st.local r1, [36]
	shl r3, 2
	shr r11, r7, 30
	or r1, r11, r3
	st.local r1, [44]
	mov r5, r13
	shl r5, 2
	ld.local r7, [24]
	shr r13, r7, 30
	or r1, r13, r5
	st.local r1, [48]
	mov r13, r10
	shl r13, 2
	ld.local r1, [12]
	shr r11, r1, 30
	or r3, r11, r13
	st.local r3, [20]
	mov r13, r4
	shl r13, 2
	shr r10, r15, 30
	or r10, r13
	f48 r13, 2654435769
	add r13, r6, r13
	f48 r6, 2027808485
	add r0, r6
	st.local r0, [28]
	shl r0, 2
	shr r6, r8, 30
	or r11, r6, r0
	ld.local r6, [16]
	shl r6, 2
	ld.local r0, [32]
	shr r5, r0, 30
	or r5, r6
	mov r6, r13
	shl r6, 2
	shr r3, r14, 30
	or r3, r6
	shr r6, r4, 30
	xor r4, r6, r4
	st.local r4, [116]
	xor r6, r10, r15
	shr r4, r9, 30
	xor r4, r9
	st.local r4, [108]
	shr r4, r13, 30
	xor r4, r13
	st.local r4, [112]
	ld.local r4, [20]
	xor r1, r4, r1
	st.local r1, [20]
	ld.local r1, [48]
	xor r13, r1, r7
	ld.local r1, [40]
	ld.local r4, [44]
	xor r9, r4, r1
	ld.local r1, [36]
	xor r10, r1, r12
	xor r15, r3, r14
	xor r0, r5, r0
	st.local r0, [24]
	xor r12, r11, r8
	shl r2, 4
	movi r3, 2
	ld.global r0, [r3 + 44]
	add r0, r2
	add r1, r0, 15
	ld.global r3, [r3 + 40]
	movi r4, 2
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [32]
	add r1, r0, 14
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [36]
	add r1, r0, 13
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [40]
	add r1, r0, 12
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [44]
	add r1, r0, 11
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [48]
	add r1, r0, 10
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [52]
	add r1, r0, 9
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [56]
	add r1, r0, 8
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [60]
	add r1, r0, 7
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [64]
	add r1, r0, 6
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [68]
	add r1, r0, 5
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [72]
	add r1, r0, 4
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [76]
	add r1, r0, 3
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [80]
	add r1, r0, 2
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [84]
	add r1, r0, 1
	ld.global.u8 r1, [r3, r1, 0, 0]
	st.local r1, [88]
	ld.global.u8 r0, [r3, r0, 0, 0]
	st.local r0, [92]
	ld.global r0, [r4 + 52]
	add r0, r2
	st.local r0, [12]
	f48 r1, 3210233709
	f48 r3, 484763065
	mov r14, r6
	mul.hi.u r0, r14, r3
	mad.acc r0, r14, r1
	ld.local r2, [116]
	mad.lo r6, r2, r3, r0
	ld.local r4, [96]
	shr r2, r4, 30
	xor r2, r4
	ld.local r5, [100]
	shr r4, r5, 30
	xor r5, r4, r5
	ld.local r7, [104]
	shr r4, r7, 30
	xor r4, r7
	st.local r15, [136]
	mul.hi.u r8, r15, r3
	mad.acc r8, r15, r1
	ld.local r0, [112]
	mad.acc r8, r0, r3
	mov r0, r10
	st.local r0, [132]
	mul.hi.u r10, r0, r3
	mad.acc r10, r0, r1
	ld.local r0, [108]
	mad.lo r0, r0, r3, r10
	st.local r0, [100]
	st.local r9, [128]
	mul.hi.u r10, r9, r3
	mad.acc r10, r9, r1
	st.local r13, [124]
	mul.hi.u r15, r13, r3
	mad.acc r15, r13, r1
	ld.local r9, [20]
	mul.hi.u r7, r9, r3
	mad.acc r7, r9, r1
	st.local r12, [120]
	mul.hi.u r9, r12, r3
	mad.acc r9, r12, r1
	st.local r9, [96]
	ld.local r9, [24]
	mul.hi.u r11, r9, r3
	mad.lo r1, r9, r1, r11
	mad.lo r9, r4, r3, r7
	st.local r9, [116]
	mad.lo r5, r5, r3, r15
	st.local r5, [104]
	mad.lo r13, r2, r3, r10
	mul.lo r7, r14, r3
	mov r15, r6
	mov r2, r15
	shl r2, 5
	shr r6, r7, 27
	or r10, r6, r2
	ld.local r4, [28]
	shr r2, r4, 30
	xor r6, r2, r4
	ld.local r4, [16]
	shr r2, r4, 30
	xor r11, r2, r4
	ld.local r2, [136]
	mul.lo r2, r3
	mov r14, r8
	shl r14, 5
	shr r12, r2, 27
	or r12, r14
	mad.lo r4, r11, r3, r1
	ld.local r1, [96]
	mad.acc r1, r6, r3
	st.local r1, [96]
	shr r6, r8, 27
	xor r6, r8
	st.local r6, [16]
	xor r6, r10, r7
	st.local r6, [28]
	ld.local r6, [132]
	mul.lo r6, r3
	st.local r6, [108]
	shl r0, 5
	shr r8, r6, 27
	or r0, r8, r0
	st.local r0, [112]
	ld.local r0, [128]
	mul.lo r10, r0, r3
	mov r7, r13
	shl r7, 5
	shr r8, r10, 27
	or r0, r8, r7
	st.local r0, [128]
	ld.local r0, [124]
	mul.lo r6, r0, r3
	mov r7, r5
	shl r7, 5
	shr r11, r6, 27
	or r0, r11, r7
	st.local r0, [124]
	ld.local r0, [20]
	mul.lo r7, r0, r3
	mov r11, r9
	shl r11, 5
	shr r9, r7, 27
	or r0, r9, r11
	st.local r0, [20]
	ld.local r0, [24]
	mul.lo r9, r0, r3
	mov r11, r4
	shl r11, 5
	shr r14, r9, 27
	or r14, r11
	xor r5, r12, r2
	ld.local r0, [120]
	mul.lo r3, r0, r3
	mov r0, r15
	shr r11, r0, 27
	xor r12, r11, r0
	mov r0, r1
	shl r0, 5
	shr r11, r3, 27
	or r1, r11, r0
	f48 r11, 2496678331
	f48 r2, 321982955
	mul.hi.u r15, r5, r2
	mad.acc r15, r5, r11
	ld.local r0, [16]
	mad.acc r15, r0, r2
	shr r8, r13, 27
	xor r0, r8, r13
	st.local r0, [120]
	xor r9, r14, r9
	ld.local r0, [20]
	xor r7, r0, r7
	ld.local r0, [124]
	xor r6, r0, r6
	ld.local r0, [128]
	xor r0, r10
	xor r1, r3
	st.local r1, [16]
	ld.local r1, [108]
	ld.local r3, [112]
	xor r8, r3, r1
	ld.local r3, [28]
	mul.hi.u r1, r3, r2
	mad.acc r1, r3, r11
	mad.lo r12, r12, r2, r1
	ld.local r3, [100]
	shr r1, r3, 27
	xor r1, r3
	st.local r1, [24]
	shr r3, r4, 27
	xor r13, r3, r4
	ld.local r1, [116]
	shr r3, r1, 27
	xor r1, r3, r1
	ld.local r3, [104]
	shr r4, r3, 27
	xor r4, r3
	shr r14, r15, 31
	xor r3, r14, r15
	st.local r3, [108]
	shl r15, 1
	mul.lo r3, r5, r2
	shr r14, r3, 31
	or r10, r14, r15
	st.local r0, [20]
	mul.hi.u r14, r0, r2
	mad.acc r14, r0, r11
	ld.local r0, [120]
	mad.lo r5, r0, r2, r14
	mul.hi.u r14, r6, r2
	mad.acc r14, r6, r11
	mad.lo r4, r4, r2, r14
	mul.hi.u r14, r7, r2
	mad.acc r14, r7, r11
	mad.lo r0, r1, r2, r14
	st.local r0, [104]
	mul.hi.u r14, r9, r2
	mad.acc r14, r9, r11
	mad.lo r13, r13, r2, r14
	mul.hi.u r14, r8, r2
	mad.acc r14, r8, r11
	ld.local r0, [24]
	mad.lo r15, r0, r2, r14
	ld.local r0, [16]
	mul.hi.u r14, r0, r2
	mad.lo r0, r0, r11, r14
	st.local r0, [100]
	ld.local r0, [96]
	shr r11, r0, 27
	xor r14, r11, r0
	shr r11, r12, 31
	xor r11, r12
	ld.local r0, [108]
	add r1, r11, r0
	xor r0, r10, r3
	shl r12, 1
	ld.local r3, [28]
	mul.lo r10, r3, r2
	shr r11, r10, 31
	or r11, r12
	xor r10, r11, r10
	add r0, r10, r0
	setp.lt.u p0, r0, r10
	@p0 add r1, r1, 1
	mul.lo r8, r2
	mov r10, r15
	shl r10, 1
	shr r11, r8, 31
	or r3, r11, r10
	st.local r3, [24]
	mul.lo r9, r2
	mov r10, r13
	shl r10, 1
	shr r11, r9, 31
	or r3, r11, r10
	st.local r3, [28]
	mul.lo r7, r2
	ld.local r3, [104]
	mov r10, r3
	shl r10, 1
	shr r11, r7, 31
	or r10, r11, r10
	st.local r10, [96]
	mul.lo r10, r6, r2
	mov r6, r4
	shl r6, 1
	shr r12, r10, 31
	or r12, r6
	ld.local r6, [100]
	mad.acc r6, r14, r2
	shr r14, r5, 31
	xor r14, r5
	add r1, r14, r1
	shl r5, 1
	ld.local r11, [20]
	mul.lo r14, r11, r2
	shr r11, r14, 31
	or r5, r11, r5
	xor r5, r14
	add r14, r5, r0
	setp.lt.u p0, r14, r5
	@p0 add r1, r1, 1
	ld.local r0, [16]
	mul.lo r5, r0, r2
	shr r0, r4, 31
	xor r0, r4
	mov r2, r3
	shr r4, r2, 31
	xor r3, r4, r2
	shr r4, r13, 31
	xor r4, r13
	shr r11, r15, 31
	xor r11, r15
	shr r13, r6, 31
	xor r13, r6
	add r1, r13, r1
	xor r10, r12, r10
	ld.local r2, [96]
	xor r7, r2, r7
	ld.local r2, [28]
	xor r9, r2, r9
	ld.local r2, [24]
	xor r8, r2, r8
	shl r6, 1
	shr r12, r5, 31
	or r6, r12, r6
	xor r5, r6, r5
	add r2, r5, r14
	setp.lt.u p0, r2, r5
	@p0 add r1, r1, 1
	add r1, r11, r1
	add r2, r8, r2
	setp.lt.u p0, r2, r8
	@p0 add r1, r1, 1
	add r1, r4, r1
	add r2, r9, r2
	setp.lt.u p0, r2, r9
	@p0 add r1, r1, 1
	add r1, r3, r1
	add r2, r7, r2
	setp.lt.u p0, r2, r7
	@p0 add r1, r1, 1
	add r0, r1
	add r1, r10, r2
	ld.local r2, [12]
	st.global r1, [#2, r2, 0, 0]
	setp.lt.u p0, r1, r10
	@p0 add r0, r0, 1
	add r1, r2, 4
	st.global r0, [#2, r1, 0, 0]
	f48 r0, 2216829733
	ld.local r1, [92]
	xor r15, r1, r0
	mul.lo r0, r15, 435
	ld.local r1, [88]
	xor r4, r0, r1
	mul.lo r1, r4, 435
	ld.local r2, [84]
	xor r14, r1, r2
	mul.lo r1, r14, 435
	ld.local r2, [80]
	xor r13, r1, r2
	mul.lo r1, r13, 435
	ld.local r2, [76]
	xor r12, r1, r2
	mul.lo r1, r12, 435
	ld.local r2, [72]
	xor r11, r1, r2
	mul.lo r1, r11, 435
	ld.local r2, [68]
	xor r2, r1, r2
	mul.lo r1, r2, 435
	ld.local r3, [64]
	xor r10, r1, r3
	mul.lo r1, r10, 435
	ld.local r3, [60]
	xor r9, r1, r3
	mul.lo r1, r9, 435
	ld.local r3, [56]
	xor r8, r1, r3
	mul.lo r1, r8, 435
	ld.local r3, [52]
	xor r7, r1, r3
	mul.lo r1, r7, 435
	ld.local r3, [48]
	xor r6, r1, r3
	mul.lo r1, r6, 435
	ld.local r3, [44]
	xor r5, r1, r3
	mul.lo r1, r5, 435
	ld.local r3, [40]
	xor r0, r1, r3
	st.local r0, [24]
	mul.lo r1, r0, 435
	ld.local r3, [36]
	xor r0, r1, r3
	st.local r0, [20]
	mul.lo r1, r0, 435
	ld.local r3, [32]
	xor r0, r1, r3
	st.local r0, [16]
	ld.local r1, [12]
	add r1, 8
	mul.lo r3, r0, 435
	st.global r3, [#2, r1, 0, 0]
	movi r1, 435
	mul.hi.u r3, r4, r1
	shl r4, 8
	add r0, r3, r4
	mul.hi.u r3, r15, r1
	shl r15, 8
	or r3, r15
	mad.acc r0, r3, r1
	mul.hi.u r3, r14, r1
	shl r14, 8
	add r3, r14
	mad.lo r0, r0, r1, r3
	mul.hi.u r3, r13, r1
	shl r13, 8
	add r3, r13
	mad.lo r0, r0, r1, r3
	mul.hi.u r3, r12, r1
	shl r12, 8
	add r3, r12
	mad.lo r0, r0, r1, r3
	mul.hi.u r3, r11, r1
	shl r11, 8
	add r3, r11
	mad.lo r0, r0, r1, r3
	mul.hi.u r3, r2, r1
	shl r2, 8
	add r2, r3, r2
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r10, r1
	shl r10, 8
	add r2, r10
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r9, r1
	shl r9, 8
	add r2, r9
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r8, r1
	shl r8, 8
	add r2, r8
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r7, r1
	shl r7, 8
	add r2, r7
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r6, r1
	shl r6, 8
	add r2, r6
	mad.lo r0, r0, r1, r2
	mul.hi.u r2, r5, r1
	shl r5, 8
	add r2, r5
	mad.lo r0, r0, r1, r2
	ld.local r3, [24]
	mul.hi.u r2, r3, r1
	shl r3, 8
	add r2, r3
	mad.lo r0, r0, r1, r2
	ld.local r3, [20]
	mul.hi.u r2, r3, r1
	shl r3, 8
	add r2, r3
	mad.lo r0, r0, r1, r2
	ld.local r3, [16]
	mul.hi.u r2, r3, r1
	shl r3, 8
	add r2, r3
	mad.lo r0, r0, r1, r2
	f48 r1, 1375942116
	add r0, r1
	ld.local r1, [12]
	add r1, 12
	st.global r0, [#2, r1, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z6hash64PKjPKhPji, Lfunc_end0-_Z6hash64PKjPKhPji

