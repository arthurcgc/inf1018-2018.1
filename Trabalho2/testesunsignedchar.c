#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned char c = 0xd0;
  unsigned char d =0xd8;
  unsigned char c2 = 0xd0*2;

  printf("%u\n%u\n%u\n\n",c,d,c2 );
  return 0;
}
