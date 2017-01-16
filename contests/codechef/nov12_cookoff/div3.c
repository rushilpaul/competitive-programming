#include <stdio.h>
#include <string.h>
#define MAX 100000
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
int P[100001];
int Q[9592];
void pre()
{
	int a,b,k=0;
	memset(P,0,sizeof(int)*(MAX+1));
	for(a=2;a<=316;a++)
	for(b=a*a;b<=MAX;b+=a) P[b] = 1;
	for(a=2;a<=MAX;a++) if(!P[a]) Q[k++] = a;
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
		{
			gcd = getgcd(gcd,in());
			if(gcd == 1) { printf("-1\n"); goto end; }
		}
		for(a=0;a<9592;a++) if(gcd % Q[a] == 0) { printf("%d\n",Q[a]); break; }
		end:;
	}
	return 0;
}
