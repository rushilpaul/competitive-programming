#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char s[100001];

int find(string &s, int n, char ch)
{
	int left=0,c=0;
	for(int a=0;a<n;a++)
	{
		if(s[a] != ch) c++;
		else left += c;
	}
	int right=0; c=0;
	for(int a=n-1;a>=0;a--)
	{
		if(s[a] != ch) c++;
		else right += c;
	}
	return min(left,right);
}

string wr,wg,wb;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		wr = wg = wb = "";
		scanf("%s",s);
		int n = strlen(s);
		string str = string(s);
		for(int a=0;a<n;a++)
		{
			if(s[a] != 'r') wr += s[a];
			if(s[a] != 'g') wg += s[a];
			if(s[a] != 'b') wb += s[a];
		}
		int ans=INT_MAX;
		// rgb
		int r = find(str,n,'r');
		int g = find(wr,wr.length(),'g');
		ans = min(ans,r+g);
		
		// rbg
		int b = find(wr,wr.length(),'b');
		ans = min(ans,r+b);

		// grb
		g = find(str,n,'g');
		r = find(wg,wg.length(),'r');
		ans = min(ans,g+r);

		// gbr
		b = find(wg,wg.length(),'b');
		ans = min(ans,g+b);

		// brg
		b = find(str,n,'b');
		r = find(wb,wb.length(),'r');
		ans = min(ans,b+r);

		// bgr
		g = find(wb,wb.length(),'g');
		ans = min(ans,b+g);
	
		printf("%d\n",ans);
	}
	return 0;
}


