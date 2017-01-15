//Program question at: http://www.codechef.com/COOK25/problems/YNOUTPUT
#include <stdio.h>
char s[4];
int main()
{
	int a,b,t; scanf("%d\n",&t);
	int bits[t], *p;
	for(a=0;a<t;a++)
	{
		p = &bits[a];
		*p = 0;
		for(b=0;b<t;b++)
		{
			gets(s);
			*p = s[0] == 'Y' ? ((*p)<<1)|1 : (*p)<<1;
		}
	}
	for(a=0;a<t;a++)
	{
		for(b=0;b<t;b++)
			if( ((1<<(t-b-1)) & bits[a]) ^ (bits[a] == bits[b])) goto next;
		for(b=0;b<t;b++) printf("%s\n",(1<<(t-b-1)) & bits[a] ? "YES" : "NO");
		return 0;
		next:;
	}
	for(a=0;a<t;a++) printf("NO\n");
	return 0;
}
