// https://www.hackerrank.com/contests/w16/challenges/sprinklers
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int find_start(int ar[], int m, int n)
{
	int ans = max(ar[0]-1, n-ar[m-1]);
	for(int a=0;a<m-1;a++)
		ans = max(ans, (ar[a+1] - ar[a])/2);
	return ans;
}

vector<int> v;
int n;

int find_min(int ar[], int m, int e)
{
	v.clear();
	int last = 0, a=0;
	while(a < m-1 and ar[a+1] - e <= last+1)
		a++;
	v.push_back(ar[a]);
	last = ar[a] + e;
	//printf("e = %d, begin = %d\n",e,last);
	while(last < n and a < m)
	{
		if(ar[a+1]-e > last+1 or (a == m-1 and last < n))
		{
			last = ar[a] + e;
			v.push_back(ar[a]);
		}
		a++;
	}
	return v.size();
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int m,s,q; scanf("%d %d %d %d",&n,&m,&s,&q);
		int ar[m];
		for(int a=0;a<m;a++) scanf("%d",ar+a);
		int start = find_start(ar,m,n);
		int min_range = start;
		int last = find_min(ar,m,start);
		LL min_cost = (LL)s*last + (LL)q*start;
		//printf("L = %d, last = %d\n",L,last);

		while(1)
		{
			int L = start, R = n-1;
			while(L <= R)
			{
				int mid = (L+R)/2;
				if(find_min(ar,m,mid) >= last)
					L = mid+1;
				else
					R = mid-1;
			}
			int next = find_min(ar,m,L);
			if(last == next)
				break;
			last = next;
			LL cost = (LL)L*q + (LL)s*last;
			if(cost < min_cost)
			{
				min_cost = cost;
				min_range = L;
			}
			//printf("L = %d, last = %d\n",L,last);
		}
		find_min(ar,m,min_range);
		printf("%d %d\n",v.size(),min_range);
		for(auto i : v)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}

