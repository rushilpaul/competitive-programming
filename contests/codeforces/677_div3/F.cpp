#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int readint() {
    int x; scanf("%d", &x);
    return x;
}

void println(int x) {
    printf("%d\n", x);
}

int main() {

    int n = readint(), m = readint(), k = readint();
    int ar[70][70];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ar[i][j] = readint();

    if(m == 1) {
        println(0);
        return 0;
    }

    int sums[70][70];
    for(int i = 0; i < 70; i++)
        fill(sums[i], sums[i] + 70, INT_MIN);

    for(int i = 0; i < n; i++) {

        int remSum[70][70][70];
        for(int j = 0; j < 70; j++)
            for (int cnt = 0; cnt < 70; cnt++) {
                fill(remSum[j][cnt], remSum[j][cnt] + 70, INT_MIN);
                remSum[j][0][0] = 0;
            }

        for(int j = 0; j < m; j++)
            remSum[j][ar[i][j] % k][1] = ar[i][j];

        for (int j = 1; j < m; j++)
            for (int cnt = 1; cnt <= m / 2; cnt++) {
                for(int r = 0; r < k; r++) {

                    int rem = (ar[i][j] + r) % k;
                    remSum[j][rem][cnt] = max(remSum[j][rem][cnt], remSum[j - 1][r][cnt - 1] + ar[i][j]);
                    remSum[j][r][cnt] = max(remSum[j][r][cnt], remSum[j-1][r][cnt]);
                }
            }
        for(int r = 0; r < k; r++)
            for(int cnt = 0; cnt < m; cnt++)
                sums[i][r] = max(sums[i][r], remSum[m - 1][r][cnt]);
    }

    int dp[70][70];
    for(int i = 0; i < 70; i++)
        fill(dp[i], dp[i] + 70, INT_MIN);

    for(int r = 0; r < k; r++)
        dp[0][r] = sums[0][r];

    for(int i = 1; i < n; i++) {
        for(int R = 0; R < k; R++) {
            for(int r = 0; r < k; r++) {
                int rem = (R + r) % k;
                if(dp[i-1][r] >= 0 && sums[i][R] >= 0)
                    dp[i][rem] = max(dp[i][rem], dp[i-1][r] + sums[i][R]);
            }
        }
    }
    println(dp[n-1][0]);
}

