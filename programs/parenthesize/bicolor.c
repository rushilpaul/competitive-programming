#include <stdio.h>
#include <string.h>
int edges[200][200],mask[200],done[200],ar[40000][2],n,l;

int solve(int i)
{
	int a;
	if(i >= n)
	{
		//for(a=0;a<n;a++) printf("%d",mask[a]);
		//printf("\n");
		for(a=0;a<l;a++)
			if( edges[ar[a][0]][ar[a][1]] && (mask[ar[a][0]] == mask[ar[a][1]]) ) return 0;
		return 1;
	}
	for(a=0;a<n;a++)
	{
		if(done[a]) continue;
		done[a] = 1;
		mask[a] = 0;
		if(solve(i+1)) return 1;
		mask[a] = 1;
		if(solve(i+1)) return 1;
		mask[a] = 0;
		done[a] = 0;
	}
	return 0;
}

int main()
{
	while(1)
	{
		int a; scanf("%d %d",&n,&l);
		if(n == 0) return 0;
		memset(edges,0,sizeof(int)*200*200);
		for(a=0;a<l;a++) { int p,q; scanf("%d %d",&p,&q); ar[a][0] = p; ar[a][1] = q; edges[p][q]=1; }
		memset(mask,0,sizeof(int)*200);
		memset(done,0,sizeof(int)*200);
		if(solve(0)) printf("BICOLORABLE\n");
		else printf("NOT BICOLORABLE\n");
	}
	return 0;
}
