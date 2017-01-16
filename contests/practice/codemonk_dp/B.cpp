// https://www.hackerearth.com/code-monk-dynamic-programming/algorithm/vibhu-and-his-mathematics/
#include <cstdio>
typedef long long LL;
#define mod 1000000007

int dp[1000001];

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	for(int a=3;a<=1000000;a++)
		dp[a] = ((LL)dp[a-1] + (LL)(a-1)*dp[a-2]) % mod;
	int t; scanf("%d",&t);
	while(t--)
	{
		LL n;
		scanf("%lld",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}

