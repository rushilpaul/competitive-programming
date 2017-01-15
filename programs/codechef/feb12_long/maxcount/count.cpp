//Program question at: http://www.codechef.com/FEB12/problems/MAXCOUNT
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000
int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc(); if(t=='-') { n=-1; t=getc(); } while(isdigit(t)) { res  = res*10 + (t&15); t=getc(); } return res*n; }

int main()
{
	int t = input();
	short ar[MAX];
	memset(ar,0,MAX*sizeof(short));
	while(t--)
	{
		int n = input(), min=MAX+1, max=0;
		for(int a=0;a<n;a++)
		{
			int num = input();
			if(num < min) min = num;
			if(num > max) max = num;
			ar[num-1]++;
		}
		int m=0,times=0;
		for(int a=min-1;a<max;a++)
		{
			short &t = ar[a];
			if(t > times) { times = t; m=a; }
			t = 0;
		}
		printf("%d %d\n", m+1, times);
	}
	return 0;
}
