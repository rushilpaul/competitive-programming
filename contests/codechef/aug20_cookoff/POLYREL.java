import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            int n = sc.nextInt();
            for(int i = 0; i < n; i++) {
                sc.nextInt();
                sc.nextInt();
            }
            int ans = n;
            while(n >= 6) {
                n >>= 1;
                ans += n;
            }
            System.out.println(ans);
        }
    }
}

/**

 n <= 5, not possible
 n = 6, n = 3
 n = 7, n = 3
 n = 8, n = 4
 n = 9, n = 4
 n = 10, n = 5
 n = 11, n = 5
 n = 12, n = 6
 f(n) = 0, for n <= 5
       f(n) = n + f(n/2) otherwise
**/
