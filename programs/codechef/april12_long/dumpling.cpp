//Program question at: http://www.codechef.com/APRIL12/problems/DUMPLING
#include <cstdio>
using namespace std;
typedef long long LL;

inline void swap(LL *a, LL *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

long hcf(LL a, LL b)
{ return !a || !b ? a+b : hcf(b,a%b); }

LL lcm(LL a, LL b)
{
	if(a < b) swap(&a,&b);
	LL i=a;
	while(a%b) a+=i;
	return a;
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		LL a,b,c,d,k;
		scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&k);
		printf("%lld\n", 1 + ((k / (lcm(hcf(a,b), hcf(c,d))) ) << 1) );
	}
	return 0;
}
