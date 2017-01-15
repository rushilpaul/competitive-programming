#include <cmath>
#include <cstdio>
#include <climits>
typedef long long LL;
using namespace std;


int main()
{
	double m,t;
	double i;
	scanf("%lf %lf %lf",&m,&t,&i);
	i /= 1200.0;
	if(i == 0)
	{
		printf("%lld",(LL)(m*t));
		return 0;
	}
	printf("%lld\n",(LL)(m * (pow(1+i,t) - 1 ) / (i*pow(1+i,t)) ));
}

