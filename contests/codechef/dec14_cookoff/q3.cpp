#include <cstdio>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	double ar[3001];
	ar[1] = 1;
	for(int a=2;a<=3000;a++)
		ar[a] = ar[a-1] * a / (a-1) + 1;
	while(t--)
	{
		int n; scanf("%d",&n);
		printf("%.2f\n",ar[n]);
	}
	return 0;
}
