; pointer passed across a call boundary
declare void @f(ptr)
define void @k(ptr %p) { call void @f(ptr %p)
  ret void }
