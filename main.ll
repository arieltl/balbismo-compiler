@formati64 = private constant [4 x i8] c"%d\0A\00"
@formatdouble = private constant [4 x i8] c"%f\0A\00"
declare i32 @printf(i8*, ...)
define i64 @sum(i64* %nums , i64 %size ) {
entry:
  %ptr.size.40 = alloca i64
  store i64 %size, ptr %ptr.size.40
  %ptr.total.14 = alloca i64
  %val13 = add i64 0, 0
  store i64 %val13, ptr %ptr.total.14
  %ptr.i.17 = alloca i64
  %val19 = add i64 0, 0
  store i64 %val19, ptr %ptr.i.17
  br label %while.36
  while.36:
    %var21 = load i64, ptr %ptr.i.17
    %var22 = load i64, ptr %ptr.size.40
    %temp.23 = icmp slt i64 %var21, %var22
    %relOp.23 = zext i1 %temp.23 to i64
    %conditionCast.36 = icmp ne i64 %relOp.23, 0
    br i1 %conditionCast.36, label %block.36, label %end.36
  block.36:
    %var25 = load i64, ptr %ptr.total.14
    %var26 = load i64, ptr %ptr.i.17
    %arrayPtr.27 = getelementptr i64, i64* %nums, i64 %var26
    %var27 = load i64, ptr %arrayPtr.27
    %binOp.28 = add i64 %var25, %var27
    store i64 %binOp.28, ptr %ptr.total.14
    %var31 = load i64, ptr %ptr.i.17
    %val32 = add i64 0, 1
    %binOp.33 = add i64 %var31, %val32
    store i64 %binOp.33, ptr %ptr.i.17
    br label %while.36
  end.36:
  %var37 = load i64, ptr %ptr.total.14
  ret i64 %var37
  ret i64 0
}
define double @sum2(double* %nums , i64 %size ) {
entry:
  %ptr.size.81 = alloca i64
  store i64 %size, ptr %ptr.size.81
  %ptr.total.55 = alloca double
  %val54 = fadd double 0.0, 0.0
  store double %val54, ptr %ptr.total.55
  %ptr.i.58 = alloca i64
  %val60 = add i64 0, 0
  store i64 %val60, ptr %ptr.i.58
  br label %while.77
  while.77:
    %var62 = load i64, ptr %ptr.i.58
    %var63 = load i64, ptr %ptr.size.81
    %temp.64 = icmp slt i64 %var62, %var63
    %relOp.64 = zext i1 %temp.64 to i64
    %conditionCast.77 = icmp ne i64 %relOp.64, 0
    br i1 %conditionCast.77, label %block.77, label %end.77
  block.77:
    %var66 = load double, ptr %ptr.total.55
    %var67 = load i64, ptr %ptr.i.58
    %arrayPtr.68 = getelementptr double, double* %nums, i64 %var67
    %var68 = load double, ptr %arrayPtr.68
    %binOp.69 = fadd double %var66, %var68
    store double %binOp.69, ptr %ptr.total.55
    %var72 = load i64, ptr %ptr.i.58
    %val73 = add i64 0, 1
    %binOp.74 = add i64 %var72, %val73
    store i64 %binOp.74, ptr %ptr.i.58
    br label %while.77
  end.77:
  %var78 = load double, ptr %ptr.total.55
  ret double %var78
  ret double 0.0
}
define i64 @main() {
entry:
  %val86 = add i64 0, 2
  %arrayptr.90 = alloca i64, i64 %val86
  %ptr.arr.90 = getelementptr i64, i64* %arrayptr.90, i64 0
  %val92 = add i64 0, 3
  %arrayptr.96 = alloca double, i64 %val92
  %ptr.arr2.96 = getelementptr double, double* %arrayptr.96, i64 0
  %val99 = add i64 0, 3
  %val97 = add i64 0, 0
  %arrayPtr.100 = getelementptr i64, i64* %ptr.arr.90, i64 %val97
  store i64 %val99, ptr %arrayPtr.100
  %val103 = add i64 0, 2
  %val101 = add i64 0, 1
  %arrayPtr.104 = getelementptr i64, i64* %ptr.arr.90, i64 %val101
  store i64 %val103, ptr %arrayPtr.104
  %val107 = fadd double 0.0, 3.0
  %val105 = add i64 0, 2
  %arrayPtr.108 = getelementptr double, double* %ptr.arr2.96, i64 %val105
  store double %val107, ptr %arrayPtr.108
  %val111 = fadd double 0.0, 2.0
  %val109 = add i64 0, 1
  %arrayPtr.112 = getelementptr double, double* %ptr.arr2.96, i64 %val109
  store double %val111, ptr %arrayPtr.112
  %val115 = fadd double 0.0, 1.0
  %val113 = add i64 0, 0
  %arrayPtr.116 = getelementptr double, double* %ptr.arr2.96, i64 %val113
  store double %val115, ptr %arrayPtr.116
  %val119 = add i64 0, 2
  %call.121 = call i64 @sum(i64* %ptr.arr.90, i64 %val119)
  %format_ptr122 = getelementptr [4 x i8], [4 x i8]* @formati64, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr122, i64 %call.121)
  %val125 = add i64 0, 3
  %call.127 = call double @sum2(double* %ptr.arr2.96, i64 %val125)
  %format_ptr128 = getelementptr [4 x i8], [4 x i8]* @formatdouble, i32 0, i32 0
  call i32 (i8*, ...) @printf(i8* %format_ptr128, double %call.127)
  ret i64 0
}
