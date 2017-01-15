#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long LL;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,d; scanf("%d",&n);
		LL ans = 0;
		vector< pair<int,int> > pos, neg;
		for(int a=0;a<n;a++)
		{
			scanf("%d",&d);
			if(d > 0)
				pos.pb(mp(a,d));
			else
				neg.pb(mp(a,-d));
		}
		n = pos.size();
		int i=0,j=0;
		while(i < n)
		{
			while(pos[i].second)
			{
				int k = min(pos[i].second,neg[j].second);
				ans += (k * abs(pos[i].first - neg[j].first));
				pos[i].second -= k;
				neg[j].second -= k;
				if(neg[j].second == 0) j++;
			}
			i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
