/*
#define LIM 1

int filtro(int x, int lim);

int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  int *p = nums;
  for (i = 0; i < 5; i++) {
    printf("%d\n", filtro(*p,LIM));
    p++;
  }
  return 0;
}
*/

.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"
LIM:  .int 1

.text
.globl main
main:
/* prologo */
   pushq %rbp
   movq  %rsp, %rbp
   subq  $16, %rsp
   movq  %rbx, -8(%rbp)
   movq  %r12, -16(%rbp)

   movq  $0,%rbx     /* i=0 -> i=(%rbx) */
   movq  $nums,%r12  /* *p=(%r12)  */

   LOOP:
   cmpq  $5,%rbx
   je     FIM
   movslq   (%r12),%rdi
   movq   LIM,%rsi
   call   filtro
   movq   $s1,%rdi
   movq   %rax,%rsi
   call   printf
   addq   $4,%r12
   addq   $1,%rbx
   jmp LOOP

   FIM:

/* finalizacao */
   movq -8(%rbp), %rbx
   movq -16(%rbp), %r12
   leave
   ret
