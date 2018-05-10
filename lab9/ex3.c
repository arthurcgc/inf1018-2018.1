#include <stdio.h>

void foo (int a[], int n);

int main()
{
  int i,n=10;
  int v[10]={1,2,3,0,4,0, 10, 5, 0, 7};
  foo(v,n);
  for(i=0;i<n;i++)
  printf("%d\n",v[i]);
  return 0;
}
