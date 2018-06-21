.text

.global returnp1

returnp1:
  push %rbp
  movq %rsp,%rbp

  movq  %rdi,%rax

  leave
  ret 
