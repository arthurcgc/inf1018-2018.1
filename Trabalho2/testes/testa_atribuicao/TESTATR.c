#include <stdio.h>
#include <stdlib.h>
#include "../../geracod.h"

int main(int argc, char *argv[])
{
  FILE *myfp;
  int res;
  funcp funcaoSB;

  // teste mov p1 constante
    /* Abre o arquivo fonte */
    if ((myfp = fopen("../../scripts/atribuicao/movp1.txt", "r")) == NULL)
    {
      perror("Falha na abertura do arquivo fonte");
      exit(1);
    }
    /* compila a função SB */
    funcaoSB = geracod(myfp);
    /* chama a função */
    res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
    printf("teste p1 := $10 de constante\n 10? : %d\n", res);
    liberacod(funcaoSB);
    fclose(myfp);

    // teste mov p2 constante
      /* Abre o arquivo fonte */
      if ((myfp = fopen("../../scripts/atribuicao/movp2.txt", "r")) == NULL)
      {
        perror("Falha na abertura do arquivo fonte");
        exit(1);
      }
      /* compila a função SB */
      funcaoSB = geracod(myfp);
      /* chama a função */
      res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
      printf("teste p2 := $20 de constante\n 20? : %d\n", res);
      liberacod(funcaoSB);
      fclose(myfp);


    // teste mov p2 v2
      /* Abre o arquivo fonte */
      if ((myfp = fopen("../../scripts/atribuicao/movp2v2.txt", "r")) == NULL)
      {
        perror("Falha na abertura do arquivo fonte");
        exit(1);
      }
      /* compila a função SB */
      funcaoSB = geracod(myfp);
      /* chama a função */
      res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
      printf("teste 1- v2 := $50\nteste 2- p2 := v2 \n 50? : %d\n", res);
      liberacod(funcaoSB);
      fclose(myfp);

      // teste mov p1 v3
        /* Abre o arquivo fonte */
        if ((myfp = fopen("../../scripts/atribuicao/movp1v3.txt", "r")) == NULL)
        {
          perror("Falha na abertura do arquivo fonte");
          exit(1);
        }
        /* compila a função SB */
        funcaoSB = geracod(myfp);
        /* chama a função */
        res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
        printf("teste 1- v3 := $150\nteste 2- p1 := v3 \n 150? : %d\n", res);
        liberacod(funcaoSB);
        fclose(myfp);

      // teste mov v1 v3
        /* Abre o arquivo fonte */
        if ((myfp = fopen("../../scripts/atribuicao/movv1v3.txt", "r")) == NULL)
        {
          perror("Falha na abertura do arquivo fonte");
          exit(1);
        }
        /* compila a função SB */
        funcaoSB = geracod(myfp);
        /* chama a função */
        res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
        printf("teste v1 := v3 \n 250? : %d\n", res);
        liberacod(funcaoSB);
        fclose(myfp);

        // teste mov v1 p2
          /* Abre o arquivo fonte */
          if ((myfp = fopen("../../scripts/atribuicao/movv1p2.txt", "r")) == NULL)
          {
            perror("Falha na abertura do arquivo fonte");
            exit(1);
          }
          /* compila a função SB */
          funcaoSB = geracod(myfp);
          /* chama a função */
          res = (*funcaoSB) (200,300);  /* passando parâmetro apropriados */
          printf("teste v1 := p2 \n 300? : %d\n", res);
          liberacod(funcaoSB);
          fclose(myfp);

          // teste mov v2 p1
            /* Abre o arquivo fonte */
            if ((myfp = fopen("../../scripts/atribuicao/movv2p1.txt", "r")) == NULL)
            {
              perror("Falha na abertura do arquivo fonte");
              exit(1);
            }
            /* compila a função SB */
            funcaoSB = geracod(myfp);
            /* chama a função */
            res = (*funcaoSB) (100,300);  /* passando parâmetro apropriados */
            printf("teste v2 := p1 \n 100? : %d\n", res);
            liberacod(funcaoSB);
            fclose(myfp);

      return 0;
}
