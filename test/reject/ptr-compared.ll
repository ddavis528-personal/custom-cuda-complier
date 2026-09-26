; pointer compared against another pointer
define void @k(ptr %a, ptr %b, ptr %out) {
  %c = icmp eq ptr %a, %b
  %z = zext i1 %c to i32
  store i32 %z, ptr %out, align 4
  ret void }
