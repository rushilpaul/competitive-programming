#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
typedef long long LL;
using namespace std;

int main()
{
	int n; scanf("%d",&n);
	vector<int> ones;
	vector<int> twos;
	for(int a=0;a<n;a++)
	{
		int w,c; scanf("%d %d",&w,&c);
		if(w == 1) ones.push_back(c);
		else twos.push_back(c);
	}
	sort(ones.begin(),ones.end(),greater<int>());
	sort(twos.begin(),twos.end(),greater<int>());
	LL cost = 0;
	int m = ones.size() + twos.size()*2;
	int ones_i=-1,twos_i=-1;
	if(ones.size() > 0) ones_i = 0;
	if(twos.size() > 0) twos_i = 0;
	
	if(ones_i == -1) printf("0 ");
	else { printf("%d ",ones[0]); cost = ones[0]; ones_i++; }
	
	for(int c=2;c<=m;c++)
	{
		LL tmp1 = cost, tmp2 = cost;
		if(ones_i+1 < ones.size() && ones_i >= 0)
		{
			tmp1 += ones[ones_i+1];
			//
			if(twos_i+1 < twos.size())
			{
				tmp2 -= ones[ones_i];
				tmp2 += twos[twos_i+1];
				if(tmp2 > tmp1)
				{
					twos_i++;
					ones_i--;
					cost = tmp2;
				}
				else
				{
					cost = tmp1;
					ones_i++;
				}
			}
			else
			{
				cost = tmp1;
				ones_i++;
			}
		}
		else
		{
			
		}
	}
	
	return 0;
}

