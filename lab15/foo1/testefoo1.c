#include <stdio.h>
#include <math.h>

float foo1 (float a, float b);

int main(void)
{
	float a = M_PI_2;
	float b = 13.0;
	float f = foo1(a,b);
	printf("%f\n", f);
	return 0;
}
