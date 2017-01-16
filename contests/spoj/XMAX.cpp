#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS std::numeric_limits<double>::epsilon()
#define max_buf_size 1024

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

LL ar[100001];

int getlen(LL n)
{
	int x = 0;
	while(n)
	{
		n >>= 1;
		x++;
	}
	return x;
}

int main()
{
	int n; scanf("%d",&n);
	for(int a=0;a<n;a++)
		scanf("%lld",&ar[a]);
	vector<LL> s[64];
	for(int a=0;a<n;a++)
		s[getlen(ar[a])].push_back(ar[a]);
	for(int a=63;a>=0;a--)
	{
		if(s[a].size() == 0) continue;
		LL first = s[a][0];
		for(int b=1;b<s[a].size();b++)
		{
			LL q = first ^ s[a][b];
			if(q)
				s[getlen(q)].push_back(q);
		}
		s[a].clear();
		s[a].push_back(first);
	}
	LL ans = 0;
	for(int a=63;a>=0;a--)
	{
		if(s[a].size() > 0)
			ans = max(ans, ans ^ s[a][0]);
	}
	printf("%lld\n",ans);
	return 0;
}

