#include <stdio.h>
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		printf("%d GALLONS PER WEEK WILL LAST %d WEEKS\n",n,10000/n);
	}
	return 0;
}
