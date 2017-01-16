#include <stdio.h>

int main()
{
	int T,t; scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		double time1,time2,elapsed=0,c,f,x,rate=2; scanf("%lf %lf %lf",&c,&f,&x);
		printf("Case #%d: ",t);
		while(1)
		{
			time1 = x/(double)rate;
			time2 = c/(double)rate;
			rate += f;
			time2 += x/(double)rate;
			if(time1 < time2) { printf("%f\n",elapsed+time1); break; }
			elapsed += c/(rate-(double)f);
		}
	}
}
