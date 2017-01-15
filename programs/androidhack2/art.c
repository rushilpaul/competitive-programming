//Program question at: http://www.codechef.com/ADR2012/problems/A105
#include <stdio.h>
int main()
{
	int a,t; scanf("%d\n",&t);
	char s[11], tmp[11];
	while(t--)
	{
		gets(s);
		int len = strlen(s);
		for(a=0;a<len;a++)
		{
			strncpy(tmp,s,a+1);
			tmp[a+1] = 0;
			printf("%s\n",tmp);
		}
		for(a=0;a<len-1;a++)
		{
			strncpy(tmp,s+a+1,len);
			tmp[len-a-1] = 0;
			printf("%s\n",tmp);
		}
		printf("\n");
	}
	return 0;
}
