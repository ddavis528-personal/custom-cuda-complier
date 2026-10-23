	.text
	.file	"cta-reduce.cu"
	.globl	_Z10cta_reducePKjPj
	.type	_Z10cta_reducePKjPj,@function
_Z10cta_reducePKjPj:
	movi r0, 2
	ld.global r2, [r0 + 36]
	srd r0, 0
	mov r1, r0
	shl r1, 2
	add r3, r2, r1
	movi r2, 0
	ld.global r3, [#0, r3, 0, 0]
	setp.lt.u p0, r3, 2
	@p0 bra LBB0_3
	movi r4, 1
LBB0_2:
	mul.lo r5, r3, 3
	add r5, 1
	and r6, r3, 1
	shr r3, 1
	setp.ne p0, r6, 0
	@p0 mov r3, r5
	add r2, 1
	setp.lt.u p0, r4, r3
	@p0 bra LBB0_2
LBB0_3:
	st.shared r2, [r1 + 0]
	movi r2, 63
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_5
	movi r2, 256
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_5:
	movi r2, 31
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_7
	movi r2, 128
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_7:
	movi r2, 15
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_9
	movi r2, 64
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_9:
	movi r2, 7
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_11
	movi r2, 32
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_11:
	movi r2, 3
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_13
	movi r2, 16
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_13:
	movi r2, 1
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_15
	movi r2, 8
	ld.shared r2, [r2, r0, 1, 0]
	ld.shared r3, [r1 + 0]
	add r2, r3, r2
	st.shared r2, [r1 + 0]
LBB0_15:
	movi r2, 0
	setp.lt p0, r2, r0
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_17
	movi r3, 4
	ld.shared r3, [r3, r0, 1, 0]
	ld.shared r4, [r1 + 0]
	add r3, r4, r3
	st.shared r3, [r1 + 0]
LBB0_17:
	bar.arrive 0
	bar.wait 0
	movi r3, 2
	ld.global r3, [r3 + 44]
	add r1, r3, r1
	ld.shared r2, [r2 + 0]
	add r0, r2, r0
	st.global r0, [#1, r1, 0, 0]
	exit
Lfunc_end0:
	.size	_Z10cta_reducePKjPj, Lfunc_end0-_Z10cta_reducePKjPj

