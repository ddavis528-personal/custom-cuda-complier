; F-131: a kernel with a local array that mem2reg could not promote.
;
; This is not exotic. It is what a tiled GEMM looks like when the inner loops
; are NOT fully unrolled -- the per-thread `a[TM]` and `b[TN]` staging arrays
; stay as allocas, indexed by the loop variable. On a 16-register machine that
; is the shape you want: the measured unroll sweep in F-131 shows `sgemm` 2x2
; going from 294 instructions and 85 spill transfers at full unroll to 173 and
; 27 at unroll=2. The backend cannot compile it.
;
; `.local` exists -- O-30 reserves R15 as the frame pointer and §5.1 gives the
; window -- so the addressing model is there. What fails is legalization, with
; "Do not know how to expand the result of this operator!", and a crash is the
; right place for this to sit until it is fixed: it is in test/reject so that
; the day it starts compiling, the gate notices and this file moves.
define void @k(ptr addrspace(1) %out, i32 %n) {
entry:
  %a = alloca [4 x float], align 4
  br label %loop
loop:
  %i = phi i32 [ 0, %entry ], [ %i.next, %loop ]
  %p = getelementptr inbounds [4 x float], ptr %a, i32 0, i32 %i
  store float 1.0, ptr %p, align 4
  %i.next = add i32 %i, 1
  %done = icmp slt i32 %i.next, 4
  br i1 %done, label %loop, label %exit
exit:
  %q = getelementptr inbounds [4 x float], ptr %a, i32 0, i32 0
  %v = load float, ptr %q, align 4
  store float %v, ptr addrspace(1) %out, align 4
  ret void }
