; F-111: a 16-bit global access through Format D's base+displacement form.
;
; The base+INDEX path has checked the memory type since the first `short`
; kernel clobbered its neighbour; this path did not, and selected the 32-bit
; form -- a four-byte transfer for a two-byte element, writing the right value
; over the wrong number of bytes. Nothing downstream could see it: the value
; asked about is correct and only the element after it is wrong.
;
; The assembly is the whole test. `ld.global`/`st.global` here must be the
; W16 forms, which differ from their 32-bit namesakes only in the TSFlags bit
; CCVInsertChwidth reads -- so the check is that a `chwidth` to 16 precedes
; them and the access is at that width.
define void @k() {
  %v = load i16, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 2
  %u = load i16, ptr addrspace(4) inttoptr (i64 131132 to ptr addrspace(4)), align 2
  %w = add i16 %v, %u
  store i16 %w, ptr addrspace(1) inttoptr (i64 196616 to ptr addrspace(1)), align 2
  ret void }
