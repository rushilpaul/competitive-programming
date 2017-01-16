#include <bits/stdc++.h>
typedef long long LL;
typedef long double LD;

void mul(LD A[2][2], LD B[2][2], LD C[2][2])
{
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
		{
			C[a][b] = 0;
			for(int c=0;c<2;c++)
				C[a][b] += A[a][c] * B[c][b];
		}
}

void invMAT(LD M[2][2], LD res[2][2])
{
	LD det = M[0][0] * M[1][1] - M[0][1] * M[1][0];
	assert(det != 0);
	res[0][0] = M[1][1]/det;
	res[0][1] = -M[0][1]/det;
	res[1][0] = -M[1][0]/det;
	res[1][1] = M[0][0]/det;
}

void f(int n, LL &s, LD M[2][2])
{
	LD P[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824LL, 2147483648LL, 4294967296LL };
	int flag = (n >= 0);
	n = abs(n);
	LD two = sqrt(2.0), six = sqrt(6.0);
	LD k1 = two - six, k2 = two + six;
	LD base[2][2] = { {k1,k2}, {k2,-k1} };
	
	int i = 0;
	while(n>0)
	{
		if(n&1)
		{
			LL exp = 1LL<<(i+1);
			if(i > 0 and s > 0 and flag)
			{
				LL sub = std::min(s,exp);
				s -= sub;
				exp -= sub;
			}
			else if(i > 0 and s < 0 and !flag)
			{
				LL sub = std::min(-s,exp);
				s += sub;
				exp -= sub;
			}
			LD tmp[2][2] = { {P[exp],0}, {0,P[exp]} };
			LD res[2][2];
			if(i == 0)
				mul(M,base,res);
			else
				mul(M,tmp,res);
			M[0][0] = res[0][0];
			M[0][1] = res[0][1];
			M[1][0] = res[1][0];
			M[1][1] = res[1][1];
		}
		i++;
		n >>= 1;
	}
}

int main()
{
	int i,k;
	LL s,cpy;
	scanf("%d %d %lld",&i,&k,&s);
	cpy = abs(s);
	LD ai, bi;
	scanf("%Lf %Lf",&ai,&bi);
	LD M[2][2] = { {1,0}, {0,1} };
	f(k-i,s,M);
	if(k-i < 0)
	{
		LD tmp[2][2];
		// tmp = inv(M)
		invMAT(M,tmp);
		for(int a=0;a<2;a++)
			for(int b=0;b<2;b++)
				M[a][b] = tmp[a][b];
	}
	LD ans = ai * (M[0][0] + M[0][1]) + bi * (M[1][0] + M[1][1]), tmp;
	if(s < 0 and abs(s) >= 63)
	{
		assert(abs(i-k) > 1e9 - 10);
	}
	while(s != 0)
	{
		tmp = ans;
		if(s > 0)
			ans /= 2;
		else
			ans *= 2;
		s = (s > 0 ? s-1 : s+1);
		if(fabs(ans-tmp) < 0.001)
			break;
	}
	printf("%Lf\n",ans);
	return 0;
}

