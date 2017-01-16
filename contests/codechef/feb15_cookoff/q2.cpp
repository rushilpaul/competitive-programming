#include <fastio>
#include <cstring>
typedef long long LL;

int dp[1801][301][10];
int mod = 1000000007;

int f(int r, int b, int w)
{
	if(r < 0 or b < 0 or w < 0) return 0;
	if(r == 0 and b == 0) return 1;
	int &val = dp[r][b][w];
	if(val >= 0) return val;
	val = (((LL)f(r,b-1,w) + f(r-4,b-1,w) ) % mod + f(r-6,b-1,w) + f(r,b-1,w-1)) % mod;
	return val;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int t; scanf("%d",&t);
	while(t--)
	{
		int R,B,L; scanf("%d %d %d",&R,&B,&L);
		if(R > 6*B) printf("0\n");
		else
		{
			printf("%d\n",f(R,B,L));
		}
	}
	return 0;
}

