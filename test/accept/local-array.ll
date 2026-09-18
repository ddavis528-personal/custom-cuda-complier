; F-131: a local array that mem2reg could not promote, indexed dynamically.
;
; This is what a tiled kernel's per-thread staging array becomes as soon as the
; loop indexing it is not fully unrolled. §5.1 windows `.local` exactly as it
; windows `.global` and O-30 reserves R15 as the window base -- which is why a
; spill has always been `[r15 + disp]` -- but until F-131 the only frame
; addressing the backend could form was that constant displacement. An array
; indexed by a loop variable needs Format D's base+index with R15 as the base,
; which the ISA had all along and the compiler could not reach.
;
; Before the fix this did not produce a bad address; it aborted in the type
; legalizer with "Do not know how to expand the result of this operator!",
; because an alloca's pointer is addrspace(0) and this data layout makes that
; 64 bits (F-20's hazard, one node further on).
;
; Pointers arrive as `inttoptr` constants rather than as arguments because a
; raw pointer argument is the separate unsupported case -- CCVLowerKernelArgs
; rewrites those, and it has not run here.
define void @k() {
  %a = alloca [8 x float], align 4
  %i = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  ; dynamic index: base+index off the frame pointer
  %p = getelementptr inbounds [8 x float], ptr %a, i32 0, i32 %i
  store float 2.5, ptr %p, align 4
  ; constant index: a displacement, which folds into the frame offset
  %q = getelementptr inbounds [8 x float], ptr %a, i32 0, i32 3
  store float 1.5, ptr %q, align 4
  %v = load float, ptr %p, align 4
  %w = load float, ptr %q, align 4
  %s = fadd float %v, %w
  store float %s, ptr addrspace(1) inttoptr (i64 196616 to ptr addrspace(1)), align 4
  ret void }
