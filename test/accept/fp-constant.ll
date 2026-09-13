; A float constant is an integer constant in a GPR: there is no constant pool,
; so ConstantFP stays legal and the f48 wide immediate carries the bit pattern.
; The default expansion emitted a constant-pool load, which has no addressing
; mode here.
define void @k(i32 %i) {
  %rb = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e  = zext i32 %rb to i64
  %w  = shl nuw nsw i64 %e, 16
  %p  = inttoptr i64 %w to ptr
  %zi = zext i32 %i to i64
  %g  = getelementptr inbounds float, ptr %p, i64 %zi
  store float 2.500000e-01, ptr %g, align 4
  ret void
}
!0 = !{}
