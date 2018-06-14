/*
double foo2 (float a, float b) {
  return sin(a) + cos(b);
}
*/

.text

.global foo2

foo2:
  pushq %rbp
  movq  %rsp,%rbp
  subq  $16,%rsp

  CVTSS2SD  %xmm0,%xmm0   #converte para double
  CVTSS2SD  %xmm1,%xmm1   #converte para double

  movsd %xmm0,-8(%rbp)     #salva a
  movsd %xmm1,-16(%rbp)    #salva b

  call  sin

  movsd %xmm0,-8(%rbp)     #salva sin(a)
  movsd -16(%rbp),%xmm0    # b = primeiro parametro de cos

  call  cos

  addsd -8(%rbp),%xmm0     # sin(a) + cos(b)

  leave
  ret
