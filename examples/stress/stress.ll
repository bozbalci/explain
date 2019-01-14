; ModuleID = 'stress.xpln'
source_filename = "stress.xpln"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-darwin18.0.0"

@ifmt = internal constant [4 x i8] c"%lf\00"
@ofmt = internal constant [5 x i8] c"%lf\0A\00"

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define double @alotofarguments(double %a, double %b, double %c, double %d, double %e, double %f, double %g, double %h, double %i, double %j, double %k, double %l, double %m, double %n, double %o, double %p, double %aa, double %bb, double %cc, double %dd, double %ee, double %ff, double %gg, double %hh, double %ii, double %jj, double %kk, double %ll, double %mm, double %nn, double %oo, double %pp, double %aaa, double %bbb, double %ccc, double %ddd, double %eee, double %fff, double %ggg, double %hhh, double %iii, double %jjj, double %kkk, double %lll, double %mmm, double %nnn, double %ooo, double %ppp, double %aaaa, double %bbbb, double %cccc, double %dddd, double %eeee, double %ffff, double %gggg, double %hhhh, double %iiii, double %jjjj, double %kkkk, double %llll, double %mmmm, double %nnnn, double %oooo, double %pppp) {
entry:
  %0 = fadd double %a, %pppp
  ret double %0
}

define double @testalotofarguments() {
entry:
  %0 = call double @alotofarguments(double 1.000000e+00, double 2.000000e+00, double 3.000000e+00, double 4.000000e+00, double 5.000000e+00, double 6.000000e+00, double 7.000000e+00, double 8.000000e+00, double 9.000000e+00, double 1.000000e+01, double 1.100000e+01, double 1.200000e+01, double 1.300000e+01, double 1.400000e+01, double 1.500000e+01, double 1.600000e+01, double 1.700000e+01, double 1.800000e+01, double 1.900000e+01, double 2.000000e+01, double 2.100000e+01, double 2.200000e+01, double 2.300000e+01, double 2.400000e+01, double 2.500000e+01, double 2.600000e+01, double 2.700000e+01, double 2.800000e+01, double 2.900000e+01, double 3.000000e+01, double 3.100000e+01, double 3.200000e+01, double 3.300000e+01, double 3.400000e+01, double 3.500000e+01, double 3.600000e+01, double 3.700000e+01, double 3.800000e+01, double 3.900000e+01, double 4.000000e+01, double 4.100000e+01, double 4.200000e+01, double 4.300000e+01, double 4.400000e+01, double 4.500000e+01, double 4.600000e+01, double 4.700000e+01, double 4.800000e+01, double 4.900000e+01, double 5.000000e+01, double 5.100000e+01, double 5.200000e+01, double 5.300000e+01, double 5.400000e+01, double 5.500000e+01, double 5.600000e+01, double 5.700000e+01, double 5.800000e+01, double 5.900000e+01, double 6.000000e+01, double 6.100000e+01, double 6.200000e+01, double 6.300000e+01, double 6.400000e+01)
  ret double %0
}

define double @unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa() {
entry:
  ret double 0.000000e+00
}

define double @triviallyoptimizabledeepnesting() {
entry:
  ret double 4.200000e+01
}

define double @iterativefactorial(double %n) {
entry:
  br label %cond

cond:                                             ; preds = %loop, %entry
  %product.0 = phi double [ 1.000000e+00, %entry ], [ %1, %loop ]
  %j.0 = phi double [ 1.000000e+00, %entry ], [ %2, %loop ]
  %0 = fcmp ugt double %j.0, %n
  br i1 %0, label %post, label %loop

loop:                                             ; preds = %cond
  %1 = fmul double %product.0, %j.0
  %2 = fadd double %j.0, 1.000000e+00
  br label %cond

post:                                             ; preds = %cond
  ret double %product.0
}

define double @recursivefibonacci(double %n) {
entry:
  %0 = fcmp oeq double %n, 1.000000e+00
  %1 = fcmp oeq double %n, 2.000000e+00
  %2 = or i1 %0, %1
  br i1 %2, label %then, label %else

then:                                             ; preds = %entry
  ret double 1.000000e+00

else:                                             ; preds = %entry
  %3 = fadd double %n, -1.000000e+00
  %4 = call double @recursivefibonacci(double %3)
  %5 = fadd double %n, -2.000000e+00
  %6 = call double @recursivefibonacci(double %5)
  %7 = fadd double %4, %6
  ret double %7
}

define double @calculatepi(double %precision) {
entry:
  br label %cond

cond:                                             ; preds = %loop, %entry
  %i.0 = phi double [ 1.000000e+00, %entry ], [ %5, %loop ]
  %result.0 = phi double [ 1.000000e+00, %entry ], [ %4, %loop ]
  %sign.0 = phi double [ -1.000000e+00, %entry ], [ %6, %loop ]
  %0 = fcmp ugt double %i.0, %precision
  br i1 %0, label %post, label %loop

loop:                                             ; preds = %cond
  %1 = fmul double %i.0, 2.000000e+00
  %2 = fadd double %1, 1.000000e+00
  %3 = fdiv double %sign.0, %2
  %4 = fadd double %result.0, %3
  %5 = fadd double %i.0, 1.000000e+00
  %6 = fsub double 0.000000e+00, %sign.0
  br label %cond

post:                                             ; preds = %cond
  %7 = fmul double %result.0, 4.000000e+00
  ret double %7
}

