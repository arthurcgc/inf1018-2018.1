/*
struct X1 {
  int vi;
  float vf;
};

double foo (double a, int b) {
  return a * (-b);
}

double pack1 (struct X1 *px, int n) {
  double acc = 0;
  int i;
  for (i=0;i<n;i++)
    acc += foo(px[i].vf, px[i].vi);
  return acc;
}
*/

.text

.global pack1

pack1:
  pushq %rbp
  movq  %rsp,%rbp
  subq  $24,%rsp

  movq  %xmm9,(%rsp) # acc
  movq  4(%rdi),%r10    # vi
  movq  8(%rdi),%xmm10 # vf



  movq  (%rsp),%xmm9
  leave
  ret
