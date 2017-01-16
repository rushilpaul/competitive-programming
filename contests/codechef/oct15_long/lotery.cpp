#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS std::numeric_limits<double>::epsilon()
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

#define mod 1000000007

const int max_primes = 100001;		// 1e5+1
int isprime[max_primes], largestpdiv[max_primes];
LL prod[max_primes];
char primepowers[316][max_primes];

void sieve()
{
	for(int a=0;a<max_primes;a++) isprime[a] = 1, largestpdiv[a] = 0;
	for(int a=2;a<max_primes;a++)
	{
		if(!isprime[a]) continue;
		largestpdiv[a] = a;
		if(a <= 316)
			primepowers[a][a] = 1;
		for(int b=a+a;b<max_primes;b+=a)
		{
			isprime[b] = 0;
			largestpdiv[b] = a;
			if(a > 316) continue;
			int num = b, c=0;
			while(num % a == 0)
			{
				c++;
				num /= a;
			}
			primepowers[a][b] = c;
		}
	}
	prod[0] = 1;
	for(int a=1;a<max_primes;a++)
		if(isprime[a]) prod[a] = a;
		else prod[a] = 1;
	repab(a,1,max_primes)
		prod[a] = (prod[a-1] * prod[a] % mod);
}

LL getprimepower(int p, int L, int R)
{
	int ans=1;
	repab(a,L,R)
		ans = (ans * pow(p,primepowers[p][a],mod) ) % mod;
	return ans;
}

LL getlcm(int L, int R)
{
	LL ans = 1;
	for(int a=2;a*a<=R;a++)
	{
		if(!isprime[a]) continue;
		ans = (ans * getprimepower(a,L,R)) % mod;
	}
	L = max(L, (int)my_sqrt(R,0.1));
	if(L > R) L = R;
	ans = ans * prod[R] % mod * (L-1 >= 1 ? inv(prod[L-1],mod) : 1) % mod;
	return ans;
}

int main()
{
	sieve();
	int t = readint();
	LL n1 = readLL(), k1 = readLL();
	LL A = readLL(), B = readLL(), M = readLL();
	LL C[t+2], D[t+2];
	rep(a,t-1)
		C[a] = readLL();
	rep(a,t-1)
		D[a] = readLL();
	int q=0;
	while(t--)
	{
		LL ans;
		// find LCM(n-k+1, n-k+2, ... , n)
		int L = n1-k1+1, R = n1;
		assert(L <= R);
		printf("%lld\n",ans = getlcm(L,R));
		n1 = 1 + (A * ans + C[q]) % M;
		k1 = 1 + (B * ans + D[q]) % n1;
		q++;
	}
	return 0;
}

