#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t; cin >> t;
	while(t--)
	{
		double a,b,c,ans; cin >> a >> b >> c;
		ans = c - a - b;
		if(ans < 0) printf("0\n");
		else printf("%f\n",ans);
	}
	return 0;
}
