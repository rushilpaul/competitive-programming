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
		setvbuf(stdout,NULL,_IONBF,max_buf_size);
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
inline void read(vector<T> &ar, int n)
{
	for(int a=0;a<n;a++) cin >> ar[a];
}
inline int read(char *s) { cin >> s; return strlen(s); }
template<class T>
inline void print(vector<T> &v, int n)
{
	for(int a=0;a<n;a++) cout << v[a] << " ";
	cout << "\n";
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

vector<LL> done(21);
LL sum;

int f(int i, int n, LL s, vector<LL> &ar)
{
	if(i == n)
	{
		if(!s) return 0;
		LL s2=0;
		for(int a=0;a<n;a++) if(done[a]) s2 += ar[a];
		if(s2 == sum)
		{
			for(int a=0;a<n;a++)
				if(done[a])
				{
					done.erase(done.begin() + a);
					ar.erase(ar.begin() + a);
					a--;
					n--;
				}
			return 1;
		}
		return 0;
	}
	if(f(i+1,n,s,ar)) return 1;
	done[i] = 1;
	if(f(i+1,n,s+ar[i],ar)) return 1;
	done[i] = 0;
	return 0;
}

int main()
{
	int t; read(t);
	while(t--)
	{
		int n,k; read(n,k);
		vector<LL> ar(n); read(ar,n);
		sum = 0;
		for(LL a : ar) sum += a;
		if((sum == 0 and k <= n) || k == 1) { printf("yes\n"); continue; }
		if(sum % k)
		{
			printf("no\n");
			continue;
		}
		sum /= k;
		done.clear();
		done.assign(n,0);
		int k1=0;
		while(1)
		{
			int tmp = ar.size();
			if(!tmp) { printf("yes\n"); break; }
			if(!f(0,tmp,0,ar))
			{
				int s=0;
				for(int a : ar) s += a;
				if(!s and k1 == k) { printf("yes\n"); break; }
				printf("no\n");
				break;
			}
			k1++;
		}
	}
	return 0;
}
