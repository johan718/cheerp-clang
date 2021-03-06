// RUN: %clang -target aarch64-linux-gnuabi %s -O3 -S -emit-llvm -o - | FileCheck %s

_Complex long double a, b, c, d;
void test_fp128_compound_assign(void) {
  // CHECK: tail call %complex._ZTSe @__multc3
  a *= b;
  // CHECK: tail call %complex._ZTSe @__divtc3
  c /= d;
}
