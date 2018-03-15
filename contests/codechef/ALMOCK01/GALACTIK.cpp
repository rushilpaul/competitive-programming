#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
#define pb push_back

vector<int> G[100001];
vector<int> done(100001,0);
int cost[100001];
int min_cost;

void dfs(int v)
{
	if(done[v])
		return;
	done[v] = 1;
	if(cost[v] >= 0)
		min_cost = min(min_cost, cost[v]);

	for(int u : G[v])
		dfs(u);
}

int main()
{
	int n,m; scanf("%d %d", &n, &m);
	for(int a = 0; a < m; a++)
	{
		int i,j; scanf("%d %d", &i, &j);
		G[i].pb(j);
		G[j].pb(i);
	}
	for(int a=1; a<=n; a++)
		scanf("%d", &cost[a]);

	vector<int> faces;
	for(int a=1;a<=n;a++)
	{
		min_cost = INT_MAX;
		if(done[a])		// component already explored
			continue;
		dfs(a);
		faces.pb(min_cost);
	}
	int possible = 1;
	for(int i : faces)
		if(i == INT_MAX)
			possible = 0;
	if(!possible and faces.size() == 1)
		possible = 1;
	
	if(!possible)
	{
		printf("-1\n");
		return 0;
	}
	auto i = min_element(faces.begin(), faces.end());
	min_cost = *i;
	*i = 0;
	int ans = min_cost * (faces.size()-1);
	for(int i : faces)
		ans += i;

	printf("%d\n", ans);
	return 0;
}
