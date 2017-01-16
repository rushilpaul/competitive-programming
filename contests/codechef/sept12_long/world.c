//Program question at: http://www.codechef.com/SEP12/problems/CROWD
#include <stdio.h>
#include <time.h>
typedef long long LL;
LL mod = 1000000007LL;
LL base[4][4] = { {2,1,-2,-1}, {1,0,0,0}, {0,1,0,0}, {0,0,1,0} }, M[4][4], result[4][4];

int maxio=8000000;
char buf[8000000], *s = buf + 8000000;
inline char getc_(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline LL input() { char t = getc_(); LL n=1,res=0; while(t!='-' && !isdigit(t)) t=getc_(); if(t=='-') { n=-1; t=getc_(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc_(); } return res*n; }

inline void sq()
{
	int i,j,k;
	for(i=0;i<4;i++) for(j=0;j<4;j++)
	{
		result[i][j] = 0;
		for(k=0;k<4;k++)
		{
			result[i][j] += (M[i][k]*M[k][j])%mod;
			result[i][j] %= mod;
		}
	}
	for(i=0;i<4;i++) for(j=0;j<4;j++) M[i][j] = result[i][j];
}

inline void mul()
{
	int i,j,k;
	for(i=0;i<4;i++) for(j=0;j<4;j++)
	{
		result[i][j] = 0;
		for(k=0;k<4;k++)
		{
			result[i][j] += (M[i][k]*base[k][j])%mod;
			result[i][j] %= mod;
		}
	}
	for(i=0;i<3;i++) for(j=0;j<3;j++) M[i][j] = result[i][j];
}

void f(LL n)
{
	if(n==1) return;
	if(n%2)
	{
		f((n-1)/2);
		sq(); mul();
	}
	else
	{
		f(n/2);
		sq();
	}
}

int main()
{
	int k=0,i,j,t = input();
	while(t--)
	{
		LL n = input();
		if(n<5)
		{
			if(n==1) printf("0\n");
			else if(n==2) printf("5\n");
			else if(n==3) printf("18\n");
			else printf("44\n");
			continue;
		}
		for(i=0;i<4;i++) for(j=0;j<4;j++) M[i][j] = base[i][j];
		f(n-4);
		n = ( (M[0][0]*44)%mod + (M[0][1]*18)%mod + (M[0][2]*5)%mod ) % mod;
		printf("%lld\n",n);
	}
	return 0;
}
