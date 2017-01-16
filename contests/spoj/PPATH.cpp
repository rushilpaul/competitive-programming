#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int prime[10000];
vector<string> primes;

string make(int n)
{
	string s = "";
	while(n)
	{
		int d = n%10;
		n /= 10;
		s = (char)(d+48) + s;
	}
	return s;
}

#define maxn 1061
int V[maxn][maxn];
vector< pair<int,int> > edges;
vector<int> visited;
int n_edges;

int countdiff(string &a, string &b)
{
	int c=0;
	assert(a.size() == 4 and b.size() == 4);
	for(int i=0;i<a.size();i++)
	{
		if(a[i] != b[i]) c++;
	}
	return c;
}

void sieve()
{
	for(int a=2;a<10000;a++)
	{
		if(prime[a]) continue;
		for(int b=a*a;b<10000;b+=a) prime[b] = 1;
	}
	for(int a=1000;a<10000;a++)
	{
		if(!prime[a]) primes.push_back(to_string(a));
	}
	for(int a=0;a<maxn;a++)
		for(int b=a+1;b<maxn;b++)
			if(countdiff(primes[a],primes[b]) == 1)
				V[a][b] = V[b][a] = 1;

	//n_edges = edges.size();
	//visited.resize(n_edges);
}

int mindist(int dist[], int vset[])
{
	int min_dist = INT_MAX, min_index;
	for(int v=0;v<maxn;v++)
	{
		if(vset[v] == 0 and dist[v] <= min_dist)
			min_dist = dist[v], min_index = v;
	}
	return min_index;
}

LL f(int s, int e)
{
	int dist[maxn], vset[maxn];
	for(int i=0;i<maxn;i++)
		dist[i] = INT_MAX, vset[i] = 0;
	dist[s] = 0;
	for(int count=0;count<maxn;count++)
	{
		int u = mindist(dist,vset);
		vset[u] = 1;
		for(int v=0;v<maxn;v++)
			if(!vset[v] and V[u][v] and dist[u] != INT_MAX and dist[u]+V[u][v] < dist[v])
				dist[v] = dist[u] + V[u][v];
	}
	return dist[e];
}

int main()
{
	sieve();
	int t;
	cin >> t;
	while(t--)
	{
		for(int &a : visited) a=0;
		string x,y;
		cin >> x >> y;
		int p=-1,q=-1;
		for(int a=0;a<maxn;a++)
		{
			if(p == -1 and strcmp(x.c_str(),primes[a].c_str()) == 0) p = a;
			if(q == -1 and strcmp(y.c_str(),primes[a].c_str()) == 0) q = a;
			if(p != -1 and q != -1) break;
		}
		if(p > q) swap(p,q);
		LL r = f(p,q);
		if(r >= INT_MAX) cout << "Impossible\n";
		else cout << r << endl;
	}
}

