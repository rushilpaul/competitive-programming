// Program question at: http://www.codechef.com/AUG13/problems/SHIRO
#include <bits/stdc++.h>
using namespace std;

double dp[10001], tmp[10001];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n],s=0;
		double P[n];
		for(int a=0;a<n;a++)
		{
			scanf("%d",ar+a);
			s += ar[a];
		}
		for(int a=0;a<n;a++)
		{
			scanf("%lf",&P[a]);
			P[a] /= 100.0;
		}
		memset(dp,0,sizeof(double)*(s+1));
		dp[0] = 1;
		for(int a=0;a<n;a++)
		{
			memcpy(tmp,dp,(s+1)*sizeof(double));
			memset(dp,0,sizeof(double)*(s+1));
			
			for(int flags=s; flags >= 0; flags--)
				if(tmp[flags] > 0)
				{
					assert(flags+ar[a] <= s);
					dp[flags + ar[a]] += tmp[flags] * P[a];
					dp[flags] += tmp[flags] * (1-P[a]);
				}
		}
		double ans=0;
		for(int flags=(s+1)/2;flags<=s;flags++)
			ans += dp[flags];
		printf("%lf\n",ans);
	}
	return 0;
}
