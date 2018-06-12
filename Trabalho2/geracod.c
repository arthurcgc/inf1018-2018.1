/* Arthur Cavalcante Gomes Coelho 1313099 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 2000
#define MAX_LINE_SIZE 200
#define MAX_LINES 20


void liberacod(void *pf)
{
  free(pf);
}

typedef int (*funcp) ();

funcp *geracod(FILE *f);
{
  unsigned char* codeBlock = (unsigned char*) malloc(TAM_MAX); //bloco aonde vai ser armazenado codigo de maquina
  char *line = (char*)malloc(sizeof(char)*MAX_LINE_SIZE);;
  int linesread, pos_codeBlock = 0;

  if(*codeBlock == NULL)
  {
    fprintf(stderr, "Falta de memoria ao alocar espaco para codigo SB.\n");
    exit(EXIT_FAILURE);
  }

  prologo(codeBlock, &pos_codeBlock);
  while( fscanf(f, " %[^\n]", line) == 1 && readLines<LINE_MAX)
  {
    linesread++;
    parseLine(line, *codeBlock, &pos_codeBlock);

  }
  finaliza(codeBlock,&pos_codeBlock);

}

static void parseLine(char *line, void *codeBlock, int *pos_codeBlock)
{
  int i;
  char type;
  if (line[0] == 'r' )
  {
    if (sscanf(line+1, "et %c%d", &type, &i) != 2)
    {
      error("comando invalido", linha);
    }

      addRet(codeBlock,pos_codeBlock, i, type);
      return;
  }

}

static void prologo(void *codeBlock, int *pos_codeBlock)
{
  //push  %ebp
  //movq  %rsp, %rbp
    codeBlock[(*pos_codeBlock)++] = 0x55;
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0xe5;
}


static void addRet(void *codeBlock, int *pos_codeBlock, int i, char type)
{
  if(type == 'p' && i == 1)
  {
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0xf8;
  }
  else if (type == 'c')
  {

  }
  else
  {
    error("comando invalido", linha);
  }
}

static void finaliza(void *codeBlock, int *pos_codeBlock)
{
  codeBlock[(*pos_codeBlock)++] = 0xc9;
  codeBlock[(*pos_codeBlock)++] = 0xc3;
}
