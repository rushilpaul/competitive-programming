#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
int k;
LL X[41][41];
LL ar[41][41][41];

void f(int g)
{
	int i,j;
	for(i=0;i<=k;i++) for(j=0;j<=k;j++) ar[g][i][j]=0;
	for(i=1;i<k;i++) ar[g][i][0] = 1;
	ar[g][1][1] = X[g][1];
	for(i=2;i<=k;i++)
	for(j=1;j<=k;j++)
		ar[g][i][j] = ar[g][i-1][j] + X[g][i]*ar[g][i-1][j-1];
}

int main()
{
	int t; scanf("%d",&t);
while(t--)
{
	int size[40];
	LL sum[40], powers[40];
	int n,m,zero=0;
	scanf("%d %d",&n,&m);
	if(m == 0) { zero = 1; m = 1; }
	int i,j,a;
	vector< pair<int,int> > input;
	for(a=0;a<n;a++)
	{
		int c,p; scanf("%d %d",&c,&p);
		input.push_back(make_pair(c,p));
	}
	sort(input.begin(),input.end());
	input.push_back(make_pair(43,0));
	k=0;
	for(a=0;a<40;a++) { size[a] = 0; sum[a] = 0; }
	for(a=0;a<n;a++)
	{
		size[k]++;
		sum[k] += input[a].second;
		if(input[a].first != input[a+1].first) k++;	
	}
	for(a=0;a<k;a++) powers[a] = (1<<size[a])-1;
	
	// computing denominator
	LL denominator=0;
	for(i=0;i<k;i++)
		X[0][i+1] = powers[i];
	f(0);
	for(i=m;i<=k;i++)
		denominator += ar[0][k][i];
	if(zero) denominator++;
	
	// computing numerator	
	for(a=1;a<=k;a++)
	{
	for(i=0,j=1;i<k;i++)
	{
		if(i+1 == a) continue;
		X[a][j++] = powers[i];
	}
	k--;
	f(a);
	k++;
	}
	/*
	for(a=1;a<=n;a++,printf("\n"))
	for(i=1;i<=n-1;i++)
		printf("%d ",ar[a][n-1][i]);
	*/
	long double numerator = 0, num=0;

	for(a=1;a<=k;a++)
	{
		LL s=0;
		for(i=m-1;i<=k-1;i++)
		{
			if(i == 0) s+=1;
			else s += ar[a][k-1][i];
		}
		numerator = numerator + ((sum[a-1])/(long double)denominator) * (1<<size[a-1]-1) * s;
	}
	//printf("num,denom: %f %lld\n",(double)num,denominator);
	printf("%.7lf\n",(double)numerator);
}
	return 0;
}
