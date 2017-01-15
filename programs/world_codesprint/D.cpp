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

#define mod 1000000007
#define MAX 10

//int dp[5][MAX][MAX][MAX][MAX];

map< vector<int>, int> dp;

int f(int D, int a, int b, int c, int d)
{
	if(a < 0 or b < 0 or c < 0 or d < 0) return 0;
	if(a + b + c + d == 0) return 1;
	//int &ret = dp[D][a][b][c][d];
	auto it = dp.find({D,a,b,c,d});
	if(it != dp.end()) return it->second;
	int ret = 0;
	if(D == 1)
		ret = f(1,a-1,b,c,d) + f(2,a,b-1,c,d);
	else if(D == 2)
		ret = f(3,a,b,c-1,d) + f(4,a,b,c,d-1);
	else if(D == 3)
		ret = f(3,a,b,c-1,d) + f(4,a,b,c,d-1);
	else
		ret = f(1,a-1,b,c,d) + f(2,a,b-1,c,d);
	ret %= mod;
	dp[ {D,a,b,c,d} ] = ret;
	return ret;
}

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int ans = (f(1,a-1,b,c,d) + f(2,a,b-1,c,d)) % mod + (f(3,a,b,c-1,d) + f(4,a,b,c,d-1)) % mod;
	ans %= mod;
	cout << ans << endl;
	return 0;
}
