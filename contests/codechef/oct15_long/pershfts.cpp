#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define EPS std::numeric_limits<double>::epsilon()
#define max_buf_size 1024
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back

char _buf[max_buf_size];
int _bytes_read_ = max_buf_size-1;
char *_s = _buf + _bytes_read_;
inline char getc1()
{
	if(_s >= _buf + _bytes_read_)
	{
		_bytes_read_ = fread(_buf,1,max_buf_size-1,stdin);
		_buf[_bytes_read_] = 0;
		_s = _buf;
	}
	return *(_s++);
}
inline int readint()
{
	char t=getc1();
	int n=1,res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{
		n=-1;
		t=getc1();
	}
	while(isdigit(t))
	{
		res = 10*res + (t&15);
		t=getc1();
	}
	return res*n;
}
inline LL readLL()
{
	char t=getc1();
	int n=1;
	LL res=0;
	while(t!='-' && !isdigit(t))
		t=getc1();
	if(t=='-')
	{
		n=-1;
		t=getc1();
	}
	while(isdigit(t))
	{
		res = (LL)10*res + (t&15);
		t=getc1();
	}
	return res*n;
}

inline char skipwhitespace()
{
	char ch = getc1();
	while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = getc1();
	return ch;
}
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

inline char readchar()
{
	return skipwhitespace();
}

char outbuf[max_buf_size];
int outbuf_p;

inline void putc1(char ch)
{
	if(outbuf_p >= max_buf_size)
	{
		fwrite(outbuf,1,max_buf_size,stdout);
		outbuf_p = 0;
	}
	outbuf[outbuf_p++] = ch;
}

inline void flush()
{
	fwrite(outbuf,1,outbuf_p,stdout);
	outbuf_p = 0;
}

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

inline void writedouble(double d, int p)
{
	char buf[40];
	sprintf(buf,"%.*f",p,d);
	writestr(buf);
}

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

int getsum(int *bit, int n, int index)
{
	int sum = 0;
	while(index>0)
	{
		sum += bit[index];
		index -= (index & (-index));
	}
	return sum;
}

void updateBIT(int *bit, int n, int index, int val)
{
	if(index < 1) return;
	while (index <= n)
	{
		bit[index] += val;
		index += (index & (-index));
	}
}

#define MAX 100001
#define mod 1000000007
int A[MAX], B[MAX], n,k;
LL C[MAX];
int F[MAX], tmp[MAX];

int mergesort(int L, int R)
{
	if(L == R) return 0;
	int mid = (L+R)/2;
	int ans=0;
	ans += mergesort(L,mid);
	ans %= 2;
	ans += mergesort(mid+1,R);
	ans %= 2;
	int i=L, j = mid+1, k=L;
	while(i <= mid and j <= R)
	{
		if(F[i] < F[j])
			tmp[k++] = F[i++];
		else
		{
			tmp[k++] = F[j++];
			ans = (ans + mid-i+1) % 2;
		}
	}
	while(i <= mid)
		tmp[k++] = F[i++];
	while(j <= R)
		tmp[k++] = F[j++];
	repab(a,L,R)
	F[a] = tmp[a];
	return ans;
}

int main()
{
	int t = readint();
	C[0] = 1;
	repab(a,1,MAX-1)
	C[a] = (C[a-1] * a) % mod;

	while(t--)
	{
		n = readint();
		k = readint();
		rep(a,n) A[a] = readint();
		rep(a,n) B[a] = readint();

		if(k == n)
		{
			int id;
			rep(a,n)
			if(A[0] == B[a])
			{
				id = a;
				break;
			}
			int flag = 1;
			rep(a,n)
			{
				if(A[a] != B[id])
				{
					flag = 0;
					break;
				}
				id = (id + 1) % n;
			}
			printf("%d\n",flag ? B[0] : -1);
			continue;
		}

		if(k % 2 == 1)
		{
			rep(a,n) F[a] = A[a];
			int invA = mergesort(0,n-1);
			rep(a,n) F[a] = B[a];
			int invB = mergesort(0,n-1);
			if(invA != invB)
			{
				printf("-1\n");
				continue;
			}
		}

		memset(tmp,0,sizeof(tmp));
		for(int a=n; a>0; a--)
		{
			F[a] = getsum(tmp,n,B[a-1]);
			updateBIT(tmp,n,B[a-1]+1,1);
		}
		LL ans=1;
		rep(a,n)
		{
			LL fact = C[n-a-1];
			if(k%2)
				fact = (fact * (n-a-1 <= 1 ? 0 : inv(2,mod)) ) % mod;
			ans = ( ans + fact * F[a+1] ) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
