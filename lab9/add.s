/*
int add (int a, int b, int c) {
  return a+b+c;
}
*/

.text
.global  add

  add:
  pushq %rbp
  movq  %rsp,%rbp

  addq  %rdi,%rsi
  addq  %rdx,%rsi
  movq  %rsi,%rax

  leave
  ret
