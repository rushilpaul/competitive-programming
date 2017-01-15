#include <stdio.h>
#include <string.h>
#define print(ar,i,b) for(i=0;i<b;i++) printf("%d ",ar[i]);

inline int isalpha(char ch)
{ return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122); }

int main()
{
	char f1[27], s[150001], s2[150001];
	int f2[26];
	int a,t; scanf("%d\n",&t);
	while(t--)
	{
		memset(f2,0,26*sizeof(int));
		gets(f1);
		gets(s);
		strcpy(s2,s);
		int len = strlen(s);
		for(a=0;a<len;a++)
			if(s[a] >= 97) f2[s[a]-97]++;
			else f2[s[a]-65]++;
		int start = 0;
		for(a=0;a<26;a++) if(f2[a]) start++;
		start = 26 - start;
		int f,p=0; char cur;
		f = 200000;
		for(a=0;a<26;a++) if(f2[a] > 0 && f2[a] < f) f = f2[a];
		if(f == 1)
		for(a=0;a<len;a++)
		{
			char ch = s[a];
			if(!isalpha(ch)) continue;
			ch = s[a] >= 97 ? ch-97 : ch-65;
			if(f2[ch] == f)
			{
				if(s[a] <= 90) s2[a] = f1[start++] - 32;
				else s2[a] = f1[start++];
			}
		}
		for(a=0;a<26;a++) if(f2[a] == f) f2[a] = -1;
		while(1)
		{
			f = 200000;
			for(a=0;a<26;a++) if(f2[a] > 0 && f2[a] < f) f = f2[a];
			if(f == 200000) break;
			while(1)
			{
				for(a=0;a<len;a++)
				{
					char ch = s[a];
					if(!isalpha(ch)) continue;
					ch = s[a] >= 97 ? ch-97 : ch-65;
					if(f2[ch] == f) { cur = ch; break; }
				}
				if(a == len) break;
				int count = 0;
				for(a=0;a<len;a++)
				{
					char ch = s[a];
					if(!isalpha(ch)) continue;
					ch = s[a] >= 97 ? ch-97 : ch-65;
					if(ch == cur)
					{
						if(s[a] <= 90) s2[a] = f1[start] - 32;
						else s2[a] = f1[start];
						count++;
						if(count == f) break;
					}
				}
				f2[cur] = -1;
				start++;
			}
			for(a=0;a<26;a++) if(f2[a] == f) f2[a] = -1;
		}
		printf("%s\n",s2);
	}
}
