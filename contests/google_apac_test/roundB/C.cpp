#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

#define MAX 31622777
vector<int> P;
char done[MAX];

void f()
{
	for(int a=2;a*a<=MAX;a++)
	{
		if(done[a]) continue;
		for(int b=a*a;b<=MAX;b+=a)
			done[b] = 1;
	}
	for(int a=2;a<=MAX;a++)
		if(!done[a]) P.push_back(a);
}

int find(LL n)
{
	int s=0;
	while(n)
	{
		s += n%10;
		n /= 10;
	}
	return s;
}

vector<LL> facts;
int dp[1<<20];

int calc(int mask)
{
	if(dp[mask] >= 0) return dp[mask];
	int n = facts.size();
	LL num = 1;
	for(int a=0;a<n;a++)
		if(mask & (1<<a))
			num *= facts[n-1-a];
	if(!done[find(num)]) return dp[mask] = 0;
	for(int a=0;a<n;a++)
	{
		if(mask & (1<<a))
			if(!calc(mask ^ (1<<a))) return dp[mask] = 1;
	}
	return dp[mask] = 0;
}

int main()
{
	f();
	int tt; scanf("%d",&tt);
	for(int t=1;t<=tt;t++)
	{
		printf("Case #%d: ",t);
		LL n; scanf("%lld",&n);
		facts.clear();
		for(int p : P)
		{
			if(p > n) break;
			LL q=1;
			while(n % p == 0)
			{
				n /= p;
				q *= p;
			}
			if(q > 1)
				facts.push_back(q);
		}
		if(n>1)
			facts.push_back(n);
		memset(dp,-1,sizeof(dp));
		printf("%s\n",!calc((1<<facts.size())-1) ? "Seymour" : "Laurence");
	}
	return 0;
}

