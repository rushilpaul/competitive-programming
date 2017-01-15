#include <fastio>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint();
		int B = readint();
		int ar[n];
		for(int a=0;a<n;a++)
		{
			ar[a] = readint();
		}
		int i=0,j=0;
		int s=0,len=0,max_s=0;
		while(i < n and j < n)
		{
			while(s + ar[j] <= B and j < n)
			{
				s += ar[j];
				j++;
			}
			if(j-i > len)
			{
				max_s = s;
				len = j-i;
			}
			else if(j-i == len)
				max_s = min(max_s,s);
			s -= ar[i];
			i++;
		}
		printf("%d %d\n",max_s,len);
	}
	return 0;
}

