//Program question at: http://www.codechef.com/DEC12/problems/GRANAMA
#include <stdio.h>
#define yus printf("YES\n");
#define nope printf("NO\n");
#define FOR for(a=0;a<26;a++)
int main()
{
	int ar[2][26],a,f,t;
	char s[2002];
	scanf("%d\n",&t);
	while(t--)
	{
		f=1;
		gets(s);
		FOR ar[0][a]=ar[1][a]=0;
		for(a=0;s[a]!=32;a++) ar[0][s[a]-97]++;
		for(a++;s[a];a++) ar[1][s[a]-97]++;
		FOR if((!ar[0][a] && ar[1][a]) || (!ar[1][a] && ar[0][a]) ) { yus goto E; }
		FOR if(ar[0][a] != ar[1][a]) { nope goto E; }
		yus
		E:;
	}
	return 0;
}
