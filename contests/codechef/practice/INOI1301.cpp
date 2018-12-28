// Problem link: https://www.codechef.com/INOIPRAC/problems/INOI1301
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;

#define MAX 1000010

int n,k, A[MAX];
LL F[MAX], B[MAX];

void forward()
{
	F[k] = 0;
	F[k+1] = A[k+1];
	for(int i = k+2; i < n; i++)
		F[i] = A[i] + max(F[i-1], F[i-2]);
}

void backward()
{
	B[0] = 0;
	B[1] = A[0];
	for(int i = 2; i < n; i++)
		B[i] = max( A[i-1] + B[i-1], A[i-2] + B[i-2] );
}

int main()
{
	scanf("%d %d",&n, &k);
	k--;
	for(int a=0;a<n;a++)
		scanf("%d",&A[a]);

	forward(); backward();

	LL ans = LLONG_MIN;
	for(int i = n-1; i >= k; i--)
		ans = max(ans, F[i] + B[i]);

	printf("%lld\n", ans);
	return 0;
}
