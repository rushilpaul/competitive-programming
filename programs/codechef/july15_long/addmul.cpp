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
		if(b & 1)
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

#define mod 1000000007

struct node
{
	node *left, *right;
	LL sum, Tsum, Tprod;
	int n;
	node()
	{
		Tsum = 0;
		Tprod = 1;
		left = right = NULL;
		n = 0;
	}
	void print()
	{
		printf("n = %d; Sum = %lld; Tprod = %lld; Tsum = %lld\n",n,sum,Tprod,Tsum);
	}
};

inline node merge(node &L, node &R)
{
	node ans;
	ans.Tprod = L.Tprod * R.Tprod;
	if(ans.Tprod >= mod)
		ans.Tprod %= mod;
	ans.Tsum = R.Tprod * L.Tsum + R.Tsum;
	if(ans.Tsum >= mod)
		ans.Tsum %= mod;
	return ans;
}

node curT;

LL query(node *root, int i, int j, int L, int R, node T)
{
	if(L <= i and R >= j)
	{
		return (root->sum * T.Tprod + T.Tsum * root->n % mod) % mod;
	}
	if(j < L || i > R) return 0;
	if(!(root->Tsum == 0 and root->Tprod == 1))
	{
		T = merge(*root,T);
	}
	int mid = (i+j)/2;
	int left = query(root->left, i, mid, L, R, T);
	int right = query(root->right, mid+1, j, L, R, T);
	return (left + right) % mod;
}

void update(node *root, int i, int j, int L, int R)
{
	if(j < L || i > R) return;
	if(i == j)
	{
		node tmp = merge(*root,curT);
		root->sum = root->sum * curT.Tprod + curT.Tsum;
		if(root->sum >= mod)
			root->sum %= mod;
		root->Tsum = tmp.Tsum;
		root->Tprod = tmp.Tprod;
		return;
	}
	if(L <= i and R >= j)
	{
		node tmp = merge(*root,curT);
		root->sum = root->sum * curT.Tprod + (curT.Tsum * root->n) % mod;
		if(root->sum >= mod)
			root->sum %= mod;
		root->Tsum = tmp.Tsum;
		root->Tprod = tmp.Tprod;
		return;
	}
	int mid = (i+j)/2;
	if(!(root->Tsum == 0 and root->Tprod == 1))
	{
		// move transformation to left
		node tmp = merge(*(root->left), *root);
		root->left->Tsum = tmp.Tsum; root->left->Tprod = tmp.Tprod;
		root->left->sum = (root->left->sum * root->Tprod % mod + root->Tsum * root->left->n % mod) % mod;
		// move transformation to right
		tmp = merge(*(root->right), *root);
		root->right->Tsum = tmp.Tsum; root->right->Tprod = tmp.Tprod;
		root->right->sum = (root->right->sum * root->Tprod % mod + root->Tsum * root->right->n % mod) % mod;
		// clear transformation in root
		root->Tprod = 1; root->Tsum = 0;
	}

	update(root->left,i,mid,L,R);
	update(root->right,mid+1,j,L,R);
	root->sum = root->left->sum + root->right->sum;
	if(root->sum >= mod)
		root->sum %= mod;
}

int ar[100001];

void build(node *root, int i, int j)
{
	if(i == j)
	{
		root->sum = ar[i];
		root->n = 1;
		return;
	}
	root->left = new node;
	root->right = new node;
	int mid = (i+j)/2;
	build(root->left,i,mid);
	build(root->right,mid+1,j);

	root->sum = root->left->sum + root->right->sum;
	if(root->sum >= mod)
		root->sum %= mod;
	root->n = root->left->n + root->right->n;
}

int main()
{
	int n = readint(), q = readint();
	for(int a=0;a<n;a++)
		ar[a] = readint();
	node *root = new node;
	build(root,0,n-1);

	while(q--)
	{
		int op = readint();
		int L = readint(), R = readint();
		if(op == 4)
		{
			node T;
			printf("%lld\n",query(root,0,n-1,L-1,R-1,T));
		}
		else
		{
			int v = readint();
			curT.Tsum = 0;
			curT.Tprod = 1;
			if(op == 1)
				curT.Tsum = v;
			else
				curT.Tprod = v;
			if(op != 3)
				update(root,0,n-1,L-1,R-1);
			else
			{
				curT.Tprod = 0;
				update(root,0,n-1,L-1,R-1);
				curT.Tsum = v;
				update(root,0,n-1,L-1,R-1);
			}
			//root->left->right->print();
			//root->left->print();
			//printf("\n");
		}
	}
	return 0;
}
