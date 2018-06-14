#include <stdio.h>
#include <math.h>

#define makefloat(s,e,f) (((s) & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)


typedef union { 
  float f;
  unsigned int i;
 } U;


float float2(float f)
{
	if(f == 0) return 0;
	U u;
	u.f = f;
	unsigned int x = u.i;
	unsigned int exp = (x >> 23) & 0xFF;
	exp++;
	if(exp >=  255)
	{
		if(f > 0) u.i =  makefloat(0,255,0);
		else u.i = makefloat(1,255,0);
	}
	else
	{
		u.i = (x & 0x807fffff) | (exp<<23);
	}
	return u.f;
	
}
