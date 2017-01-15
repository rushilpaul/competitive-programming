#include <stdio.h>
typedef long long LL;
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		LL ans = 2LL*n*(n-1)*(n-1);
		LL ans1;
		if(n >= 2)
		{
			ans1 = 3LL*n*(n-1)*(n-2);
			ans += ans1;
		}
		if(n >= 3)
		{
			ans1 = 2LL*n*(n-1)*(n-2)*(n-3);
			ans += ans1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
