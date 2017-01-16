#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define EPS std::numeric_limits<double>::epsilon()
#define max_buf_size 2048
 
char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void) { if(_s >= buf + max_buf_size) { fread(buf,1,max_buf_size,stdin); _s = buf; } return *(_s++); }
inline int readint() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline LL readLL() { char t = getc1(); int n=1; LL res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline char skipwhitespace() { char ch = getc1(); while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1(); return ch; }
inline int readline(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n' && ch != 0) )
	{
		s[n++] = ch;
		ch = getc1();
	}
	s[n] = 0;
	return n;
}
 
inline int readstr(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n' && ch != ' ' && ch != '\t' && ch != 0) )
	{
		s[n++] = ch;
		ch = getc1();
	}
	s[n] = 0;
	return n;
}
 
inline char readchar() { return skipwhitespace(); }
 
char outbuf[max_buf_size];
int outbuf_p;
 
inline void putc1(char ch) { if(outbuf_p >= max_buf_size) { fwrite(outbuf,1,max_buf_size,stdout); outbuf_p = 0; } outbuf[outbuf_p++] = ch; }
 
inline void flush() { fwrite(outbuf,1,outbuf_p,stdout); outbuf_p = 0; }
 
inline void writeint(int n)
{
	int sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[10];
	int i = 9;
	if(!n) buf[i--] = 48;
	while(n)
	{
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) putc1('-');
	while(++i < 10) putc1(buf[i]);
}
 
inline void writeLL(LL n)
{
	int sign = n >= 0 ? 1 : -1;
	n = n>0 ? n : -n;
	char buf[25];
	int i = 24;
	if(!n) buf[i--] = 48;
	while(n)
	{
		buf[i--] = n % 10 + 48;
		n /= 10;
	}
	if(sign < 0) putc1('-');
	while(++i < 25) putc1(buf[i]);
}
 
inline void writestr(char *s)
{
	char *p = s;
	while(*p)
	{
		putc1(*p);
		p++;
	}
}
 
inline void writedouble(double d, int p) { char buf[40]; sprintf(buf,"%.*f",p,d); writestr(buf); }
 
// END OF IO

inline int pow(int b, int e)
{
	int ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e)
{
	LL ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow1(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(b & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}
 
inline LL pow(LL b, LL e, LL mod)	// mod should be prime
{
	if(e < 0)
		return pow1(pow1(b,-e,mod),mod-2,mod);
	else return pow1(b,e,mod);
}
 
int egcd(int a, int b, int &x, int &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL egcd(LL a, LL b, LL& x, LL& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL inv(LL a, LL m)
{
	LL inv,y;
	assert(egcd(a,m,inv,y) == 1);
	if(inv < 0) inv += m;
	return inv;
}
 
inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}
 
vector<int> getfactors(int n)
{
	vector<int> f;
	for(int a=2;a*a<=n;a++)
	{
		int p = 1;
		while(n % a == 0)
		{
			n /= a;
			p *= a;
		}
		if(p > 1) f.push_back(p);
	}
	return f;
}

inline int getbit(LL n, int i)
{
	return n & (1<<i);
}

int main()
{
	int n = readint();
	string s[n];
	char tmp[101];
	for(int a=0;a<n;a++)
	{
		readstr(tmp);
		s[a] = string(tmp);
	}
	sort(s,s+n);
	int ans=0, m=1;
	for(int a=0;a<n-1;a++)
	{
		int flag = 1;
		for(int b=0;b<n;b++)
		{
			if(s[a][b] != s[a+1][b])
				flag = 0;
		}
		if(flag)
			m++;
		else
		{
			ans = max(ans,m);
			m = 1;
		}
	}
	ans = max(ans,m);
	printf("%d\n",ans);
	return 0;
}

