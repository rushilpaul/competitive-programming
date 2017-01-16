#include <stdio.h>

void swap(char **a, char **b)
{
	char *c;
	c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	char ar[2][4];
	ar[0] = "abc\0";
	ar[1] = "xyz\0";
	printf("%s %s\n",ar[0],ar[1]);
	swap(&ar[0],&ar[1]);
	printf("%s %s\n",ar[0],ar[1]);
	return 0;
}
