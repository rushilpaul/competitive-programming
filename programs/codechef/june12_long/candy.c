//Program question at: http://www.codechef.com/JUNE12/problems/LECANDY
#include <stdio.h>

int maxio=1000000;
char buf[1000000], *s = buf + 1000000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

int main()
{
	int t = input();
	while(t--)
	{
		int a,s=0,n=input(), c=input(), tmp;
		for(a=0;a<n;a++) s += input();
		if(s <= c) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
