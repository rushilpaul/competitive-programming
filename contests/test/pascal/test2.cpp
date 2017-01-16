#include <cstdio>

int& getint()
{
	int i=10;
	return i;
}

int main()
{
	int i = getint();
	printf("%d\n",i);
	return 0;
}
