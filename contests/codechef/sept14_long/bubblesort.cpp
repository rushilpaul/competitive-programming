#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 105;
 
int n, test, a[N];
double g[N * N], g2[N * N], f[N][N * N], dp[N];
 
void work() {
	scanf("%d", &n);
	int MAX = n * (n - 1) / 2;
	long long kk;
	cin >> kk;
	int k = min(kk, (long long)MAX);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j < i; j++) {
			if (a[j] > a[i]) {
				s++;
			}
		}
	}
	
	if (k == 0) {
		printf("%.12f\n", (double)s);
		return;
	}
	
	g[0] = f[n][0];
	g2[0] = 0.0;
	for (int i = 1; i <= MAX; i++) {
		g[i] = g[i - 1] + f[n][i];
		g2[i] = g2[i - 1] + (double)f[n][i] * i;
	}
		
	dp[1] = 0.0;
	for (int i = 0; i <= MAX; i++) {
		dp[1] += f[n][i] * (double)i;
	}
	
	for (int i = 2; i <= k; i++) {
		int x = (int)(dp[i - 1] + (double)i - 1.0);
		x = min(MAX, x);
		dp[i] = g2[x] - g2[i - 1] - (g[x] - g[i - 1]) * (double)(i - 1);
		dp[i] += (g[MAX] - g[x]) * dp[i - 1];
	}
	
	printf("%.12f\n", min(dp[k], max(0.0, (double)(s - k))));
}
 
int main() {
	f[1][0] = 1.0;
	for (int i = 2; i <= 100; i++) {
		int s = i * (i - 1) / 2;
		g[0] = f[i - 1][0];
		for (int j = 1; j <= s; j++) {
			g[j] = g[j - 1] + f[i - 1][j];
		}
		
		for (int j = 0; j <= s; j++) {
			f[i][j] = g[j];
			if (j >= i) {
				f[i][j] -= g[j - i];
			}
			
			f[i][j] /= (double)i;
		}
	}
	
	scanf("%d", &test);
	while (test--) {
		work();
	}
	
	return 0;
}