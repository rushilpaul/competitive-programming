#include <iostream>
#include <cstring>
using namespace std;

#define mod 100000007

long f(long ans, int n);

inline long f(long ans, int n)
{
	for(int i=0;i<n;i++)
	{
		ans <<= 1;
		if(ans >= mod) ans %= mod;
	}
	return ans;
}

int key[]   = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int index1[]= { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };

int main()
{
	int t;
	cin >> t;
	string msg = "";

	while(t--)
	{
		cin >> msg;
		int prev = 0, len = strlen(msg.c_str()), s=0, cur=0;
		long ans = 1;
		for(int a = 0; a < len; a++)
		{
			cur = key[ msg[a]-'a' ];
			int i = index1[ msg[a]-'a' ];
			if(prev != cur && a != 0)
			{
				ans = f(ans,s-1);
				s=0;
			}
			s += i;
			prev = cur;
		}
		ans = f(ans,s-1);
		cout << ans << endl;
	}
	return 0;
}
