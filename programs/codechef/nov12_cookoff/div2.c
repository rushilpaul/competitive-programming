#include <stdio.h>
#define MAX 100000
#define min(a,b) a<b?a:b
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
int P[100001];
void pre()
{
	int a,b;
	for(a=2;a<=MAX;a++) P[a] = a;
	for(a=2;a<=MAX/2;a++)
	{
		if(P[a] == a)
		for(b=a<<1;b<=MAX;b+=a) P[b] = min(a,P[b]);
	}
}

int getgcd(int a, int b)
{ return !a || !b ? a+b : getgcd(b,a%b); }

int main()
{
	pre();
	int t=in();
	while(t--)
	{
		int n=in(),gcd=in(),a;
		for(a=1;a<n;a++)
			gcd = getgcd(gcd,in());
		if(gcd == 1) printf("-1\n");
		else printf("%d\n",P[gcd]);
	}
	return 0;
}
