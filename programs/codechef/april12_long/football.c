//Program question at: http://www.codechef.com/APRIL12/problems/PLAYFIT
#include <stdio.h>

int maxio=50000;
char buf[50000], *s = buf + 50000;
inline char getc1(void) { if(s >= buf + maxio) { fread_unlocked(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }

int main()
{
	int t = input();
	while(t--)
	{
		int s = input()-1, max=0;
		int x = input();
		for(;s;s--)
		{
			int n = input();
			if(n-x > max) max = n-x;
			if(n < x) x=n;
		}
		if(max) printf("%d\n",max);
		else printf("UNFIT\n");
	}
	return 0;
}
