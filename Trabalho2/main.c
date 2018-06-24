#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

// teste retorno de parametro
  /* Abre o arquivo fonte */
  if ((myfp = fopen("scripts/retp1.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (5);  /* passando parâmetro apropriados */
  printf("teste retorno de p1\n 5? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);

  if ((myfp = fopen("scripts/retp2.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  // compila a função SB
  funcaoSB = geracod(myfp);
  // chama a função passando parâmetro apropriados
  res = (*funcaoSB) (5,6);
  printf("teste retorno de p2\n 6? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
//  fim do teste retorno de parametro

//teste retorno de constante

  if ((myfp = fopen("scripts/retcons.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  funcaoSB = geracod(myfp);
  // chama a função passando parâmetro apropriados
  res = (*funcaoSB) ();
  printf("teste retorno de constante $\n 1000? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
//fim do teste retorno de constante

//teste atribuicao + retorno

  if ((myfp = fopen("scripts/mov$p1.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  funcaoSB = geracod(myfp);
  // chama a função passando parâmetro apropriados
  res = (*funcaoSB) (5);
  printf("teste atribuicao de p1\n 1100? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
//fim do teste atribuicao + retorno


//teste testesimples.txt

  if ((myfp = fopen("scripts/testesimples.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  funcaoSB = geracod(myfp);
  // chama a função passando parâmetro apropriados
  res = (*funcaoSB) (10);
  printf("testesimples.txt\n 5442? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
//fim do teste atribuicao + retorno

//teste testesimples.txt

  if ((myfp = fopen("scripts/adicao.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  funcaoSB = geracod(myfp);
  // chama a função passando parâmetro apropriados
  res = (*funcaoSB) (100,200);
  printf("teste adicao\n 300? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
//fim do teste atribuicao + retorno

  return 0;
}
