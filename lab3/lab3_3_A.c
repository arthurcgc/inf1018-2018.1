#include <stdio.h>

unsigned char switch_byte(unsigned char x)
{ 
    unsigned char mask1,mask2;
    mask1 = x>>4;
    mask2 = x<<4;
    return mask1|mask2;
}


int main()
{
    unsigned char x = 0xAB;
    printf("%02x\n",switch_byte(x));
    return 0;
}
