#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

void read(int &n) { scanf("%d\n",&n); }
void read(LL &n) { scanf("%lld",&n); }
void read(double &n) { scanf("%f",&n); }
void read(long double &n) { scanf("%lf",&n); }

int main()
{
	int t; read(t);
	while(t--)
	{
		int n; read(n);
		char s[1001];
		gets(s);
		bool indian=true,pos=false;
		for(int a=0;a<n;a++)
		{
			if(s[a] == 'Y') { indian = false; pos = true; }
			if(s[a] == 'I') pos = true;
		}
		if(!pos) printf("NOT SURE\n");
		else if(indian) printf("INDIAN\n");
		else printf("NOT INDIAN\n");
	}
	return 0;
}

