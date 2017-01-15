#include <stdio.h>
int main()
{
	int t,T; scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int a,N,n;
		int ar1[5],ar2[5];
		scanf("%d",&N);
		for(n=1;n<N;n++) for(a=0;a<4;a++) scanf("%d",&ar1[4]);
		for(a=0;a<4;a++) scanf("%d",&ar1[a]);
		N = 4 - n;
		for(a=0;a<4*N;a++) scanf("%d",&ar1[4]);
		scanf("%d",&N);
		for(n=1;n<N;n++) for(a=0;a<4;a++) scanf("%d",&ar2[4]);
		for(a=0;a<4;a++) scanf("%d",&ar2[a]);
		N = 4 - n;
		for(a=0;a<4*N;a++) scanf("%d",&ar2[4]);
		int b,c=0;
		for(a=0;a<4;a++)
		for(b=0;b<4;b++)
			if(ar1[a] == ar2[b]) { n = ar1[a]; c++; }
		if(!c) printf("Volunteer cheated!\n");
		else if(c > 1) printf("Bad magician!\n");
		else printf("%d\n",n);
	}
}
