#include <stdio.h>
#include <math.h>


double foo2 (float a, float b);

int main()
{
  float a,b;
  a = M_PI_2;
  b = 0.5;

  printf("%lf\n",foo2(a,b));

  return 0;

}
