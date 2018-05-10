/*
void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}
*/

.text
.global foo

  foo:
  pushq %rbp
  movq  %rsp,%rbp

  movq  $0,%r10   /* int i=0*/
  movq  $0,%r11   /*int s=0*/

  loop:
  cmpq  %r10,%rsi
  jge fim
  addq %rdi,%r11  /*s=s+a[i]*/
  cmpq  $0,%rdi   /*if(a[i]==0)*/
  je    if
  jne continue

  continue:
    /*repetir comando em if*/
    addq  $4,%rdi   /*a[i] = a+i*/
    addq  $1,%r10
    jmp   loop

  if:
    movq  %r11,%rdi
    movq  $0,%r11
    jmp   continue

  fim:
  leave
  ret
