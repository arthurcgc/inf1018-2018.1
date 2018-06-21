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
  if(val>0) //se for unsigned
  {
	for(i=8;i<NUM_BYTES;i++) res[i]=0; // Preenche o restante com zero
  }
  else  //se for signed
  {
    for(i=8;i<NUM_BYTES;i++)  res[i]=0xFF; // Preenche o restante com uns
  }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b)
{
  	int overflow=0,i;
  	unsigned short soma;
  	for (i=0;i<NUM_BYTES;i++)
    {
  		soma=a[i]+b[i]+overflow; // soma byte a byte + o overflow
  		overflow=soma>>8; // overflow = os "vai um's" na soma de bits
  		res[i]=soma&0xFF; // soma o byte sem se "importar" com o oveflow que será tratado a partir da segunda iteração do loop
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
	big_val(um,1);
	big_sum(res,res,um); // obtem o complemento a dois
}

void big_sub(BigInt res, BigInt a, BigInt b)
{
  BigInt bneg;  // b negativo
  big_comp2(bneg,b);
  big_sum(res,a,bneg); // a+(-b)=a-b
}

//simplesmente copia um  BigInt byte a byte para res
void big_copia(BigInt res, BigInt a)
{
	int i;
  	if(res == a) return;
  	for(i=0;i<NUM_BYTES;i++) res[i]=a[i];
}

void big_mul(BigInt res, BigInt a, BigInt b)
{
  int i,j,aux,overflow;
  BigInt temp, parcial;
  big_val(temp, 0); //para que se possa fazer algo como a=a*b
  for(i=0; i<NUM_BYTES; i++)
  {
    big_val(parcial,0);		// variavel para armazenar os resultados sem o overflow(parciais)
    overflow=0;
    for(j=i; j<NUM_BYTES; j++)
    {
      aux=((a[i]*b[j-i])+overflow);  // multiplica a com b e guarda em aux
      parcial[j] =aux&0xFF; //  parcial armazena apenas o que cabe em um byte
      overflow=aux>>8;                // pega o overflow
    }
    big_sum(temp,temp,parcial);
  }
  big_copia(res,temp);
}

//dummy
void big_shl(BigInt res, BigInt a, int n)
{
  return;
}
//dummy
void big_shr(BigInt res, BigInt a, int n)
{
  return;
}
