#include <stdio.h>
#define mod 1000000007ULL
typedef unsigned long long ULL;

ULL dec2bin(int n)
{
	return n == 1 ? 1ULL : dec2bin(n/2)*10ULL + n%2;
}

ULL f(ULL e)
{
	ULL ans = 1, base = 2;
	while(e > 0)
	{
		if(e & 1 == 1) ans = (ans * base) % mod;
		e >>= 1;
		base = (base * base) % mod;
	}
	return ans;
}

int main()
{
	int t; scanf("%d",&t);
	ULL ans;
	while(t--)
	{
		int n; scanf("%d",&n);
		ULL bin = dec2bin(n);
		ans = f(bin);
		ans = ans * ans;
		printf("%llu\n",ans % mod);
	}
}
