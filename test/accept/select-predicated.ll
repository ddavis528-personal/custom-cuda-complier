; F-58: a `select` must lower to a PREDICATED MOVE, not to `sel`.
;
; §4 point 19's `sel` writes rd in all 32 lanes and uses the qualifier as the
; selector. A predicated `mov` writes only the lanes the qualifier selects and
; preserves the rest (invariant 10) -- so the false arm costs no instruction and
; no lane activation, and the result is the same.
;
; Every select in the benchmark set was the conditional-overwrite shape
; `sel rd, a, rd`, for which the two are exactly equivalent. This pins the
; lowering so it cannot silently go back: `sel` uses 32 lane-activations
; unconditionally and would not show up as a correctness failure anywhere.
;
target triple = "ccv"

define void @k(ptr addrspace(3) %out, i32 %a, i32 %b, i32 %c) {
entry:
  %cmp = icmp slt i32 %a, %b
  %sel = select i1 %cmp, i32 %a, i32 %c
  store i32 %sel, ptr addrspace(3) %out, align 4
  ret void
}
