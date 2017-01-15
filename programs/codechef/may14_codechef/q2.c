#include <stdio.h>
int main()
{
	int a,n,k; scanf("%d %d",&n,&k);
	long long int ar[n],max=-2000000000,min=2000000000;
	for(a=0;a<n;a++) { scanf("%lld",&ar[a]); if(max < ar[a]) max = ar[a]; if(min > ar[a]) min=ar[a]; }
	if(k!=0) for(a=0;a<n;a++) ar[a] = max-ar[a];
	max -= min;
	for(a=0;a<n;a++)
	{
		if(k%2 == 0 && k!=0) ar[a] = max-ar[a];
		printf("%lld ",ar[a]);
	}
	return 0;	
}
