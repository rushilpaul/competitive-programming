#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,k; scanf("%d %d",&n,&k);
		long long s=0;
		for(int a=0;a<n;a++) { int b; scanf("%d",&b); s += b; }
		printf("%s\n",s % 2 == 0 and k == 1 ? "odd" : "even");
	}	
	return 0;
}
