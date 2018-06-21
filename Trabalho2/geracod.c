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

void prologo(unsigned char *codeBlock, int *pos_codeBlock);


void addRet(unsigned char *codeBlock, int *pos_codeBlock, int i, char type);

void finaliza(unsigned char *codeBlock, int *pos_codeBlock);

void parseLine(char *line, unsigned char *codeBlock, int *pos_codeBlock);


funcp geracod(FILE *f)
{
  unsigned char* codeBlock = (unsigned char*) malloc(TAM_MAX); //bloco aonde vai ser armazenado codigo de maquina
  char *line = (char*)malloc(sizeof(char)*MAX_LINE_SIZE);;
  int linesread, pos_codeBlock = 0;

  if(codeBlock == NULL)
  {
    fprintf(stderr, "Falta de memoria ao alocar espaco para codigo SB.\n");
    exit(EXIT_FAILURE);
  }

  prologo(codeBlock, &pos_codeBlock);
  while( fscanf(f, " %[^\n]", line) == 1 && linesread<MAX_LINES)
  {
    linesread++;
    parseLine(line, codeBlock, &pos_codeBlock);

  }

  finaliza(codeBlock,&pos_codeBlock);
  return (funcp) ((codeBlock));
}

void parseLine(char *line, unsigned char *codeBlock, int *pos_codeBlock)
{
  int i;
  char type;
  if (line[0] == 'r' )
  {
    if (sscanf(line+1, "et %c%d", &type, &i) != 2)
    {
      fprintf(stderr, "comando invalido");
      exit(EXIT_FAILURE);
    }
      addRet(codeBlock,pos_codeBlock, i, type);
      return;
  }

}

void prologo(unsigned char *codeBlock, int *pos_codeBlock)
{
  //push  %ebp
  //movq  %rsp, %rbp
    codeBlock[(*pos_codeBlock)++] = 0x55;
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0xe5;
    return;
}


void addRet(unsigned char *codeBlock, int *pos_codeBlock, int i, char type)
{
  if(type == 'p' && i == 1)
  {
    //  mov    %rdi,%rax
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0xf8;
  }
  else if (type == 'c')
  {

  }
  else if(type == '$')
  {

  }
  else
  {
    fprintf(stderr, "comando invalido\n");
    exit(EXIT_FAILURE);
  }
}

void finaliza(unsigned char *codeBlock, int *pos_codeBlock)
{
  //  leave ret
  codeBlock[(*pos_codeBlock)++] = 0xc9;
  codeBlock[(*pos_codeBlock)++] = 0xc3;
}
