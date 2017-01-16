// https://www.codechef.com/problems/COUPON
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

vector<int> C[1000000], D[1000000];
LL min_ans[1000000];
int M;
int n,m;

LL f(int i, int j, vector< vector<LL> > &dp)
{
	if(i == n-1) return min(M, max(0,C[i][j] - D[i-1][j]));
	if(i >= n) return 0;
	if(dp[i][j] >= 0) return dp[i][j];

	LL res = LLONG_MAX;
	if(min_ans[i] >= 0)
	{
		res = min(min_ans[i], max(0,C[i][j] - D[i-1][j]) + f(i+1,j,dp));
		return dp[i][j] = res;
	}
	for(int b=0;b<m;b++)
	{
		LL q = C[i][b] + f(i+1,b,dp);
		res = min(res,q);
	}
	min_ans[i] = res;
	res = min(res, max(0,C[i][j] - D[i-1][j]) + f(i+1,j,dp));
	return dp[i][j] = res;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		vector< vector<LL> > dp(n);
		for(int a=0;a<n;a++)
		{
			int min_ele = INT_MAX;
			C[a].clear();
			min_ans[a] = -1;
			for(int b=0;b<m;b++)
			{
				int p; scanf("%d",&p);
				min_ele = min(min_ele,p);
				C[a].push_back(p);
				dp[a].push_back(-1);
			}
			M = min_ele;
		}
		for(int a=0;a<n;a++)
		{
			D[a].clear();
			for(int b=0;b<m;b++)
			{
				int p; scanf("%d",&p);
				D[a].push_back(p);
			}
		}
		if(n == 1)
		{
			printf("%d\n",M);
			continue;
		}
		LL ans = LLONG_MAX;
		for(int a=0;a<m;a++)
			ans = min(ans, C[0][a] + f(1,a,dp));
		printf("%lld\n",ans);
	}
	return 0;
}

