	.text
	.file	"reduce.cu"
	.globl	_Z6reducePfPKfi
	.type	_Z6reducePfPKfi,@function
_Z6reducePfPKfi:
	movi r4, 0
	srd r0, 1
	movi r5, 2
	ld.global r2, [r5]
	srd r1, 0
	mad.lo r3, r0, r2, r1
	ld.global r5, [r5 + 48]
	setp.le.u p0, r5, r3
	@p0 bra LBB0_2
	ld.global r4, [#2, r3, 1, 0]
LBB0_2:
	mov r3, r1
	shl r3, 2
	st.shared r4, [r3 + 0]
	bar.arrive 0
	bar.wait 0
	setp.lt.u p0, r2, 2
	@!p0 bra LBB0_3
LBB0_7:
	setp.eq p0, r1, 0
	@p0 bra LBB0_8
	exit
LBB0_3:
	mov r4, r2
	bra.short LBB0_4
LBB0_6:
	bar.arrive 0
	bar.wait 0
	setp.lt.u p0, r2, 4
	mov r2, r4
	@p0 bra LBB0_7
LBB0_4:
	shr r4, 1
	setp.le.u p0, r4, r1
	@p0 bra LBB0_6
	add r5, r4, r1
	shl r5, 2
	ld.shared r5, [r5 + 0]
	ld.shared r6, [r3 + 0]
	fadd r5, r6
	st.shared r5, [r3 + 0]
	bra.short LBB0_6
LBB0_8:
	movi r1, 0
	ld.shared r1, [r1 + 0]
	st.global r1, [#0, r0, 1, 0]
	exit
Lfunc_end0:
	.size	_Z6reducePfPKfi, Lfunc_end0-_Z6reducePfPKfi

