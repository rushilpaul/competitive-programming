#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;
using namespace std;

inline LD round(LD val, int nPlaces)
{
    LD shift = pow(10.0, nPlaces);
	return floor(val * shift + 0.5) / shift;
}

int main()
{
	LD ans = 0;
	int t; scanf("%d",&t);
	LL N0,P,M,B;
	LD R1,R2,R3,R4;
	scanf("%lld %lld %lld %lld %Lf %Lf %Lf %Lf\n",&N0,&P,&M,&B, &R1,&R2,&R3,&R4);
	LD k1 = -1/R1, k2 = 1/R2, k3 = 1/R3, k4 = 1/R4, k4_copy = k4;
	LD c1 = k1 + k2, c2 = k1 * k2;

	while(t--)
	{
		k4 = k4_copy;
		N0 = P*N0 % M + B;
		int n = N0;
		if(n == 1) { ans += R1; continue; }
		if(n == 2) { ans += R2; continue; }
		if(n == 3) { ans += R3; continue; }
		if(n == 4) { ans += R4; continue; }
		n -= 4;

		LD Sn = 1*c1 - sqrt(c2 + c1*k4);
		k4 = (Sn*Sn - c2) / c1;
		int flag = 0;
		if(round(k4,12) == round(k3,12))
		{
			Sn = 1*c1 + sqrt(c2 + c1*k4_copy);
			k4 = (Sn*Sn - c2) / c1;
			flag = 1;
		}
		if(k4 >= k4_copy)
			flag = 1;
		Sn = (n-1)*c1 - sqrt(c2 + c1*k4) * (flag ? -1 : 1);
		Sn = (Sn*Sn - c2)/c1;
		Sn = 1/Sn;
		ans += Sn;
		//printf("%.12f\n",(double)Sn);
	}
	printf("%.6f\n",(double)ans);
	return 0;
}
