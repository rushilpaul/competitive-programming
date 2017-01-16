#include <cstdio>
typedef long long LL;

int main()
{
	while(1)
	{
		LL x,y,z;
		scanf("%lld %lld %lld\n",&x,&y,&z);
		if(!x and !y and !z) break;
		if(y-x == z-y)
			printf("AP %lld\n",z+y-x);
		else
			printf("GP %lld\n",z*y/x);
	}
	return 0;
}
