#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL pow1(LL b, LL e, LL mod)
{
	if(e == 0) return 1;
	LL ans = pow1(b,e/2,mod);
	ans = (ans * ans) % mod;
	if(e&1) return (ans*b)%mod;
	else return ans;
}

inline LL pow(LL b, LL e, LL mod)	// mod should be prime
{
	if(e < 0)
		return pow1(pow1(b,-e,mod),mod-2,mod);
	else return pow1(b,e,mod);
}


int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		LL ar[n];
		map<LL,int> m;
		for(int a=0;a<n;a++)
		{
			scanf("%lld",ar+a);
			LL tmp = ar[a];
			for(LL i=2;i<=tmp;i++)
			{
				if(i*i > tmp)
				{
					if(m.find(tmp) != m.end())
						m[tmp] = m[tmp] + 1;
					else
						m[tmp] = 1;
					break;
				}
				int c=0;
				while(tmp % i == 0)
				{
					c++;
					tmp /= i;
				}
				if(m.find(i) != m.end())
					m[i] = m[i] + c;
				else
					m[i] = c;
			}
		}
		int sq=1,cube=1;
		for(auto e : m)
		{
			if(e.second % 2 != 0) sq = 0;
			if(e.second % 3 != 0) cube = 0;
		}
		int mod = 1000000007;
		LL p=1;
		for(auto e : m)
		{
			if(e.second % 3)
			{
				int exp = e.second + 3-e.second%3;
				p = (p * pow(e.first,exp,mod)) % mod;
			}
			else
				p = (p * pow(e.first,e.second,mod)) % mod;
		}
		printf("%lld\n",p);
	}
	return 0;
}
