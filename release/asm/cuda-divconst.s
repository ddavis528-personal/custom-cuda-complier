	.text
	.file	"divconst.cu"
	.globl	_Z8divconstPiPKii
	.type	_Z8divconstPiPKii,@function
_Z8divconstPiPKii:
	srd r0, 0
	ld.global r1, [#2, r0, 1, 0]
	sra r2, r1, 31
	shr r2, r2, 28
	add r2, r1, r2
	shl r0, 3
	mov r3, r2
	sra r3, 4
	st.global r3, [#0, r0, 1, 0]
	and r2, r2, -16
	sub r2, r1, r2
	or r4, r0, 1
	st.global r2, [#0, r4, 1, 0]
	f48 r2, 2454267027
	mul.hi.s r2, r1, r2
	add r2, r1
	shr r4, r2, 31
	sra r2, 2
	add r2, r4
	or r4, r0, 2
	st.global r2, [#0, r4, 1, 0]
	f48 r4, 4294967289
	mad.lo r2, r2, r4, r1
	or r5, r0, 3
	st.global r2, [#0, r5, 1, 0]
	neg r2, r3
	or r3, r0, 4
	st.global r2, [#0, r3, 1, 0]
	or r2, r0, 5
	mov r3, r1
	shr r3, 4
	st.global r3, [#0, r2, 1, 0]
	f48 r2, 613566757
	mul.hi.u r2, r1, r2
	sub r3, r1, r2
	shr r3, 1
	add r2, r3, r2
	shr r2, 2
	or r3, r0, 6
	st.global r2, [#0, r3, 1, 0]
	mad.acc r1, r2, r4
	or r0, 7
	st.global r1, [#0, r0, 1, 0]
	exit
Lfunc_end0:
	.size	_Z8divconstPiPKii, Lfunc_end0-_Z8divconstPiPKii

