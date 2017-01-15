#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS (std::numeric_limits<double>::epsilon())
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
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

int ar[100001], B[100001];

struct node
{
	node *left, *right;
	int max1, nmax1, nmax2;
	node()
	{
		max1 = nmax1 = nmax2 = 0;
		left = right = NULL;
	}
};

inline node merge(node &L, node &R)
{
	node ans;
	if(L.max1 == R.max1)
	{
		ans.max1 = L.max1;
		ans.nmax1 = L.nmax1 + R.nmax1;
		ans.nmax2 = L.nmax2 + R.nmax2;
	}
	else
	{
		ans.max1 = max(L.max1, R.max1);
		ans.nmax1 = L.max1 > R.max1 ? L.nmax1 : R.nmax1;
		if(ans.max1 - 1 == L.max1)
			ans.nmax2 = L.nmax1;
		if(ans.max1 - 1 == R.max1)
			ans.nmax2 += R.nmax1;
	}
	return ans;
}

node query(node *root, int i, int j, int L, int R)
{
	if(L <= i and R >= j) return *root;
	if(j < L || i > R) return node();
	int mid = (i+j)/2;
	node left =  query(root->left, i, mid, L, R);
	node right = query(root->right, mid+1, j, L, R);
	return merge(left,right);
}

void update(node *root, int i, int j, int pos, node &cur)
{
	if(i == j)
	{
		root->max1 = cur.max1;
		root->nmax1 = cur.nmax1;
		root->nmax2 = cur.nmax2;
		return;
	}
	int mid = (i+j)/2;
	if(pos <= mid) update(root->left,i,mid,pos,cur);
	else update(root->right,mid+1,j,pos,cur);
	node res = merge(*(root->left),*(root->right));
	root->max1 = res.max1;
	root->nmax1 = res.nmax1;
	root->nmax2 = res.nmax2;
}

void build(node *root, int i, int j)
{
	if(i == j)
	{
		return;
	}
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);
	//node res = merge(*(root->left),*(root->right));
}

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint();
		rep(a,n) ar[a] = readint();
		rep(a,n) B[a] = ar[a];
		map<int,int> m;
		int i=1;
		sort(B,B+n);
		rep(a,n)
			if(m[B[a]] == 0) m[B[a]] = i++;
		rep(a,n)
			B[a] = m[ar[a]];

		node *root = new node;
		n = i;
		build(root,0,n-1);
		node tmp;
		tmp.nmax1 = tmp.nmax2 = 1;
		update(root,0,n-1,0,tmp);
		for(int a=0;a<n-1;a++)
		{
			node cur = query(root,0,n-1,0,B[a]-1);
			cur.max1++;
			printf("num: %d; max1,f: %d,%d;  max2,f: %d,%d\n",B[a],cur.max1,cur.nmax1,cur.max1-1,cur.nmax2);
			update(root,0,n-1,B[a],cur);
		}
	}
	return 0;
}

