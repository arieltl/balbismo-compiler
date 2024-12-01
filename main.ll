@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"
declare i32 @printf(i8*, ...)
define i32 @main() {
entry:
  %ptr.arrSize.5 = alloca i64
  %val2 = add i64 0, 10
  %val3 = add i64 0, 2
  %binOp.4 = mul i64 %val2, %val3
  store i64 %binOp.4, ptr %ptr.arrSize.5
  %ptr.a.9 = alloca i64
  %val8 = add i64 0, 1
  store i64 %val8, ptr %ptr.a.9
  %var11 = load i64, ptr %ptr.arrSize.5
  %arrayptr.15 = alloca i64, i64 %var11
  %ptr.arr.15 = getelementptr i64, i64* %arrayptr.15, i64 0
  %var17 = load i64, ptr %ptr.arrSize.5
  %arrayptr.21 = alloca double, i64 %var17
  %ptr.arr2.21 = getelementptr double, double* %arrayptr.21, i64 0
  %var24 = load i64, ptr %ptr.a.9
  %val25 = fadd double 0.0, 0.0
  %conv.26 = sitofp i64 %var24 to double
  %binOp.26 = fadd double %conv.26, %val25
  %val22 = add i64 0, 2
  %arrayPtr.27 = getelementptr double, double* %ptr.arr2.21, i64 %val22
  store double %binOp.26, ptr %arrayPtr.27
  %val30 = add i64 0, 10
  %val28 = add i64 0, 0
  %arrayPtr.31 = getelementptr i64, i64* %ptr.arr.15, i64 %val28
  store i64 %val30, ptr %arrayPtr.31
  %var34 = load i64, ptr %ptr.a.9
  %val35 = add i64 0, 1
  %binOp.36 = add i64 %var34, %val35
  %val32 = add i64 0, 1
  %arrayPtr.37 = getelementptr i64, i64* %ptr.arr.15, i64 %val32
  store i64 %binOp.36, ptr %arrayPtr.37
  %ptr.i.41 = alloca i64
  %val40 = add i64 0, 0
  store i64 %val40, ptr %ptr.i.41
  br label %while.57
  while.57:
    %var42 = load i64, ptr %ptr.i.41
    %var43 = load i64, ptr %ptr.arrSize.5
    %temp.44 = icmp slt i64 %var42, %var43
    %relOp.44 = zext i1 %temp.44 to i64
    %conditionCast.57 = icmp ne i64 %relOp.44, 0
    br i1 %conditionCast.57, label %block.57, label %end.57
  block.57:
    %var45 = load i64, ptr %ptr.i.41
    %arrayPtr.46 = getelementptr i64, i64* %ptr.arr.15, i64 %var45
    %var46 = load i64, ptr %arrayPtr.46
    %format_ptr47 = getelementptr [4 x i8], [4 x i8]* @formati64, i32 0, i32 0
    call i32 (i8*, ...) @printf(i8* %format_ptr47, i64 %var46)
    %var48 = load i64, ptr %ptr.i.41
    %arrayPtr.49 = getelementptr double, double* %ptr.arr2.21, i64 %var48
    %var49 = load double, ptr %arrayPtr.49
    %format_ptr50 = getelementptr [4 x i8], [4 x i8]* @formatdouble, i32 0, i32 0
    call i32 (i8*, ...) @printf(i8* %format_ptr50, double %var49)
    %var52 = load i64, ptr %ptr.i.41
    %val53 = add i64 0, 1
    %binOp.54 = add i64 %var52, %val53
    store i64 %binOp.54, ptr %ptr.i.41
    br label %while.57
  end.57:
  ret i32 0
}
