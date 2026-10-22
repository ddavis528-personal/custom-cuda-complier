; A pointer compared against another, where neither has an (rbase, roffset)
; pair to build its flat address from: bare arguments, which nothing split.
; Pointers that do have one are compared by tools/check-ptrlist.sh (F-22).
define void @k(ptr %a, ptr %b, ptr %out) {
  %c = icmp eq ptr %a, %b
  %z = zext i1 %c to i32
  store i32 %z, ptr %out, align 4
  ret void }
