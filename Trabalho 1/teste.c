#include "bigint.h"
#include <stdio.h>

void imprime_BigInt(BigInt a)
{
  printf("%s","0x" );
  for(int i=0;i<NUM_BYTES;i++)
  {
    printf("%02x",a[i]);
  }
  printf("\n");
}

  int main()
  {

    BigInt res;
    BigInt a,b;
    big_val(a,2); big_val(b,3);
    printf("%s","a=" );
    imprime_BigInt(a);
    printf("%s","b=" );
    imprime_BigInt(b);
    big_sum(res,a,b);
    printf("sum=");
    imprime_BigInt(res);
    big_sub(res,a,b);
    printf("sub=");
    imprime_BigInt(res);
    printf("Complemento a dois de b\n");
    big_comp2(res,b);
    imprime_BigInt(res);
    printf("a*b=");
    big_mul(res,a,b);
    imprime_BigInt(res);
    return 0;
  }
