//Program question at: http://www.codechef.com/COOK23/problems/TWTCLOSE
#include <stdio.h>
#include <string.h>
char s[11];
int ten[4] = {1,10,100,1000};
int main()
{
	int a,n,k,open=0; scanf("%d %d\n",&n,&k);
	int tweet[n]; memset(tweet,0,n*4);
	while(k--)
	{
		gets(s);
		int len = strlen(s);
		if(s[5] == 'A') { open=0; memset(tweet,0,n*4); }
		else
		{
			int q=0;
			for(a=len-1;s[a] != 32;a--)
				q += (s[a]-48)*ten[len-1-a];
			if(tweet[q-1]) { open--; tweet[q-1] = 0; }
			else { open++; tweet[q-1] = 1; }
		}
		printf("%d\n",open);
	}
	return 0;
}
