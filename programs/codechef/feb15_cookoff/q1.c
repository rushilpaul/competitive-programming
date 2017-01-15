#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int b; scanf("%d",&b);
		int c = (b-2)/2;
		printf("%d\n",c*(c+1)/2);
	}
	return 0;
}
