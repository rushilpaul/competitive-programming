#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,n,k; scanf("%d %d",&n,&k);
		if(n == 1 && k == 1) { printf("1\n"); continue; }
		if(n/2 >= k)
		{
			for(a=2;a<=n && k;a+=2,k--)
				printf("%d ",a);
			printf("\n");
		}
		else
			printf("-1\n");
	}
}
