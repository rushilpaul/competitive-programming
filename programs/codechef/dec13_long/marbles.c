#include <stdio.h>
typedef long long LL;

int main()
{
	int a,n,q; scanf("%d %d",&n,&q);
	int ar[n];
	LL sum[n];
	for(a=0;a<n;a++)
	{
		scanf("%d",&ar[a]);
		if(!a) sum[a] = ar[a];
		else sum[a] = sum[a-1] + ar[a];
	}
	char ch;
	LL i,j;
	for(a=0;a<q;a++)
	{
		scanf("\n%c",&ch);
		scanf("%lld %lld",&i,&j);
		if(ch == 'S')
		{
			if(i) i = sum[i-1];
			if(j) j = sum[j];
			printf("%lld\n",j-i);
		}
		//else if(ch == 'G')		
	}
	
}
