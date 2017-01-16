// Given a number, reverse the binary equivalent of that number and print the corresponding decimal number
#include <cstdio>

int main()
{
	int a,b=0;
	scanf("%d",&a);
	while(a)
	{
		b = b<<1 | (a&1);
		a >>= 1;
	}
	printf("%d\n",b);
}
