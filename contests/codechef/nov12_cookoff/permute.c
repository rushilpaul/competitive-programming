//Program question at: http://www.codechef.com/COOK28/problems/LEPERMUT
#include <stdio.h>

int main()	
{
	int t,a,b,n; scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ar[n];
		for(a=0;a<n;a++) scanf("%d",&ar[a]);
		if(n==1) { printf("YES\n"); continue; }		
		int n1=0,n2=0;
		for(a=0;a<n-1;a++)
		{
			if(ar[a] > ar[a+1]) n2++;
			for(b=a+1;b<n;b++) if(ar[a] > ar[b]) n1++;
		}
		if(n1==n2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
