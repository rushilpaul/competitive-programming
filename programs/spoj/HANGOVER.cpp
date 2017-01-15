#include <cstdio>

int main()
{
	while(1)
	{
		double s=0;
		int i=0;
		double c; scanf("%lf",&c);
		if(c == 0) break;
		while(s <= c)
		{
			s += 1.0/(i+2);
			i++;
		}
		printf("%d card(s)\n",i);
	}
	return 0;
}

