// RUN: %clang_cc1 -w -triple i386-pc-win32 -emit-llvm -o - %s | FileCheck %s

// CHECK-LABEL: define i64 @f1_1()
// CHECK-LABEL: define void @f1_2(%"struct.\01?s1@@"* byval align 4 %a0)
struct s1 {
  int a;
  int b;
};
struct s1 f1_1(void) { while (1) {} }
void f1_2(struct s1 a0) {}

// CHECK-LABEL: define i32 @f2_1()
struct s2 {
  short a;
  short b;
};
struct s2 f2_1(void) { while (1) {} }

// CHECK-LABEL: define i16 @f3_1()
struct s3 {
  char a;
  char b;
};
struct s3 f3_1(void) { while (1) {} }

// CHECK-LABEL: define i8 @f4_1()
struct s4 {
  char a:4;
  char b:4;
};
struct s4 f4_1(void) { while (1) {} }

// CHECK-LABEL: define i64 @f5_1()
// CHECK-LABEL: define void @f5_2(%"struct.\01?s5@@"* byval align 4)
struct s5 {
  double a;
};
struct s5 f5_1(void) { while (1) {} }
void f5_2(struct s5 a0) {}

// CHECK-LABEL: define i32 @f6_1()
// CHECK-LABEL: define void @f6_2(%"struct.\01?s6@@"* byval align 4 %a0)
struct s6 {
  float a;
};
struct s6 f6_1(void) { while (1) {} }
void f6_2(struct s6 a0) {}

