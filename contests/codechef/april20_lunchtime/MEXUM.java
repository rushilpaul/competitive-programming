import java.util.*;

class Solution {

    static int mod = 998244353;

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        long powers[] = new long[100001];
        powers[0] = 1;
        for(int i = 1; i <= 100000; i++)
            powers[i] = (powers[i-1] * 2) % mod;

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int ar[] = new int[n];
            Map<Integer, Integer> freq = new HashMap<>();
            for(int i = 0; i < n; i++) {
                ar[i] = sc.nextInt();
                freq.merge(ar[i], 1, Integer::sum);
            }
            Arrays.sort(ar);

            long ans = 1;
            int cum = 0;
            for(int i = 0; i < n; i++) {
                if(ar[i] > 1)
                    cum++;
                int size = n - i - 1;
                if(ar[i] > 1)
                    ans = (ans + powers[size]) % mod;
            }

            long numberOfWays[] = new long[n+1];
            if(freq.containsKey(1))
                numberOfWays[1] = powers[freq.get(1)] - 1;
            for(int i = 2; i <= n; i++) {
                if(!freq.containsKey(i))
                    break;
                numberOfWays[i] = numberOfWays[i-1] * (powers[freq.get(i)] - 1) % mod;
            }

            for(int mex = 2; mex <= n + 1; mex++) {

                // exclude mex
                if(!freq.containsKey(mex-1))
                    break;
                if(freq.containsKey(mex))
                    cum -= freq.get(mex);
                ans = (ans + numberOfWays[mex-1] * powers[cum] % mod * mex % mod) % mod;
            }

            if(ans < 0)
                ans += mod;
            System.out.println(ans);
        }
    }

}

