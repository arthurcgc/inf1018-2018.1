#include <stdio.h>
#include <math.h>

float float2(float f);

int main(void)
{
	float f = 0.33333333333333333333;
	//float2	
	printf("%f\n", float2(f));
	f = -10;
	printf("%f\n", float2(f));
	f = 10;
	printf("%f\n", float2(f));
	f = 12334676456345667450.;
	printf("%f\n", float2(f));
	f = -12334676345665.;
	printf("%f\n", float2(f));
}
