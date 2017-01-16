#include <stdio.h>
#define mod 1000000007
typedef long long LL;

LL f(int n)
{
	if(!n) return 1;
	LL p = f(n/2);
	p *= p;
	if(n&1) return (p << 1) % mod;
	else return p % mod;
}

int main()
{
	int t; scanf("%d",&t);
	LL ans;
	while(t--)
	{
		int n; scanf("%d",&n);
		ans = f(n)%mod - 1;
		if(ans < 0) ans += mod;
		printf("%lld\n",ans);
	}
}
