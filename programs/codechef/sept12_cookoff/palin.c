#include <stdio.h>
typedef long long LL;
char s[1000001];
LL mod = 10000009LL;

LL calc(LL n)
{
	LL ans=1;
	while(n--)
	{
		ans *= 26;
		ans %= mod;
	}
	return ans;
}

int main()
{
	int t,a; scanf("%d\n",&t);
	while(t--)
	{
		gets(s); int len = strlen(s);
		LL ans = 0;
		for(a=0;a<len/2;a++)
		{
			if(s[a] == '?' || s[len-a-1] == '?') continue;
			if(s[a] != s[len-a-1]) { printf("0\n"); goto next; }
			if(s[a] == '?' && s[len-a-1] == '?') ans++;
		}
		ans = calc(ans);
		if(len%2 && s[len/2] == '?') ans *= 26;
		printf("%lld\n",ans%mod);
		next:;
	}
	return 0;
}