#include <iostream>
#include <cstdio>
using namespace std;


int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = res*10 + (t&15); t=getc(); } return res*n; }


int main()
{
	int t = input();
	while(t--)
	{
		char ch;
		int m=0;
		while(1)
		{	
			ch = getc();
			if(ch == ' ' || ch == '\t') continue;
			if(!isdigit(ch)) break;
			if(ch != 52 && ch != 55) m++;
		}
		printf("%d\n",m);
	}
	return 0;
}
