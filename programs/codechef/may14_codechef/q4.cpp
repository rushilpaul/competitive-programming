//Problem statement: http://www.codechef.com/MAY14/problems/CHEFBM
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define pi pair<int,int>
using namespace std;

int main()
{
	vector< pi > ar;
	map< pi,int > f;
	int n,m,p; scanf("%d %d %d",&n,&m,&p);
	for(int a=0;a<p;a++)
	{
		int r,c; scanf("%d %d",&r,&c);
		ar.push_back(make_pair(r,c));
	}
	if(m == 1)
	{
		for(int row=1;row<=n;row++) printf("0\n");
		return 0;
	}
	sort(ar.begin(),ar.end());
	ar.push_back(make_pair(n+1,0));
	p++;
	for(int a=0;a<p;a++)
		f[ar[a]]++;
	int ar2[f.size()][3],k=0;
	map< pi,int >::iterator it;
	for(it=f.begin();it!=f.end();it++)
	{
		ar2[k][0] = (it->first).first;
		ar2[k][1] = (it->first).second;
		ar2[k][2] = it->second;
		k++;
	}
	int ans[n+1];
	for(int a=1;a<=n;a++) ans[a] = m-1;
	for(int a=0;a<k-1;a++)
	{
		if(ans[ ar2[a][0] ] == -1) continue;
		if(ar2[a][0] != ar2[a+1][0])
		{
			if(ar2[a][1] != m && ar2[a][2] >= 2) { ans[ ar2[a][0] ] = -1; continue; }
		
			ans[ ar2[a][0] ] += f[make_pair(ar2[a][0],m)] - f[make_pair(ar2[a][0],1)];
			continue;
		}
		
		if(ar2[a][1]+1 != ar2[a+1][1] && ar2[a][2] >= 2) ans[ ar2[a][0] ] = -1;
		else if(ar2[a][1]+1 == ar2[a+1][1] && ar2[a][2]-1 > ar2[a+1][2]) ans[ ar2[a][0] ] = -1;
	}
	for(int a=1;a<=n;a++)
		printf("%d\n",ans[a]);
	return 0;
}
