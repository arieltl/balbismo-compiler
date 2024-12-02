@str.1 = private constant [4 x i8] c"%f\0A\00"
@str.0 = private constant [5 x i8] c"%d \0A\00"
@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"
declare i32 @printf(i8*, ...)
define i64 @main() {
entry:
  %ptr.a.5 = alloca i64
  %val7 = fadd double 0.0, 3.14
  %conv.8 = fptosi double %val7 to i64
  store i64 %conv.8, ptr %ptr.a.5
  %var11 = load i64, ptr %ptr.a.5
  call i32 (i8*, ...) @printf(i8* @str.0, i64 %var11)
  %val14 = add i64 0, 3
  %conv.15 = sitofp i64 %val14 to double
  call i32 (i8*, ...) @printf(i8* @str.1, double %conv.15)
  %val17 = add i64 0, 0
  ret i64 %val17
  ret i64 0
}
