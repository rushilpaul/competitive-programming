#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
typedef long long LL;
using namespace std;

#define mset_int_it multiset<int>::iterator
#define mset_LL_it multiset<LL>::iterator

void read(int &n) { scanf("%d",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }

void f(int i, int n, int s, int num, multiset<int> &set, int *ar)
{
	if(i == n)
	{
		if(!s) return;
		mset_int_it it = set.find(s+num);
		if(it != set.end())
			set.erase(it);
		return;
	}
	f(i+1,n,s,num,set,ar);
	f(i+1,n,s+ar[i],num,set,ar);
}

int main()
{
	int t; read(t);
	while(t--)
	{
		int n; read(n);
		int size = 1<<n;
		int ar[n],k=0;
		multiset<int> set;
		for(int a=0;a<size;a++)
		{
			int c; read(c);
			set.insert(c);
		}
		set.erase(set.begin());
		ar[0] = *(set.begin());
		set.erase(set.begin());
		for(int a=1;a<n;a++)
		{
			f(0,a,0,*(set.begin()),set,ar);
			ar[a] = *(set.begin());
			set.erase(set.begin());
		}
		for(int a=0;a<n;a++) printf("%d ",ar[a]);
		printf("\n");
	}
	return 0;
}
