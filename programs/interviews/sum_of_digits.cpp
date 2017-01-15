// http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char s[101];

int pow2(int n)
{
	int p=1;
	for(int a=1;a<=n;a++)
		p *= 10;
	return p;
}

int g(int n) { return 45*n*pow2(n-1); }

int f(int i)
{
	if(i == n-1)
		return s[i]*(s[i]+1)/2;
	int x=0;
	for(int a=i+1;a<n;a++)
		x = x*10 + s[a];
	x++;
	return s[i]*(s[i]-1)/2 * pow2(n-1-i) + s[i] * g(n-1-i) + s[i]*x + f(i+1);
}

int main()
{
	scanf("%s",s);
	n = strlen(s);
	for(int a=0;a<n;a++)
		s[a] -= '0';
	printf("%d\n",f(0));
}
