@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"
declare i32 @printf(i8*, ...)
define i32 @main() {
entry:
  %val0 = add i64 0, 34
  %val1 = add i64 0, 7
  %binOp.2 = sdiv i64 %val0, %val1
  %format_ptr3 = getelementptr [4 x i8], [4 x i8]* @formati64, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr3, i64 %binOp.2)
  %val4 = add i64 0, 6
  %val5 = add i64 0, 2
  %binOp.6 = srem i64 %val4, %val5
  %format_ptr7 = getelementptr [4 x i8], [4 x i8]* @formati64, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr7, i64 %binOp.6)
  ret i32 0
}
