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
    cmpq  $0,%rdi
    jl    soma2
    je    sub2
    addq  $10000,%rdi
    soma2:
    addq  $2,%rdi
    sub2:
    subq  $2,%rdi

  fim:
    movq  %rdi,%rax
    movq (%rsp), %r10
    movq 8(%rsp), %r11
    movq 16(%rsp), %r12
    movq 24(%rsp), %r13
    movq %rbp, %rsp
    popq %rbp
    ret
