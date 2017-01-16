// code: ANARC09A
#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[2001];
	int tt=1;
	while(tt++)
	{
		cin >> s;
		if(s[0] == '-') break;
		int n = strlen(s);
		vector<char> v(n);
		for(int a=0;a<n;a++) v[a] = s[a];
		int ans=0;
		while(v.size())
		{
			if(v[0] == '}')
			{
				ans++;
				v[0] = '{';
			}
			if(v.back() == '{')
			{
				ans++;
				v.back() = '}';
			}
			for(auto it = v.begin(); it != v.end(); it++)
				if(*it == '}')
				{
					v.erase(it-1,it+1);
					it -= 2;
					break;
				}
		}
		printf("%d. %d\n",tt-1,ans);
	}
	return 0;
}

