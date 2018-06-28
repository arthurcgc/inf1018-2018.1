/*
struct X {
  int vi;
  double vd;
  struct X *next;
};

double pack (struct X *px) {
  double acc = 0;
  while (px != NULL) {
    acc += foo(px->vd, px->vi);
    px = px->next;
  }
  return acc;
}

double foo (double a, int b);

*/

.text

.global pack

pack:
pushq %rbp
movq  %rsp,%rbp
subq  $24,%rsp
movq  %xmm

movsd $0,%xmm9    #acc
movsd %xmm0,24(%rsp)

  loop:
    ucomisd $0,
