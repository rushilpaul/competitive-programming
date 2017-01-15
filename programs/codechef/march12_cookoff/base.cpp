#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	unsigned long long num=0; int ans=0;
	char nums[3] = {'3','5','8'};
	while(ans != 5000)
	{
		long ar[3] = { 0,0,0 };
		unsigned long long n=num;
		string s;
		while(n)
		{
			int tmp = n%3;
			s = s + nums[tmp];
			ar[tmp]++;
			n/=3;
		}
		if(ar[2] >= ar[1] && ar[1] >= ar[0]) { ans++; printf("%s\n",s.c_str()); }
		num++;
	}
	return 0;
}
