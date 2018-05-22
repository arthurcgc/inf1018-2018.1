/*
int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++)
  {
    *a = num;
    a++;
  }
  return addl (local, 4);
}
*/

.text
.global bemboba

bemboba:
  pushq %rbp
  movq  %rsp,%rbp
  subq  $16,%rsp

  movq  $0,%r10     # int i =0
  leaq -16(%rbp),%rbx   # int *a

  loop:
  cmpq  $4,%r10
  jge   fim

  movq  %rdi,(%rbx)  
  addq  $4,%rbx
  addq  $1,%r10

  jmp   loop

  fim:
  leaq -16(%rbx), %rdi
  movq  $4,%rsi
  call  addl

  leave
  ret
