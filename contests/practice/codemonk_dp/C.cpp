// https://www.hackerearth.com/code-monk-dynamic-programming/algorithm/samu-and-special-coprime-numbers/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

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

#define max1 163
#define max2 1459
LL dp[19][max1][max2];

LL f(string &s, int i, int tight, int sum1, int sum2)
{
	if(i < 0)
	{
		return gcd(sum1,sum2) == 1;
	}
	LL ans=0;
	int end = tight ? s[i] : 9;
	LL &ret = dp[i][sum1][sum2];
	if(ret >= 0 and !tight) return ret;
	for(int d=0;d<=end;d++)
		ans += f(s,i-1,tight and d == s[i], sum1 + d, sum2 + d*d);
	if(!tight)
		ret = ans;
	return ans;
}

int main()
{
	int t; scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		string L,R;
		cin >> L >> R;
		reverse(L.begin(), L.end());
		reverse(R.begin(), R.end());
		int n1 = L.size(), n2 = R.size();
		for(int a=0;a<n1;a++)
			L[a] -= '0';
		for(int a=0;a<n2;a++)
			R[a] -= '0';
		LL ans2 = f(R,n2-1,1,0,0);
		LL ans1 = f(L,n1-1,1,0,0);

		// check for L
		int flag=0,s1=0,s2=0;

		for(int a=0;a<n1;a++)
		{
			s1 += L[a];
			s2 += L[a]*L[a];
		}
		if(gcd(s1,s2) == 1)
			flag = 1;
		printf("%lld\n",ans2 - ans1 + flag);
	}
}

