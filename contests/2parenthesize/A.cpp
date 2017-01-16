#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 1024

#define putchar putc1

char buf[max_buf_size], *_s = buf + max_buf_size;
inline char getc1(void) { if(_s >= buf + max_buf_size) { fread(buf,1,max_buf_size,stdin); _s = buf; } return *(_s++); }
inline int readint() { char t = getc1(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline LL readLL() { char t = getc1(); int n=1; LL res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) { res = 10*res + (t&15); t=getc1(); } return res*n; }
inline char skipwhitespace() { char ch = getc1(); while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1(); return ch; }
inline int readline(char *s)
{
	char ch=skipwhitespace();
	int n=0;
	while( (ch != '\n') )
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
	while( (ch != '\n' && ch != ' ' && ch != '\t') )
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

// END of IO

LL pow1(LL b, LL e, LL mod)
{
	if(e == 0) return 1;
	LL ans = pow1(b,e/2,mod);
	ans = (ans * ans) % mod;
	if(e&1) return (ans*b)%mod;
	else return ans;
}

inline LL pow(LL b, LL e, LL mod)	// mod should be prime
{
	if(e < 0)
		return pow1(pow1(b,-e,mod),mod-2,mod);
	else return pow1(b,e,mod);
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

LL gcd(LL a, LL b)
{
	return !a || !b ? a+b : gcd(b,a%b);
}

inline int getbit(LL n, int i)
{
	return n & (1<<i);
}

char mat[3][10] = { { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' },
    				{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '*' },
	  		 	   {  'z', 'x', 'c', 'v', 'b', 'n', 'm', '*', '*', '*' } };

int dist(char src, char dst)
{
	int n = 10;
	int r1,c1,r2,c2;
	for(int a=0;a<3;a++)
		for(int b=0;b<n;b++)
		{
			if(mat[a][b] == src)
				{ r1 = a; c1 = b; }
			if(mat[a][b] == dst)
			{
				r2 = a; c2 = b;
			}
		}
	return abs(r1-r2) + abs(c1-c2);
}

int diff(string a, string b)
{
	int s=0;
	for(int i=0;i<a.length();i++)
		s += dist(a[i],b[i]);
	return s;
}

string baap;

int cmp(string a, string b)
{
	int r1 = diff(baap,a), r2 = diff(baap,b);
	if(r1 != r2) return r1 < r2;
	return strcmp(a.c_str(),b.c_str());
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		cin >> baap;
		int n;
		cin >> n;
		string ar[n];
		for(int a=0;a<n;a++)
		{
			cin >> ar[a];
		}
		sort(ar,ar+n,cmp);
		for(int a=0;a<n;a++)
			printf("%s %d\n",ar[a].c_str(),diff(baap,ar[a]));
	}
	return 0;
}






