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

vector<int> G[100001];
int costar[100001];

void dfs(int u, int cost)
{
	costar[u] = max(costar[u], cost);
	for(int v : G[u])
		dfs(v,cost+1);
}

int main()
{
	int n; cin >> n;
	if(n == 1) { printf("1\n"); return 0; }
	int ar[n];
	rep(a,n) scanf("%d",ar+a);
	rep(a,n-1)
	{
		if(ar[a] < ar[a+1])
			G[a].pb(a+1);
		else if(ar[a] > ar[a+1])
			G[a+1].pb(a);
	}
	LL ans = 0;
	repab(a,1,n-2)
	{
		if(ar[a] == ar[a-1] and ar[a] == ar[a+1])
			ans++;
	}
	if(ar[0] == ar[1]) ans++;
	if(ar[n-1] == ar[n-2]) ans++;

	rep(a,n)
	{
		if(G[a].size() > 0 and costar[a] == 0)
			dfs(a,1);
	}
	rep(a,n)
		ans += costar[a];
	cout << ans;

	return 0;
}

