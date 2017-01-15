#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL dp[1001][50][51];
int n,p,m;
int mod = 998244353;

int main()
{
	scanf("%d %d %d",&n,&p,&m);
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++)
			dp[i][0][0] = 1;

	for(int s=1;s<=9;s++)
		dp[1][s%p][s] = 1;

	for(int i=2;i<=n;i++)
		for(int s=1;s<=m;s++)
			for(int d=0;d<=9 and s-d >= 0;d++)
				for(int r=0;r<p;r++)
					dp[i][(r*10 + d) % p][s] = (dp[i][(r*10 + d) % p][s] + dp[i-1][r][s-d]) % mod;

	//for(int r=0;r<p;r++)
		//for(int s=0;s<=m;s++) printf("r=%d, s=%d, ans=%lld\n",r,s,dp[2][r][s]);

	LL q=dp[n][0][0];
	printf("%lld ",q);
	for(int a=1;a<=m;a++)
	{
		q = (q + dp[n][0][a]) % mod;
		printf("%lld ",q);
	}

	return 0;
}


