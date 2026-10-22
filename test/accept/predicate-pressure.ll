; Four predicates live at one branch, with P3 reserved: one must spill, and a
; predicate spill built ld.pred/st.pred from a register still virtual, so
; allocation failed. Also a branch on a predicate compared with true (br_cc
; on i1). Reduced from the CoreMark-derived port's core_list_init.

define void @_Z8coremarkPhPti() {
  %1 = call ptr @core_list_init(ptr null)
  ret void
}

define ptr @core_list_init(ptr %0) {
  %2 = icmp ult ptr null, %0
  %3 = select i1 false, i1 %2, i1 false
  br i1 %3, label %4, label %6

4:                                                ; preds = %1
  %5 = shl i16 0, 0
  br label %6

6:                                                ; preds = %4, %1
  ret ptr null
}
