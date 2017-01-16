//Program question at: http://www.codechef.com/problems/PALIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000001];

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		int d=strlen(s),a,len = d/2;
		int *n = (int*)malloc(d*4);
		for(a=0;a<d;a++) n[d-1-a] = s[a]-48;
		a=0;
		while(a<d && n[a] == 9) a++;
		if(a==d)
		{
			printf("1"); for(a=0;a<d-1;a++) printf("0");
			printf("1\n"); continue;
		}
		if(d==1) { printf("%d\n",s[0]-47); continue; }
		for(a=0;a<len;a++)
			if(n[a] != n[d-1-a]) break;
		if(a == len)
		{
			a=0;
			while(n[a] == 9) n[a++]=0;
			n[a]++;
		}		
		
		for(a=0;a<len;a++)
		{
			if(n[a] < n[d-1-a]) n[a] = n[d-1-a];
			else if(n[a] > n[d-1-a])
			{
				n[a] = n[d-1-a];
				int b=a+1;
				while(n[b] == 9) n[b++]=0;
				n[b]++;
			}
		}
		for(a=0;a<len;a++)
			if(n[a] < n[d-1-a]) n[a] = n[d-1-a];
		for(a=0;a<d;a++)
			printf("%d",n[d-1-a]);
		printf("\n");
	}
	return 0;
}
