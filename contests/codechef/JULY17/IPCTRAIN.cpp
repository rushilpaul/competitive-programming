#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

inline int readint()
{
	int x; scanf("%d",&x); return x;
}

int S[100001], duration[100001], D[100001];

int main()
{
	int t = readint();
	while(t--)
	{
		map<int, vector<int> > m;
		vector< pair<int,int> > people;
		int n = readint(), days = readint();
		for(int a=0;a<n;a++)
		{
			int start = readint(), dur = readint(), s = readint();
			D[a] = start;
			S[a] = s;
			duration[a] = dur;
			people.push_back({start, a});
		}
		sort(people.begin(), people.end(), greater< pair<int,int> >());

		for(int a=1;a<=days;a++)
		{
			while(people.size() > 0 and D[people.back().second] == a)		// on-board people who start on this day
			{
				m[ S[people.back().second] ].push_back( duration[people.back().second] );
				people.pop_back();
			}
			if(m.size() == 0)
				continue;
			auto &saddest = m.rbegin()->second;
			saddest.back()--;
			if(saddest.back() == 0)
				saddest.pop_back();
			if(saddest.size() == 0)
				m.erase(next(m.rbegin()).base());
		}
		LL ans = 0;
		for(auto it : m)
		{
			auto devdas = it.second;
			for(int remaining : devdas)
				ans += (1ll * it.first * remaining);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
