#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;
#define max_buf_size 1024

struct _init_
{
	_init_()
	{
		ios_base::sync_with_stdio(0); cin.tie(0);
		setvbuf(stdout,NULL,_IOFBF,max_buf_size);
		setvbuf(stdin,NULL,_IOFBF,max_buf_size);
	}
} _init_ob_unused;

char chef[4];
char words[100000][4];
LD B[26][26], res[26][26];

inline void mul(LD A[26][26], LD B[26][26], LD C[26][26])
{
	for(int a=0;a<26;a++)
	for(int b=0;b<26;b++)
	{
		C[a][b] = 0;
		for(int c=0;c<26;c++) C[a][b] += A[a][c] * B[c][b];
	}
}

void expo(int k)
{
	if(k == 1) return;
	LD P[26][26];
	expo(k/2);
	mul(res,res,P);
	memcpy(res,P,26*26*sizeof(LD));
	if(k & 1)
		mul(P,B,res);
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,k; scanf("%d %d\n",&n,&k);
		gets(chef);
		int len_chef = strlen(chef);
		for(int a=0;a<26;a++) for(int b=0;b<26;b++) { scanf("%Lf",&B[a][b]); res[a][b] = B[a][b]; }
		expo(k);
		scanf("\n");
		LD ans=0;
		set<string> words_set;
		for(int a=0;a<n;a++)
		{
			gets(words[a]);
			int len = strlen(words[a]);
			if(len == len_chef && words_set.find(words[a]) == words_set.end())
			{
				words_set.insert(string(words[a]));
				LD p = 1;
				for(int b=0;b<len;b++)
					p *= res[chef[b]-97][words[a][b]-97];
				ans += p;
			}
		}
		printf("%.7Lf\n",ans);
	}
	return 0;
}
