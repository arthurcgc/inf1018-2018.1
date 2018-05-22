/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}
*/

.data
Sf: .string "%d"
S1: .string "Numero:\n"

.text
.global novonum

  novonum:
    pushq %rbp
    movq  %rsp,%rbp
    subq  $16,%rsp

    leaq  -4(%rbp),%rbx
    print:
    movq  $S1,%rdi
    call  printf

    scan:
    movq  $Sf,%rdi
    leaq  (%rbx),%rsi
    call scanf
    movq  (%rbx),%rax

    fim:
    leave
    ret
