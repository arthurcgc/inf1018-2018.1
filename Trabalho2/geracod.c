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

void addAtribuicao(unsigned char *codeBlock, int *pos_codeBlock, char type1, int i1, char type2, int i2);

void addAdicao(unsigned char *codeBlock, int *pos_codeBlock, char type1, int i1, char type2, int i2);

void finaliza(unsigned char *codeBlock, int *pos_codeBlock);

void parseLine(char *line, unsigned char *codeBlock, int *pos_codeBlock);

static void preenche_cons (unsigned char *codeBlock,int *pos_codeBlock, int num)
{
    int i;
    for(i=0;i<4;i++,(*pos_codeBlock)++)          /*preenche em codeBlock o valor em Hexadecimal do numero int */
        codeBlock[(*pos_codeBlock)]=(unsigned char)(num>>(i*8));
}

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
  int i1,i2;
  char type1,type2;
  if (line[0] == 'r' ) //retorno
  {
    if (sscanf(line+1, "et %c%d", &type1, &i1) != 2)
    {
      fprintf(stderr, "comando invalido\n");
      exit(EXIT_FAILURE);
    }
      addRet(codeBlock,pos_codeBlock, i1, type1);
      return;
  }

  else if (line[0] == 'v' || line[0] == 'p') //operacao
  {
    if(sscanf(line,"%c%d", &type1, &i1) != 2)
    {
      fprintf(stderr, "comando invalido\n");
      exit(EXIT_FAILURE);
    }
    if(line[3] == ':' && line[4] == '=') //atribuicao
    {
      if(sscanf(line+5," %c%d", &type2, &i2) !=2)
      {
        fprintf(stderr, "comando invalido\n");
        exit(EXIT_FAILURE);
      }
      addAtribuicao(codeBlock,pos_codeBlock,type1,i1,type2,i2);
    }
    else if(line[3] == '+' && line[4] == '=') //operacao
    {
      if(sscanf(line+5," %c%d", &type2, &i2) !=2)
      {
        fprintf(stderr, "comando invalido\n");
        exit(EXIT_FAILURE);
      }
      addAdicao(codeBlock,pos_codeBlock,type1,i1,type2,i2);
    }
  }
  return;
}

void addAtribuicao(unsigned char *codeBlock, int *pos_codeBlock, char type1, int i1, char type2, int i2)
{
  //v1 = %r10, v2 = %r11, v3 = %r12, v4= %r13

  //atribuicao de parametro
  if(type1 == 'p')
  {
    if(type2 == 'v')  //caso lado direito = variavel
    {
      codeBlock[(*pos_codeBlock)++] = 0x4c;
      codeBlock[(*pos_codeBlock)++] = 0x89;
      if(i1 == 1)
      {
        //movq %rxd,%rdi
        codeBlock[(*pos_codeBlock)++] = (0xd7 - 0x8) + i2 * 0x8;//desloca conforme o índice
      }
      else if(i1 == 2)
      {
        //movq %rxd,%rsi
        codeBlock[(*pos_codeBlock)++] = (0xd6 - 0x8) + i2 * 0x8;//desloca conforme o índice
      }
    }
    else if(type2 == 'p' && i1 != i2)  //caso lado direito = parametro
    {
      //movq %rsi,%rdi ou movq %rdi,%rsi
      codeBlock[(*pos_codeBlock)++] = 0x48;
      codeBlock[(*pos_codeBlock)++] = 0x89;

      // p1 := p2 -> movq %rsi,%rdi
      if(i1 == 1) codeBlock[(*pos_codeBlock)++] = 0xf7;

      //  p2 := p1 ->movq %rdi,%rsi
      else if(i1 == 2)  codeBlock[(*pos_codeBlock)++] = 0xfe;
    }
    else if(type2 == '$')  //caso lado direito = constante
    {
      //movq $x,%rdi ou %rsi
      codeBlock[(*pos_codeBlock)++] = 0x48;
      codeBlock[(*pos_codeBlock)++] = 0xc7;
      codeBlock[(*pos_codeBlock)++] = (0xc7 + 0x1) - 0x1 *i1 ;
      // preenche o numero int no codeBlock para terminar a intrucao de mov
      preenche_cons(codeBlock, pos_codeBlock, i2);
    }
  }
  //fim de attribuicao a parametro

  //atribuicao de variavel
  else if(type1 == 'v')
  {
    if(type2 == '$') //lado direto = constante
    {
        //  movq = $x,%rxd
        codeBlock[(*pos_codeBlock)++] = 0x49;
        codeBlock[(*pos_codeBlock)++] = 0xc7;
        codeBlock[(*pos_codeBlock)++] = (0xc2 - 0x1) + i1 * 0x1; //desloca conforme o índice
        preenche_cons(codeBlock, pos_codeBlock, i2);
    }
    else if(type2 == 'v' && i2 != i1) //lado direito = variavel
    {
        //  movq = %rxd,%rxd
      codeBlock[(*pos_codeBlock)++] = 0x4d;
      codeBlock[(*pos_codeBlock)++] = 0x89;
      codeBlock[(*pos_codeBlock)++] = ((0xd1 + 0x1 * i1) - 0x8) + 0x8 * i2;//desloca conforme os índices
    }
    else if(type2 == 'p') //lado direito = parametro
    {
      //  movl = $e(ds)i,%exd
      codeBlock[(*pos_codeBlock)++] = 0x49;
      codeBlock[(*pos_codeBlock)++] = 0x89;
      codeBlock[(*pos_codeBlock)++] = (0xf9 + 0x1 * i1 + 0x8) - 0x8 * i2;//desloca conforme os índices
    }
  }
  return;
}

