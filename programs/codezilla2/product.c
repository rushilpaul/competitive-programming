// Program question at: http://www.codechef.com/COZL2012/problems/RBX12R03
#include <stdio.h>
#include <stdbool.h>

inline void swap(int *a, int *b)
{
	if (*a == *b) return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int num; scanf("%d",&num);
		int c1,n1,c2,n2; scanf("%d %d %d %d", &c1, &n1, &c2, &n2);
		bool sw=0;
		if (c1 < c2) { swap(&c1,&c2); swap(&n1,&n2); sw = 1; }
		int i=0, t;
		for(;(t = num - n1*i) >= 0; i++)
			if( t % n2 == 0)
			{
				if(!sw) { printf("%d %d %d\n", i, t/n2, i*c1 + t*c2/n2); break; }
				else { printf("%d %d %d\n", t/n2, i, i*c1 + t*c2/n2); break; }
			}
		if(t < 0) printf("%s\n","0 0 0");
	}
	return 0;
}
