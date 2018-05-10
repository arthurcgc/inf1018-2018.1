/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/

.text
.global fat

  fat:
  pushq %rbp
  movq %rsp,%rbp
  subq  $8,%rsp
  movq  %rbx,-8(%rbp)



  cmpq  $0,%rdi
  jne    else

  movq $1,%rax
  jmp fim

  else:
  movq %rdi,%rbx    /* rbx=n */
  subq  $1,%rdi     /*rdi = n-1*/
  call  fat         /*fat(n-1)*/
  imul  %rbx,%rax   /*n*retorno de fat que é igual a fat(n-1)*/

  fim:
  movq  -8(%rbp),%rbx
  leave
  ret
