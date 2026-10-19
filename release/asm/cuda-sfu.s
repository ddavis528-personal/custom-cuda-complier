	.text
	.file	"sfu.cu"
	.globl	_Z3sfuPfPKfi
	.type	_Z3sfuPfPKfi,@function
_Z3sfuPfPKfi:
	srd r0, 0
	mul.lo r1, r0, 5
	ld.global r0, [#1, r0, 1, 0]
	cos.f32 r2, r0
	st.global r2, [#0, r1, 1, 16]
	sin.f32 r2, r0
	st.global r2, [#0, r1, 1, 12]
	rsqrt.f32 r2, r0
	st.global r2, [#0, r1, 1, 8]
	lg2.f32 r2, r0
	st.global r2, [#0, r1, 1, 4]
	ex2.f32 r0, r0
	st.global r0, [#0, r1, 1, 0]
	exit
Lfunc_end0:
	.size	_Z3sfuPfPKfi, Lfunc_end0-_Z3sfuPfPKfi

