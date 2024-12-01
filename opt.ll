; ModuleID = 'main.ll'
source_filename = "main.ll"

@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr nocapture noundef readonly, ...) local_unnamed_addr #0

; Function Attrs: nofree nounwind
define noundef i32 @main() local_unnamed_addr #0 {
entry:
  %arrayptr.157 = alloca [20 x i64], align 8
  %arrayptr.218 = alloca [20 x double], align 8
  %arrayPtr.27 = getelementptr inbounds double, ptr %arrayptr.218, i64 2
  store double 1.000000e+00, ptr %arrayPtr.27, align 8
  store i64 10, ptr %arrayptr.157, align 8
  %arrayPtr.37 = getelementptr inbounds i64, ptr %arrayptr.157, i64 1
  store i64 2, ptr %arrayPtr.37, align 8
  br label %block.57

block.57:                                         ; preds = %entry, %block.57
  %ptr.i.41.09 = phi i64 [ 0, %entry ], [ %binOp.54, %block.57 ]
  %arrayPtr.46 = getelementptr i64, ptr %arrayptr.157, i64 %ptr.i.41.09
  %var46 = load i64, ptr %arrayPtr.46, align 8
  %0 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formati64, i64 %var46)
  %arrayPtr.49 = getelementptr double, ptr %arrayptr.218, i64 %ptr.i.41.09
  %var49 = load double, ptr %arrayPtr.49, align 8
  %1 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formatdouble, double %var49)
  %binOp.54 = add nuw nsw i64 %ptr.i.41.09, 1
  %temp.44 = icmp ult i64 %ptr.i.41.09, 19
  br i1 %temp.44, label %block.57, label %end.57

end.57:                                           ; preds = %block.57
  ret i32 0
}

attributes #0 = { nofree nounwind }
