#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	gets(s);
	int a,b,i=0,count=0,l=0;
	for(a=0;s[a];a++) l++;
	if(s[0] >= 'a' && s[a] <= 'z') s[a] -= 32;
	
	for(a=0;a<l;a++)
	{
		if(s[a] == ' ')
		{
			if(a-i == 1)
			{
				if(s[a-1] == 'i') s[a-1] = 'I'; i=a+1; count = 0;
				continue;
			}
			if(!( (count<0 && count == a-i) || count == a-i))
				for(b=i;b<a;b++) if(s[b] >= 'A' && ) s[b] -= 32;

			count = 0;
			i = a+1;
		}
		else
		{
			if(s[a] >= 'a' && s[a] <= 'z') count++;
			else count--;
		}
	}
	if(s[l-1] != '.') { s[l] = '.'; s[l+1] = 0; }
	printf("%s\n",s);
}

