//Program question at: http://www.codechef.com/COOK22/problems/LUCKYBAL
#include <cstdio>
#include <cstring>
typedef long long LL;
char s[100001];

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		LL l = strlen(s),n4=0,ans;
		for(int a=0;a<l;a++) if(s[a] == '4') n4++;
		ans = n4*l - (n4*(n4-1))/2;
		int i=-1;
		while (i<l-1)
		{
			while(s[i] != '7' && i<l) i++;
			if(i==l) break;
			bool f = 0;
			for(int j=i+1;j<l;j++)
			{
				if (s[j] == '4') f = 1;
				if (s[j] == '7' && f) ans++;
			}
			i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
