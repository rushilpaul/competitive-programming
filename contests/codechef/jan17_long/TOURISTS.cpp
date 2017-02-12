#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<int,int> G[100001];		// G[i][j] is number of edges between i & j. Can be 1 or 2
vector<pair<int,int> > edges;
set< pair<int,int> > order;

int main()
{
	int n,e; scanf("%d %d",&n,&e);
	for(int a=0;a<e;a++)
	{
		int i,j; scanf("%d %d",&i,&j);
		edges.push_back({i,j});
		G[i][j] = G[i][j] + 1;
		G[j][i] = G[j][i] + 1;
	}

	// preliminary check
	for(int a=1;a<=n;a++)
		if(G[a].size() == 0)
		{
			printf("NO\n");
			return 0;
		}
		else
		{
			int s = 0;
			for(auto edge : G[a])
				s += edge.second;
			if(s % 2)
			{
				printf("NO\n");
				return 0;
			}
		}
	
	int num_edges = 0;
	vector<int> nodes;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		int flag = 0;	// if there is no edge
		for(auto &j : G[i])
		{
			int target = j.first;
			if(j.second > 0)
			{
				num_edges++;
				flag = 1;
				order.insert( {i,j.first} );
				nodes.push_back(i);
				q.push(j.first);
				j.second = j.second - 1;
				G[target][i] = G[target][i] - 1;
				break;
			}
		}
		if(num_edges == e)
		{
			printf("YES\n");
			//for(auto edge : order)
			//{
				//printf("%d %d\n", edge.first, edge.second);
			//}
			for(auto edge : edges)
			{
				pair<int,int> reverse_edge = { edge.second, edge.first };
				if(order.find(edge) != order.end())
				{
					printf("%d %d\n", edge.first, edge.second);
					order.erase(edge);
				}
				else if(order.find(reverse_edge) != order.end())
				{
					printf("%d %d\n", reverse_edge.first, reverse_edge.second);
					order.erase(reverse_edge);
				}
				else
					printf("Something is wrong with %d %d!", edge.first, edge.second);
			}
			return 0;
		}
		if(!flag)
		{
			if(nodes.size() == 0)
			{
				printf("NO\n");
				return 0;
			}
			q.push(nodes.back());
			nodes.pop_back();
		}
	}
	return 0;
}

