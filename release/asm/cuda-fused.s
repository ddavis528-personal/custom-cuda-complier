	.text
	.file	"fused.cu"
	.globl	_Z5fusedPfPKfS1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_fi
	.type	_Z5fusedPfPKfS1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_fi,@function
_Z5fusedPfPKfS1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_fi:
	movi r0, 2
	ld.global r1, [r0]
	srd r2, 0
	srd r3, 1
	mad.lo r1, r3, r1, r2
	ld.global r2, [r0 + 180]
	setp.le.u p0, r2, r1
	@p0 bra LBB0_2
	shl r1, 2
	ld.global r2, [r0 + 52]
	add r2, r1
	ld.global r2, [#4, r2, 0, 0]
	ld.global r3, [r0 + 44]
	add r3, r1
	ld.global r3, [#2, r3, 0, 0]
	ld.global r4, [r0 + 176]
	ffma.acc.f0 r2, r3, r4
	ld.global r3, [r0 + 60]
	add r3, r1
	ld.global r3, [#6, r3, 0, 0]
	ffma.f0 r2, r2, r4, r3
	ld.global r3, [r0 + 68]
	add r3, r1
	ld.global r3, [#8, r3, 0, 0]
	ffma.f0 r2, r2, r4, r3
	ld.global r3, [r0 + 76]
	add r3, r1
	ld.global r3, [#10, r3, 0, 0]
	ffma.f0 r2, r2, r4, r3
	movi r3, 0
	setp.lt.f p0, r3, r2
	@p0 mov r3, r2
	ld.global r0, [r0 + 36]
	add r0, r1
	st.global r3, [#0, r0, 0, 0]
LBB0_2:
	exit
Lfunc_end0:
	.size	_Z5fusedPfPKfS1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_fi, Lfunc_end0-_Z5fusedPfPKfS1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_S1_fi

