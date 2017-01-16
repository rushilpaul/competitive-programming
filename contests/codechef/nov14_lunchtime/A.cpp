#include <bits/stdc++.h>
using namespace std;

#define max_buf_size 1024
 
 struct _init_
 {
	 _init_()
	 {
		 ios_base::sync_with_stdio(0); cin.tie(0);
		 setvbuf(stdout,NULL,_IOFBF,max_buf_size);
		 setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	 }
 } _init_ob_unused;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d %d",&n,&m);
		int ar[n+1][n+1];
		for(int a=1;a<=n;a++) for(int b=1;b<=n;b++) ar[a][b] = 0;
		for(int a=0;a<m;a++)
		{
			int i,j; scanf("%d %d",&i,&j);
			ar[i][j] = ar[j][i] = 1;
		}
		int flag = 1;
		for(int a=1;a<=n;a++)
		{
			int count=0;
			for(int b=1;b<=n;b++)
				if(ar[a][b]) count++;
			if(count >= 3) { flag = 0; break; }
		}
		if(flag)
		{
			int c=0;
			for(int i=1;i<=n;i++)
			{
				int count=0;
				for(int a=1;a<=n;a++)
				{
					if(a == i) continue;
					for(int b=1;b<=n;b++)
					{
						if(b == i) continue;
						if(ar[a][b]) count++;
					}
				}
				if(!count) { c=1; break; }
			}
			if(!c) flag = 0;
		}
		printf("%s\n",flag ? "YES" : "NO");
	}
}

