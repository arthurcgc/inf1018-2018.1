#include <stdio.h>
#include <stdlib.h>
#include "../../geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

  // teste retorno de constante
    /* Abre o arquivo fonte */
    if ((myfp = fopen("../../scripts/retornos/retcons.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) ();  /* passando parâmetro apropriados */
    printf("teste retorno de constante\n 1500? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

// teste retorno de parametro 1
  /* Abre o arquivo fonte */
  if ((myfp = fopen("../../scripts/retornos/retp1.txt", "r")) == NULL)
  {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função SB */
  funcaoSB = geracod(myfp);
  /* chama a função */
  res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
  printf("teste retorno de p1\n 5? : %d\n", res);
  liberacod(funcaoSB);
  fclose(myfp);

  // teste retorno de parametro 2
    /* Abre o arquivo fonte */
    if ((myfp = fopen("../../scripts/retornos/retp2.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
    printf("teste retorno de p2\n 200? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

    // teste retorno de variavel local
      /* Abre o arquivo fonte */
      if ((myfp = fopen("../../scripts/retornos/retv4.txt", "r")) == NULL)
      {
        perror("Falha na abertura do arquivo fonte");
        exit(1);
      }
      /* compila a função SB */
      funcaoSB = geracod(myfp);
      /* chama a função */
      res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
      printf("teste retorno de variavel local v4\n 4? : %d\n", res);
      liberacod(funcaoSB);
      fclose(myfp);

      // teste retorno de variavel local
        /* Abre o arquivo fonte */
        if ((myfp = fopen("../../scripts/retornos/retv1.txt", "r")) == NULL)
        {
          perror("Falha na abertura do arquivo fonte");
          exit(1);
        }
        /* compila a função SB */
        funcaoSB = geracod(myfp);
        /* chama a função */
        res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
        printf("teste retorno de variavel local v1\n 1? : %d\n", res);
        liberacod(funcaoSB);
        fclose(myfp);

        // teste retorno de variavel local
          /* Abre o arquivo fonte */
          if ((myfp = fopen("../../scripts/retornos/retv2.txt", "r")) == NULL)
          {
            perror("Falha na abertura do arquivo fonte");
            exit(1);
          }
          /* compila a função SB */
          funcaoSB = geracod(myfp);
          /* chama a função */
          res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
          printf("teste retorno de variavel local v2\n 2? : %d\n", res);
          liberacod(funcaoSB);
          fclose(myfp);

          // teste retorno de variavel local
            /* Abre o arquivo fonte */
            if ((myfp = fopen("../../scripts/retornos/retv3.txt", "r")) == NULL)
            {
              perror("Falha na abertura do arquivo fonte");
              exit(1);
            }
            /* compila a função SB */
            funcaoSB = geracod(myfp);
            /* chama a função */
            res = (*funcaoSB) (5,200);  /* passando parâmetro apropriados */
            printf("teste retorno de variavel local v3\n 3? : %d\n", res);
            liberacod(funcaoSB);
            fclose(myfp);

            return 0;
  }
