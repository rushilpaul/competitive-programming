import java.util.Scanner;

public class KPRIME {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int max = 100000;
        int A[] = new int[max + 1];
        for(int i = 2; i <= max; i++) {
            if(A[i] > 0)
                continue;
            for(int j = i; j <= max; j+=i)
                A[j]++;
        }

        int dp[][] = new int[max + 1][6];
        for(int k = 1; k <= 5; k++)
        for(int i = 2; i <= max; i++) {
                if(A[i] == k)
                    dp[i][k] = 1;
                dp[i][k] += dp[i-1][k];
        }

        int t = sc.nextInt();
        while(t-- > 0) {
            int L = sc.nextInt(), R = sc.nextInt(), k = sc.nextInt();
            System.out.println(dp[R][k] - dp[L-1][k]);
        }
    }
}

