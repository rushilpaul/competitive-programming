import java.util.*;
import java.util.stream.Collectors;

public class GDSUB {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int mod = (int) 1e9 + 7;
        int n = sc.nextInt(), k = sc.nextInt();
        Map<Integer, Integer> F = new HashMap<>();

        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            F.merge(x, 1, Integer::sum);
        }
        List<Integer> A = F.values().stream().collect(Collectors.toList());
        n = A.size();
        k = Math.min(k, n);

        int dp[][] = new int[n+1][k+1];

        for(int i = 0; i <= k; i++)
            dp[0][i] = 1;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= k; j++) {
                dp[i][j] = (int) ( dp[i-1][j] + (j == 0 ? 0 : (long) dp[i-1][j-1] * A.get(i-1) % mod) );
                dp[i][j] %= mod;
            }

        System.out.println(dp[n][k]);
    }
}

