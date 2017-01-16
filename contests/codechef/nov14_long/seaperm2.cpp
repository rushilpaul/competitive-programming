#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define max_buf_size 1024

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		setvbuf(stdout,NULL,_IONBF,max_buf_size);
		setvbuf(stdin,NULL,_IONBF,max_buf_size);
	}
} _init_ob_unused;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		int ar[n][n-1];
		for(int a=0;a<n;a++)
		for(int b=0;b<n-1;b++)
			scanf("%d",&ar[a][b]);

				
	}
	return 0;
}