define double @abs(double %x) {
entry:
  %0 = fcmp olt double %x, 0.000000e+00
  br i1 %0, label %then, label %else

then:                                             ; preds = %entry
  %1 = fsub double 0.000000e+00, %x
  ret double %1

else:                                             ; preds = %entry
  ret double %x
}

define double @eq(double %a, double %b) {
entry:
  %0 = fsub double %a, %b
  %1 = call double @abs(double %0)
  %2 = fcmp olt double %1, 1.000000e-03
  %merge = select i1 %2, double 1.000000e+00, double -1.000000e+00
  ret double %merge
}

define double @euclideangcd(double %a, double %b) {
entry:
  br label %cond

cond:                                             ; preds = %loop, %entry
  %a1.0 = phi double [ %a, %entry ], [ %a1.1, %loop ]
  %b2.0 = phi double [ %b, %entry ], [ %b2.1, %loop ]
  %0 = call double @eq(double %a1.0, double %b2.0)
  %1 = fcmp olt double %0, 0.000000e+00
  br i1 %1, label %loop, label %post

loop:                                             ; preds = %cond
  %2 = fcmp ogt double %a1.0, %b2.0
  %3 = fsub double %a1.0, %b2.0
  %4 = fsub double %b2.0, %a1.0
  %a1.1 = select i1 %2, double %3, double %a1.0
  %b2.1 = select i1 %2, double %b2.0, double %4
  br label %cond

post:                                             ; preds = %cond
  ret double %a1.0
}

define double @modulo(double %a, double %b) {
entry:
  br label %cond

cond:                                             ; preds = %loop, %entry
  %k.0 = phi double [ 0.000000e+00, %entry ], [ %3, %loop ]
  %0 = fmul double %b, %k.0
  %1 = fsub double %a, %0
  %2 = fcmp ult double %1, %b
  br i1 %2, label %post, label %loop

loop:                                             ; preds = %cond
  %3 = fadd double %k.0, 1.000000e+00
  br label %cond

post:                                             ; preds = %cond
  ret double %1
}

define double @iseven(double %n) {
entry:
  %0 = call double @modulo(double %n, double 2.000000e+00)
  %1 = fcmp oeq double %0, 0.000000e+00
  %merge = select i1 %1, double 1.000000e+00, double -1.000000e+00
  ret double %merge
}

define double @isodd(double %n) {
entry:
  %0 = call double @iseven(double %n)
  %1 = fsub double 1.000000e+00, %0
  ret double %1
}

define double @exponentiationbysquaring(double %x, double %n) {
entry:
  %0 = fcmp olt double %n, 0.000000e+00
  br i1 %0, label %then, label %else

then:                                             ; preds = %entry
  %1 = fdiv double 1.000000e+00, %x
  %2 = fsub double 0.000000e+00, %n
  %3 = call double @exponentiationbysquaring(double %1, double %2)
  ret double %3

else:                                             ; preds = %entry
  %4 = fcmp oeq double %n, 0.000000e+00
  br i1 %4, label %then7, label %else8

then7:                                            ; preds = %else8, %else
  %merge = phi double [ 1.000000e+00, %else ], [ %x, %else8 ]
  ret double %merge

else8:                                            ; preds = %else
  %5 = fcmp oeq double %n, 1.000000e+00
  br i1 %5, label %then7, label %else12

else12:                                           ; preds = %else8
  %6 = call double @iseven(double %n)
  %7 = fcmp ogt double %6, 1.000000e+00
  %8 = fmul double %x, %x
  br i1 %7, label %then16, label %else17

then16:                                           ; preds = %else12
  %9 = fmul double %n, 5.000000e-01
  %10 = call double @exponentiationbysquaring(double %8, double %9)
  ret double %10

else17:                                           ; preds = %else12
  %11 = fadd double %n, -1.000000e+00
  %12 = fmul double %11, 5.000000e-01
  %13 = call double @exponentiationbysquaring(double %8, double %12)
  %14 = fmul double %x, %13
  ret double %14
}

define double @etothepower(double %n) {
entry:
  %0 = call double @exponentiationbysquaring(double 0x4005BF0A8B145769, double %n)
  ret double %0
}

define double @xpln_main() {
entry:
  %0 = call double @testalotofarguments()
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %0)
  %2 = call double @unreasonablylongfunctionnameaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa()
  %3 = call double @triviallyoptimizabledeepnesting()
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %3)
  %5 = call double @iterativefactorial(double 2.000000e+01)
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %5)
  %7 = call double @recursivefibonacci(double 3.000000e+01)
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %7)
  %9 = call double @calculatepi(double 1.000000e+08)
  %10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %9)
  %11 = call double @euclideangcd(double 5.050000e+04, double 1.008990e+05)
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %11)
  %13 = call double @modulo(double 1.000000e+02, double 7.000000e+00)
  %14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %13)
  %15 = call double @etothepower(double 1.500000e+01)
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @ofmt, i64 0, i64 0), double %15)
  ret double 0.000000e+00
}
