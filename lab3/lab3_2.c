#include <stdio.h>


int odd_ones(unsigned int x)
{
    int i,uns,r;
    unsigned int y = 0x01;
    uns=0;
    for (i=0;i<sizeof(x)*8;i++)
    {
        if((x&y)!=0) uns++;
        x = x >> 1;
    }
    r = uns & y;
    return r;
}

int main() 
{
    printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
    printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
    return 0;
}
