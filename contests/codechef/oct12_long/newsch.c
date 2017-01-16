//Program question at: http://www.codechef.com/OCT12/problems/NEWSCH
#include <stdio.h>
typedef long long LL;
LL mod = 1000000007LL;

LL f(LL n)
{
	if(n==0) return 1;
	else if(n==1) return 3;
	if(n&1)
		return (3 * (f(n-1)%mod))%mod;
	else
	{
		LL tmp = f(n/2)%mod;
		return (tmp*tmp)%mod;
	}
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		LL n; scanf("%lld",&n);
		LL ans = f(n);
		if(n&1)
		{
			ans -= 3;
			if(ans<0) ans += mod;
		}
		else ans += 3;
		printf("%lld\n",ans%mod);
	}
	return 0;
}
