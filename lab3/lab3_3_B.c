#include <stdio.h>


unsigned char rotate_left(unsigned char x, int n)
{
    unsigned char mask;
    int nbits = sizeof(x)*8;
    mask = (nbits - n) >> x;
    return (x << n) | mask;
}


int main()
{
    unsigned char x = 0x61;
    printf("x = %x\n",rotate_left(x,1));
    printf("x = %x\n",rotate_left(x,2));
    printf("x = %x\n",rotate_left(x,7));
    return 0;
}
