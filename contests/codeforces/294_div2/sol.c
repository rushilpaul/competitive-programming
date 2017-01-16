#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int ans=0;

	while( (a >= 1 and b >= 2) or (a >= 2 and b >= 1) )
	{
		if(a >= 1 and b >= 2 and b>=a)
		{
			a -= 1;
			b -= 2;
			ans++;
		}
		else if(a >= 2 and b >= 1)
		{
			a -= 2;
			b -= 1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

