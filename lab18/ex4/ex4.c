#include <stdio.h>

struct X1 {
  int vi;
  float vf;
};


double foo (double a, int b);
  // return a * (-b);
// }


 double pack1 (struct X1 *px, int n);
//   double acc = 0;
//   int i;
//   for (i=0;i<n;i++)
//     acc += foo(px[i].vf, px[i].vi);
//   return acc;
// }

int main()
{
  struct X1 a = {1, 5.5};
  printf("%f\n", pack1(&a,5));

  return 0;
}
