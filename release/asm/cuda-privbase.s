	.text
	.file	"privbase.cu"
	.globl	_Z8privbasePjj
	.type	_Z8privbasePjj,@function
_Z8privbasePjj:
	pmov p3, 1
	srd r1, 3
	movi r0, 2
	@p3 ld.global r2, [r0 + 24]
	@p3 add r2, r2, r1
	@!p3 shfl.idx r2, r2, 0
	@p3 ld.global r1, [r0 + 40]
	@!p3 shfl.idx r1, r1, 0
	movi r3, 65536
	setp.lt.u p0, r3, r1
	f48 r3, 4294967295
	srd r1, 0
	@p0 bra LBB0_3
	setp.eq p0, r2, 0
	@p0 bra LBB0_3
	mov r3, r1
	shl r3, 4
	or r4, r3, 1
	st.global r4, [r2 + 4]
	add r4, r3
	st.global r3, [r2]
	or r5, r3, 2
	or r6, r3, 3
	or r7, r3, 4
	or r8, r3, 5
	or r9, r3, 6
	or r3, 7
	st.global r3, [r2 + 28]
	st.global r9, [r2 + 24]
	st.global r8, [r2 + 20]
	st.global r7, [r2 + 16]
	st.global r6, [r2 + 12]
	st.global r5, [r2 + 8]
	add r2, r5, r4
	add r2, r6, r2
	add r2, r7, r2
	add r2, r8, r2
	add r2, r9, r2
	add r3, r2
LBB0_3:
	shl r1, 2
	@p3 ld.global r0, [r0 + 36]
	@!p3 shfl.idx r0, r0, 0
	add r0, r1
	st.global r3, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z8privbasePjj, Lfunc_end0-_Z8privbasePjj