void addAdicao(unsigned char *codeBlock, int *pos_codeBlock, char type1, int i1, char type2, int i2)
{
  if(type1 == 'p') //adicao de parametro (px += $y) -> addl $y,%e(ds)i
  {
    if(type2 == '$')
    {
      codeBlock[(*pos_codeBlock)++] = 0x48;
      codeBlock[(*pos_codeBlock)++] = 0x81;
      codeBlock[(*pos_codeBlock)++] =  (0xc7 + 0x1) - 0x1 * i1;
      preenche_cons(codeBlock,pos_codeBlock,i2);
    }
    else if(type2 == 'v')
    {

    }
  }
  return;
}

void prologo(unsigned char *codeBlock, int *pos_codeBlock)
{

  //pushq  %rbp
  //movq  %rsp, %rbp
    codeBlock[(*pos_codeBlock)++] = 0x55;
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0xe5;

  // subq $32,%rsp
    codeBlock[(*pos_codeBlock)++] = 0x48;
    codeBlock[(*pos_codeBlock)++] = 0x83;
    codeBlock[(*pos_codeBlock)++] = 0xec;
    codeBlock[(*pos_codeBlock)++] = 0x20;

  //movq %r10,(%rsp)
    codeBlock[(*pos_codeBlock)++] = 0x4c;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0x14;
    codeBlock[(*pos_codeBlock)++] = 0x24;

  // movq %r11,8(%rsp)
    codeBlock[(*pos_codeBlock)++] = 0x4c;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0x5c;
    codeBlock[(*pos_codeBlock)++] = 0x24;
    codeBlock[(*pos_codeBlock)++] = 0x08;

  // movq %r12,16(%rsp)
    codeBlock[(*pos_codeBlock)++] = 0x4c;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0x64;
    codeBlock[(*pos_codeBlock)++] = 0x24;
    codeBlock[(*pos_codeBlock)++] = 0x10;

  // movq %r13,24(%rsp)
    codeBlock[(*pos_codeBlock)++] = 0x4c;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = 0x6c;
    codeBlock[(*pos_codeBlock)++] = 0x24;
    codeBlock[(*pos_codeBlock)++] = 0x18;


    return;
}


void addRet(unsigned char *codeBlock, int *pos_codeBlock, int i, char type)
{
    //utilizarei os registradores de 32 bits para facilitar o entendimento e a didática do codigo já que estamos mexendo com inteiros
  if(type == 'p')
  {
    //  movl    %edi,%eax
      codeBlock[(*pos_codeBlock)++] = 0x89;
      codeBlock[(*pos_codeBlock)++] = (0xf8 + 0x8) - 0x8 * i;
  }
  else if(type == '$')
  {
    //  mov constante
    codeBlock[(*pos_codeBlock)++] = 0xb8;
    preenche_cons (codeBlock, pos_codeBlock, i); // preenche em codeBlock os 8 espaços que o int ocupa
  }
  else if(type == 'v')
  {
    codeBlock[(*pos_codeBlock)++] = 0x44;
    codeBlock[(*pos_codeBlock)++] = 0x89;
    codeBlock[(*pos_codeBlock)++] = (0xd0 - 0x8) + 0x8 * i;
  }
  else
  {
    fprintf(stderr, "comando invalido\n");
    exit(EXIT_FAILURE);
  }
  return;
}

void finaliza(unsigned char *codeBlock, int *pos_codeBlock)
{

  //movq (%rsp),%r10
  codeBlock[(*pos_codeBlock)++] = 0x4c;
  codeBlock[(*pos_codeBlock)++] = 0x8b;
  codeBlock[(*pos_codeBlock)++] = 0x14;
  codeBlock[(*pos_codeBlock)++] = 0x24;

  //movq 8(%rsp),%r11
  codeBlock[(*pos_codeBlock)++] = 0x4c;
  codeBlock[(*pos_codeBlock)++] = 0x8b;
  codeBlock[(*pos_codeBlock)++] = 0x5c;
  codeBlock[(*pos_codeBlock)++] = 0x24;
  codeBlock[(*pos_codeBlock)++] = 0x08;
  //movq 16(%rsp),%r12
  codeBlock[(*pos_codeBlock)++] = 0x4c;
  codeBlock[(*pos_codeBlock)++] = 0x8b;
  codeBlock[(*pos_codeBlock)++] = 0x64;
  codeBlock[(*pos_codeBlock)++] = 0x24;
  codeBlock[(*pos_codeBlock)++] = 0x10;

  //movq 24(%rsp),%r13
  codeBlock[(*pos_codeBlock)++] = 0x4c;
  codeBlock[(*pos_codeBlock)++] = 0x8b;
  codeBlock[(*pos_codeBlock)++] = 0x6c;
  codeBlock[(*pos_codeBlock)++] = 0x24;
  codeBlock[(*pos_codeBlock)++] = 0x18;

  //movq %rbp,%rsp
  //popq  %rbp
  //ret
  codeBlock[(*pos_codeBlock)++] = 0x48;
  codeBlock[(*pos_codeBlock)++] = 0x89;
  codeBlock[(*pos_codeBlock)++] = 0xec;
  codeBlock[(*pos_codeBlock)++] = 0x5d;
  codeBlock[(*pos_codeBlock)++] = 0xc3;

  return;
}
