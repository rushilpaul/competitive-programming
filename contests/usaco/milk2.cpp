/*
ID: rushilp1
PROG: milk2
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int A[1000001], B[1000001];

int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n; scanf("%d",&n);
	int start=INT_MAX, end=INT_MIN;
	for(int a=0;a<n;a++)
	{
		int i,j; scanf("%d %d",&i,&j);
		start = min(start, i);
		end = max(end, j);
		A[i]++;
		B[j]++;
	}
	int ans=0, cur=0, x=0;
	for(int a=0;a<=1000000;a++)
	{
		cur += (A[a] - B[a]);
		if(cur > 0) x++;
		else
		{
			ans = max(ans,x);
			x = 0;
		}
	}
	printf("%d ",ans);
	ans = x = cur = 0;
	for(int a=start;a<=end;a++)
	{
		cur += (A[a] - B[a]);
		if(cur == 0) x++;
		else
		{
			ans = max(ans,x);
			x=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}

