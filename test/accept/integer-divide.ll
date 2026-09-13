; §4's integer map ends at `prmt` with no divide and there is no runtime
; library, so LLVM's default expansion -- a libcall -- failed as "Cannot
; select: udivrem". CCGExpandDivision applies the shift-subtract expansion in
; IR instead, which is what nvcc does for the same reason.
;
; This one kernel found three separate bugs, none of which it is obviously
; about: the select hang (F-42), predicate copies emitted as GPR moves, and
; compressed shift immediates truncated from 31 to 15 (F-43). tools/run-tests.sh
; also executes it, because all three produced code that compiled cleanly.
; out[tid] = (tid*7+13) / (tid+1), integer division by a runtime value.
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
define void @k() {
entry:
  %t = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %n = mul i32 %t, 7
  %num = add i32 %n, 13
  %den = add i32 %t, 1
  %q = udiv i32 %num, %den
  %rb = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e = zext i32 %rb to i64
  %w = shl nuw nsw i64 %e, 16
  %p = inttoptr i64 %w to ptr
  %zi = zext i32 %t to i64
  %g = getelementptr inbounds i32, ptr %p, i64 %zi
  store i32 %q, ptr %g, align 4
  ret void
}
!0 = !{}
