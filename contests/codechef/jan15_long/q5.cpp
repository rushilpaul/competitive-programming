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
inline void print(vector<T> &v, int n)
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

int findans(int n, int k)	// embarrassing
{
	vector<int> s;
	int ar[n];
	fill(ar,ar+n,0);
	for(int a=0;a<k;a++)
	{
		int i; read(i);
		ar[i-1] = 1;
	}
	for(int a=1;a<=n;a++) if(ar[a-1] == 0) s.push_back(a);
	int ans=1;
	for(int i : s)
	{
		if(i > ans) break;
		ans += i;
	}
	return ans;
}

LL f(LL n)
{
	return n*(n+1)/2;
}

int main()
{
	int t; read(t);
	while(t--)
	{
		int n,k; read(n,k);
		if(!k)
		{
			if(f(n) % 2 == 0) printf("Chef\n");
			else printf("Mom\n");
		}
		else
		{
			LL ans=1;
			if(n <= 100)
				ans = findans(n,k);
			else {
			vector<int> s(k);
			for(int &a : s) read(a);
			sort(s.begin(),s.end());
			int i=1,j=s[0]-1,k1=0;
			while(s[0] == 1 and s[k1]+1 == s[k1+1] and k1<k) k1++;
			if(i == s[0])
			{
				i = s[k1]+1;
				j = s[k1+1]-1;
			}
			while(1)
			{
				if(i > ans) break;
				ans += f(j) - f(i-1);
				if(k1 == k) break;
				while(s[k1]+1 == s[k1+1] and k1<k) k1++;
				i = s[k1]+1;
				j = k1 < k-1 ? s[k1+1]-1 : n;
				k1++;
				if(i > j) break;
			}
			}
			ans--;
			if(ans % 2) printf("Mom\n");
			else printf("Chef\n");
		}
	}	
	return 0;
}
