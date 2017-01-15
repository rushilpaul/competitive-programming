#include <stdio.h>
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int n,d,tmp,ans=1; scanf("%d\n%d",&n,&d);
		n--;
		while(n--)
		{
			scanf("%d",&tmp);
			if(tmp < d) { ans++; d = tmp; }
		}
		printf("%d\n",ans);
	}
	return 0;
}
