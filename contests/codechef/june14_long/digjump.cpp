#include <fastio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	char s[100001];
	readline(s,100000);
	int n = strlen(s);
	vector<int> digs[10];
	int ans[n], done[10];
	memset(done,0,sizeof(int)*10);
	for(int a=0;a<n;a++)
	{
		ans[a] = n-1-a;
		digs[s[a]-48].push_back(a);
	}
	queue<int> q;
	q.push(n-1);
	while(!q.empty())
	{
		int pos = q.front(), ele = s[pos]-48, size = digs[ele].size();
		if(!done[ele])
		{
			for(int a=0;a<size;a++)
			{
				int i = digs[ele][a];
				if(i == pos) continue;
				q.push(i);
				ans[i] = min(ans[i], ans[pos]+1);
			}
			done[ele] = 1;
		}
		if(pos-1 >= 0)
		{
			ans[pos-1] = min(ans[pos-1], ans[pos]+1);
			if(!done[ s[pos-1]-48 ]) q.push(pos-1);
		}
		if(pos+1 < n)
		{
			ans[pos+1] = min(ans[pos+1], ans[pos]+1);
			if(!done[ s[pos+1]-48 ]) q.push(pos+1);
		}
		q.pop();
	}
	printf("%d\n",ans[0]);
	return 0;
}
