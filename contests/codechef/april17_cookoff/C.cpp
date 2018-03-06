#include <iostream>
#include <cstdio>
#include <set>
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
typedef vector<LL> VLL;
typedef vector<double> VD;

#define DEBUG 0
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

struct data
{
	vector<vector<pair<int,int> > > v;
	double cost;
};

#define max 4096

double dist[14][14];

inline double find_dist(pair<int,int> a, pair<int,int> b)
{ return sqrt(sq(a.first - b.first) + sq(a.second - b.second)); }

double find_cost(vector< pair<int,int> > v)
{
	int n = v.size();
	double dp[(1<<n)][n];
	rep(S,1<<n) rep(i,n) dp[S][i] = 1e9;

	rep(S,1<<n)
	{
		if(!S) continue;
		int count = 0, setbit = -1;
		rep(i,n)
			if(S & (1<<i)) { count++; setbit = i; }
		if(count == 1)
		{
			dp[1 << setbit][setbit] = sqrt(sq(v[setbit].first) + sq(v[setbit].second));
			continue;
		}

		rep(i,n)
		{
			rep(j,n)
			{
				if(!(S & (1<<j)) or i == j) continue;
				int S_ = S ^ (1<<i);
				dp[S][i] = min(dp[S][i], dp[S_][j] + find_dist(v[i], v[j]));
			}
		}
	}
	double cost = 1e9;
	rep(i,n)
		cost = min(cost, dp[(1<<n)-1][i] + dp[1<<i][i]);
	if(DEBUG)
		printf("Calculated cost for %d points as %f\n", v.size(), cost);
	return cost;
}

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint(), k = readint();
		vector< pair<int,int> > points;
		rep(a,n)
		{
			int x = readint(), y = readint();
			points.push_back({x,y});
		}
		//rep(a,n)
		//rep(b,n)
			//dist[a][b] = sqrt(sq(points[a].first - points[b].first) + sq(points[a].second - points[b].second));

		map<int, data> m;
		map<int, data> new_map;
		rep(a,max)
		{
			data x;
			x.cost = -1;
			m[a] = x;
		}
		//m[0].cost = 0;

		rep(a,n)
		{
			new_map.clear();
			string s = readstring(k+10);
			int bits = 0;
			for(int i = k-1; i >= 0; i--)
				if(s[i] == '1') bits |= (1<<(k-1-i));
			if(DEBUG)
				printf("Got %d\n",bits);

			vector<pair<int,int> > v;
			v.pb(points[a]);
			double single_cost = find_cost(v);
			if(m[bits].cost < 0 or single_cost < m[bits].cost)
			{
				m[bits].v.clear();
				m[bits].v.pb(v);
				m[bits].cost = single_cost;
				if(DEBUG)
					printf("Added %f for %d\n", single_cost, bits);
			}

			rep(B,max)
			{
				if(m[B].cost < 0) continue;
				int new_bits = bits | B;
				if(DEBUG)
					printf("comparing %d with %d + %d\n", new_bits, bits, B);

				auto &it = m[B];
				auto &newit = m[new_bits];
				vector< vector< pair<int,int> > > ans;
				double min_cost = 1e9;

				for(auto v : it.v)
				{
					vector< pair<int,int> > new_v = v;
					int flag = 1;
					for(auto it2 : v)
						if(it2 == points[a])
						{
							flag = 0;
							//if(DEBUG)
								//printf("%d,%d already exists in one of the vectors of %d\n", points[a].first, points[a].second, B);
							break;
						}
					if(flag == 0) continue;

					new_v.pb(points[a]);
					double cost = find_cost(new_v);
					if(cost < min_cost)
					{
						min_cost = cost;
						ans.clear();
						ans.push_back(new_v);
					}
					else if(cost == min_cost)
						ans.push_back(new_v);
				}
				if(min_cost < newit.cost or newit.cost < 0)
				{
					if(DEBUG)
						printf("Got better cost!\n");
					newit.v = ans;
					newit.cost = min_cost;
				}
				else if(min_cost == newit.cost)
				{
					if(DEBUG)
						printf("Same cost!\n");
					for(auto v : ans)
						newit.v.pb(v);
				}
				if(DEBUG)
					printf("min_cost for %d: %f\n", new_bits ,min_cost);
			}
		}
		int ans_bits = (1<<k) - 1;
		if(m[ans_bits].v.size() == 0)
			printf("-1\n");
		else
			printf("%.8f\n", m[ans_bits].cost);

		if(DEBUG)
		for(auto v : m[ans_bits].v)
		{
			for(auto v1 : v)
				printf("%d,%d ", v1.first, v1.second);
			printf("\n");
		}
	}
	return 0;
}


