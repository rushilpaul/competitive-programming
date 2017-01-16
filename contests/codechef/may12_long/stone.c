//Program question at: http://www.codechef.com/MAY12/problems/STONES
#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		char s[101], j[101];
		scanf("%s\n%s",&j,&s);
		int s_len = strlen(s);
		int j_len = strlen(j),a,b,ans=0;
		for(a=0;a<s_len;a++)
		for(b=0;b<j_len;b++)
			if(s[a] == j[b])
			{
				ans++;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}
