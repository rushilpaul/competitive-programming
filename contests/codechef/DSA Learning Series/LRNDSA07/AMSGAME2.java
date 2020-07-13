import java.util.*;
import java.util.stream.Collectors;

class Solution {

    static int gcd(int a, int b) {
        if(a == 0 || b == 0)
            return a + b;
        return gcd(b, a % b);
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Map<Integer, Long> dp[] = new Map[60];

        while(t-- > 0) {
            int n = sc.nextInt();
            int ar[] = new int[n];

            for(int i = 0; i < n; i++)
                ar[i] = sc.nextInt();

            Arrays.setAll(dp, (i) -> new HashMap<Integer, Long>(10000));
            dp[0].put(ar[0], 1L);

            for(int i = 1; i < n; i++) {

                dp[i].put(ar[i], 1L);
                for(int g : dp[i-1].keySet()) {
                    int newGcd = gcd(g, ar[i]);
                    dp[i].merge(newGcd, dp[i-1].get(g), Long::sum);
                    dp[i].merge(g, dp[i-1].get(g), Long::sum);
                }
            }
            if(dp[n-1].containsKey(1))
                System.out.println(dp[n-1].get(1));
            else
                System.out.println(0);
        }
   }

}

