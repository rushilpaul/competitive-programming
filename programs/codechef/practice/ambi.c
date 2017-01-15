//Program question at: http://www.codechef.com/problems/PERMUT2
#include <stdio.h>
int main()
{
	while(1)
	{
		int n,a; scanf("%d",&n);
		if(n==0) break;
		int ar[n];
		for(a=0;a<n;a++) { scanf("%d",&ar[a]); ar[a]--; }
		for(a=0;a<n;a++)
			if(ar[ar[a]] != a) break;
		if(a == n) printf("ambiguous\n");
		else printf("not ambiguous\n");
	}
	return 0;
}
