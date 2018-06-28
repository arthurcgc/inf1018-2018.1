#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

// teste JUMP
  /* Abre o arquivo fonte */
  if ((myfp = fopen("scripts/jump.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (5);  /* passando parâmetro apropriados */
  printf("teste pulo incondicional\n 5? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);

  // teste IF
    /* Abre o arquivo fonte */
    if ((myfp = fopen("scripts/if.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) (0);  /* passando parâmetro apropriados */
    printf("teste pulo condicional(if)\n -2? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

  return 0;
}
