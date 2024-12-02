; ModuleID = 'main.ll'
source_filename = "main.ll"

@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr nocapture noundef readonly, ...) local_unnamed_addr #0

; Function Attrs: nofree norecurse nosync nounwind memory(argmem: read)
define i64 @sum(ptr nocapture readonly %nums, i64 %size) local_unnamed_addr #1 {
entry:
  %temp.234 = icmp sgt i64 %size, 0
  br i1 %temp.234, label %block.36, label %end.36

block.36:                                         ; preds = %entry, %block.36
  %ptr.i.17.06 = phi i64 [ %binOp.33, %block.36 ], [ 0, %entry ]
  %ptr.total.14.05 = phi i64 [ %binOp.28, %block.36 ], [ 0, %entry ]
  %arrayPtr.27 = getelementptr i64, ptr %nums, i64 %ptr.i.17.06
  %var27 = load i64, ptr %arrayPtr.27, align 4
  %binOp.28 = add i64 %var27, %ptr.total.14.05
  %binOp.33 = add nuw nsw i64 %ptr.i.17.06, 1
  %temp.23 = icmp slt i64 %binOp.33, %size
  br i1 %temp.23, label %block.36, label %end.36

end.36:                                           ; preds = %block.36, %entry
  %ptr.total.14.0.lcssa = phi i64 [ 0, %entry ], [ %binOp.28, %block.36 ]
  ret i64 %ptr.total.14.0.lcssa
}

; Function Attrs: nofree norecurse nosync nounwind memory(argmem: read)
define double @sum2(ptr nocapture readonly %nums, i64 %size) local_unnamed_addr #1 {
entry:
  %temp.643 = icmp sgt i64 %size, 0
  br i1 %temp.643, label %block.77, label %end.77

block.77:                                         ; preds = %entry, %block.77
  %ptr.i.58.05 = phi i64 [ %binOp.74, %block.77 ], [ 0, %entry ]
  %ptr.total.55.04 = phi double [ %binOp.69, %block.77 ], [ 0.000000e+00, %entry ]
  %arrayPtr.68 = getelementptr double, ptr %nums, i64 %ptr.i.58.05
  %var68 = load double, ptr %arrayPtr.68, align 8
  %binOp.69 = fadd double %ptr.total.55.04, %var68
  %binOp.74 = add nuw nsw i64 %ptr.i.58.05, 1
  %temp.64 = icmp slt i64 %binOp.74, %size
  br i1 %temp.64, label %block.77, label %end.77

end.77:                                           ; preds = %block.77, %entry
  %ptr.total.55.0.lcssa = phi double [ 0.000000e+00, %entry ], [ %binOp.69, %block.77 ]
  ret double %ptr.total.55.0.lcssa
}

; Function Attrs: nofree nounwind
define noundef i64 @main() local_unnamed_addr #0 {
entry:
  %0 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formati64, i64 5)
  %1 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formatdouble, double 6.000000e+00)
  ret i64 0
}

attributes #0 = { nofree nounwind }
attributes #1 = { nofree norecurse nosync nounwind memory(argmem: read) }
