	.text
	.file	"spinwait.cu"
	.globl	_Z8spinwaitPViPi
	.type	_Z8spinwaitPViPi,@function
_Z8spinwaitPViPi:
	movi r1, 2
	ld.global r0, [r1 + 36]
	srd r2, 0
	setp.eq p0, r2, 1
	@p0 bra LBB0_5
	setp.ne p0, r2, 0
	@p0 bra LBB0_6
	movi r1, 1
LBB0_3:
	add r1, r1, -1
	ld.global r2, [#0, r0, 0, 0]
	setp.eq p0, r2, 0
	@p0 bra LBB0_3
	setp.eq p0, r1, 0
	movi r0, 2
	movi r1, 1
	@p0 mov r1, r0
	ld.global r0, [r0 + 44]
	st.global r1, [#1, r0, 0, 0]
	exit
LBB0_5:
	ld.global r1, [r1 + 44]
	movi r2, 7
	st.global r2, [#1, r1, 0, 4]
	movi r1, 1
	st.global r1, [#0, r0, 0, 0]
LBB0_6:
	exit
Lfunc_end0:
	.size	_Z8spinwaitPViPi, Lfunc_end0-_Z8spinwaitPViPi

