//Problem question: http://www.codechef.com/MAY14/problems/COMPILER
#include <stdio.h>
char s[1000001];

int main()
{
	int t,a,i,n,l; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		l = strlen(s);
		a=n=i=0;
		for(a=0;a<l;a++)
		{
			if(s[a] == '<') n++;
			else n--;
			if(n < 0) break;
			if(!n) i=a+1;
		}
		if(n) a=i;
		printf("%d\n",a>0?a:0);
	}
	return 0;
}
