//Program question at: http://www.codechef.com/problems/DCE05
#include <stdio.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int n,ans=1; scanf("%d",&n);
		while(ans<n) ans <<= 1;
		printf("%d\n",ans>>1);
	}
	return 0;
}
