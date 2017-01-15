#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define PI 3.141592653589793238462643383279502884197

inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

LL dp[101][101], ar[101], F[101];

int get(int i, int j)
{
	return (F[j] - (i == 0 ? 0 : F[i-1])) % 100;
}

LL f(int i, int j)
{
	LL &ret = dp[i][j];
	if(ret >= 0) return ret;
	if(j - i == 0) return ret = 0;
	if(j - i == 1) return ret = ar[i] * ar[j];
	LL ans = LLONG_MAX;
	for(int k=i;k<j;k++)
		ans = min(ans, f(i,k) + f(k+1,j) + (LL)get(i,k) * get(k+1,j));
	return ret = ans;
}

int main()
{
	while(1)
	{
		int n; if(scanf("%d",&n) <= 0) break;
		for(int a=0;a<n;a++) scanf("%lld",ar+a);
		F[0] = ar[0];
		for(int a=1;a<n;a++) F[a] = F[a-1] + ar[a];
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",f(0,n-1));
	}
	return 0;
}
