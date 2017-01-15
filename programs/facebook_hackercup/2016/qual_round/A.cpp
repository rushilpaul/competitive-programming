#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define PI 3.141592653589793238462643383279502884197

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

vector< pair<int,int> > P;
vector<int> dist[2001];

int main()
{
	int tt; cin >> tt;
	rep(t,tt)
	{
		printf("Case #%d: ",t+1);
		int n; cin >> n;
		P.clear();
		rep(a,n)
		{
			dist[a].clear();
			int i,j; cin >> i >> j;
			P.pb({i,j});
		}
		LL ans=0;
		rep(a,n)
		{
			rep(b,n)
				if(a != b)
					dist[a].pb( pow(P[a].first - P[b].first,2) + pow(P[a].second - P[b].second,2) );
			sort(all(dist[a]));
		}
		rep(a,n)
		{
			rep(b,n)
			{
				if(a == b) continue;
				int d = pow(P[a].first - P[b].first,2) + pow(P[a].second - P[b].second,2);
				ans += (upper_bound(all(dist[b]), d) - dist[b].begin()) - (lower_bound(all(dist[b]), d) - dist[b].begin()) - 1;
			}
		}
		cout << ans/2 << endl;
	}
	return 0;
}

