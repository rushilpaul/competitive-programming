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

int ar[100], n, ans;

void f(int i, vector<int> v)
{
	if(i == n)
	{
		if(v.size() % 2 == 0) return;
		if(v.size() > 1 and abs(v[1] - v[0]) != 1) return;
		for(int a=1;a<v.size();a++)
		{
			if(a % 2 and (v[a] != v[0]-1 and v[a] != v[0]+1)) return;
			if(a % 2 == 0 and v[a] != v[0]) return;
		}
		ans++;
		return;
	}
	f(i+1,v);
	v.pb(ar[i]);
	f(i+1,v);
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		rep(a,n) cin >> ar[a];
		vector<int> v;
		ans=0;
		f(0,v);
		cout << ans << endl;
	}
	return 0;
}

