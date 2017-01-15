#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;
#define max_buf_size 1024
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORn(i,n) for(int i=0;i<(n);i++)

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		setvbuf(stdout,NULL,_IOFBF,max_buf_size);
		setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	}
} _init_ob_unused;

template<class T>
inline T read(T &n) { cin >> n; return n; }
template<class T1,class T2>
inline void read(T1 &n1, T2 &n2) { cin >> n1 >> n2; }
template<class T1,class T2,class T3>
inline void read(T1 &n1, T2 &n2, T3 &n3) { cin >> n1 >> n2 >> n3; }
template<class T1,class T2,class T3,class T4>
inline void read(T1 &n1, T2 &n2, T3 &n3, T4 &n4) { cin >> n1 >> n2 >> n3 >> n4; }
inline int readline(char *n, int len) { while(1) { cin.getline(n,len); int i = strlen(n); if(i) return i; } }
template<class T>
inline void read(T *ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}
inline int read(char *s) { cin >> s; return strlen(s); }
template<class T>
inline void print(char sep, T a) { assert(sep==' ' or sep=='\n'); cout << a << sep; }
template<class T1, class T2>
inline void print(char sep, T1 a, T2 b) { assert(sep==' ' or sep=='\n'); cout << a << sep << b << sep; }
template<class T1, class T2, class T3>
inline void print(char sep, T1 a, T2 b, T3 c) { assert(sep==' ' or sep=='\n'); cout << a << sep << b << sep << c << sep; }
template<class T>
inline void print(vector<T> v)
{
	int s = v.size();
	for(int a=0;a<s;a++) cout << v[a] << " ";
}

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

int main()
{
	int ans=0;
	FOR(a1,1,5)
	FOR(a2,a1,5)
	FOR(a3,a2,5)
	FOR(a4,a3,5)
	FOR(a5,a4,5)
		ans++;
	printf("%d\n",ans);	
	return 0;
}
