#include <stdio.h>
#include <string.h>
int main(int nargs, char **args)
{
	int a,n=atoi(args[1]),t=atoi(args[2]);
	for(a=0;a<t;a++)
		printf("%d",(1<<(t-a-1)) & n ? 1 : 0);
	printf("\n");
	return 0;
}
