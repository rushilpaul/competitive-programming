#include <stdio.h>
#include <string.h>
#include <math.h>
int locx, locy, n;
int p[1000][2];
int marked[1000],done[1000],k;

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
}

int find(int i, int index)	// leave out i
{
	int p_,a;
	double d, mind = 100000; // p_ = selected
	for(a=0;a<n;a++)
	{
		if(a == i) continue;
		d = dist(p[index][0], p[index][1], p[a][0], p[a][1]);
		if(d < mind) { mind = d; p_ = a; }
	}
	return p_;
}

void solve()
{
	int a;
	int ar2[1000], k2=0;
	again:;
	for(a=0;a<k;a++)
	{
		int p_,q;
		p_ = find(-1,marked[a]);
		q = find(p_,marked[a]);
		if(!done[p_]) { ar2[k2++] = p_; done[p_] = 1; }
		if(!done[q]) { ar2[k2++] = q;	done[q] = 1; }
	}
	if(k2 > 0)
	{
		for(a=0;a<k2;a++) marked[a] = ar2[a];
		goto again;
	}
}

int main()
{
	int locx,locy,a,b; scanf("%d\n%d %d",&n,&locx,&locy);
	n--;
	for(a=0;a<n;a++) scanf("%d %d",&p[a][0],&p[a][1]);
	// sort
	for(a=0;a<n;a++)
	for(b=0;b<n-1-a;b++)
		if(p[b][0] > p[b+1][0])
		{
			int c = p[b][0];
			p[b][0] = p[b+1][0];
			p[b+1][0] = c;

			c = p[b][1];
			p[b][1] = p[b+1][1];
			p[b+1][1] = c;
		}
	int m,i,d;
	for(m=0;m<n;)
	{
		d = p[m][0];
		i = m;
		while(d == p[m][0] && m < n) m++;
		for(a=i;a<m;a++)
		for(b=i;b<m-1;b++)
			if(p[b][1] > p[b+1][1])
			{
				int c = p[b][0];
				p[b][0] = p[b+1][0];
				p[b+1][0] = c;
	
				c = p[b][1];
				p[b][1] = p[b+1][1];
				p[b+1][1] = c;
			}
	}
	// sorting finished
	memset(done,0,sizeof(int)*1000);
	double mind = dist(locx,locy, p[0][0], p[0][1]);
	i = 0; k = 0;

	for(a=1;a<n;a++)
	{
		double dd = dist(locx,locy,p[a][0],p[a][1]);
		if(dd < mind) { mind = dd; i = a; }
	}
	marked[k++] = i;
	done[i] = 1;
	mind = 100000;
	m = i;
	for(a=0;a<n;a++)
	{
		if(a == m) continue;
		double dd = dist(locx,locy,p[a][0],p[a][1]);
		if(dd < mind) { mind = dd; i = a; }
	}
	marked[k++] = i;
	done[i] = 1;
	// 2 closest points marked
	printf("\n");
	for(a=0;a<n;a++)
	{
		printf("%d %d\n",p[a][0],p[a][1]);
	}
	printf("%d, %d\n",marked[0],marked[1]);

	solve();
	for(a=0;a<n;a++)
		if(!done[a]) { printf("no\n"); return 0; }
	printf("yes\n");
	return 0;
}

