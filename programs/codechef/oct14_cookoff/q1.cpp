#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
typedef long long LL;
using namespace std;

void read(int &n) { scanf("%d",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }

int main()
{
	int t;
	read(t);
	while(t--)
	{
		LL n; read(n);
		printf("%lld\n",(n+1)*(n+2)/2-1);
	}
	return 0;
}
