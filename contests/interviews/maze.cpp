// http://www.geeksforgeeks.org/flipkart-interview-experience-set-32-for-sde-1/
// Round 1 question 2 (Maze)
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int i,j,cost,idx;
	node() {}
	node(int i, int j, int cost, int idx) : i(i), j(j), cost(cost), idx(idx) {}
	void print()
	{
		printf("%d %d %d %d\n",i,j,cost,idx);
	}
};

int n, dist[10][10];
char s[101][101];
vector<node> pos;

int fromS[10], toE[10];
int si,sj,ei,ej;


int find(pair<int,int> src, pair<int,int> dst)
{
	int done[100][100];
	memset(done,0,sizeof(done));
	queue<node> q;
	q.push( { src.first, src.second, 0, 0 } );
	done[src.first][src.second] = 1;
	while(q.size() > 0)
	{
		node t = q.front();
		if(t.i == dst.first and t.j == dst.second)
			return t.cost;
		q.pop();
		node neigh[4];
		neigh[0] = { t.i-1, t.j, t.cost+1, 0};
		neigh[1] = { t.i, t.j-1, t.cost+1, 0 };
		neigh[2] = { t.i+1, t.j, t.cost+1, 0 };
		neigh[3] = { t.i, t.j+1, t.cost+1, 0 };
		for(auto i : neigh)
		{
			if(i.i >= 0 and i.i < n and i.j >= 0 and i.j < n and s[i.i][i.j] != '#' and done[i.i][i.j] == 0)
			{
				q.push(i);
				done[i.i][i.j] = 1;
			}
		}
	}
	return INT_MIN;
}

int findcost()
{
	int cost = fromS[pos[0].idx];
	int size = pos.size();
	for(int a=0;a<size;a++)
		cost += dist[pos[a].idx][pos[a+1].idx];
	cost += toE[pos[size-1].idx];
	return cost;
}

int cmp(const node &a, const node &b)
{
	return a.idx < b.idx;
}

int main()
{
	scanf("%d",&n);
	int idx = 0;
	for(int a=0;a<n;a++)
	{
		scanf("%s",s[a]);
		for(int b=0;b<n;b++)
			if(s[a][b] == 'k')
			{
				pos.push_back( {a,b,0,idx} );
				idx++;
			}
			else if(s[a][b] == 'S')
				si = a, sj = b;
			else if(s[a][b] == 'E')
				ei = a, ej = b;
	}
	int size = pos.size();
	for(int a=0;a<size;a++)
	{
		// from S
		fromS[a] = find({si,sj}, {pos[a].i, pos[a].j});
		toE[a] = find({ei,ej}, {pos[a].i, pos[a].j});

		for(int b=a+1;b<size;b++)
			dist[a][b] = dist[b][a] = find( {pos[a].i,pos[a].j}, {pos[b].i, pos[b].j} );
	}
	/*
	int ans = INT_MAX;
	for(int a=0;a<pos.size();a++)
		for(int b=a+1;b<pos.size();b++)
			printf("%d->%d = %d\n",a,b,dist[pos[a].idx][pos[b].idx]);
	*/
	int ans = INT_MAX;
	do
	{
		ans = min(ans, findcost());
	} while(next_permutation(pos.begin(),pos.end(),cmp));
	printf("%d\n",ans);

	return 0;
}

