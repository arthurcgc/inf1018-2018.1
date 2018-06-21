.text

.global myotherwrite

myotherwrite:

  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp

  movq %r12, (%rsp)
  movq %r13, 8(%rsp)


  movq %rdi, %r12
  movq %rsi, %r13

  movq %rsi, %rdi

  call strlen

  movq %rax, %rdx

  movq $1, %rax

  movl %r12d, %edi
  movq %r13, %rsi

  syscall

  movq (%rsp), %r12
  movq 8(%rsp), %r13

  movq %rbp, %rsp
  popq %rbp

  ret
