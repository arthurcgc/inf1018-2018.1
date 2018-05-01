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
    big_val(a,1); big_val(b,1);
    printf("%s","a=" );
    imprime_BigInt(a);
    printf("%s","b=" );
    imprime_BigInt(b);
    big_sum(res,a,b);
    printf("res=");
    imprime_BigInt(res);
    return 0;
  }
