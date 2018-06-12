#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

int main(int argc, char *argv[]) {
  FILE *myfp;
  funcp funcaoSB;
  int res;

  /* Abre o arquivo fonte */
  if ((myfp = fopen("programa", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  fclose(myfp);

  /* chama a função */
  res = (*funcaoSB) (....);  /* passando parâmetro apropriados */
  ...
  liberacod(funcaoSB);
  ...
}
