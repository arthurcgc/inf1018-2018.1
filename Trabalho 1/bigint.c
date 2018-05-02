  /* Arthur Cavalcante Gomes Coelho 1313099 3WA */
#include "bigint.h"
#include <stdio.h>

void big_val (BigInt res, long val)
{
  int i;
	for (i= 0;i<8;i++)
  {
		res[i] = val>>(8*i) & 0xFF; // Copia o equivalente a 1 byte do unsigned long para uma posição do vetor de unsigned char
	}
  if(val>0)
  {
	for(i=8;i<NUM_BYTES;i++) res[i]=0; // Preenche o restante com zero
  }
  else
  {
    for(i=8;i<NUM_BYTES;i++)  res[i]=0xFF; // Preenche o restante com uns
  }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b)
{
  	int carry=0,i;
  	unsigned short soma;
  	for (i=0;i<NUM_BYTES;i++)
    {
  		soma=a[i]+b[i]+carry; // Pega o primeiro byte do carry e aponta-o para o byte do BigInt atual
  		carry=soma>>8; // shifta um byte do carry para que seja somado no proximo loop
  		res[i]=soma&0xFF; // soma em 1 byte
  	}
  }

void big_comp2(BigInt res,BigInt a)
{
	int i;
	BigInt um;
	for(i=0;i<NUM_BYTES;i++) //inverte o valor a cada byte
  {
		res[i]=~a[i];
	}
	big_val(um,1); // obtem o complemento a dois
	big_sum(res,res,um);
}

void big_sub(BigInt res, BigInt a, BigInt b)
{
  BigInt bneg;  // b negativo
  big_comp2(bneg,b);
  big_sum(res,a,bneg); // -b+a=a-b
}

//simplesmente copia um  BigInt byte a byte
void big_copia(BigInt res, BigInt a){
	int i;
  	if(res == a) return;
  	for(i=0;i<NUM_BYTES;i++)
  		res[i]=a[i];
}

void big_mul(BigInt res, BigInt a, BigInt b)
{
  int i,j,aux,carry;
  BigInt temp, parcial;
  big_val(temp, 0);
  for(i=0; i<NUM_BYTES; i++)
  {
    big_val(parcial,0);		// variavel para armazenar os resultados parciais
    carry=0;
    for(j=i; j<NUM_BYTES; j++)
    {
      aux=((a[i]*b[j-i])+carry);  // multiplica o i do a com todos do b guarda o resultado em aux
      parcial[j] =aux&0xFF; //  resultado parcial recebe apenas a parte que "cabe" em 1 byte
      carry=aux>>8;                // carry pega o overflow
    }
    big_sum(temp,temp,parcial);      // soma o resultado parcial da multiplicacao de a[i] por b com a os resultados anteriores, a cada iteração
  }
  big_copia(res,temp);
}
