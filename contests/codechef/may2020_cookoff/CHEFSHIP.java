import java.util.Scanner;

class CHEFSHIP {

    static long mod = (int)1e9 + 7, p = 31;
    static long hashes[] = new long[100001];

    static long pow(long n, int p) {
        if(p == 0)
            return 1;
        long ans = pow(n, p / 2);
        ans = ans * ans % mod;
        if((p & 1) == 1)
            ans = ans * n % mod;
        return ans;
    }

    static long getSum(int i, int j) {
        long hash = i == 0 ? hashes[j] : hashes[j] - hashes[i-1];
        if(hash < 0)
            hash += mod;
        return hash;
    }

    static boolean hash(int i, int j) {

        int mid = (i + j) / 2;  // i, mid-1     mid, j
        int len = mid - i + 1;
        long initialP = pow(p, len);
        return initialP * getSum(i, mid) % mod == getSum(mid+1, j) % mod;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            char[] s = sc.next().toCharArray();
            int n = s.length;
            int ans = 0;

            long cur = 1;
            hashes[0] = s[0];
            for(int i = 1; i < n; i++) {
                cur = cur * p % mod;
                hashes[i] = (hashes[i-1] + cur * s[i]) % mod;
                if(hashes[i] < 0)
                    hashes[i] += mod;
            }

            for(int i = 2; i <= n-2; i+=2) {

                if(hash(0,i-1) && hash(i, n-1))
                    ans++;
            }
            System.out.println(ans);
        }
    }
}

