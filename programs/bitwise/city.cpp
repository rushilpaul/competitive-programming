#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

#define mapi map<int,int>
mapi cache;
int **path, *timex;
int C,P,E,H;
bool *done, *cache2;

int find(int st)
{
	if(st == 1) return 0;
	if(cache2[st-1]) return cache[st];
	int t=0,min=500*C; bool check=0;
	for(int a=0;a<C;a++)
	{
		if(done[a]) continue;
		if(path[a][0] == st || path[a][1] == st)
		{
			check = 1;
			int sec = path[a][0] == st ? path[a][1] : path[a][0];
			done[a] = 1;
			int r = find(sec);
			done[a] = 0;
			t += timex[a] + r;
			min = t < min ? t : min;
		}
	}
	if(check) { cache2[st-1] = 1; cache[st] = min; return min; }
	else return 0;
}


int main()
{
	scanf("%d %d %d", &C, &P, &E);
	path = new int*[C];
	timex = new int[C];
	done = new bool[C];
	cache2 = new bool[C];
	memset(cache2, 0, C*sizeof(bool));
	for(int a=0;a<P;a++) { path[a] = new int[2]; scanf("%d %d %d", &path[a][0], &path[a][1], &timex[a]); }
	scanf("%d",&H);
	int w[H][2];
	for(int a=0;a<H;a++) scanf("%d %d", &w[a][0], &w[a][1]);
	int totalt=0;
	for(int a=0;a<H;a++)
		totalt += find(w[a][0]) * w[a][1];
	printf("%d\n",totalt);
	return 0;
}
