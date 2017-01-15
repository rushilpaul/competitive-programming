#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 100001
int main()
{
	int t=in(),a,b;
	int ar[max], P[max], sqmax = sqrt(max);
	memset(P,0,sizeof(int)*max);
	for(a=2;a<=sqmax;a++)
		for(b=a*a;b<=max;b+=a) P[b]=1;
	while(t--)
	{
		next:;
		int large=0,sm=max,tmp,n=in();
		memset(ar,0,sizeof(int)*max);
		for(a=0;a<n;a++)
		{
			tmp = in();
			if(tmp < sm) sm = tmp;
			if(tmp > large) large = tmp;
			ar[tmp]++;
		}
		if(sm == 1) { printf("-1\n"); continue; }
		int num, sqsm = sqrt(sm);
		for(a=2;a<=sqsm;a++)
		{
			if(P[a] || sm % a) continue;
			num=0;
			for(b=sm;b<=large;b++)
				if(ar[b] && !(b%a)) num++;
			if(num == n) {
			printf("%d\n",a); goto next; }
		}
		for(a=sqsm;a>=2;a--)
		{
			if(sm % a) continue;
			num=0;
			for(b=sm;b<=large;b++)
				if(ar[b] && !(b%(sm/a))) num++;
			if(num == n) {
			printf("%d\n",sm/a); goto next; }
		}
		num=0;
		for(a=sm;a<=large;a++)
			if(ar[a] && !(a%sm)) num++;
		if(num == n)
			printf("%d\n",sm);
		else
			printf("-1\n");
	}
	return 0;
}
