	.text
	.file	"dot.cu"
	.globl	_Z3dotPfPKfS1_i
	.type	_Z3dotPfPKfS1_i,@function
_Z3dotPfPKfS1_i:
	movi r4, 0
	srd r0, 1
	movi r3, 2
	ld.global r2, [r3]
	srd r1, 0
	mad.lo r5, r0, r2, r1
	ld.global r6, [r3 + 56]
	setp.le.u p0, r6, r5
	@p0 bra LBB0_2
	shl r5, 2
	ld.global r4, [r3 + 44]
	add r4, r5
	ld.global r3, [r3 + 52]
	add r3, r5
	ld.global r3, [#4, r3, 0, 0]
	ld.global r4, [#2, r4, 0, 0]
	fmul r4, r3
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
	shl r0, 2
	movi r1, 2
	ld.global r1, [r1 + 36]
	add r0, r1, r0
	movi r1, 0
	ld.shared r1, [r1 + 0]
	st.global r1, [#0, r0, 0, 0]
	exit
Lfunc_end0:
	.size	_Z3dotPfPKfS1_i, Lfunc_end0-_Z3dotPfPKfS1_i

