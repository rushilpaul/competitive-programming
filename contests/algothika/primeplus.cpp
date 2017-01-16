#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define max 1000000
typedef long long LL;

int main()
{
	int t,u; scanf("%d\n",&t);
	bool P[max];
	LL s[max];
	for(int a=2;a<=1000;a++)
		for(int b=a*a;b<max;b+=a) P[b]=1;
	memset(s,0,sizeof(LL)*max);
	s[2] = 2;
	LL *r = &s[3];
	for(int a=3;a<max;a++,r++)
	{
		*r = *(r-1);
		if(!P[a]) *r += a;
	}
	while(t--)
	{
		scanf("%d",&u);
		if(u <= 2) { printf("%d\n",0); continue; }
		printf("%lld\n",s[u]);
	}
	return 0;
}
