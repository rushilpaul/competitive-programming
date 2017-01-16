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
		setvbuf(stdout,NULL,_IOFBF,max_buf_size);
		setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	}
} _init_ob_unused;

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

int f(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second or (a.second == b.second and a.first < b.first);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		pair<int,int> ar[n];
		for(int a=0;a<n;a++)
		{
			int i,j; scanf("%d %d",&i,&j);
			ar[a] = make_pair(i,j);
		}
		sort(ar,ar+n,f);
		int ans=1,last=ar[0].second;
		for(int a=1;a<n;a++)
			if(ar[a].first > last) { ans++; last = ar[a].second; }
		printf("%d\n",ans);
	}
	return 0;
}
