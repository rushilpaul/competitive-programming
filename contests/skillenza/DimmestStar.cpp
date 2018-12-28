#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
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

int readint() { int i; scanf("%d",&i); return i; }

vector<string> split(string S, string D)	// Split string S with D as the delimiter, return tokens
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
    T d = egcd(b % a, a, x1, y1);
    x = y1 - x1 * (b/a);
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

vector<int> V[10001];
int ans, root, max_depth;

void f(int v, int parent, int depth)
{
	if(V[v].size() == 1 and v != root)
	{
		//printf("leaf node %d at depth %d\n", v, depth);
		if(depth > max_depth)
		{
			max_depth = depth;
			ans = v;
		}
		else if(depth == max_depth) {
			ans = min(ans, v);
		}
		return;
	}
	for(int u : V[v])
		if(u != parent)
			f(u, v, depth+1);
}

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint();
		repab(i,1,n)
			V[i].clear();

		rep(a,n-1)
		{
			int u = readint(), v = readint();
			V[u].pb(v);
			V[v].pb(u);
		}
		root = readint();

		if(n == 1) {
			printf("%d\n", root);
			continue;
		}
		ans = INT_MAX;
		max_depth = 0;
		f(root, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}


