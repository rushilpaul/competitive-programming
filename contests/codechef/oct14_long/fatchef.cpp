#include <cstdio>
#include <vector>
using namespace std;
#define mod 1000000009

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d",&n,&m);
		int buck[m][2];
		for(int a=0;a<m;a++)
		{
			scanf("%d %d",&buck[a][0],&buck[a][1]);
			buck[a][0] -= 65;
			buck[a][1]--;
		}
		
		
	}
	return 0;
}
