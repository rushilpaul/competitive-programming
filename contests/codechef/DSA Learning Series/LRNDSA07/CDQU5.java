import java.util.Scanner;

public class CDQU5 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int mod = (int)1e9 + 9;

        int dp[] = new int[1000001];
        dp[2] = dp[3] = 1;
        for(int i = 4; i <= 1000000; i++)
            dp[i] = (dp[i-2] + dp[i-3]) % mod;

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            System.out.println(dp[n]);
        }
    }
}

