//Program question at: http://www.codechef.com/CDEZILLA/problems/CD202
#include <stdio.h>
#include <string.h>

int main()
{
	char s[101]; int k=0,c=0;
	gets(s);
	while(1)
	{
		int t = c+k;
		if(!s[t]) break;
		if(s[t] == 'a' || s[t] == 'e' || s[t] == 'i' || s[t] == 'o' || s[t] == 'u') c += 2;
		k++;
		printf("%c",s[t]);
	}
	return 0;
}
