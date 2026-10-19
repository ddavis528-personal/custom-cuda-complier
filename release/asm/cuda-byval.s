	.text
	.file	"byval.cu"
	.globl	_Z5byvalPfPKf6Params
	.type	_Z5byvalPfPKf6Params,@function
_Z5byvalPfPKf6Params:
	movi r0, 2
	ld.global r2, [r0 + 48]
	srd r1, 0
	setp.le.u p0, r2, r1
	@p0 bra LBB0_2
	shl r1, 2
	ld.global r2, [r0 + 44]
	add r2, r1
	ld.global r2, [#1, r2, 0, 0]
	ld.global r3, [r0 + 52]
	cvt.f32.s32 r3, r3
	ld.global r4, [r0 + 56]
	ffma.f0 r2, r2, r3, r4
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r2, [#0, r0, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z5byvalPfPKf6Params, Lfunc_end0-_Z5byvalPfPKf6Params

