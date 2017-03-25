#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
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

#define EPS (std::numeric_limits<double>::epsilon())
#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define sq(a) ((a)*(a))
#define PI 3.141592653589793238462643383279502884197
#define mod 1000000007


int dp[52][52][52], trees;

class TreeMovingDiv2
{
	public:

		vector< pair<int,int> > edges[52];
		vector<int> G[52][52];

		set<int> split(int tree, pair<int,int> e)
		{
			queue<int> q;
			q.push(e.first);
			char done[52];
			memset(done,0,52);
			set<int> ans;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				if(done[u]) continue;
				done[u] = 1;
				ans.insert(u);
				for(int v : G[tree][u])
				{
					if( mp(u,v) == e or mp(v,u) == e) continue;
					q.push(v);
				}
			}
			return ans;
		}

		LL f(int tree, int e, set<int> v)
		{
			LL ans = 0;
			if(tree == 0)
			{
				auto i = v.find(edges[0][e].first), j = v.find(edges[0][e].second);
				return !( (i == v.end() and j == v.end()) or (i != v.end() and j != v.end()) );
			}
			for(int a = 0; a < edges[tree].size(); a++)
			{
				auto edge = edges[tree][a];
				auto i = v.find(edge.first), j = v.find(edge.second);
				if( (i != v.end() and j != v.end()) or (i == v.end() and j == v.end()) ) continue;

				if(dp[e][tree][a] >= 0)
				{
					ans = (ans + dp[e][tree][a]) % mod;
					continue;
				}
				int prev = dp[e][tree][a];
				dp[e][tree][a] = f(tree-1, e, split(tree, edge));
				ans = (ans + dp[e][tree][a]) % mod;
			}
			return ans;
		}

		int count(int n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c)
		{
			memset(dp,-1,sizeof(dp));
			LL X[n+1];
			rep(i,roots.size())
			{
				X[0] = c[i];
				for(int k = 1; k <= n-2; k++)
					X[k] = ((LL)a[i] * X[k-1] + b[i]) % mod;
				for(int j = 0; j < n-1; j++)
				{
					int u = (roots[i] + j + 1) % n;
					int v = (roots[i] + (X[j] % (j+1))) % n;
					edges[i].push_back( {u,v} );
					G[i][u].push_back(v);
					G[i][v].push_back(u);
				}
			}

			trees = roots.size();
			LL ans = 0;
			rep(a, edges[0].size())
			{
				ans = (ans + f(trees-1, a, split(0,edges[0][a])) ) % mod;
			}
			printf("ans = %d\n", (int)ans);
			return ans;
		}
};

int main()
{
	TreeMovingDiv2 ob;
	ob.count(3, {0, 0, 1}, {6, 1, 3}, {6, 5, 5}, {2, 5, 9});
}
