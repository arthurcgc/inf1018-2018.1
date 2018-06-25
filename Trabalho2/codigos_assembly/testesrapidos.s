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
    movq $10,%r10
    movq $5,%r11
    jmp  ret
    movq $15,%r11
    ret:
        movq %r11,%rax
  fim:
    movq (%rsp), %r10
    movq 8(%rsp), %r11
    movq 16(%rsp), %r12
    movq 24(%rsp), %r13
    movq %rbp, %rsp
    popq %rbp
    ret
