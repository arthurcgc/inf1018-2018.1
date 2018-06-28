#include <stdio.h>
#include <stdlib.h>
#include "geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;


  /* testa exemplo1 */
  if ((myfp = fopen("scripts/exempl_enun/ex1.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (1);  /* passando parâmetro apropriados */
  printf("teste enunciado 1\n 2? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
/* FIM testa exemplo1 */

  /*  testa exemplo2 */
  if ((myfp = fopen("scripts/exempl_enun/ex2.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (-1);  /* passando parâmetro apropriados */
  printf("teste enunciado 2\n 1? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
  /* FIM testa exemplo2 */

  /*  testa exemplo3 */
  if ((myfp = fopen("scripts/exempl_enun/ex3.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (5,6);  /* passando parâmetro apropriados */
  printf("teste enunciado 3\n -11? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
  /* FIM testa exemplo2 */

  /*  testa exemplo4 */
  if ((myfp = fopen("scripts/exempl_enun/ex4.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (4);  /* passando parâmetro apropriados */
  printf("teste enunciado 4\n 24? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
  /* FIM testa exemplo4 */

  /*  testa exemplo5 */
  if ((myfp = fopen("scripts/exempl_enun/ex5.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (3,6);  /* passando parâmetro apropriados */
  printf("teste pulo incondicional\n 14? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);
  /* FIM testa exemplo5 */


  return 0;
}
