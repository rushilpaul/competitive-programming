#include <cstdio>
using namespace std;

int main()
{
	int hour,min,sec; scanf("%d",&sec);
	min = sec/60;
	sec = sec%60;
	hour = min/60;
	min = min%60;
	printf("Time is %d:%d:%d\n",hour,min,sec);
	return 0;
}
