#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 2000


typedef int (*funcp) ();

void liberacod(void *pf)
{
  free(pf);
}

void dump (void *p, int n)
{
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

unsigned char* geracod ()
{
  unsigned char* codeBlock = (unsigned char*) malloc(20); //bloco aonde vai ser armazenado codigo de maquina
  codeBlock[0]= 0x55;
  codeBlock[1]= 0x48;
  codeBlock[2]= 0x89;
  codeBlock[3]= 0xe5;
  codeBlock[4]= 0x48;
  codeBlock[5]= 0x83;
  codeBlock[6]= 0xc7;
  codeBlock[7]= 0x01;
  codeBlock[8]= 0x48;
  codeBlock[9]= 0x89;
  codeBlock[10]= 0xf8;
  codeBlock[11]= 0xc9;
  codeBlock[12]= 0xc3;

  return codeBlock;
}

int main(void)
{
	unsigned char *codigo = (unsigned char*)malloc(20);
  codigo=geracod();
  dump(codigo,20);
	return 0;
}
