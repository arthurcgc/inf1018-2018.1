/*
double foo (double a, int b) {
  return a * (-b);
}
*/

.text

.global foo

foo:
  pushq %rbp
  movq  %rsp,%rbp

  imulq $-1,%rdi # -b
  cvtsi2sd %rdi,%xmm1
  mulsd  %xmm1,%xmm0

  leave
  ret
