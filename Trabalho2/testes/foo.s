/*
int foo (int x) {
  return x+1;
}
*/

.text
.global  foo

  foo:
    pushq %rbp
    movq  %rsp,%rbp

    addq  $1,%rdi
    movq  %rdi,%rax

    leave
    ret
