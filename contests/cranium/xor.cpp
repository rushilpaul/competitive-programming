//Program question at: http://www.codechef.com/CRNM2012/problems/CRNM1207
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc(); } return res*n; }
	  
int cache[1000000];

int main()
{
	memset(cache, 0, sizeof(int)*1000000);
	int n = input();
	int ar[n];
	for(int a=0;a<n;a++) ar[a] = input();
	int q = input();
	for(int a=0;a<q;a++)
	{
		int t, qr=input(), max=0;
		int &mem = cache[qr-1];
		if(mem) { printf("%d\n",mem); continue; }
		for(int a=0;a<n;a++) { t = ar[a]^qr; if(t>max) max=t; }
		printf("%d\n",max);
		mem = max;
	}
	return 0;
}
