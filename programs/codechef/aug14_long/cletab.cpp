#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d",&n,&m);
		int ar[401],tmp;
		memset(ar,0,sizeof(int)*401);
		for(int a=0;a<m;a++)
		{
			scanf("%d",&tmp);
			ar[tmp]++;
		}
		int ans=0;
		for(int a=1;a<=400;a++) if(ar[a]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
