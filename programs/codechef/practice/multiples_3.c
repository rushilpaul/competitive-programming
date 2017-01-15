//Program question at: http://www.codechef.com/problems/MULTQ3/
#include <stdio.h>
int maxio=1000000;
char buf[1000000], *s = buf + 1000000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

int main()
{
	int n = input(), q = input();
	int *ar = (int*)malloc(n*4);
	while(q--)
	{
		int op = input(), a = input(), b = input(), c=0;
		for(;a<=b;a++)
		{
			if(op) { if(ar[a] % 3 == 0) c++; }
			else ar[a]++;
		}
		if(op) printf("%d\n",c);
	}
}
