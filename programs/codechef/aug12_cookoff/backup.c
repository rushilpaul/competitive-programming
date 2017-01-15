//Program question at: http://www.codechef.com/COOK25/problems/YNOUTPUT
#include <stdio.h>
int **bits,t;
int maxio=50000;
char buf[50000], *s = buf + 50000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

inline int check(int a, int b)
{
	int c=0;
	for(;c<t;c++)
		if(bits[a][c] ^ bits[b][c]) return 0;
	return 1;
}
int main()
{
	int a,b; t = input();
	bits = (int**)malloc(t*sizeof(int*));
	for(a=0;a<t;a++)
	{
		bits[a] = (int*)malloc(t*sizeof(int));
		for(b=0;b<t;b++)
		{
			char ch = getc_();
			while(ch < 65 || ch > 90) ch = getc_();
			bits[a][b] = ch == 'Y' ? 1 : 0;
			if(ch == 'Y') { getc_(); getc_(); }
			else getc_();
		}
	}
	for(a=0;a<t;a++)
	{
		for(b=0;b<t;b++)
			if(bits[a][b] ^ check(a,b)) goto next;
		for(b=0;b<t;b++) printf("%s\n",bits[a][b] ? "YES" : "NO");
		return 0;
next:;
	}
	for(a=0;a<t;a++) printf("NO\n");
	return 0;
}

