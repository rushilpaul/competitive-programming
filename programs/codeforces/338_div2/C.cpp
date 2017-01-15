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

struct node
{
	node *ptr[26];
	set<int> pos[26];
	node() { rep(a,26) { ptr[a] = NULL; pos[a].clear(); } }
};

int main()
{
	node *root = new node, *cur = NULL;
	char s[2200];
	int n = readstr(s);
	rep(a,n)
	{
		cur = root;
		repab(b,a,n-1)
		{
			char ch = s[b];
			if(cur->ptr[ch-'a'] == NULL)
				cur->ptr[ch-'a'] = new node;
			cur->pos[ch-'a'].insert(b);
			cur = cur->ptr[ch-'a'];
		}
		cur = root;
		for(int b=a;b>=0;b--)
		{
			char ch = s[b];
			if(cur->ptr[ch-'a'] == NULL)
				cur->ptr[ch-'a'] = new node;
			cur->pos[ch-'a'].insert(b);
			cur = cur->ptr[ch-'a'];
		}
	}
	char t[2200];
	n = readstr(t);
	t[n] = 'z' + 1;
	t[n+1] = 0;
	int ans = 0, last = 0;
	cur = root;
	vector< pair<int,int> > v;

	rep(a,n+1)
	{
		char ch = t[a];
		if(ch <= 'z' and cur->ptr[ch-'a'])
			cur = cur->ptr[ch-'a'];
		else
		{
			int len = a - last;
			if(len == 0) { printf("-1\n"); return 0; }
			ans++;
			if(len > 1)
			{
				int flag = 1;
				for(int p : root->pos[t[last]-'a'])
				{
					cur = root->ptr[t[last]-'a'];
					int x = p;
					flag = 1;
					repab(i,last+1,a-1)
					{
						char c = t[i] - 'a';
						if(cur->pos[c].find(x+1) == cur->pos[c].end()) { flag = 0; break; }
						x++;
						cur = cur->ptr[c];
					}
					if(flag)
					{
						v.pb({p+1,x+1});
						break;
					}
				}
				if(flag == 0)
				{
					for(int p : root->pos[t[last]-'a'])
					{
						cur = root->ptr[t[last]-'a'];
						int x = p;
						flag = 1;
						repab(i,last+1,a-1)
						{
							char c = t[i] - 'a';
							if(cur->pos[c].find(x-1) == cur->pos[c].end()) { flag = 0; break; }
							x--;
							cur = cur->ptr[c];
						}
						if(flag)
						{
							v.pb({p+1,x+1});
							break;
						}
					}
				}
			}
			else
				v.pb({ *root->pos[t[last]-'a'].begin() + 1, *root->pos[t[last]-'a'].begin() + 1 });
			cur = root;

			last = a;
			if(a < n)
				a--;
		}
	}
	cout << ans << endl;
	for(auto i : v)
		printf("%d %d\n",i.first,i.second);

	return 0;
}

