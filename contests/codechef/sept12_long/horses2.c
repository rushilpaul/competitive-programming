//Program question at: http://www.codechef.com/SEP12/problems/HORSES
#include <stdio.h>
#include <stdlib.h>
char s[60000];
int compare(int *a, int *b)
{
	return *a - *b;
}
int main()
{
	int t; gets(s); t = atoi(s);
	while(t--)
	{
		int tmp=0,n=0,a,min=1000000000;
		gets(s);
		int ar[atoi(s)],len;
		gets(s); len = strlen(s);
		s[len] = 32; s[len+1] = 0;
		for(a=0;a<len+2;a++)
		{
			if(s[a] == 32)
			{
				ar[n++] = tmp;
				tmp = 0;
				continue;
			}
			tmp = tmp*10 + (s[a]-48);
		}
		qsort(ar,n,sizeof(int),compare);
		for(a=0;a<n-1;a++)
		{
			tmp = ar[a+1] - ar[a];
			if(tmp < min) min = tmp;
			if(!min) break;
		}
		printf("%d\n",min);
	}
	return 0;
}
