/*
#include <stdio.h>

int main()
{
  int i;
  for (i = 1; i < 11; i++)
  {
    printf("%d\n",i*i);
  }
  return 0;
}
*/

.data
Sf:  .string "%d"    /* primeira string de formato para printf */
Sf2: .string "\n"    /* segunda string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12,-16(%rbp)
/********************************************************/

  movl  $1, %r12d  /* r12 = 1; */

  L1:
  cmpl  $11,%r12d
  jae L3
  movl  %r12d,%ebx
  imull %ebx,%ebx

  /************************************************************/
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %ebx, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
  /***********************************************************/

  /************************************************************/
  movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
  /***********************************************************/

  addl  $1,%r12d    /* r12++ */
  jmp   L1

  L3:
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx  /* recupera rbx */
  movq  -16(%rbp),%rbx
  leave
  ret
