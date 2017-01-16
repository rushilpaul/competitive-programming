#include <cstdio>
using namespace std;

int main()
{
	int t; scanf("%d\n",&t);
	int ar[3][3] = {0};
	while(t--)
	{
		for(int a=0;a<3;a++) for(int b=0;b<3;b++) scanf("%d",&ar[a][b]);
	}
	return 0;
}
