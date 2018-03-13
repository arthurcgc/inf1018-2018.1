#include <stdio.h>


int odd_ones(unsigned int x)
{
	int y = 0xffffffff;
	int i;
	int uns;
	printf("%08x\n", y);
	for (i=0;i<sizeof(x)*8;i++)
	{
		if (y & x) uns++;
		x = x >> 1;
		y = y >> 1;		
	}
	if (uns%2 == 0) return 0;
	return 1;
	
}


int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}
