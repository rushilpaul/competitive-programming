//Program question at: http://www.codechef.com/MAY12/problems/DIVPAIR
#include <stdio.h>
typedef unsigned long long ULL;
int main()
{
	int t,m,n,a; ULL ans=0;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		ans=0;
		for(a=1;a<n;a++)
			ans += (n+a)/m - (a<<1)/m;
		printf("%llu\n",ans);
	}
	return 0;
}
