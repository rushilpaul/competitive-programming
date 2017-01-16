#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,m) for(int i=0;i<m;i++)
#define repab(i,a,b) for(int i=a;i<b;i++)

char _buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = _buf + _bytes_read_;
inline char getc1()
{
	if(_s >= _buf + _bytes_read_)
	{
		_bytes_read_ = fread(_buf,1,max_buf_size-1,stdin);
		_buf[_bytes_read_] = 0;
		_s = _buf;
	}
	return *(_s++);
}
inline int readint()
{
	char t=getc1();
	int n=1,res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{
		n=-1;
		t=getc1();
	}
	while(isdigit(t))
	{
		res = 10*res + (t&15);
		t=getc1();
	}
	return res*n;
}
inline LL readLL()
{
	char t=getc1();
	int n=1;
	LL res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{
		n=-1;
		t=getc1();
	}
	while(isdigit(t))
	{
		res = (LL)10*res + (t&15);
		t=getc1();
	}
	return res*n;
}

inline char skipwhitespace()
{
	char ch = getc1();
	while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1();
	return ch;
}
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

inline char readchar()
{
	return skipwhitespace();
}

char outbuf[max_buf_size];
int outbuf_p;

inline void putc1(char ch)
{
	if(outbuf_p >= max_buf_size)
	{
		fwrite(outbuf,1,max_buf_size,stdout);
		outbuf_p = 0;
	}
	outbuf[outbuf_p++] = ch;
}

inline void flush()
{
	fwrite(outbuf,1,outbuf_p,stdout);
	outbuf_p = 0;
}

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

inline void writedouble(double d, int p)
{
	char buf[40];
	sprintf(buf,"%.*f",p,d);
	writestr(buf);
}

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

#define MAX 1001
#define mod 1000000007
int F1[MAX], F2[MAX];

int main()
{
	int n = readint(), m = readint(), c = readint();
	rep(a,n) F1[readint()]++;
	rep(a,m) F2[readint()]++;
	vector<LL> v;

	repab(a,1,MAX)
	if((LL)F1[a] * F2[a] > 0)
		v.push_back((LL)F1[a] * F2[a] % mod);
	n = v.size();
	LL A[n];
	rep(a,n)
	A[a] = v[a];

	LL C[n];
	C[n-1] = v[n-1];
	for(int a=n-2; a>=0; a--)
		C[a] = (C[a+1] + v[a]) % mod;

	int end = n;
	rep(t,c)
	{
		LL ans=0;
		repab(i,1,end)
		{
			LL x = C[i] * v[i-1] % mod;
			ans = (ans + x) % mod;
			A[i-1] = x;
		}
		printf("%lld ",ans);
		end--;
		if(end <= 0) continue;
		n = end;
		C[n-1] = A[n-1];
		for(int a=n-2; a>=0; a--)
			C[a] = (C[a+1] + A[a]) % mod;
	}
	return 0;
}
