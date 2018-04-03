#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}


int main()
{
	signed char sc = -1;
	unsigned int ui;
	printf("dump de sc\n");
	dump (&sc,sizeof(sc));
	printf("\n");
	printf("dump de ui ANTES da atribuição ui=sc\n");
	dump (&ui,sizeof(ui));
	printf("\n");
	ui=sc;
	printf("dump de ui DEPOIS da atribuição ui=sc\n");
	dump (&ui,sizeof(ui));
	return 0;

}
