#include <stdio.h>

inline double abs(double x) { return x<0?-x:x; }

inline double f(double x, double a, double b, double c, double d)
{
	return a*x*x*x + b*x*x + c*x + d;
}

void cubic(double a, double b, double c, double d, double *x1, double *x2, double *x3)
{
	if(b*b - 3*a*c < 0) { *x1 = *x2 = *x3 = 0; return; }
	double det = sqrt(b*b - 3*a*c), r1 = (-b+det)/(3.0*a), r2 = (-b-det)/(3.0*a);
	if(r1 > r2) { det = r1; r1 = r2; r2 = det; }
	double L,R,mid,tmp;
	L = -2147483647; R = r1;
	int inc = f(R-1,a,b,c,d) < f(R,a,b,c,d);
	while(L<R)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		if(tmp == 0) break;
		if(inc)
		{
			if(tmp > 0) R = mid;
			else L = mid;
		}
		else
		{
			if(tmp > 0) L = mid;
			else R = mid;
		}
		if(abs(tmp) < 1e-10) break;
	}
	*x1 = mid;
	L = r1; R = r2;
	inc = f(R-1,a,b,c,d) < f(R,a,b,c,d);
	while(L<R)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		if(tmp == 0) break;
		if(inc)
		{
			if(tmp > 0) R = mid;
			else L = mid;
		}
		else
		{
			if(tmp > 0) L = mid;
			else R = mid;
		}
		if(abs(tmp) < 1e-10) break;
	}
	*x2 = mid;
	L = r2; R = 2147483647;
	inc = f(R-1,a,b,c,d) < f(R,a,b,c,d);
	while(L<R)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		if(tmp == 0) break;
		if(inc)
		{
			if(tmp > 0) R = mid;
			else L = mid;
		}
		else
		{
			if(tmp > 0) L = mid;
			else R = mid;
		}
		if(abs(tmp) < 1e-10) break;
	}
	*x3 = mid;
}

int main()
{
	double a,b,c,d,r1,r2,r3;
	a = 1; b = -52.5903; c = 593.708; d = -259.89;
	cubic(a,b,c,d,&r1,&r2,&r3);
	printf("%f %f %f\n",r1,r2,r3);
	return 0;
}
