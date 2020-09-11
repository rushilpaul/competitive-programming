import java.util.Arrays;
import java.util.Scanner;

public class F {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        char s[] = sc.next().toCharArray();
        String t = sc.next();
        char first = t.charAt(0);
        char second = t.charAt(1);

        int dp[][][] = new int[n+1][n+1][k+1];
        for(int i = 0; i < dp.length; i++)
            for(int x = 0; x < dp[0].length; x++)
                Arrays.fill(dp[i][x], Integer.MIN_VALUE);
        dp[0][0][0] = 0;

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int c = 0; c <= i; c++) {
                for(int op = 0; op <= k; op++) {

                    char cur = s[i-1];
                    int e1 = cur == first ? 1 : 0;
                    int e2 = cur == second ? 1 : 0;
                    int e12 = first == second ? 1 : 0;
//                    // we put 'first'
                    if(c > 0 && op > 0)
                        dp[i][c][op] = Math.max(dp[i][c][op], dp[i-1][c-1][op-1]);

                    // then we put 'second'
                    if(op > 0 && c - e12 >= 0)
                        dp[i][c][op] = Math.max(dp[i][c][op], dp[i-1][c - e12][op-1] + c - e12);

                    // or we leave it as it is
                    if(c - e1 >= 0)
                        dp[i][c][op] = Math.max(dp[i][c][op], dp[i-1][c - e1][op] + (e2 == 1 ? c - e1 : 0));

                    ans = Math.max(ans, dp[i][c][op]);
                }
            }
        System.out.println(ans);
    }
}

