
import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = sc.nextInt();
            int ar[] = new int[n];
            for(int i = 0; i < n; i++)
                ar[i] = sc.nextInt();

            int lastD = ar[1] - ar[0], cur = 1;
            int ans = 2;

            for(int i = 1; i < n; i++) {

                int d = ar[i] - ar[i-1];
                if(d == lastD)
                    cur++;
                else {
                    cur = 2;
                }
                ans = Math.max(ans, cur);
                lastD = d;
            }
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
}

