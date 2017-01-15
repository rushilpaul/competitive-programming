#include <iostream>
using namespace std;

bool **done;
char **ar;
int r,c,blue,converted;

inline bool four(int a, int b, bool f)
{
	if(!f) done[a][b] = done[a][b+1] = done[a+1][b] = done[a+1][b+1] = 0;
	else if(a+1 < r && b+1 < c)
	{
		if(ar[a][b]=='#' && ar[a][b+1]=='#' && ar[a+1][b]=='#' && ar[a+1][b+1]=='#' && !done[a][b] && !done[a][b+1] && !done[a+1][b] && !done[a+1][b+1]) {
			done[a][b] = done[a][b+1] = done[a+1][b] = done[a+1][b+1] = 1; return 1; }
	}
	return 0;
}
inline bool one(int a, int b, int f)
{
	if(!f) done[a][b] = done[a][b-1] = done[a-1][b] = done[a-1][b-1] = 0;
	else if(a-1 >= 0 && b-1 >= 0)
	{
		if(ar[a][b]=='#' && ar[a][b-1]=='#' && ar[a-1][b]=='#' && ar[a-1][b-1]=='#' && !done[a][b] && !done[a][b-1] && !done[a-1][b] && !done[a-1][b-1]) {
			done[a][b] = done[a][b-1] = done[a-1][b] = done[a-1][b-1] = f; return 1; }
	}
	return 0;
}
inline bool two(int a, int b, int f)
{
	if(!f) done[a][b] = done[a][b+1] = done[a-1][b] = done[a-1][b+1] = 0;
	else if(a-1 >= 0 && b+1 < c)
	{
		if(ar[a][b]=='#' && ar[a][b+1]=='#' && ar[a-1][b]=='#' && ar[a-1][b+1]=='#' && !done[a][b] && !done[a][b+1] && !done[a-1][b] && !done[a-1][b+1]) {
			done[a][b] = done[a][b+1] = done[a-1][b] = done[a-1][b+1] = f; return 1; }
	}
	return 0;
}
inline bool three(int a, int b, int f)
{
	if(!f) done[a][b] = done[a][b-1] = done[a+1][b] = done[a+1][b-1] = 0;
	else if(a+1 < r && b-1 >= 0)
	{
		if(ar[a][b]=='#' && ar[a][b-1]=='#' && ar[a+1][b]=='#' && ar[a+1][b-1]=='#' && !done[a][b] && !done[a][b-1] && !done[a+1][b] && !done[a+1][b-1]) {
			done[a][b] = done[a+1][b] = done[a][b-1] = done[a+1][b-1] = f; return 1; }
	}
	return 0;
}

bool solve(int i)
{
	if(converted == blue) return 1;
	for(int a=i;a<r;a++)
	for(int b=0;b<c;b++)
	{
		if(done[a][b]) continue;
		if(ar[a][b] == '#')
		{
			if(one(a,b,1))
			{
				converted+=4;				
				if(converted == blue || solve(i)) return 1;
				one(a,b,0);
			}
			if(two(a,b,1))
			{
				converted+=4;
				if(converted == blue || solve(i)) return 1;
				two(a,b,0);
			}
			if(three(a,b,1))
			{
				converted+=4;
				if(converted == blue || solve(i)) return 1;
				three(a,b,0);
			}
			if(four(a,b,1))
			{
				converted+=4;
				if(converted == blue || solve(i)) return 1;
				four(a,b,0);
			}
		}
	}
	return 0;
}

int main()
{
	int tt; cin >> tt;
	for(int t=1;t<=tt;t++)
	{
		cin >> r >> c;
		ar = new char*[r];
		done = new bool*[r];
		blue = converted = 0;
		for(int a=0;a<r;a++)
		{
			ar[a] = new char[c];
			done[a] = new bool[c];
			for(int b=0;b<c;b++)
			{
				done[a][b] = 0;
				cin >> ar[a][b];
				if(ar[a][b] == '#') blue++;
			}
		}
		cout << "Case #" << t << ":" << endl;
		if(solve(0))
		{
			for(int a=0;a<r;a++)
			for(int b=0;b<c;b++)
				if(ar[a][b] == '/' || ar[a][b] == '\\') continue;
				else if(ar[a][b] == '#')
				{
					ar[a][b] = ar[a+1][b+1] = '/';
					ar[a+1][b] = ar[a][b+1] = '\\';
				}
			for(int a=0;a<r;a++,cout << endl)
			for(int b=0;b<c;b++) cout << ar[a][b];
		}
		else cout << "Impossible" << endl;
		
	}
	return 0;
}
