#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; scanf("%d",&n);
		char s[51];
		scanf("%s",s);
		n = strlen(s);
		for(int ch=0;ch<26;ch++)
		{
			int flag = -1;
			for(int a=0;a<n;a++)
				if(s[a] == ch+65)
					flag = a;
			if(flag == -1) continue;
			int p = -1;
			for(int a=0;a<flag;a++)
			{
				if(ch+65 < s[a])
				{
					p = a;
					break;
				}
			}
			if(p == -1) continue;
			for(int a=flag;a>p;a--) s[a] = s[a-1];
			s[p] = ch+65;
			break;
		}
		printf("%s\n",s);
	}
	return 0;
}

// ABBCDFB
// ADCBC
