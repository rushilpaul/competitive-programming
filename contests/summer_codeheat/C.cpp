// https://www.hackerrank.com/contests/ie-cse-summer-codeheat/challenges/the-really-stupid-question
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f(int ar[], int n)
{
	int lis[n],i,j;
	int pre[n];
	for (i=0; i<n; i++)
	{
		lis[i] = 1;
		pre[i] = -1;
	}

	for (i=1; i<n; i++)
		for (j=0; j<i; j++)
			if (ar[i] > ar[j] and lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				pre[i] = j;
			}
			else if(ar[i] > ar[j] and lis[i] == lis[j] + 1 and pre[j] < pre[i])
				pre[i] = j;

	int idx=-1, m=0;
	for (i=0; i<n; i++)
		if (m < lis[i])
			m = lis[i];

	vector< vector<int> > A;
	for(i=0; i<n; i++)
	{
		if(lis[i] == m)
		{
			vector<int> tmp;
			for(int a=i; a>=0; a=pre[a])
				tmp.push_back(a);
			reverse(tmp.begin(),tmp.end());
			A.push_back(tmp);
		}
	}
	sort(A.begin(),A.end());

	cout << m << endl;
	for(auto i : A[0])
		cout << ar[i] << " ";
	cout << endl;
	return m;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ar[n];
		for(int a=0; a<n; a++)
			cin >> ar[a];
		f(ar,n);
		//cout << endl;
	}
	return 0;
}
