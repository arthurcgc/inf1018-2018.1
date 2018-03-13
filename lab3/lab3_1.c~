#include <stdio.h>
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = x << 24;
  y = y >> 24;

  /* o byte mais significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z = 0xFF000000;
  z = x | z;

  printf("%08x %08x\n", y, z);
}
