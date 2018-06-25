#include <stdio.h>
#include <stdlib.h>
#include "../../geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

  // teste addq p1 constante
    /* Abre o arquivo fonte */
    if ((myfp = fopen("../../scripts/adicao/add150p1.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
    printf("teste p1 += $150 de constante\n 350? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

    // teste addq p1, p2 e variaveis
      /* Abre o arquivo fonte */
      if ((myfp = fopen("../../scripts/adicao/addmany.txt", "r")) == NULL)
      {
        perror("Falha na abertura do arquivo fonte");
        exit(1);
      }
      /* compila a função SB */
      funcaoSB = geracod(myfp);
      /* chama a função */
      res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
      printf("varias somas de variaveis e parametros ao mesmo tempo\n 802? : %d\n", res);
      liberacod(funcaoSB);
      fclose(myfp);

    return 0;
  }
