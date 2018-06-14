/*
float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/

.text

.global foo

foo:

	pushq	%rbp
	movq	%rsp,%rbp
	
	movsd	%xmm0,%xmm2  /* salva a */
	movsd	%xmm1,%xmm3  /* salva b */
	
	addsd	%xmm0,%xmm1  /* a + b */
	subsd	%xmm3,%xmm2  /* a = a - b */
	
	mulsd	%xmm1,%xmm2  /* (a+b)*(a-b) */
	
	movsd	%xmm2,%xmm0  /* return (a+b)*(a-b) */
	cvtsd2ss	%xmm0,%xmm0  /* return (float) (a+b)*(a-b) */
	
	leave
	ret
