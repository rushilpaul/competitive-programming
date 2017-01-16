#include <stdio.h>
typedef long long LL;
inline LL abs(LL x) { return x>0?x:-x; }

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,a; scanf("%d",&n);
		int ar[n][2];
		for(a=0;a<n;a++) scanf("%d %d",&ar[a][0],&ar[a][1]);
		LL ans = 0;
		for(a=0;a<n-1;a++)
			ans += abs(ar[a][0]-ar[a+1][0]) + abs(ar[a][1]-ar[a+1][1]);
		printf("%lld\n",ans);
		int i,d,l;
		for(a=0;a<n-1;a++)
		{
			while( !((ar[a][0] == ar[a+1][0]) && (ar[a][1] == ar[a+1][1]) ))
			{
				if(ar[a][0] < ar[a+1][0])
					for(i=ar[a][0];i<ar[a+1][0] && i+1!=ar[a][1];i++) { printf("L+"); ar[a][0]++; }
				else if(ar[a][0] > ar[a+1][0])
					for(i=ar[a][0];i>ar[a+1][0] && i-1!=ar[a][1];i--) { printf("L-"); ar[a][0]--; }

				if(ar[a][1] < ar[a+1][1])
					for(i=ar[a][1];i<ar[a+1][1] && i+1!=ar[a][0];i++) { printf("R+"); ar[a][1]++; break; }
				else if(ar[a][1] > ar[a+1][1])
					for(i=ar[a][1];i>ar[a+1][1] && i-1!=ar[a][0];i--) { printf("R-"); ar[a][1]--; break; }
				//getch();
			}
		}
		printf("\n");
	}
}
