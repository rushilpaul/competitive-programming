#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

inline LL pow(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(e & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}

template<class T>
T egcd(T a, T b, T &x, T &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}

LL inv(LL a, LL m)
{
	LL inv,y;
	assert(egcd(a,m,inv,y) == 1);
	if(inv < 0) inv += m;
	return inv;
}
 
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

#define mod 2003

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int N,K,L,F;
		scanf("%d %d %d %d",&N,&K,&L,&F);
		assert(F == 1);
		LL ans = pow(K,L,mod);
		if(gcd(ans, mod) != 1)
		{
			printf("0\n");
			continue;
		}
		ans = inv(ans,(LL)mod);
		for(int n=0;n<L;n++)
		{
			ans = ans * (N-n) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
