/*
int foo (int x) {
  return add(x);
}
*/

.text

.global foo

foo:
  call  add
  ret
