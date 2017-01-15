#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int from, to, cost, id;
	edge() {}
	edge(int i, int j, int c, int id) : from(i), to(j), cost(c), id(id) {}
};

struct subset
{
    int parent, rank;
};
 
int find(struct subset subsets[], int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
 
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int main()
{
	int tt; scanf("%d",&tt);
	for(int t=1;t<=tt;t++)
	{
		printf("Case #%d:\n",t);
		int n,m; scanf("%d %d",&n,&m);
		vector<edge> edges;
		int done[n][n];
		memset(done,0,sizeof(int)*n*n);
		for(int a=0;a<m;a++)
		{
			int u,v,cost;
			scanf("%d %d %d",&u,&v,&cost);
			if(!done[u][v] and !done[v][u])
				edges.push_back(edge(u,v,cost,a));
			done[u][v] = done[v][u] = 1;
		}
		m = edges.size();
		sort(edges.begin(), edges.end(), [](edge i, edge j) { return i.cost < j.cost; });

		int count = 1, i=0;
		vector<int> ans;
		subset subsets[n];
		for(int a=0;a<n;a++)
		{
			subsets[a].parent = a;
			subsets[a].rank = 0;
		}
		while(count < n)
		{
			int u = edges[i].from, v = edges[i].to;
			u = find(subsets,u);
			v = find(subsets,v);
			if(u == v)
				ans.push_back(edges[i].id);
			else
			{
				Union(subsets,u,v);
				count++;
			}
			i++;
		}
		while(i < m)
			ans.push_back(edges[i++].id);
			
		sort(ans.begin(), ans.end());
		for(int i : ans)
			printf("%d\n",i);
	}
	return 0;
}

