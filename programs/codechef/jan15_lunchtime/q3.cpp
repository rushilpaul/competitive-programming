#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;
#define max_buf_size 1024

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		//setvbuf(stdout,NULL,_IOFBF,max_buf_size);
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
template<class T>
inline void read(vector<T> ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}
inline int read(char *s) { cin >> s; return strlen(s); }
template<class T>
inline void print(vector<T> v, int n)
{
	for(int a=0;a<n;a++) cout << v[a] << " ";
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

inline int getbit(LL n, int i)
{
	return n & (1<<i);
}

struct node
{
	int coor[11];
	node()
	{
		fill(coor,coor+11,0);
	}
	node(const node &n)
	{
		for(int a=0;a<11;a++) coor[a] = n.coor[a];
	}
	int operator==(const node &n) const
	{
		for(int a=0;a<11;a++) if(coor[a] != n.coor[a]) return 0;
		return 1;
	}
	int operator<(const node &n) const
	{
		for(int a=0;a<11;a++) if(coor[a] < n.coor[a]) return 1;
		return 0;
	}
};

int n,d;
map<node,LL> dp;
int count=0;

LL f(node *root)
{
	for(int a=1;a<=n;a++)
		if(root->coor[a] >= d) return LLONG_MAX;
	int flag = 1;
	for(int a=1;a<=n;a++)
		if(root->coor[a] != d-1) { flag = 0; break; }
	if(flag)	// last cell
		return n*(d-1) * (n % 2 ? d-1 : 0);
	
	auto it = dp.find(*root);
	if(it != dp.end()) return it->second;
	
	LL ans=LLONG_MAX;
	for(int a=1;a<=n;a++)
	{
		root->coor[a]++;
		ans = min(ans,f(root));
		root->coor[a]--;
	}
	LL q1=0,q2=0;
	for(int a=1;a<=n;a++) { q1 += root->coor[a]; q2 ^= root->coor[a]; }
	ans += q1*q2;
	dp[*root] = ans;
	//printf("%d\n",dp.size());
	return ans;
}

int main()
{
	clock_t t1 = clock();
	int t; read(t);
	while(t--)
	{
		read(n,d);
		if(n == 1)
		{
			d--;
			printf("%lld\n",(LL)d*(d+1)*(2*d+1)/6);
			continue;
		}
		node *root = new node;
		dp.clear();
		printf("%lld\n",f(root));
	}
	t1 = clock() - t1;
	//printf("%.2f\n",(double)t1/CLOCKS_PER_SEC);
	return 0;
}
