#include "bigint.h"
#include <stdio.h>

void big_val (BigInt res, long val)
{
  int i;
	for (i= 0;i<8;i++){
		res[i] = val>>(8*i) & 0xFF; // Copia o equivalente a 1 byte do unsigned long para uma posição do vetor de unsigned char
	}
  if(val>0)
  {
	for(i=8;i<NUM_BYTES;i++) // Preenche o restante com zeros
		res[i]=0;
  }
  else
  {
    for(i=8;i<NUM_BYTES;i++) // Preenche o restante com uns
  		res[i]=0xFF;
  }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b)
{
  	int buffer=0,i;
  	unsigned short soma;
  	for (i=0;i<NUM_BYTES;i++)
    {
  		soma=a[i]+b[i]+buffer; // Pega o primeiro byte do buffer e aponta-o para o byte do BigInt atual
  		buffer=soma>>8; // shifta um byte do buffer para que seja somado no proximo loop
  		res[i]=soma&0xFF; // soma em 1 byte
  	}
  }
