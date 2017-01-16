#include <stdio.h>
#include <math.h>
int time;
inline long double f(long double x, long double a, long double b, long double c, long double d)
{
	return a*x*x*x + b*x*x + c*x + d;
}

inline long double g(long double x, long double a, long double b, long double c, long double d)
{
	return (a*x*x*x*x)/4.0 + (b*x*x*x)/3.0 + (c*x*x)/2.0 + d*x;
}

void cubic(long double a, long double b, long double c, long double d, long double *x1, long double *x2, long double *x3)
{
	if(b*b - 3*a*c < 0)
	{
		long double L,R,mid,tmp;
		L = 0; R = time; int i;
		long double inc = f(L,a,b,c,d);
		for(i=0;i<100;i++)
		{
			mid = (L+R)/2.0;
			tmp = f(mid,a,b,c,d);
			if((inc < 0 && tmp < 0) || (inc > 0 && tmp > 0)) L = mid;
			else R = mid;
		}
		*x1 = (L+R)/2.0;
		*x2 = *x3 = 0;
		return;
	}
	long double det = sqrtl(b*b - 3*a*c), r1 = (-b+det)/(3.0*a), r2 = (-b-det)/(3.0*a);
	if(r1 > r2) { det = r1; r1 = r2; r2 = det; }
	if(r1 < 0) r1 = 0;
	if(r2 < 0) r2 = 0;
	if(r1 > time) r1 = time;
	if(r2 > time) r2 = time;
	long double L,R,mid,tmp;
	L = 0; R = r1;
	long double inc = f(L,a,b,c,d);
	int i;
	for(i=0;i<100;i++)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		//if(tmp == 0) break;
		if((inc < 0 && tmp < 0) || (inc > 0 && tmp > 0)) L = mid;
		else R = mid;
		//if(fabs(tmp) < 1e-10) break;
	}
	*x1 = (L+R)/2.0;
	L = r1; R = r2;
	inc = f(L,a,b,c,d);
	for(i=0;i<100;i++)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		//if(tmp == 0) break;
		if((inc < 0 && tmp < 0) || (inc > 0 && tmp > 0)) L = mid;
		else R = mid;
		//if(fabs(tmp) < 1e-10) break;
	}
	*x2 = (L+R)/2.0;
	L = r2; R = time;
	inc = f(L,a,b,c,d);
	for(i=0;i<100;i++)
	{
		mid = (L+R)/2.0;
		tmp = f(mid,a,b,c,d);
		//if(tmp == 0) break;
		if((inc < 0 && tmp < 0) || (inc > 0 && tmp > 0)) L = mid;
		else R = mid;
		//if(fabs(tmp) < 1e-10) break;
	}
	*x3 = (L+R)/2.0;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d",&time);
		int in[4][2];
		for(a=0;a<4;a++) for(b=0;b<2;b++) scanf("%d",&in[a][b]);
		int A[4][4] = 
		{
			{ in[0][0]*in[0][0]*in[0][0], in[0][0]*in[0][0], in[0][0], 1},
			{ in[1][0]*in[1][0]*in[1][0], in[1][0]*in[1][0], in[1][0], 1},
			{ in[2][0]*in[2][0]*in[2][0], in[2][0]*in[2][0], in[2][0], 1},
			{ in[3][0]*in[3][0]*in[3][0], in[3][0]*in[3][0], in[3][0], 1}
		};
		int Asub[4][3][3], sign[3];
		long double Ainv[4][4];
		int det=0, sub, b1;
		for(sub=0;sub<4;sub++)
		{
			for(a=1;a<4;a++)
			for(b1=0,b=0;b<4;b++)
			{
				if(b == sub) continue;
				Asub[sub][a-1][b1] = A[a][b];
				if(a==1)
					sign[b1] = ((a-1+b1)%2) ? -1:1;
				b1++;
			}
			int sub1 = ( Asub[sub][1][1]*Asub[sub][2][2] - Asub[sub][2][1]*Asub[sub][1][2] ) * (sign[0]*Asub[sub][0][0]);
			int sub2 = ( Asub[sub][1][0]*Asub[sub][2][2] - Asub[sub][2][0]*Asub[sub][1][2] ) * (sign[1]*Asub[sub][0][1]);
			int sub3 = ( Asub[sub][1][0]*Asub[sub][2][1] - Asub[sub][2][0]*Asub[sub][1][1] ) * (sign[2]*Asub[sub][0][2]);
			det += (sub1+sub2+sub3) * A[0][sub] * (sub%2 ? -1:1);
		}
		int i,j,p,q;
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			for(p=0,a=0;a<4;a++)
			{
				if(a == i) continue;
				for(q=0,b=0;b<4;b++)
				{
					if(b == j) continue;
					Asub[0][p][q++] = A[a][b];
				}
				p++;
			}
			// find determinant
			int sub1 = ( Asub[0][1][1]*Asub[0][2][2] - Asub[0][2][1]*Asub[0][1][2] ) * (Asub[0][0][0]);
			int sub2 = ( Asub[0][1][0]*Asub[0][2][2] - Asub[0][2][0]*Asub[0][1][2] ) * (-Asub[0][0][1]);
			int sub3 = ( Asub[0][1][0]*Asub[0][2][1] - Asub[0][2][0]*Asub[0][1][1] ) * (Asub[0][0][2]);
			Ainv[i][j] = ((sub1 + sub2 + sub3) * ((i+j)%2 ? -1:1))/(long double)det;
		}
		for(a=0;a<4;a++)
		for(b=a+1;b<4;b++)
		{
			long double tmp = Ainv[a][b];
			Ainv[a][b] = Ainv[b][a];
			Ainv[b][a] = tmp;
		}
		long double sol[4] = {0};
		for(p=0;p<4;p++) sol[0] += Ainv[0][p] * in[p][1];
		for(p=0;p<4;p++) sol[1] += Ainv[1][p] * in[p][1];
		for(p=0;p<4;p++) sol[2] += Ainv[2][p] * in[p][1];
		for(p=0;p<4;p++) sol[3] += Ainv[3][p] * in[p][1];
		long double r1,r2,r3;
		cubic(sol[0],sol[1],sol[2],sol[3],&r1,&r2,&r3);
		long double root[] = { 0,r1,r2,r3,time }, ans=0;
		for(a=0;a<5;a++) for(b=0;b<4;b++) if(root[b] > root[b+1]) { long double tmp = root[b]; root[b] = root[b+1]; root[b+1] = tmp; }
		for(a=1;a<5;a++)
		{
			ans += fabs( g(root[a],sol[0],sol[1],sol[2],sol[3]) - g(root[a-1],sol[0],sol[1],sol[2],sol[3]) );
			if(root[a] == time) break;
		}
		printf("%.12f\n",(double)ans);
	}
	return 0;
}
