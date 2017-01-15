//Program question at: http://www.codechef.com/problems/DCE05
#include <stdio.h>

int ar[] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912 };

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int n,ans=0; scanf("%d",&n);
		while(n>=ar[ans] && ans<=29) ans++;
		printf("%d\n",ar[ans-1]);
	}
	return 0;
}
