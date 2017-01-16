#include <stdio.h>
#include <math.h>

int main()
{
	int tc,t; scanf("%d\n",&tc);
	int ar[] = { 1,4,9,121,484 };
	for(t=1;t<=tc;t++)
	{
		int i,a,b,c=0; scanf("%d %d",&a,&b);
		for(i=0;i<5;i++) if(ar[i] >= a && ar[i] <= b) c++;
		printf("Case #%d: %d\n",t,c);
	}
}
