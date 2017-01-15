#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	if(a<b) swap(a,b);
	if(a >= 2*b)
	{
		printf("%d\n",b);
		return 0;
	}
	
	int k = ceil( (2*b-a)/3.0);
	if(k < 0) k = 0;
	int ans = k;
	a -= k; b-= 2*k;
	ans += b;	
	printf("%d\n",ans);
	return 0;
}

