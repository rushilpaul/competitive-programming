#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != -1)
	{
		ar.push_back(S.substr(last,pos-last));
		last = pos + D.length();
	}
	ar.push_back(S.substr(last));
	return ar;
}

set< vector<LL> > ans;
vector<LL> x;
int s;

void f(int i, int n, LL s, vector<LL> &ar)
{
	if(i == n)
	{
		if(s == ::s)
			ans.insert(ar);
		return;
	}
	f(i+1,n,s,ar);
	ar.push_back(x[i]);
	f(i+1,n,s+x[i],ar);
	ar.pop_back();
}

LL convert(string s)
{
	LL n=0;
	for(int a=0;a<(int)s.length();a++)
		n = n*10 + (int)s[a]-48;
	return n;
}

int main()
{
	string input;
	getline(cin,input);
	vector<string> s_ar = split(input," ");
	for(int a=0;a < (int)s_ar.size();a++)
		x.push_back(convert(s_ar[a]));
	sort(x.begin(),x.end(),greater<LL>());
	cin >> s;
	vector<LL> tmp;
	f(0,s_ar.size(),0,tmp);
	for(set< vector<LL> >::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
	{
		int n = (int)(*it).size();
		if(n == 0)
			continue;
		printf("[");
		for(int a=0;a<n;a++)
			if(a == n-1)
				printf("%lld",(*it)[a]);
			else
				printf("%lld, ",(*it)[a]);
		printf("]\n");
	}
	return 0;
}

