	.text
	.file	"saxpy.cu"
	.globl	_Z5saxpyPfPKffi
	.type	_Z5saxpyPfPKffi,@function
_Z5saxpyPfPKffi:
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r1, r3, r1, r2
	ld.global r2, [r0 + 52]
	setp.le.u p0, r2, r1
	@p0 bra LBB0_2
	shl r1, 2
	ld.global r2, [r0 + 36]
	add r2, r1
	ld.global r3, [r0 + 44]
	add r1, r3, r1
	ld.global r1, [#2, r1, 0, 0]
	ld.global r0, [r0 + 48]
	ld.global r3, [#0, r2, 0, 0]
	ffma.f0 r0, r1, r0, r3
	st.global r0, [#0, r2, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z5saxpyPfPKffi, Lfunc_end0-_Z5saxpyPfPKffi

