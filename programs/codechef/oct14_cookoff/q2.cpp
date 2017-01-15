#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
typedef long long LL;
using namespace std;


void readint(int &n) { scanf("%d",&n); }
void readLL(LL &n) { scanf("%d",&n); }
void readdouble(double &n) { scanf("%f",&n); }

int main()
{
	int t;
	readint(t);
	while(t--)
	{
		int n,m; scanf("%d %d",&n,&m);
		int min1=1000000,max1=0;
		for(int a=0;a<m;a++)
		{
			int i; readint(i);
			min1 = min(min1,i);
			max1 = max(max1,i);		
		}
		for(int a=0;a<n;a++) printf("%d ",max(abs(a-min1),abs(a-max1)));
		printf("\n");
	}
	return 0;
}
