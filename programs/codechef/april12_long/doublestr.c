#include <stdio.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		printf("%d\n", n%2 ? n-1 : n);
	}
	return 0;
}
