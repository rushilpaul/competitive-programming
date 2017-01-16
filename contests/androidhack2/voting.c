//Program question at: http://www.codechef.com/ADR2012/problems/A110
#include <stdio.h>
#include <string.h>
int main()
{
	int a,n,n1,n2,n3; scanf("%d %d %d\n",&n1,&n2,&n3);
	int ar[1000]; memset(ar,0,4000);
	for(a=0;a<n1;a++)
	{
		scanf("%d",&n);
		ar[n-1]++;
	}
	for(a=0;a<n2;a++)
	{
		scanf("%d",&n);
		ar[n-1]++;
	}
	for(a=0;a<n3;a++)
	{
		scanf("%d",&n);
		ar[n-1]++;
	}
	int ans=0;
	for(a=0;a<1000;a++)
		if(ar[a] >= 2) ans++;
	printf("%d\n",ans);
	for(a=0;a<1000;a++)
		if(ar[a] >= 2) printf("%d\n",a+1);
	return 0;
}
