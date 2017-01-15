//Program question at: http://www.codechef.com/JUNE12/problems/CAKEDOOM
#include <stdio.h>
#include <string.h>
char s[101];
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a=0,k,len; scanf("%d\n",&k);
		gets(s);
		len = strlen(s);
		if(len == 1 && s[0] != '?') { printf("%s\n",s); continue; }
		if(k==2 && s[0] == '?')
		{
			while(s[++a] == '?');
			if(a < len && ((a%2 == 0 && s[a] == 49) || (a%2 == 1 && s[a] == 48))) s[0] = 49;
		}
		int l,r,p;
		for(a=0;a<len;a++)
		{
			l = a==0 ? len-1 : a-1; r = a==len-1 ? 0 : a+1; p=0;
			if(s[a] == '?')
			{
				while(s[l]-48 == p || s[r]-48 == p) p++;
				if(p >= k) goto NP;
				s[a] = p+48;
			}
			else
			{
				if(s[a] == s[l] || s[a] == s[r] || s[a] >= k+48) goto NP;
			}
		}
		printf("%s\n",s); continue;
		NP:
		printf("NO\n");
	}
}
