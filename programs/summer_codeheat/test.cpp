#include <cstdio>

int main()
{
	int n; scanf("%d",&n);
	printf("%d\n",n);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",ar+a);
	for(int a=0;a<n;a++)
		printf("%d ",ar[a]);
}
