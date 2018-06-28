#include <stdio.h>
#include <stdlib.h>
#include "../../geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

  // teste varios imul
    /* Abre o arquivo fonte */
    if ((myfp = fopen("../../scripts/desvios/jump.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
    printf("teste varios go to\n 15? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

    return 0;
  }
