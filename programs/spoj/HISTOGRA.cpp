#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)

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

int A[100001], F[100001], B[100001];

void f(int *next, int *ar, int n)
{
	stack<int> s;
	s.push(n-1);
	for(int a=n-2;a>=0;a--)
	{
		while(s.size() > 0 and ar[a] < ar[s.top()] )
		{
			next[s.top()] = a;
			s.pop();
		}
		s.push(a);
	}
	while(!s.empty())
	{
		next[s.top()] = -1;
		s.pop();
	}
}

int main()
{
	while(1)
	{
		int n = readint();
		if(!n) break;
		for(int a=0;a<n;a++) A[a] = readint();
		f(B,A,n);
		reverse(A,A+n);
		f(F,A,n);
		reverse(A,A+n);
		reverse(F,F+n);
		rep(a,n)
			F[a] = n-1-F[a];
		LL ans = 0;
		rep(a,n)
			ans = max(ans, (LL)A[a] * (LL)(F[a] - B[a] - 1));
		printf("%lld\n",ans);
	}
	return 0;
}

