; A window plus a constant past base+offset's 13 bits: __ccv_privbase's data
; at L - size in the thread's O-83 region (IS-25). It takes base+index with the
; offset in a register; before, it reached the type legalizer and crashed it.
define void @k(i32 %w, i32 %v) {
  %a = zext i32 %w to i64
  %b = shl nuw nsw i64 %a, 16
  %p = inttoptr i64 %b to ptr
  %q = getelementptr i8, ptr %p, i64 61072
  store i32 %v, ptr %q, align 4
  %r = getelementptr i8, ptr %p, i64 61076
  %x = load i32, ptr %r, align 4
  %s = getelementptr i8, ptr %p, i64 61080
  store i32 %x, ptr %s, align 4
  ret void }
