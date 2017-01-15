//Program question at: http://www.codechef.com/SEP12/problems/CKISSHUG
#include <stdio.h>
typedef long long LL;
#define mod 1000000007LL
LL ans;
LL f(LL n)
{
	LL tmp;
	if(n==0) return 1;
	if(n%2)
	{
		tmp = f((n-1)/2);
		tmp = ((tmp*tmp)<<1);
	}
	else
	{
		tmp = f(n/2);
		tmp = tmp*tmp;
	}
	return tmp%mod;
}

int main()
{
	int t;
	LL n,count; scanf("%d\n",&t);
	while(t--)
	{
		ans = 0;
		scanf("%lld",&n);
		if(n&1)
			printf("%lld\n",f((n+3)/2)-2);
		else
			printf("%lld\n",(3*f(n/2)-2)%mod);
	}
	return 0;
}