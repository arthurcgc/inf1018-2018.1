#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

int main(int argc, char *argv[]) {
  FILE *myfp;
  funcp funcaoSB;
  int res;

  /* Abre o arquivo fonte */
  if ((myfp = fopen("SB.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);

  /* chama a função */
  res = (*funcaoSB) ();  /* passando parâmetro apropriados */
  printf("\n 1? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
  return 0;
}
