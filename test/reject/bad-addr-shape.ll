; address shape OUTSIDE the DAGCombine whitelist: a reassociated base
define void @k(i32 %rb, i32 %i, i32 %j) {
  %w = zext i32 %rb to i64
  %s = shl i64 %w, 16
  %zi = zext i32 %i to i64
  %zj = zext i32 %j to i64
  %sum = add i64 %zi, %zj
  %a = add i64 %s, %sum
  %p = inttoptr i64 %a to ptr
  store i32 %i, ptr %p, align 4
  ret void }
