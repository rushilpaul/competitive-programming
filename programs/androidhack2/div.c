//Program question at: http://www.codechef.com/ADR2012/problems/A102
#include <stdio.h>
#include <string.h>
int main()
{
	int n,d,a,ans=1,t,pos=1; char ch;
	scanf("%d\n%d\n",&n,&d);
	int ar[n+1]; memset(ar,0,(n+1)*sizeof(int));
	for(a=1;a<n+1;a++)
	{
		scanf("%c\n",&ch);
		if(ch=='-') ar[a] = -1;
		else ar[a] = 1;
	}
	for(a=0;a<d;a++)
	{
		scanf("%d\n",&t);
		if( ans+ar[ans]*t < 1 || ans+ar[ans]*t > n) continue;
		ans = ans + ar[ans]*t;
		if(ans == 1) pos++;
	}
	printf("%d\n",pos);
	return 0;
}
