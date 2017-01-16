// Program question at: http://www.codechef.com/problems/F4
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long int ULL;

int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res     = 10*res + (t&15); t=getc(); } return res*n; }


inline bool f(ULL x)
{
	if(x % 7 == 0) return 1;
	while(x)
	{
		if(x%10 == 7) return 1;
		x/=10;
	}
	return 0;
}

int main()
{
	int t=input(),i=0;
	ULL ar[t];
	for(;i<t;ar[i++]=input());
	for(int a=0;a<t;a++) {
	int d=1; i=0;
	for(ULL &n=ar[a],count=1;count<=n;count++)
	{
		i += d;
		if(!i) i = 1337;
		else if(i>1337) i=1;
		if(f(count)) d *= -1;
	}
	printf("%d\n",i); }
	return 0;
}
