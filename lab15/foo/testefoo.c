#include <stdio.h>

float foo (double a, float b);

int main()
{
	double a,b;

	a = 2.0;
	b = 1.0;

	printf("%lf\n",foo(a,b));

	return 0;
}
