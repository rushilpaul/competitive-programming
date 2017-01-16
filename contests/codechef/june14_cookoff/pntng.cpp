#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;

int main()
{
	LL n,m,h; scanf("%lld %lld %lld",&n,&m,&h);
	LL s=0,tiles = n*m;
	vector< pair<LL,LL> > layers;
	for(int a=0;a<h;a++)
	{
		LL t,c;
		scanf("%lld %lld",&t,&c);
		layers.push_back(make_pair(c,t));
		s += t;
	}
	if(tiles > s) { printf("Impossible\n"); return 0; }
	sort(layers.begin(),layers.end());
	LL cost=0;
	for(int a=0;a<h;a++)
	{
		LL used = layers[a].second;
		if(tiles < layers[a].second) used = tiles;
		cost += layers[a].first * used;
		tiles -= used;
		if(tiles <= 0) break;
	}
	printf("%lld\n",cost);
	return 0;
}
