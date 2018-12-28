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

LL readint() { LL x; scanf("%lld",&x); return x; }

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

int H[100001], C[100001];
vector<int> G[100001];
int done[100001];
LL ans[1000001][2];
int n, m;

void solve()
{
	queue<int> q;
	q.push(1);
	while(q.size() > 0)
	{
		int u = q.front();
		q.pop();
		done[u] = 1;
		for(int v : G[u])
		{
			if(done[v])
				continue;
			if(H[u] < H[v])	// uphill
			{
				ans[v][0] = min(ans[v][0], ans[u][0]);
				ans[v][0] = min(ans[v][0], ans[u][1] + C[u]);
			}
			else if(H[u] > H[v])	// downhill
			{
				ans[v][1] = min(ans[v][1], ans[u][0] + C[u]);
				ans[v][1] = min(ans[v][1], ans[u][1]);
			}
			else	// same hill
			{
				ans[v][0] = min(ans[v][0], ans[u][0]);
				ans[v][1] = min(ans[v][1], ans[u][1]);
			}
			q.push(v);
		}
	}
	LL final_ans = min(ans[n][0], ans[n][1]);
	if(final_ans == LLONG_MAX)
		final_ans = -1;
	printf("%lld\n", final_ans);
}

int main()
{
	n = readint(); m = readint();
	for(int a=0;a<n;a++)
		H[a] = readint();
	for(int a=0;a<n;a++)
	{
		C[a] = readint();
		ans[a][0] = ans[a][1] = LLONG_MAX;
	}
	for(int a=0;a<m;a++)
	{
		int x = readint(), y = readint();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	solve();
	return 0;
}
