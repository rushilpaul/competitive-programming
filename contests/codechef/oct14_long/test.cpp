#include <cmath>
#include <set>
#include <climits>
#include <algorithm>
#include <string>
#include <cstdio>
#define PII pair<int,int>
#define mp make_pair
using namespace std;

int main()
{
	int n; scanf("%d",&n);
	PII p[n];
	set< PII > set_p;
	for(int a=0;a<2000;a++)
	{
		int i,j; scanf("%d %d",&i,&j);
		p[a] = mp(i,j);
		set_p.insert(p[a]);
	}
	double min = INT_MAX;
	for(int a=0;a<2000;a++) 
	for(int b=a+1;b<2000;b++)
	{
		//int d = sqrt( (p[a].x-p[b].x)*(p[a].x-p[b].x) + (p[a].y-p[b].y)*(p[a].y-p[b].y) );
		//if(d < min) min = d;
		for(int c=0;c<6;c++)
		{
			PII p1 = mp(p[a].first,p[b].second);
			if(set_p.find(p1) == set_p.end())
			{
				
			}
		}
	}
	printf("%f\n",min);
	return 0;
}
