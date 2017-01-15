//Program question at: http://www.codechef.com/COOK25/problems/NOCODING
#include <stdio.h>
#include <string.h>
char s[1001];
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		int l=strlen(s),a,p=s[0]-97,total=l+1;
		for(a=1;a<l;a++)
		{
			if(s[a]-97 < p)
				total += (25-p + s[a]-97+1);
			else
				total += ((s[a]-97) - p);
			p = s[a] - 97;
		}
		if(total > l*11) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
