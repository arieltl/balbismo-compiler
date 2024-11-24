; ModuleID = 'main.ll'
source_filename = "main.ll"

@formati64 = private constant [4 x i8] c"%d\0A\00"

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr nocapture noundef readonly, ...) local_unnamed_addr #0

; Function Attrs: nofree nounwind
define noundef i32 @main() local_unnamed_addr #0 {
entry:
  %0 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formati64, i64 0)
  %1 = tail call i32 (ptr, ...) @printf(ptr nonnull dereferenceable(1) @formati64, i64 10)
  ret i32 0
}

attributes #0 = { nofree nounwind }
