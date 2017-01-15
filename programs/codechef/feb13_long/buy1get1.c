//Program question at: http://www.codechef.com/FEB13/problems/BUY1GET1
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int t,a,ans; scanf("%d\n",&t);
	int Ar[26],ar[26]; char ch;
	while(t--)
	{
		memset(Ar,0,sizeof(int)*26);
		memset(ar,0,sizeof(int)*26);
		ans=0;
		while(1)
		{
			ch = getchar();
			if(ch == '\n') break;
			if(ch <= 90) Ar[ch-65]++;
			else ar[ch-97]++;
		}
		for(a=0;a<26;a++) { ans += (round(ar[a]/2.0) + round(Ar[a]/2.0)); }
		printf("%d\n",ans);
	}
	return 0;
}
