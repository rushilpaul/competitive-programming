//Program question at: http://www.codechef.com/MAY12/problems/DIVPAIR
#include <stdio.h>
typedef unsigned long long ULL;
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int s,m,n,times; scanf("%d %d",&n,&m);
		ULL ans=0;
		for( times=(2*n-1)/m, s=m; times--; s+=m)
			if(s>n)
				ans += (n-s/2);
			else
			{
				ans += (s/2-1);
				if(s%2) ans++;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
