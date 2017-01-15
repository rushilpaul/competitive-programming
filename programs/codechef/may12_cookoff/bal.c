//Program question at: http://www.codechef.com/problems/LUCKYBAL
#include <stdio.h>
typedef unsigned long long LL;
char s[100002];
int main()
{
	int t,a; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		LL len = strlen(s),n=0;
		s[len] = '4'; s[len+1] = '\0';
		LL ans = (len*(len+1))>>1;
		for(a=0;a<len+1;a++)
			if(s[a] == '7') n++;
			else
			{
				ans -= (LL)(n*(n+1))>>1;
				n=0;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
