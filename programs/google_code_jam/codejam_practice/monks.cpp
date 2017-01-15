#include <iostream>
#include <cstring>
using namespace std;

int **m, n;
bool *done;

int find(int i)
{
	int s=1;
	for(int a=0;a<n;a++)
	{
		if(m[a][0] == i)
		{
			if(done[m[a][1]-1]) continue;
			done[m[a][0]-1] = 1;
			s += find(m[a][1]);
		}
	}
	return s;
}

int main()
{
	int t; cin >> t;
	for(int tt=1;tt<=t;tt++)
	{
		cin >> n;
		m = new int*[n];
		for(int a=0;a<n;a++)
		{
			m[a] = new int[2];
			int na; cin >> na;
			m[a][0] = na;
			m[a][1] = a+1;
		}
		done = new bool[n];
		cout << "Case #" << tt << ":" << endl;
		for(int a=1;a<=n;a++)
		{
			memset(done,0,n);
			cout << find(a) << endl;
		}
	}
	return 0;
}
