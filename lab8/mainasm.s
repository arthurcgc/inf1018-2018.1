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

   movq $nums,%r12
   movl $0,%ecx

   LOOP1:
    cmpl    $5,%ecx
    je FIM
    movsbl  (%r12),%eax
    movl    %eax,%edi
    movl    LIM,%esi
    call    filtro
    movq    %rax,%rbx
    movq    $s1,%rdi
    movq    %rax,%rsi
    call    printf
    addl    $1,%ecx
    addq    $4,%r12
    jmp     LOOP1


   FIM:
/* finalizacao */
   movq -8(%rbp), %rbx
   movq -16(%rbp), %r12
   leave
   ret
