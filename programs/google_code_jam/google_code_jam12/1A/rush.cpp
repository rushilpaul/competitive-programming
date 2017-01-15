#include <iostream>
using namespace std;

int **star;
bool **done;
long long cur,ans,n;

void solve(int count, int total)
{
	int step=0;
	if(count == n)
	{
		if(total < ans) ans = total;
		return;
	}
	// 2nd level
	for(int a=0;a<n;a++)
	{
		if(done[a][1]) continue;
		if(star[a][1] <= cur)
		{
			if(done[a][0]) step=1; else step=2;
			cur += step;
			done[a][1] = 1;
			solve(count+1,total+1);
			done[a][1] = 0;
			cur -= step;
		}
	}
	// 1st level
	for(int a=0;a<n;a++)
	{
		if(done[a][0] || done[a][1]) continue;
		if(star[a][0] <= cur)
		{
			cur++;
			done[a][0] = 1;
			solve(count,total+1);
			done[a][0] = 0;
			cur--;
		}
	}
}

int main()
{
	int tt; cin >> tt;
	for(int t=1;t<=tt;t++)
	{
		cin >> n;
		star = new int*[n];
		done = new bool*[n];
		ans = 10000000000; cur=0;
		for(int a=0;a<n;a++)
		{
			star[a] = new int[2];
			done[a] = new bool[2];
			done[a][0] = done[a][1] = 0;
			cin >> star[a][0] >> star[a][1];
		}
		solve(0,0);
		cout << "Case #" << t << ": ";
		if(ans == 10000000000) cout << "Too Bad" << endl;
		else cout << ans << endl;
	}
	return 0;
}
