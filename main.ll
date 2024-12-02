@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"
declare i32 @printf(i8*, ...)
define i64 @main() {
entry:
  %ptr.a.5 = alloca i64
  %val7 = fadd double 0.0, 3.14
  %conv.8 = fptosi double %val7 to i64
  store i64 %conv.8, ptr %ptr.a.5
  %var10 = load i64, ptr %ptr.a.5
  %format_ptr11 = getelementptr [4 x i8], [4 x i8]* @formati64, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr11, i64 %var10)
  %val12 = add i64 0, 3
  %conv.13 = sitofp i64 %val12 to double
  %format_ptr14 = getelementptr [4 x i8], [4 x i8]* @formatdouble, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr14, double %conv.13)
  %val15 = add i64 0, 0
  ret i64 %val15
  ret i64 0
}
