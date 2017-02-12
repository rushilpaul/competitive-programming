#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cassert>
typedef long long LL;
typedef long double LD;
using namespace std;

inline int pow(int b, int e)
{
	int ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e)
{
	LL ans=1;
	while(e--) ans *= b;
	return ans;
}

inline LL pow(LL b, LL e, LL mod)
{
	LL ans=1;
	while(e)
	{
		if(e & 1)
			ans = ans * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return ans;
}
 
int egcd(int a, int b, int &x, int &y)
{
	if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL egcd(LL a, LL b, LL& x, LL& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1;
    LL d = egcd(b%a, a, x1, y1);
    x = y1 - x1* (b/a);
    y = x1;
    return d;
}
 
LL inv(LL a, LL m)
{
	LL inv,y;
	assert(egcd(a,m,inv,y) == 1);
	if(inv < 0) inv += m;
	return inv;
}

inline LL gcd(LL a, LL b)
{
	while(b)
	{
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

vector<string> split(string S, string D)
{
	vector<string> ar;
	int pos = 0, last = 0;
	while( (pos = S.find(D,last)) != string::npos)
	{
		ar.push_back(S.substr(last,pos-last));
		last = pos + D.length();
	}
	ar.push_back(S.substr(last));
	return ar;
}

class BuildingStrings
{
	public:
		vector <string> findAny(int k)
		{
			vector<string> ans;
			vector< pair<int,int> > ar;
			int num = 26;
			while(num) {
				num--;
				while(k >= num)
				{
					int q = k / num;
					if(q*num > 50)
						q = 50/num;
					ar.push_back(make_pair(num,q));
					k -= q * num;
				}
				if(k == 0) break;
			}
			for(pair<int,int> i : ar)
			{
				int num = i.first, freq = i.second;
				if(num > freq) swap(num,freq);
				string s = "";
				// num <= 26
				for(int a=0;a<num;a++)
					s = s + (char)('a' + a);

				int total = num * freq;
				for(int a=0;a<total - num;a++)
					s = s + s[0];
				ans.push_back(s);
			}
			return ans;
		}
		

};

