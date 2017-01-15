#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		char s[51];
		scanf("%s",&s);
		int m,l,i;
		l = strlen(s); m = l>>1;
		for(i=m-1;i>=0;i--) printf("%c",s[i]);
		for(i=l-1;i>=m;i--) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
