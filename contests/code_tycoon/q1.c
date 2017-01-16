#include <stdio.h>
int main()
{
	char ch;
	while(1)
	{
		ch = getchar();
		if(ch == 0 || ch == 13) break;
		printf("%c,",ch);
	}
}
