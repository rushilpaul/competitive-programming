#include <cstdio>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int ans = -1;
		if(x == 1 and y == 1)
			ans = 1;
		else if(x == 0 and !y)
			ans = 0;
		else if(x % 2 == 0 and y == x-2)
			ans = x*2-2;
		else if(x % 2 == 0 and y == x)
			ans = x*2;
		else if(x % 2 and y == x-2)
			ans = 2*x-3;
		else if(x % 2 and y == x)
			ans = 2*x-1;
		if(ans == -1)
			printf("No Number\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
