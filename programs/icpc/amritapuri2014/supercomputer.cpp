#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define PI 3.141592653589793238462643383279502884197

char _buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = _buf + _bytes_read_;
inline char getc1() { if(_s >= _buf + _bytes_read_) { _bytes_read_ = fread(_buf,1,max_buf_size-1,stdin); _buf[_bytes_read_] = 0;  _s = _buf; } return *(_s++); }
inline int readint()
{
	char t=getc1(); int n=1,res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{ n=-1; t=getc1(); }
	while(isdigit(t))
	{ res = 10*res + (t&15); t=getc1(); }
	return res*n;
}
inline LL readLL()
{
	char t=getc1(); int n=1; LL res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{ n=-1; t=getc1(); }
	while(isdigit(t))
	{ res = (LL)10*res + (t&15); t=getc1(); }
	return res*n;
}

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

inline string readstring(int n)
{
	char buf[n+1];
	readstr(buf);
	string s(buf);
	return s;
}

inline double readdouble()
{
	char buf[40];
	readstr(buf);
	double d;
	sscanf(buf,"%lf",&d);
	return d;
}

inline LD readLD()
{
	char buf[80];
	readstr(buf);
	LD d;
	sscanf(buf,"%Lf",&d);
	return d;
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

double my_sqrt(double x, double delta = .00001)
{
    double g = x / 2, ng;
    while(fabs(g - (ng = (x / g + g) / 2)) > delta)
        g = ng;
    return g;
}

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		ar.push_back(S.substr(last,pos-last));
		last = pos + D.length();
	}
	ar.push_back(S.substr(last));
	return ar;
}

inline LL pow(LL b, LL e)
{
	LL ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(e & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}

template<class T>
T egcd(T a, T b, T &x, T &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = egcd(b%a, a, x1, y1);
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

LL mod = 1000000007;

LL sum_agp(LL a, LL d, LL r, LL n, LL mod)	// mod should be <= 2^31
{
	if(n <= 0) return 0;
	LL first = ((a + (n-1) * d) % mod * pow(r,n,mod) - a) % mod;
	if(first < 0) first += mod;
	LL second = (pow(r,n-1,mod)-1) % mod * d * r % mod;
	LL ans = ((r-1) * first - second) % mod * inv((r-1)*(r-1),mod) % mod;
	if(ans < 0) ans += mod;
	return ans;
}

int main()
{
	int t = readint();
	while(t--)
	{
		int m = readint();
		LL d[m], L[m];
		rep(a,m)
		{
			L[a] = readLL();
			d[a] = readLL();
		}
		LL C[m+1], C2[m+1];
		C[m] = C2[m] = 0;
		for(int a=m-1;a>=0;a--)
			C[a] = C[a+1] + L[a];

		for(int a=m-1;a>=0;a--)
		{
			C2[a] = ( C2[a+1] + (pow(10,L[a],mod) - 1) * inv(9,mod) % mod * d[a] * pow(10,C[a+1],mod) % mod ) % mod;
			if(C2[a] < 0) C2[a] += mod;
		}

		LL ans=0;
		rep(i,m)
		{
			LL n = C[i], x = L[i];
			LL first = (pow(10,x,mod) - 1) * inv(9,mod) % mod * pow(10,n-x,mod) % mod * d[i]*(d[i]-1) % mod * inv(2,mod) % mod;
			LL second;
			if(n != x)
				second = pow(10,n-x-1,mod) * sum_agp(n-x,1,10,x,mod) % mod * 45 * d[i] % mod;
			else
				second = sum_agp(1,1,10,x-1,mod) % mod * 45 * d[i] % mod;
			LL third = x * d[i] % mod * (C2[i+1]+1) % mod + inv(9,mod) * d[i] * d[i] % mod * pow(10,C[i+1],mod) % mod * ( (pow(10,x,mod)-1) * inv(9,mod) % mod - x % mod );
			third %= mod;
			if(third < 0) third += mod;
			//printf("first = %lld, second = %lld, third = %lld\n",first,second,third);
			ans = (ans + first + second + third) % mod;
			if(ans < 0) ans += mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

