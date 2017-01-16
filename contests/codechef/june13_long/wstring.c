//Program question at: http://www.codechef.com/JUNE13/problems/WSTRING
#include <stdio.h>
#include <string.h>
char s[10001];

inline int find(int *ar)
{
	int a,c=0;
	for(a=0;a<26;a++) if(ar[a] > c) c = ar[a];
	return c;
}

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		int l = strlen(s);
		int a,b,k=0;
		int freq[26],hashes[10000], alpha[26], forward[10000],reverse[10000],between[10000];
		memset(freq,0,sizeof(int)*26);
		memset(alpha,0,sizeof(int)*26);
		for(a=0;a<l;a++)		// reverse
		{
			if(s[a] == '#')
			{
				hashes[k] = a;
				if(k)
				{
					between[k-1] = find(alpha);
					memset(alpha,0,sizeof(int)*26);
				}
				reverse[k++] = find(freq);
				continue;
			}
			if(k) alpha[s[a]-97]++;
			freq[s[a]-97]++;
		}
		int count = k;
		if(count < 3) { printf("0\n"); continue; }
		memset(freq,0,sizeof(int)*26);
		for(a=l-1;a>=0;a--)		// forward
		{
			if(s[a] == '#')
			{
				forward[--k] = find(freq);
				continue;
			}
			freq[s[a]-97]++;
		}
		int max = 0;
		for(a=0;a<count-2;a++)
		{
			if(hashes[a+1]-hashes[a] == 1 || hashes[a+2]-hashes[a+1] == 1) continue;
			if(!reverse[a] || !forward[a+2]) continue;
			k = reverse[a] + between[a] + between[a+1] + forward[a+2];
			if(k > max) max = k;
		}
		printf("%d\n",max ? max+3 : 0);
	}
	return 0;
}
