#include <stdio.h>

float foo (double a, float b);

int main()
{
	double a,b;
	
	a = 25.5;
	b = 11.0;
	
	printf("%lf\n",foo(a,b));

	return 0;
}
