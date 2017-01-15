#include <bits/stdc++.h>
typedef unsigned long long LL;
typedef long double LD;
using namespace std;
#define EPS std::numeric_limits<double>::epsilon()
#define max_buf_size 1024

char buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = buf + _bytes_read_;
inline char getc1() { if(_s >= buf + _bytes_read_) { _bytes_read_ = fread(buf,1,max_buf_size-1,stdin); buf[_bytes_read_] = 0;  _s = buf; } return *(_s++); }
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

inline double readdouble()
{
	// to be implemented
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
		if(e & 1)
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

vector<int> ar[100001];
int n;

vector<int> getbits(int n)
{
	vector<int> bits;
	while(n)
	{
		bits.push_back(n&1);
		n >>= 1;
	}
	reverse(bits.begin(),bits.end());
	return bits;
}

int find(vector<int> &a, vector<int> &b)	// a to b
{
	int L = min(a.size(),b.size());
	int count=0,i;
	for(i=0;i<L;i++)
	{
		if(a[i] != b[i]) break;
		count++;
	}
	for(;i<b.size();i++)
		if(b[i]) return -1;
	return a.size() - count + b.size() - count;
}

int getsum(vector<int> T)
{
	int s=0;
	for(int a=0;a<n;a++)
	{
		int ret = find(ar[a],T);
		if(ret == -1) return -1;
		s += ret;
	}
	return s;
}

int main()
{
	n = readint();
	int m=0;
	for(int a=0;a<n;a++)
	{
		ar[a] = getbits(readint());
		m = max(m, (int)ar[a].size());
	}
	int ans=INT_MAX;
	vector<int> first = ar[0];
	while(first.size() > 0)
	{
		vector<int> tmp = first;
		int ret = getsum(tmp);
		if(ret != -1)
			ans = min(ans,ret);
		
		for(int a=tmp.size();a<m;a++)
		{
			tmp.push_back(0);
			int ret = getsum(tmp);
			if(ret != -1)
				ans = min(ans,ret);
		}
		if(tmp[first.size()-1] == 1)
		{
			tmp[first.size()-1] = 0;
			int ret = getsum(tmp);
			if(ret != -1)
				ans = min(ans,ret);
		}
		first.pop_back();
	}
	printf("%d\n",ans);
	return 0;
}

