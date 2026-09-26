	.text
	.file	"dp4.cu"
	.globl	_Z1kPiPKiS1_i
	.type	_Z1kPiPKiS1_i,@function
_Z1kPiPKiS1_i:
	srd r0, 0
	shl r0, 2
	movi r1, 2
	ld.global r2, [r1 + 36]
	add r2, r0
	ld.global r3, [r1 + 52]
	add r3, r0
	ld.global r1, [r1 + 44]
	add r0, r1, r0
	ld.global r0, [#2, r0, 0, 0]
	ld.global r1, [#4, r3, 0, 0]
	ld.global r3, [#0, r2, 0, 0]
	dp4.ss r0, r1, r0, r3
	st.global r0, [#0, r2, 0, 0]
	exit
Lfunc_end0:
	.size	_Z1kPiPKiS1_i, Lfunc_end0-_Z1kPiPKiS1_i

