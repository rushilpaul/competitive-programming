#include <cstdio>
#include <algorithm>

int main()
{
	int a,b; scanf("%d %d",&a,&b);
	if(a < b)
	{
		printf("-1\n");
		return 0;
	}
	int k = (a+b)/(2*b);
	double x = (a+b)/(2.0*k);
	k = (a-b)/(2.0*b);
	if(k)
		x = std::min(x, (a-b)/(2.0*k));
	printf("%.12lf\n",x);
	return 0;
}
