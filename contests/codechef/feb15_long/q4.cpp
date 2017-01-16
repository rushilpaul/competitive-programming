#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 2048

char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void) { if(_s >= buf + max_buf_size) { fread(buf,1,max_buf_size,stdin); _s = buf; } return *(_s++); }
inline int readint() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline LL readLL() { char t = getc1(); int n=1; LL res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline int readstr(char *s)
{
	char ch=getc1();
	int n=0;
	while( (ch != '\n') )
	{
		s[n++] = ch;
		ch = getc1();
	}
	s[n] = 0;
	return n;
}

inline char readchar()
{
	char ch = getc1();
	while(ch == ' ' or ch == '\n' or ch == '\r') ch = getc1();
	return ch;
}

int fact[10000000];
void init(int mod)
{
	fact[0] = fact[1] = 1;
	for(int a=2;a<mod;a++)
		fact[a] = ((LL)fact[a-1] * a) % mod;
}

int main()
{
	int n = readint(), m = readint();
	if(m == 1) { printf("0\n"); return 0; }
	init(m);
	LL A=0;
	for(int a=0;a<n;a++)
	{
		LL p = readLL();
		LL ans1,ans2,k;
		if(p % 2 == 0) k = p/2;
		else k = (p+1)/2;
		k = k % m;
		if(p % 2 == 0) ans1 = k*(2*k+1) % m;
		else ans1 = k*(2*k-1) % m;
		ans1 = (ans1 * (p%m)) % m;
		
		if(p+1 >= m)
			ans2 = -1;
		else
			ans2 = fact[p+1] - 1;
		if(ans2 < 0) ans2 += m;
		ans1 = (ans1 + ans2) % m;
		A = (A + ans1) % m;
	}
	printf("%lld\n",A);
	return 0;
}
