.text

.global returncons.s

returncons:
  pushq %rbp
  movq  %rsp,%rbp

  movq  $1000,%rax

  leave
  ret
