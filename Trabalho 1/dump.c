#include <stdio.h>

void dump (void *p) {
  int n = sizeof(p);
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main()
{
  long x = 1;
  dump(&x);
  return 0;
}
