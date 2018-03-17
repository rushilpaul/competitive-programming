#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;

inline LL readint()
{
	LL x; scanf("%lld\n", &x); return x;
}

vector< pair<LL,LL> > additions;
multiset<LL> sets[4];	// ++, +-, -+, --

void deleteFromMSet(multiset<LL> &m, LL x)
{
	auto it = m.find(x);
	if(it != m.end())
		m.erase(it);
}

int main()
{
	int q = readint();
	LL ans = 0;
	for(int i = 1; i <= q; i++)
	{
		char ch; scanf("%c", &ch);
		//printf("c = %c\n", ch);
		if(ch == '+' or ch == '?')
		{
			LL x = readint() xor ans, y = readint() xor ans;
			if(ch == '+')
			{
				additions.push_back({x,y});
				sets[0].insert(x+y);
				sets[1].insert(x-y);
				sets[2].insert(-x+y);
				sets[3].insert(-x-y);
			}
			else
			{
				vector<LL> answers = { *sets[0].rbegin() - x - y, *sets[1].rbegin() - x + y, *sets[2].rbegin() + x - y, *sets[3].rbegin() + x + y };
				ans = *max_element(answers.begin(), answers.end());
				printf("%lld\n", ans);
			}
		}
		else
		{
			int a = readint() xor ans;
			a--;
			assert(a < additions.size());
			LL x = additions[a].first, y = additions[a].second;
			deleteFromMSet(sets[0], x+y);
			deleteFromMSet(sets[1], x-y);
			deleteFromMSet(sets[2], -x+y);
			deleteFromMSet(sets[3], -x-y);
		}
	}
	return 0;
}
