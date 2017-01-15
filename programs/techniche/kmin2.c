//Program question at: http://www.codechef.com/BTCD2012/problems/KMIN
#include <stdio.h>
#include <string.h>
#define size 100000
int maxio=50000;
char buf[50000], *s = buf + 50000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = getc_(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }
int main()
{
	int a,n=input(),k=input();
	int ar[size],min=99999,max=0,d=0;
	memset(ar,0,size*4);
	while(n--)
	{
		int num=input()-1;
		if(num == -2)
		{
			for(a=min;a<=max && d<k;a++) d+=ar[a];
			printf("%d\n",a);
			d=0;
		}
		else
		{
			ar[num]++;
			if(num < min) min = num;
			if(num > max) max = num;
		}
	}
	return 0;
}
