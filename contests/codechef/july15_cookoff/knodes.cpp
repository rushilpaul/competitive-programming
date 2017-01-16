#include <bits/stdc++.h>
typedef long long LL;
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

inline int getbit(LL n, int i)
{
	return n & (1<<i);
}

vector<int> G[100001];
int L[100001], vis[100001];

inline int parent(int v)
{
	int p = -1;
	for(auto i : G[v])
		if(L[i] < L[v]) p = i;
	return p == -1 ? v : p;
}

inline int findlca(int u, int v)
{
	int lca=-1;
	int Lu = L[u], Lv = L[v];
	if(Lu > Lv)
	{
		swap(Lu,Lv);
		swap(u,v);
	}
	while(L[v] > Lu)
	{
		v = parent(v);
	}
	while(v != u)
	{
		u = parent(u);
		if(u == v) { lca = u; break; }
		v = parent(v);
		if(u == v) { lca = v; break; }
	}
	if(v == u) lca = v;
	assert(lca != -1);
	return lca;
}

int check(int a, int b, int c, int &m)
{
	int l1 = findlca(a,b), l2 = findlca(b,c), l3 = findlca(c,a);
	m = min(m, min(L[l1], min(L[l2],L[l3])));
	if(l1 != a and l1 != b and L[l1] != m) return 0;
	if(l2 != b and l2 != c and L[l2] != m) return 0;
	if(l3 != c and l3 != a and L[l3] != m) return 0;
	return 1;
}

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint();
		for(int a=0;a<=n;a++)
		{
			L[a] = 0;
			vis[a] = 0;
			G[a].clear();
		}
		for(int a=0;a<n-1;a++)
		{
			int x = readint(), y = readint();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int root = -1;
		for(int a=1;a<=n;a++)
			if(G[a].size() <= 2)
			{
				root = a;
				break;
			}
		queue< pair<int,int> > q;
		q.push({root,1});
		L[root] = 1;
		vis[root] = 1;
		while(q.size() > 0)
		{
			auto e = q.front();
			int u = e.first, level = e.second;
			for(auto v : G[u])
			{
				if(vis[v]) continue;
				q.push({v,level+1});
				L[v] = level+1;
				vis[v] = 1;
			}
			q.pop();
		}
		// print levels
		//for(int a=1;a<=n;a++)
			//printf("%d %d\n",a,L[a]);
		int qq = readint();
		while(qq--)
		{
			int k = readint();
			int A[k];
			for(int a=0;a<k;a++)
				A[a] = readint();
				
			int flag = 0, ml = INT_MAX;
			for(int a=0;a<k-2;a++)
			{
				if(check(A[a],A[a+1],A[a+2],ml) == 0)
				{
					flag = 1;
					break;
				}
			}
			printf("%s\n",flag ? "No" : "Yes");
		}
	}
	return 0;
}

