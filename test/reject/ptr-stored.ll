; A pointer stored to memory that has no (rbase, roffset) pair to build the
; flat address from (ISA v1.9 §5.7): here a bare argument, which nothing
; split. A pointer that does have one is stored by CCVPointerPairs and
; executed by tools/check-ptrmem.sh.
define void @k(ptr %slot, ptr %val) { store ptr %val, ptr %slot, align 8
  ret void }
