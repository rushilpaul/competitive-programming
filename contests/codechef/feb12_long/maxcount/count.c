//Program question at: http://www.codechef.com/FEB12/problems/MAXCOUNT
#include <stdio.h>
#include <string.h>
#define MAX 10000

int maxio = 1000000;
char buf[1000000], *s = buf + 1000000;
inline char getc1(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res  = res*10 + (t&15); t=getc1(); } return res*n; }

int main()
{
	int t = input();
	while(t--)
	{
		int n = input(), a, m=n+1,times=0;
		short ar[MAX];
		memset(ar,0,MAX*sizeof(short));
		for(a=0;a<n;a++)
		{
			int num = input();
			int t = ++ar[num-1];
			if(t == times && num < m) m=num;
			else if(t > times) { times=t; m=num; }
		}
		printf("%d %d\n", m, times);
	}
	return 0;
}
