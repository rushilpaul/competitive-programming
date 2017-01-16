//Program question at: http://www.codechef.com/JULY12/problems/CSUMD
#include <stdio.h>
typedef long long LL;
LL mod = (LL)1000000007;

LL p(int pow)
{
	int a=0; LL ans=1;
	for(;a<pow;a++)
	{
		ans <<= 1;
		ans %= mod;
	}
	return ans;
}

int main()
{
	//printf("%lld\n",p(1000000000));
	//return 0;
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,k; LL n,ans;
		scanf("%lld\n",&n);
		n--;
		k = n/2;
		ans = p(n);
		int sub = n;
		for(a=0;a<k;a++)
		{
			if(a==0) sub--;
			else sub -= 2;
			ans += p(sub);
		}
		n--; k = n/2;
		ans += p(n);
		sub = n;
		for(a=0;a<k;a++)
		{
			if(a==0) sub--;
			else sub -= 2;
			ans += p(sub);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
