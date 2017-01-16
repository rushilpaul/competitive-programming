#include <bits/stdc++.h>
using namespace std;

double dp[1001][1001];

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n], n2=0;
		for(int a=0;a<n;a++) scanf("%d",&ar[a]);
		for(int a=0;a<n;a++) if(ar[a] == -1) n2++;

		memset(dp,0,sizeof(dp));
		dp[1][1] = 1;
		n = n2;
		for(int a=2;a<=n;a++)
		{
			for(int b=1;b<=a;b++)
			{
				dp[a][b] += dp[a-1][b] / 2.0;
				if(b-1 >= 1)
					dp[a][b] += dp[a-1][b-1] * 0.5 * b / (b-1);
			}
		}
		double ans = 0;
		for(int a=0;a<n;a++)
			ans += dp[n][a+1];
		printf("%f\n",ans);
	}
	return 0;
}
