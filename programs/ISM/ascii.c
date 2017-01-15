#include <stdio.h>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		char s[1024];
		scanf("%s",&s);
		int a;
		for(a=0;s[a];a++)
		{
			if( s[a] == '3') { printf(" "); a++; continue; }
			if( s[a] == '9')
			{
				if(s[a+1] == '0') { printf("Z"); a++; continue; }
				switch (s[a+1])
				{
					case '7': printf("a"); break;
					case '8': printf("b"); break;
					case '9': printf("c"); break;
				}
				a++; continue;
			}
			if( s[a] >= '6' && s[a] <= '8')
			{
				int ch = (s[a]-48)*10 + s[a+1]-48;
				printf("%c",ch); a++;
			}
			else if( s[a] == '1')
			{
				int ch = 100 + (s[a+1]-48)*10 + s[a+2]-48;
				printf("%c",ch); a+=2;
			}
		}
		printf("\n");
	}
	return 0;
}
