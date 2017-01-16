#include <cstdio>
#include <cmath>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int b,ls; scanf("%d %d",&b,&ls);
		printf("%f %f\n",sqrt(ls*ls - b*b),sqrt(ls*ls + b*b));
	}
	return 0;
	
}