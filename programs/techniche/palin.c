//Program question at: http://www.codechef.com/BTCD2012/problems/T02
#include <stdio.h>
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int a,n,k; scanf("%d %d",&n,&k);
		if(n==1) { printf("%d\n",k-1); continue; }
		if(n != 2) k--;
		int ar[n];
		ar[0] = ar[n-1] = 1;
		for(a=1;a<n-1;a++) ar[a] = 0;
		int m = n%2 ? n/2 : n/2-1;
		for(a=m;k;k/=10) ar[a--] = k%10;
		if(a<0 && n>2) { ar[0]++; ar[n-1]++; }
		if(n%2) m--;
		for(a=n%2?m+2:m+1; a<n; a++) ar[a] = ar[m--];
		for(a=0;a<n;a++) printf("%d",ar[a]);
		printf("\n");
	}
	return 0;
}
