; pointer stored to memory (an array of pointers)
define void @k(ptr %slot, ptr %val) { store ptr %val, ptr %slot, align 8
  ret void }
