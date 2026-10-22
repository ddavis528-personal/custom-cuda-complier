; A 64-bit shift by a variable amount is SHL_PARTS on 32-bit halves, done
; inline: there is no __ashldi3. Switch bit tests produce one from i32 source.
define void @k() {
entry:
  %x = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  %z = zext i32 %x to i64
  %s = shl i64 1, %z
  %r = lshr i64 -1, %z
  %q = ashr i64 -9, %z
  %a = xor i64 %s, %r
  %b = xor i64 %a, %q
  %lo = trunc i64 %b to i32
  %h = lshr i64 %b, 32
  %hi = trunc i64 %h to i32
  store i32 %lo, ptr addrspace(1) inttoptr (i64 196608 to ptr addrspace(1)), align 4
  store i32 %hi, ptr addrspace(1) inttoptr (i64 196612 to ptr addrspace(1)), align 4
  ret void
}
