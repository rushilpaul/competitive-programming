#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
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

template<class T>
void print(vector<T> v)
{
	for(T i : v)
		cout << i << " ";
}

template<class T>
void fill(vector<T> v, T val = 0)
{
	fill(v.begin(),v.end(),val);
}

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		string sub = S.substr(last,pos-last);
		if(sub.length() > 0)
			ar.push_back(sub);
		last = pos + D.length();
	}
	string sub = S.substr(last);
	if(sub.length() > 0)
		ar.push_back(sub);
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

int w[500001];
set<int> G[500001];
int vis[500001];
vector< pair<int,int> > paths;
vector<LL> ans;
vector<int> hist[500001];	// weights

struct subset
{
    int parent, rank;
	LL val;
};

subset subs[500001];

int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
	if(xroot == yroot) return;

    if (subsets[xroot].rank < subsets[yroot].rank)
	{
        subsets[xroot].parent = yroot;
		subsets[yroot].val += subsets[xroot].val;
	}
    else if (subsets[xroot].rank > subsets[yroot].rank)
	{
        subsets[yroot].parent = xroot;
		subsets[xroot].val += subsets[yroot].val;
	}
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
		subsets[xroot].val += subsets[yroot].val;
    }
}

struct query
{
	char ch;
	int index;
	int u, w;
};

query Q[500001];

map<LL,int> P;

LL f(int u, int parent)
{
	if(vis[u]) return 0;
	vis[u] = 1;
	LL ans = w[u];
	for(int v : G[u])
		if(v != parent)
			ans += f(v,u);
	return ans;
}

int main()
{
	int n = readint(), m = readint(), nq = readint();
	rep(a,n) { w[a+1] = readint(); hist[a+1].pb(w[a+1]); }

	rep(a,m)
	{
		int i = readint(), j = readint();
		G[i].insert(j);
		G[j].insert(i);
		paths.pb({i,j});
	}

	rep(k,nq)
	{
		char ch = readchar();
		Q[k].ch = ch;
		if(ch == 'D')
		{
			int i = readint()-1, u = paths[i].first, v = paths[i].second;
			G[u].erase(v);
			G[v].erase(u);

			Q[k].index = i;
		}
		else
		{
			int u = readint(), p = readint();
			Q[k].u = u; Q[k].w = p;
			hist[u].pb(p);
		}
	}
	rep(a,n) w[a+1] = hist[a+1].back();
	
	repab(u,1,n)
	{
		subs[u].parent = u, subs[u].rank = 0, subs[u].val = hist[u].back();
		if(vis[u] == 0)
		{
			LL x = f(u,0);
			P[x]++;
		}
	}

	repab(u,1,n)
	{
		for(int v : G[u])
			Union(subs,u,v);
	}

	for(int k=nq-1;k>=0;k--)
	{
		ans.pb(P.rbegin()->first);
		if(Q[k].ch == 'D')
		{
			int u = paths[Q[k].index].first, v = paths[Q[k].index].second;
			int root = find(subs,u);
			LL pop = subs[root].val;
			P[pop]--;
			if(P[pop] == 0) P.erase(pop);

			root = find(subs,v);
			pop = subs[root].val;
			P[pop]--;
			if(P[pop] == 0) P.erase(pop);
			
			Union(subs,u,v);
			root = find(subs,u);
			pop = subs[root].val;
			P[pop]++;
		}
		else
		{
			int u = Q[k].u, w = Q[k].w;
			LL diff = -hist[u].back();
			hist[u].pop_back();
			diff += hist[u].back();

			int root = find(subs,u);
			LL val = subs[root].val;
			P[val]--;
			if(P[val] == 0) P.erase(val);
			val += diff;
			P[val]++;
			subs[root].val = val;
		}
	}
	reverse(all(ans));
	for(LL i : ans) printf("%lld\n",i);
	return 0;
}
