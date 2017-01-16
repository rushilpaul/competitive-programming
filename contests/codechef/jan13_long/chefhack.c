//Program question at: http://www.codechef.com/JAN13/problems/CHEFHACK
#include <stdio.h>
#define max 10000000

int maxio=8192;
char buf[8192], *s = buf + 8192;
inline char _getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = _getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=_getc(); if(t=='-') { n=-1; t=_getc(); } while(isdigit(t)) { res = 10*res + (t&15); t=_getc(); } return res*n; }

typedef long long LL;
int n, P[max],primes[max], ar[350][350];

inline int valid(int a, int b)
{
	if(a < 0 || b < 0 || a >= n || b >= n) return 0;
	return 1;
}

inline void pre()
{
	int a,b,c=0;
	P[0] = P[1] = 1;
	for(a=2;a<=3162;a++)
	{
		if(P[a]) continue;
		for(b=a*a;b<max;b+=a) P[b]=1;
	}
	for(a=2;a<max;a++)
		if(!P[a])
		{
			primes[a] = c;
			c++;
		}
}

void solve(int a, int b, int p)
{
	if(!valid(a,b)) return;
	if( ((ar[a][b] & 1) ^ p) || ar[a][b] < 0) return;	// parity check & negative value check
	if(P[ar[a][b]] == 0) return;
	if( (ar[a][b] & 1) && p) ar[a][b] = -2;
	if( ((ar[a][b] & 1) == 0) && (!p) ) ar[a][b] = -1;
	solve(a,b+1,p);
	solve(a,b-1,p);
	solve(a+1,b,p);
	solve(a-1,b,p);
}

int main()
{
	pre();
	int t = input();
	while(t--)
	{
		LL ans1=0,ans2=0;
		int a,b;
		n = input();
		for(a=0;a<n;a++) for(b=0;b<n;b++) ar[a][b] = input();
		for(a=0;a<n;a++)
		for(b=0;b<n;b++)
		{
			int c = ar[a][b];
			if(c < 0) continue;
			if(!P[c])
			{
				ans2 += primes[c];
				continue;
			}
			ans1 += ((c & 1) ? c+3 : c);
			solve(a,b,c & 1);
		}
		printf("%llu\n",ans1/2 + ans2);
	}
	return 0;
}
