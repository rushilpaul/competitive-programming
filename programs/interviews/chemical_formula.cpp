#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	vector< pair<char,int> > v;
	vector<int> st;
	int L = 0;
	for(int a=0;a<n;a++)
	{
		if(isalpha(s[a]))
		{
			st.push_back(L);
			int d=1;
			if(a<n-1 and isdigit(s[a+1]))
				d = s[a+1]-48;
			v.push_back({s[a],d});
		}
		else if(s[a] == '(')
			L++;
		else if(s[a] == ')')
		{
			int d = 1;
			if(a<n-1 and isdigit(s[a+1]))
				d = s[a+1]-48;
			auto i = v.rbegin();
			auto j = st.rbegin();
			while(*j >= L)
			{
				i->second *= d;
				i++; j++;
			}
			L--;
		}
	}
	for(auto i : v)
		printf("%c: %d\n",i.first,i.second);
	
	return 0;
}
