#include <iostream>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;
char s[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	char m[1000];
	
	while(t--)
	{
		int n; cin >> n;
		memset(m,' ',1000);
		for(int a=0;a<n;a++)
		{
			char ci,pi;
			cin >> ci >> pi;
			m[ci] = pi;
		}
		cin >> s;
		int len = strlen(s);
		int start=-1, end=-1, dots=0;
		for(int a=0;a<len;a++)
		{
			if(m[s[a]] != ' ')
				s[a] = m[ s[a] ];
			if(s[a] != '0' && start<0)
				start = a;
			if(s[a] == '.')
				dots++;
		}
		assert(dots <= 1);		// <--
		
		if(start < 0) { cout << "0\n"; continue; }
		for(int a=len-1;a>=start;a--)
		{
			if(s[a] != '0') { end = a; break; }
		}
		if(dots == 0) end = len-1;
		if(s[end] == '.') end--;
		s[end+1] = 0;
		len = strlen(s+start);
		if(len == 0) { cout << "0\n"; continue; }
		cout << s+start << endl;
	}
	return 0;
}
