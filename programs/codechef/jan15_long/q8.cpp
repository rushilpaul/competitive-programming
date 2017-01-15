#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

vector<int> ar;

int main()
{
	int m; scanf("%d",&m);
	while(m--)
	{
		int q; scanf("%d",&q);
		if(q == 0)
		{
			int x; scanf("%d",&x);
			ar.push_back(x);
		}
		else if(q == 1)
		{
			int L,R,x; scanf("%d %d %d",&L,&R,&x); L--; R--;
			int y = ar[L], ans = x xor y;
			for(int a=L+1;a<=R;a++) if((x xor ar[a]) > ans) { y = ar[a]; ans = x xor y; }
			printf("%d\n",y);
		}
		else if(q == 2)
		{
			int k; scanf("%d",&k);
			for(int a=0;a<k;a++) ar.pop_back();
		}
		else if(q == 3)
		{
			int ans=0,L,R,x; scanf("%d %d %d",&L,&R,&x); L--; R--;
			for(int a=L;a<=R;a++) if(ar[a] <= x) ans++;
			printf("%d\n",ans);
		}
		else if(q == 4)
		{
			int L,R,k; scanf("%d %d %d",&L,&R,&k); L--; R--; k--;
			int ar2[R-L+1];
			for(int a=L;a<=R;a++) ar2[a-L] = ar[a];
			sort(ar2,ar2+R-L+1);
			printf("%d\n",ar2[k]);
		}
	}
	return 0;
}
