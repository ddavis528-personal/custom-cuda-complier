	.text
	.file	"privbase.cu"
	.globl	_Z8privbasePjj
	.type	_Z8privbasePjj,@function
_Z8privbasePjj:
	pmov p3, 1
	srd r1, 3
	movi r0, 2
	@p3 ld.global r2, [r0 + 24]
	@p3 add r1, r2, r1
	@!p3 shfl.idx r1, r1, 0
	@p3 ld.global r3, [r0 + 40]
	@!p3 shfl.idx r3, r3, 0
	movi r2, 65536
	@p3 sub r5, r2, r3
	@p3 and r4, r5, -16
	@!p3 shfl.idx r4, r4, 0
	@p3 shl r6, r1, 16
	@!p3 shfl.idx r6, r6, 0
	@p3 add r7, r6, r4
	@!p3 shfl.idx r7, r7, 0
	@p3 or r8, r6, r5
	@!p3 shfl.idx r8, r8, 0
	andn r8, r7
	@p3 and r5, r6, r5
	@p3 or r5, r5, r8
	setp.lt.u p1, r7, r6
	setp.lt.u p0, r2, r3
	@p3 shr r2, r1, 16
	@!p3 shfl.idx r2, r2, 0
	mov r6, r2
	@p0 add r6, r6, -1
	@p1 add r6, r6, 1
	@p3 shr r5, r5, 31
	@p3 add r9, r2, r5
	movi r6, 0
	f48 r5, 4294967295
	srd r2, 0
	movi r8, 0
	@p0 add r8, r8, -1
	@p3 or r7, r7, r9
	@!p3 shfl.idx r7, r7, 0
	@p0 bra LBB0_4
	setp.lt.u p0, r4, r6
	setp.eq p1, r8, 0
	pand p0, 1, 0
	@p0 bra LBB0_4
	setp.eq p0, r7, 0
	@p0 bra LBB0_4
	movi r4, 65536
	@p3 sub r3, r4, r3
	@p3 and r4, r3, -16
	@!p3 shfl.idx r4, r4, 0
	mov r3, r2
	shl r3, 4
	st.global r3, [r1, r4, 0, 0]
	@p3 or r5, r4, 4
	@!p3 shfl.idx r5, r5, 0
	or r6, r3, 1
	st.global r6, [r1, r5, 0, 0]
	@p3 or r5, r4, 8
	@!p3 shfl.idx r5, r5, 0
	or r7, r3, 2
	st.global r7, [r1, r5, 0, 0]
	@p3 or r5, r4, 12
	@!p3 shfl.idx r5, r5, 0
	or r8, r3, 3
	st.global r8, [r1, r5, 0, 0]
	@p3 add r5, r4, 16
	@!p3 shfl.idx r5, r5, 0
	or r9, r3, 4
	st.global r9, [r1, r5, 0, 0]
	@p3 add r5, r4, 20
	@!p3 shfl.idx r5, r5, 0
	or r10, r3, 5
	st.global r10, [r1, r5, 0, 0]
	@p3 add r5, r4, 24
	@!p3 shfl.idx r5, r5, 0
	or r11, r3, 6
	st.global r11, [r1, r5, 0, 0]
	@p3 add r4, r4, 28
	@!p3 shfl.idx r4, r4, 0
	or r5, r3, 7
	st.global r5, [r1, r4, 0, 0]
	add r1, r6, r3
	add r1, r7, r1
	add r1, r8, r1
	add r1, r9, r1
	add r1, r10, r1
	add r1, r11, r1
	add r5, r1
LBB0_4:
	shl r2, 2
	@p3 ld.global r0, [r0 + 36]
	@!p3 shfl.idx r0, r0, 0
	add r0, r2
	st.global r5, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z8privbasePjj, Lfunc_end0-_Z8privbasePjj

