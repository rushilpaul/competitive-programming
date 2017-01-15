#include <stdio.h>
int main()
{
	int mod = 1000000007;
	int M[3][3] = { {1,1,1}, {1,0,0}, {0,1,0} };
	int n = ( (4*M[0][0])%mod + (2*M[0][1]) + M[0][2] ) % mod;
	return 0;
}