//Program question at: http://www.codechef.com/DEC12/problems/BEX
#include <stdio.h>
int sp;
inline int tonum(char *s)
{
	int a,n=0;
	for(a=0;s[a]!=32;a++) n = n*10 + (s[a]-48);
	sp = a;
	return n;
}

int main()
{
	int k=0,min=100000,a=0,n,t; scanf("%d\n",&n);
	char s[30], books[n][16];
	int M[n], loc[n];
	while(n--)
	{
		gets(s);
		if(s[0] == '-')
		{
			printf("%d %s\n",a-k-1,books[k]);
			a = k;
			if(k>0)
			{
				min = M[k-1];
				k = loc[k-1];
			}
			if(!a) min=100000;
			continue;
		}
		t = tonum(s);
		if(!t) continue;
		if(t<=min)
		{
			M[a] = min = t;
			loc[a] = a;
			k = a;
			strcpy(books[a],s+sp+1);
		}
		else
		{
			M[a] = M[a-1];
			loc[a] = loc[a-1];
			strcpy(books[a],books[a-1]);
		}
		a++;
	}
	return 0;
}
