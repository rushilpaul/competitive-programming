#include <stdio.h>

int main()
{
	long long n; scanf("%lld",&n);
	n %= 6;
	printf("%s\n",n==0 || n == 1 || n == 3 ? "yes":"no");
	return 0;
}
