//Program question at: http://www.codechef.com/JUNE12/problems/HULL
#include <stdio.h>
typedef long long LL;

inline double abs(double x) { return x<0 ? -x:x; }
inline double area(LL *X, LL *Y, int n)
{
	double area = 0;
	int i,j = n-1;  // last vertex is the previous one to the 1st
	for (i=0;i<n;i++)
	{
		area += (X[j]+X[i]) * (Y[j]-Y[i]); 
		j = i;
	}
	return area/2;
}

int main()
{
	LL *x,*y;
	x = malloc(4*sizeof(LL));
	y = malloc(4*sizeof(LL));
	x[0] = 3; x[1] = 2; x[2] = 1; x[3] = 0;
	y[0] = 0; y[1] = 1; y[2] = 1; y[3] = 0;
	double ans = abs(area(x,y,4));
	printf("%.1f\n",ans);
	return 0;
}
