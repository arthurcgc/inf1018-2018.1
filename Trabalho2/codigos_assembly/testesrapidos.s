/*
movl %edi,%r10d
movl %edi,%r11d
movl %edi,%r12d
movl %edi,%r13d
*/
.text

.global add

add:

  prologo:
    pushq  %rbp
    movq  %rsp,%rbp
    subq  $32,%rsp
    movq %r10, (%rsp)
    movq %r11, 8(%rsp)
    movq %r12, 16(%rsp)
    movq %r13, 24(%rsp)

  operacoes:
   if:
   cmpl $0,%edi
   jl   ret1
   je   ret0
   retn5: #retorna 1
    movq $-5,%rax
    movq (%rsp), %r10
    movq 8(%rsp), %r11
    movq 16(%rsp), %r12
    movq 24(%rsp), %r13
    movq %rbp, %rsp
    popq %rbp
    ret
   ret0: #retorna 1
    movq $0,%rax
    movq (%rsp), %r10
    movq 8(%rsp), %r11
    movq 16(%rsp), %r12
    movq 24(%rsp), %r13
    movq %rbp, %rsp
    popq %rbp
    ret

   ret1: #retorna 1
    movq $1,%rax
    movq (%rsp), %r10
    movq 8(%rsp), %r11
    movq 16(%rsp), %r12
    movq 24(%rsp), %r13
    movq %rbp, %rsp
    popq %rbp
    ret
