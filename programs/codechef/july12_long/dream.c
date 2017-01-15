//Program question at: http://www.codechef.com/JULY12/problems/DREAM
#include <stdio.h>
int main()
{
	int a,b,n,k; scanf("%d %d\n",&n,&k);
	int num[n], ans=0;;
	for(a=0;a<n;a++) scanf("%d",&num[a]);
	for(a=0;a<n;a++) if(num[a] >= 0)
	{
		ans++;
		int x=num[a];;
		for(b=a;b<a+k && b<n;b++) if(x == num[b]) num[b] = -1;
	}
	printf("%d\n",ans);
	return 0;
}
