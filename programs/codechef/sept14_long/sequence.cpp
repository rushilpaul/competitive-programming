#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n,k; scanf("%d %d",&n,&k);
	int ar[n];
	for(int a=0;a<n;a++) scanf("%d",ar+a);
	if(n <= 100)
	{
		int bestcd=2000000000,bests=1000000000;
		for(int a=0;a<n;a++)
			for(int b=a+1;b<n;b++)
			{
				if((ar[b]-ar[a]) % (b-a)) continue;
				int cd = (ar[b]-ar[a])/(b-a), ocd=cd;
				int num=k;
				for(int i=a-1;i>=0 && num>=0;i--)
				{
					if(ar[a] - cd != ar[i]) num--;
					cd += ocd;
				}
				cd = ocd;
				for(int i=b;i<n-1 && num>=0;i++)
				{
					if(ar[b] + cd != ar[i+1]) num--;
					cd += ocd;
				}
				cd = ocd;
				for(int i=a;i<b && num>=0;i++)
				{
					if(ar[a] + cd != ar[i+1]) num--;
					cd += ocd;
				}
				if(num >= 0)
				{
					if(ar[a] - ocd*a < bests) {
						bests = ar[a] - ocd*a; bestcd = ocd; }
					else if(ar[a] - ocd*a == bests)
					{
						if(ocd < bestcd) bestcd = ocd;
					}
				}
			}
		for(int a=0;a<n;a++) { printf("%d ",bests); bests += bestcd; }
		return 0;
	}
	
	map<int,int> freq;
	for(int a=1;a<n;a++)
	{
		int cd = ar[a]-ar[a-1];
		if(freq.find(cd) == freq.end()) freq[cd] = 0;
		freq[cd] += 1;
	}
	int max = 0, cd, pos;
	for(int a=1;a<n;a++) if(max < freq[ar[a]-ar[a-1]]) { max = freq[ar[a]-ar[a-1]]; cd = ar[a]-ar[a-1]; pos = a; }
	int f = ar[pos] - cd*pos;
	for(int a=0;a<n;a++) { printf("%d ",f); f += cd; }
	
	return 0;
}
