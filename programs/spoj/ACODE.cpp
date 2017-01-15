#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long LL;

char s[6001];
LL dp[6001];

LL f(int i, int n)
{
	if(i == n-1 and s[i] == 0) return 0;
	if(i >= n-1) return 1;
	LL &ret = dp[i];
	if(ret >= 0) return ret;
	int c = s[i]*10 + s[i+1];
	ret = 0;
	if(s[i] != 0)
		ret = f(i+1,n);
	if(c <= 26 and s[i] != 0)
		ret += f(i+2,n);
	return ret;
}

int main()
{
	while(1)
	{
		std::cin >> s;
		int n = strlen(s);
		for(int a=0;a<n;a++)
			s[a] -= 48;
		if(n == 1 and s[0] == 0) break;
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",f(0,n));
	}
	return 0;	
}
