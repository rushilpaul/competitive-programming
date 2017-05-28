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
	LL n; scanf("%lld", &n);
	return n;
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
	int n;
	scanf("%s", s);
	return n = strlen(s);
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

//inline char readchar() { }
 
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

int n,m, X;
string ans;
int swapped;

void op(pair<int,int> p1, pair<int,int> p2)
{
	X++;
	if(swapped)
	{
		swap(p1.first, p1.second);
		swap(p2.first, p2.second);
	}
	ans = ans + to_string(p1.first) + " " + to_string(p1.second) + " " + to_string(p2.first) + " " + to_string(p2.second) + "\n";
}

// bring hole from start to bottom right corner
void bringToCorner(pair<int,int> start)
{
	for(int a = start.first + 1; a <= n; a++)
		op( {a, start.second}, {a-1, start.second} );
	for(int a = start.second + 1; a <= m; a++)
		op( {n, a}, {n, a-1} );
}

// bring ball from src to dest
void bringToLocation(pair<int,int> src, pair<int,int> dest)
{
	if(src.first == dest.first)
	{
		if(src.second > dest.second)
			for(int col = src.second; col >= dest.second + 1; col--)
				op( {src.first, col}, {src.first, col-1} );
		else
			repab(col, src.second, dest.second - 1)
				op( {src.first, col}, {src.first, col+1} );
	}
	else
	{
		if(src.first > dest.first)
			for(int row = src.first; row >= dest.first + 1; row--)
				op( {row, src.second}, {row-1, src.second} );
		else
			repab(row, src.first, dest.first - 1)
				op( {row, src.second}, {row+1, src.second} );
	}
}

// transform **. to .*.
void transformRow(int r)
{
	// first move: 3rd last jumps to last
	op( {r, m-2}, {r, m} );
	// move last to second last column
	op( {r, m}, {r, m-1} );
}

// transform **. to .*.
void transformCol(int c)
{
	// first move: 3rd jumps to first
	op( {3, c}, {1, c} );
	// move first to second row
	op( {1, c}, {2, c} );
}

void solve()
{
	// solve each row starting from last row
	for(int r = n; r >= 1; r--)
	{
		transformRow(r);
		for(int col = m - 4; col >= 1; col -= 2)
		{
			op( {r, col}, {r, col+2} );
			bringToLocation( {r, col+2}, {r, m-2} );
			transformRow(r);
		}
		if(m % 2 == 0)
		{
			// kill the ball in first col
			bringToLocation( {r, 1}, {r, m-2} );
			transformRow(r);
		}
		// now the row r is: ....*.
		if(r > 1)
		{
			// bring the last col of previous row down
			op( { r-1, m}, {r, m} );
			// make the row ....*..
			op( {r, m}, {r, m-2} );
		}
	}
	if(n == 1) return;
	if(n == 2)
	{
		// ....*.
		// ...*..
		op( {2, m-2}, {1, m-2} );
		op( {1, m-2}, {1, m} );
		return;
	}
	// transform the 3rd last column
	transformCol(m-2);
	for(int r = 4; r <= n; r++)
	{
		// bring rth row to 3rd row
		bringToLocation( {r, m-2}, {3, m-2} );
		transformCol(m-2);
	}
	// now config will be:
	// ....*.
	// ...*..
	op( {2, m-2}, {1, m-2} );
	op( {1, m-2}, {1, m} );
}

int main()
{
	int t = readint();
	while(t--)
	{
		ans = "";
		swapped = X = 0;
		n = readint(); m = readint();
		int startx, starty;
		rep(a,n)
		{
			string s = readstring(15);
			if(s.find('.') != string::npos)
			{
				startx = a + 1;
				starty = s.find('.') + 1;
			}
		}
		if(n < 3 and m < 3)
		{
			printf("%d\n", n*m == 2 ? 0 : -1);
			continue;
		}
		if(m < 3)
		{
			swap(n,m);
			swap(startx, starty);
			swapped = 1;
		}
		bringToCorner({startx, starty});
		solve();
		assert(X <= 5000);
		printf("%d\n%s", X, ans.c_str());
	}
	return 0;
}



