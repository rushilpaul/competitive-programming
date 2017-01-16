#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL dp[62][62];

int main()
{
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	for(int i=1;i<=60;i++)
		dp[i][0] = 1;
	for(int i=2;i<=60;i++)
		for(int n=1;n<=i;n++)
			dp[i][n] = dp[i-1][n] + dp[i-1][n-1];
	int t; scanf("%d",&t);
	while(t--)
	{
		LL n,k; scanf("%lld %lld",&n,&k);
		int ans[(int)n];
		memset(ans,0,sizeof(int)*n);
		int i = n, j = 0;
		LL last = -1;
		while(k > 0)
		{
			last = k;
			k -= dp[i][j];
			j++;
		}
		k = last;
		j--;
		while(1)
		{
			LL diff = k - dp[i][j];
			//printf("%lld\n",diff);
			if(diff == 0)
			{
				for(int a=n-i;a<n and j>0;a++,j--)
					ans[a] = 1;
				break;
			}
			if(diff > 0)
			{
				k = diff;
				ans[n-i-1] = 1;
				j--;
			}
			else
				i--;
		}
		LL x = 0;
		for(int a=0;a<n;a++)
		{
			x <<= 1;
			if(ans[a])
				x++;
		}
		printf("%lld\n",x);
	}
		return 0;
}

