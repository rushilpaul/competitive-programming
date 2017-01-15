//Program question at: http://www.codechef.com/ADR2012/problems/A109
#include <stdio.h>
#include <string.h>
int main()
{
	int t,a,b; scanf("%d\n",&t);
	char s[1001];
	while(t--)
	{
		gets(s);
		int p=0,len = strlen(s);
		if( !(s[len-1] == 'Y' && s[len-2] == 'A'))
		{
			s[len] = 'A'; s[len+1] = 'Y';
			s[len+2] = 0;
			len+=2;
		}
		for(a=0;a<len-1;a++)
		{
			if( s[a] < 65 || s[a] > 90) { p=a+1; printf("%c",s[a]); continue; }
			if( s[a] == 'A' && s[a+1] == 'Y')
			{
				if(p-1 != a-1) printf("%c",s[a-1]);
				for(b=p;b<a-1;b++) printf("%c",s[b]);
			}
		}
		printf("\n");
	}
	return 0;
}
