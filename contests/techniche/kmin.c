//Program question at: http://www.codechef.com/BTCD2012/problems/KMIN
#include <stdio.h>
#include <string.h>
#define size 100000
int main()
{
	int a,n,k; scanf("%d\n%d",&n,&k);
	int ar[size],min=99999,max=0,d=0;
	memset(ar,0,size*4);
	while(n--)
	{
		int num; scanf("%d",&num); num--;
		if(num == -2)
		{
			for(a=min;a<=max && d<k;a++) d+=ar[a];
			printf("%d\n",a);
			d=0;
		}
		else
		{
			ar[num]++;
			if(num < min) min = num;
			if(num > max) max = num;
		}
	}
	return 0;
}
