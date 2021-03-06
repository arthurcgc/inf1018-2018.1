#define NUM_BYTES 16
typedef unsigned char BigInt[NUM_BYTES];
/* Atribuição (com extensão) */
void big_val (BigInt res, long val);  //feito

/* Operações Aritméticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a); //feito

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b); //feito

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b); //feito

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b); //feito

/* Operações de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n);

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n);
