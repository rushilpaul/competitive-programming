#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector< pair<int,int> > VII;
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
inline LL readint()
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

// assigns x and y such that a*x + b*y = gcd(a,b)
// returns gcd(a,b)
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

#define MOD 1000000007

int A[100002];
vector< pair<int,int> > inc, decr;
vector< pair< pair<int,int>, char> > allp;
map<int,int> incmap, decrmap;

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint(), m = readint(), k = readint();
		rep(a,n)
			A[a+1] = readint();

		int start = 0, end = 0, prevtype;

		allp.clear(); inc.clear(); decr.clear();
		rep(a,m)
		{
			int type = readchar();
			allp.pb( { { readint(), readint() }, type } );
		}
		sort(all(allp));
		if(allp[m-1].second == 'I')
			allp.pb({ {1000000, 1000001}, 'D'});
		else
			allp.pb({ {1000000, 1000001}, 'I'});

		start = allp[0].first.first;
		end = allp[0].first.second;
		prevtype = allp[0].second;

		int overlap = 0;
		for(int a=1;a<m+1;a++)
		{
			if(allp[a].second == prevtype)
			{
				if(allp[a].first.second <= end)
					continue;

				if(allp[a].first.first > end)
				{
					inc.pb({ start, end });
					incmap[start] = end;
					start = allp[a].first.first;
					end = allp[a].first.second;
				}
				end = allp[a].first.second;
			}
			else
			{
				if(allp[a].first.first < end)
				{
					overlap = 1;
					break;
				}
				if(allp[a-1].second == 'I')
				{
					inc.pb({ start, end});
					incmap[start] = end;
				}
				else
				{
					decr.pb({ start, end});
					decrmap[start] = end;
				}

				start = allp[a].first.first;
				end = allp[a].first.second;
				prevtype = allp[a].second;
			}
		}

		int unknown = 0;
		rep(a,n)
			if(A[a] == -1)
				unknown = 1;
		if(!unknown)
		{
			printf("1\n");
			continue;
		}
		if(unknown and overlap)
		{
			printf("0\n");
			continue;
		}
		
		allp.clear();
		for(auto it : inc)
			allp.pb({it, 'I'});
		for(auto it : decr)
			allp.pb({it, 'D'});

		sort(all(allp));

		LL ans = 1;
		int pos = 1;
		for(int i=0;i<allp.size();i++)
		{
			auto it = allp[i];
			int start = it.first.first, end = it.first.second;
			unknown = 1;
			pair<int,int> known = {0,0};		// pos, num
			for(int a=start;a<=end;a++)
				if(A[a] != -1)
				{
					unknown = 0;
					if(A[a] - (a - start) < 1 or A[a] + (end - a) > k)
						pos = 0;
					if(known.second and A[a] - (a - known.first) != known.second)
						pos = 0;
					known = { a, A[a] };
				}

			if(!pos or (end - start + 1 > k))
			{
				ans = 0;
				break;
			}
			if(!unknown)
				continue;

			ans = ans * (k - (end - start)) % MOD;
		}

		for(auto it : decr)
		{
			int start = it.first, end = it.second;
			unknown = 1;
			pair<int,int> known = {0,0};		// pos, num
			for(int a=start;a<=end;a++)
				if(A[a] != -1)
				{
					unknown = 0;
					if(A[a] + (a - start) > k or A[a] - (end - a) <= 0)
						pos = 0;
					if(known.second and A[a] + (a - known.first) != known.second)
						pos = 0;
					known = { a, A[a] };
				}

			if(!pos or (end - start + 1 > k))
			{
				ans = 0;
				break;
			}
			if(!unknown)
				continue;

			ans = ans * (k - (end - start)) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

