#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m,k; scanf("%d %d %d",&n,&m,&k);
		for(int a=0;a<n;a++,printf("\n")) for(int b=0;b<m;b++) printf("A");
	}
	return 0;
}