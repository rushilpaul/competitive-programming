#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		map<int,int> dish_chef;
		map<int,int> dish_score;
		vector<int> chef_dish[n];
		for(int a=0;a<n;a++)
		{
			int c; scanf("%d",&c);
			dish_chef[a] = a;
			dish_score[a] = c;
			chef_dish[a].push_back(a);
		}
		int q; scanf("%d",&q);
		for(int a=0;a<q;a++)
		{
			int i,j,k; scanf("%d %d",&i,&j); j--;
			if(i==0)
			{
				scanf("%d",&k); k--;
				if(dish_chef[j] == dish_chef[k]) printf("Invalid query!\n");
				else
				{
					int c = dish_chef[k], d = dish_chef[j];
					int p = dish_score[d], q = dish_score[c];
					if(p > q)
						for(int i=0;i<chef_dish[c].size();i++)
						{
							chef_dish[d].push_back(chef_dish[c][i]);
							dish_chef[chef_dish[c][i]] = dish_chef[j];
						}
					else if(q > p)
						for(int i=0;i<chef_dish[d].size();i++)
						{
							chef_dish[c].push_back(chef_dish[d][i]);
							dish_chef[chef_dish[d][i]] = dish_chef[k];
						}
				}
			}
			else
				printf("%d\n",dish_chef[j]+1);
		}
	}
	return 0;
}