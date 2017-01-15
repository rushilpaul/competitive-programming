#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 1024

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

// END OF IO

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

multimap< pair<LL,int>, pair<LL,int> > edges;
map< pair<LL,int>, LL > term;

struct vertex
{
	LL L;
	int row;
	char type;
	vertex() {}
	vertex(LL col, int row, char type) : L(col), row(row), type(type) {}
};

inline int cmp(const vertex &a, const vertex &b)
{
	return a.L < b.L or (a.L == b.L and a.row < b.row) or (a.L == b.L and a.row == b.row and a.type < b.type);
}

vertex ar[100001];
int mod = 1000000007;

int main()
{
	clock_t time = clock();
	LL n = readLL();
	int m = readint(), k = readint(), idx=0;
	for(int a=0;a<k;a++)
	{
		LL u = readLL(); int v = readint();
		u = n-u;
		pair<LL,int> s = make_pair(u,v);
		u = readLL(); v = readint();
		u = n-u;
		pair<LL,int> e = make_pair(u,v);
		if(s.first < e.first) swap(s,e);
		edges.insert(make_pair(s,e));
		ar[idx++] = vertex(s.first,s.second,1);
		ar[idx++] = vertex(e.first,e.second,2);
	}
	//for(auto it : edges) printf("%lld,%d -> %lld,%d\n",(it.first).first,(it.first).second,(it.second).first,(it.second).second);
	term[make_pair(-1,0)] = 1;
	sort(ar,ar+2*k,cmp);
	ar[2*k] = vertex(-2,0,2);
	LL l, cur = 1, i = 0, last = -3;
	LL paths = 0;
	set< pair<LL,int> > cache;
	for(int a=0;a<2*k+1;a++)
	{
		l = ar[a].L;
		if(last != l and last >= 0 and paths > 0)
		{
			LL exp = last-i+1;
			if(last == n) exp--;
			cur = ((cur * pow(m,exp,mod)) % mod + paths) % mod;
			i = last+1;
			paths = 0;
			cache.clear();
		}
		pair<LL,int> p = make_pair(ar[a].L,ar[a].row);
		int exists = cache.find(p) != cache.end();
		cache.insert(p);
		if(p.first >= 0)
		{
			LL count1 = 0;
			LL count2 = 0;
			int flag=0;
			if(ar[a].type == 2) flag = term.find(p) == term.end();
			if(ar[a].type == 2)
				count1 = (pow(m,ar[a].L-i,mod) * cur) % mod;
			if(!exists or flag)
			{
				auto start = edges.lower_bound(p), end = edges.upper_bound(p);
				for(;start != end; start++)
				{
					pair<LL,int> p2 = start->second;
					count2 = (count2 + term[p2]) % mod;
				}
			}
			if(ar[a].type == 1)		// init
			{
				//if(ar[a].L == 2) printf("count2 = %lld, coord: %lld,%d\n",count2,ar[a].L,ar[a].row);
				if(exists) count2 = 0;
				paths = (paths + count2) % mod;
			}
			else	// terminal
			{
				if(flag)
					term[p] = (count1 + count2) % mod;
			}
		}
		last = l;
	}
	if(i <= n)
		cur = ((cur * pow(m,n-i,mod)) % mod + paths) % mod;
	printf("%lld\n",cur);
	//time = clock() - time;
	//printf("%.2f\n",(double)time/CLOCKS_PER_SEC);
	return 0;
}
