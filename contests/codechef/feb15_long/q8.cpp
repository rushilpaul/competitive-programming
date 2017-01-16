#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ar[300][300];
LL dp[300][300];
LL n,m;

inline int check(int a, int b) { return !(a < 0 || b < 0 || a >= n || b >= n); }

LL findmax(int i, int j)
{
	LL &r = dp[i][j];
	//if(r >= 0) return r;
	LL ans=-1;
	if(check(i+1,j) and ar[i+1][j] - ar[i][j] == 1)
		ans = max(ans,findmax(i+1,j));
	if(check(i-1,j) and ar[i-1][j] - ar[i][j] == 1)
		ans = max(ans,findmax(i-1,j));
	if(check(i,j+1) and ar[i][j+1] - ar[i][j] == 1)
		ans = max(ans,findmax(i,j+1));
	if(check(i,j-1) and ar[i][j-1] - ar[i][j] == 1)
		ans = max(ans,findmax(i,j-1));
	ans = max(ans,ar[i][j]);
	return r = ans;
}

LL f(int i, int j)
{
	if(ar[i][j] == m) return 1;
	LL &r = dp[i][j];
	if(r >= 0) return r;
	LL ans=0;
	if(check(i+1,j) and ar[i+1][j] - ar[i][j] == 1)
		ans = f(i+1,j);
	if(check(i-1,j) and ar[i-1][j] - ar[i][j] == 1)
		ans += f(i-1,j);
	if(check(i,j+1) and ar[i][j+1] - ar[i][j] == 1)
		ans += f(i,j+1);
	if(check(i,j-1) and ar[i][j-1] - ar[i][j] == 1)
		ans += f(i,j-1);
	return r = ans;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		m = 0;
		LL L,R; scanf("%lld %lld",&L,&R);
		n = R-L+1;
		for(LL a=L;a<=R;a++)
			for(LL b=L;b<=R;b++)
				ar[a-L][b-L] = a^b;
		LL ans=0;
		for(int a=0;a<n;a++)
		{
			LL r = findmax(a,a);
			m = max(m,r);
		}
		memset(dp,-1,sizeof(dp));
		for(int a=0;a<n;a++)
			ans += f(a,a);
		printf("%lld %lld\n",m,ans);
	}

	return 0;
}
