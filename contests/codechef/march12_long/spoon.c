#include <stdio.h>

int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		int f=0,a,b,m,n,ans=0; scanf("%d %d\n",&m,&n);
		char ar[m][n], buf[n+2];
		for(a=0;a<m;a++)
		{
		fgets(buf,n+2,stdin);
		for(b=0;b<n;b++)
		{
			char ch = buf[b];
			ar[a][b] = (ch>=97) ? (char)(ch-32) : ch;
			ch = ar[a][b];
			if(ans == 0) if(ch == 'S') ans++; else ans=0;
			else if(ans == 1) if(ch == 'P') ans++; else ans=0;
			else if(ans == 2) if(ch == 'O') ans++; else ans=0;
			else if(ans == 3) if(ch == 'O') ans++; else ans=0;
			else if(ans == 4) if(ch == 'N') { ans++; f=1; }
		}
		}
		if(f) { printf("There is a spoon!\n"); continue; }
		for(a=0;a<n;a++) for(ans=0,b=0;b<m;b++)
		{
			char ch = ar[b][a];
			if(ans == 0) if(ch == 'S') ans++; else ans=0;
			else if(ans == 1) if(ch == 'P') ans++; else ans=0;
			else if(ans == 2) if(ch == 'O') ans++; else ans=0;
			else if(ans == 3) if(ch == 'O') ans++; else ans=0;
			else if(ans == 4) if(ch == 'N') { ans++; goto out; }
		}
		printf("There is indeed no spoon!\n");
		continue;
		out:
		printf("There is a spoon!\n");
	}
}
