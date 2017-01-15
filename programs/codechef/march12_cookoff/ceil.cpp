#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t; scanf("%d\n",&t);
	char s[1000000]; long long ans=0;
	while(t--)
	{
		gets(s);
		unsigned long len = strlen(s), _3,_5,_8; bool pos=1;
		_3 = _5 = _8 = 0;
		for(int a=0;a<len;a++)
		{
			if(!isdigit(s[a])) { _3 = _5 = _8 = 0; pos=1; continue; }
			if(s[a] == '3') _3++;
			else if(s[a] == '5') _5++;
			else if(s[a] == '8') _8++;
			else { pos=0; continue; }
		}
		if(_8 >= _5 && _5 >= _3 && pos) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
