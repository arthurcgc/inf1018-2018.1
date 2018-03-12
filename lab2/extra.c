#include <stdio.h>


int is_little() //retorna 1 se é little endian
{
	unsigned int x = 0x1234567;
	unsigned char *c = (char*) &x; /*iguala *c ao valor apontado pelo 						primeiro byte do endereço de x*/
	if (*c == 0x67)
	{
		return 1;
	}
	else return 0;
}

int main()
{
	if (is_little() == 1)
	{
		printf("little endian\n");
	}
	else printf("big endian\n");
	return 0;
}
