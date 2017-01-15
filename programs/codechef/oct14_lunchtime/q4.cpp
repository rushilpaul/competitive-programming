#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void read(int &n) { scanf("%d",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }
void read(long double &n) { scanf("%lf",&n); }

int main()
{
	int n,m; read(n); read(m);
	multimap< pair<int,int>, pair<int,int> > map1;
	for(int a=0;a<n;a++)
	{
		int id,attr,val,p;
		read(id); read(attr); read(val); read(p);
		map1.insert(make_pair( make_pair(id,attr), make_pair(val,p) ) );
	}
	for(int a=0;a<m;a++)
	{
		int id,attr;
		read(id); read(attr);
		multimap< pair<int,int>, pair<int,int> >::iterator it = map1.find(make_pair(id,attr));
		int max_val=0,value;
		while(1)
		{
			pair<int,int> obj = it->first, val = it->second;
			if(obj.first != id || obj.second != attr) break;
			if(val.second >= max_val)
			{
				max_val = val.second;
				value = val.first;
			}
			it++;
			if(it == map1.end()) break;
		}
		printf("%d\n",value);
	}	
	return 0;
}

