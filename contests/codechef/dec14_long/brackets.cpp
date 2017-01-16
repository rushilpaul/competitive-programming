#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int mod = 1000000007;
int ar[101], n;
LL dp[101][101];

LL f(int i, int j)
{
	if(i >= j) return 1;
	LL &r = dp[i][j];
	if(r >= 0) return r;	
	LL ans = f(i+1,j);
	if(ar[i] < 0)
	{
		for(int a=i+1;a<=j;a++)
			if(ar[a] == -ar[i]) ans = (ans + f(i+1,a-1) * f(a+1,j)) % mod;
	}
	return r = ans;
}

int main()
{
	scanf("%d",&n);
	for(int a=0;a<n;a++) scanf("%d",ar+a);
	map<int,int> m;
	int q=1;
	for(int a=0;a<n;a++)
	{
		int b = ar[a];
		int t = m[abs(b)];
		if(!t)
		{
			m[abs(b)] = q++;
			ar[a] = b>0 ? q-1 : 1-q;
		}
		else ar[a] = b>0 ? t : -t;
	}
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",f(0,n-1));
	return 0;
}
