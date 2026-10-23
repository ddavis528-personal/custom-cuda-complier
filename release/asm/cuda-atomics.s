	.text
	.file	"atomics.cu"
	.globl	_Z7atomicsPKjPKfPjPfPii
	.type	_Z7atomicsPKjPKfPjPfPii,@function
_Z7atomicsPKjPKfPjPfPii:
	srd r1, 0
	movi r0, 15
	setp.lt p0, r0, r1
	movi r0, 2
	ld.global r2, [r0 + 72]
	mov r0, r1
	shl r0, 2
	@p0 bra LBB0_2
	movi r3, 0
	st.shared r3, [r0 + 0]
LBB0_2:
	setp.le p0, r2, r1
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_8
	movi r2, 2
	ld.global r3, [r2 + 36]
	add r3, r0
	ld.global r3, [#0, r3, 0, 0]
	and r4, r3, 63
	shl r4, 2
	ld.global r5, [r2 + 52]
	add r5, r4
	ld.global r6, [r2 + 48]
	movi r7, 1
	atom.add.global r5, [r6, r5, 0, 0], r7
	ld.global r5, [r2 + 44]
	add r6, r5, r0
	ld.global r5, [r2 + 60]
	add r5, r4
	ld.global r5, [#3, r5, 0, 0]
	ld.global r6, [#1, r6, 0, 0]
	pmov p0, -1
LBB0_4:
	ld.global r7, [r2 + 60]
	add r7, r4
	mov r8, r5
	fadd r8, r6
	ld.global r9, [r2 + 56]
	@p0 cas.global r5, [r9, r7, 0, 0], r5, r8, p1
	@!p1 bra LBB0_4
	and r2, r3, 15
	shl r2, 2
	movi r4, 1
	movi r5, 0
	atom.add.shared r2, [r2, r5, 0, 0], r4
	movi r2, 2
	ld.global r6, [r2 + 64]
	ld.global r7, [r2 + 68]
	add r8, r3, -1000
	atom.min.s.global r6, [r6, r7, 0, 0], r8
	ld.global r6, [r2 + 64]
	ld.global r7, [r2 + 68]
	atom.max.s.global r6, [r6, r7, 0, 4], r8
	ld.global r6, [r2 + 68]
	add r6, 8
	ld.global r7, [r2 + 64]
	atom.min.u.global r6, [r7, r6, 0, 0], r3
	ld.global r6, [r2 + 68]
	add r6, 12
	ld.global r7, [r2 + 64]
	atom.max.u.global r6, [r7, r6, 0, 0], r3
	and r6, r1, 31
	shl r6, r4, r6
	ld.global r7, [r2 + 68]
	add r7, r7, 16
	ld.global r8, [r2 + 64]
	atom.or.global r7, [r8, r7, 0, 0], r6
	ld.global r7, [r2 + 68]
	add r7, r7, 20
	ld.global r8, [r2 + 64]
	atom.xor.global r3, [r8, r7, 0, 0], r3
	ld.global r3, [r2 + 64]
	ld.global r7, [r2 + 68]
	fence 2
	add r7, r7, 24
	neg r8, r1
	atom.add.global r3, [r3, r7, 0, 0], r8
	not r3, r6
	fence 2
	ld.global r6, [r2 + 68]
	add r6, r6, 28
	ld.global r7, [r2 + 64]
	atom.and.global r3, [r7, r6, 0, 0], r3
	add r3, r1, 1
	ld.global r6, [r2 + 64]
	ld.global r7, [r2 + 68]
	@p0 cas.global r3, [r6, r7, 0, 32], r5, r3, p1
	@p1 add r5, r5, 1
	ld.global r3, [r2 + 68]
	add r3, r3, 36
	ld.global r6, [r2 + 64]
	atom.add.global r3, [r6, r3, 0, 0], r5
	ld.global r3, [r2 + 68]
	add r5, r3, 42
	and r3, r5, -4
	ld.global r3, [#4, r3, 0, 0]
	and r5, 3
	shl r5, 3
	shl r4, r5
	movi r6, 65535
	shl r5, r6, r5
	not r6, r5
LBB0_6:
	add r7, r3, r4
	and r7, r5
	and r8, r3, r6
	or r7, r8, r7
	ld.global r8, [r2 + 64]
	ld.global r9, [r2 + 68]
	add r9, r9, 42
	and r9, r9, -4
	@p0 cas.global r3, [r8, r9, 0, 0], r3, r7, p1
	@!p1 bra LBB0_6
	movi r2, 2
	ld.global r3, [r2 + 68]
	add r3, r3, 44
	ld.global r4, [r2 + 64]
	atom.exch.global r3, [r4, r3, 0, 0], r1
	ld.global r2, [r2 + 68]
	add r2, r0
	add r2, r2, 128
	st.global r3, [#4, r2, 0, 0]
LBB0_8:
	movi r2, 15
	setp.lt p0, r2, r1
	bar.arrive 0
	bar.wait 0
	@p0 bra LBB0_10
	movi r1, 2
	ld.global r1, [r1 + 68]
	add r1, r0
	ld.shared r0, [r0 + 0]
	st.global r0, [#4, r1, 0, 64]
LBB0_10:
	exit
Lfunc_end0:
	.size	_Z7atomicsPKjPKfPjPfPii, Lfunc_end0-_Z7atomicsPKjPKfPjPfPii

