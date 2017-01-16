//Program question: http://code.google.com/codejam/contest/1145485/dashboard#s=p1
#include <cstdio>
#include <cstring>
using namespace std;

inline bool check(char **words, int **freq, int *len, int m, int n, char ch)
{
	if(len[m] != len[n] || freq[m][ch-97] != freq[n][ch-97]) return 0;
	for(int i=0;i<len[m];i++)
		if(words[m][i] == ch)
		if(words[n][i] != ch) return 0;
	return 1;
}

int main()
{
	int t; scanf("%d\n",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int m,nlist; scanf("%d %d\n", &m, &nlist);
		char **words = new char*[m];
		char buf[26];
		int *len = new int[m];
		int **freq = new int*[m];
		for(int a=0;a<m;a++)
		{
			scanf("%s",&buf);	// dicti words input
			int l = strlen(buf);
			len[a] = l;
			words[a] = new char[l];
			freq[a] = new int[26];
			for(int i=0;i<l;i++)
				freq[a][buf[i]-97]++;
		}
		bool elim[m];
		printf("Case #%d: ",tt);
		while(nlist--)
		{
			scanf("%s",&buf);
			int points=0,max=0;
			char ans[11];
			for(int a=0;a<m;a++)
			{
				// assuming words[a] is the answer
				memset(elim,0,m);
				int no=0,k=0;
				while(no != m-1)
			 	{
					char cur = buf[k];
					if(!freq[a][cur-97])
					{
						bool was=0;
						for(int i=0;i<m;i++) if(freq[i][cur-97]) { elim[i]=1; was=1; no++; }
						if(was) points++;
					}
					else
					{
						for(int i=0;i<m;i++)
						{
							if(i==a || elim[i]) continue;		
							if( !check(words,freq,len,a,i,buf[k]) ) { no++; elim[i]=1; }
						}
					}
					k++;
				}
				if(points > max) { max = points; strcpy(ans,buf); }
			}
			printf("%s%c",ans,nlist ? '\n':' ');
		}

	}
	return 0;
}
