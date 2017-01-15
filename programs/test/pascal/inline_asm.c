#include <stdio.h>

int gcd( int a, int b )
{
	int result ;
	asm (	"movl %1, %%eax;"
			"movl %2, %%ebx;"
			"CONTD: cmpl $0, %%ebx;"
			"je DONE;"
			"xorl %%edx, %%edx;"
			"idivl %%ebx;"
			"movl %%ebx, %%eax;"
			"movl %%edx, %%ebx;"
			"jmp CONTD;"
			"DONE: movl %%eax, %0;"
			: "=r" (result)
			: "r" (a), "r" (b)
		);
	return result;
}

void f(int a, int b)
{
	int q,r;
	asm (
		"movl %2, %1;"
		: "=a" (q)
		: "a" (a), "b" (b)
		);
	printf("%d\n",q);
}

int main(int nargs, char **args)
{
	int a = atoi(args[1]), b = atoi(args[2]);
	f(a,b);
	return 0;
}
