#include <stdio.h>

double foo (double a, int b);

struct X {
  int vi;
  double vd;
  struct X *next;
};

double pack (struct X *px) {
  double acc = 0;
  while (px != NULL) {
    acc += foo(px->vd, px->vi);
    px = px->next;
  }
  return acc;
}

int main()
{
  struct X b = {6, 6.5, NULL};
  struct X a = {5, 5.5, &b};

  printf("%f\n", pack(&a));

  return 0;

}
