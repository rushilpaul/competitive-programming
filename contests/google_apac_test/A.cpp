#include <cstdio>
typedef long long LL;

int f(LL n, LL k)
{
	if(n == 1 or k == n/2+1) return 0;
	return k > n/2+1 ? 1 ^ f(n,1+n-k) : f(n/2,k);
}

int main()
{
	int tt; scanf("%d",&tt);
	for(int t=1;t<=tt;t++)
	{
		LL n=1,k;
		scanf("%lld",&k);
		while(n < k)
			n = (n<<1)+1;
		printf("Case #%d: %d\n",t,f(n,k));
	}
	return 0;
}

