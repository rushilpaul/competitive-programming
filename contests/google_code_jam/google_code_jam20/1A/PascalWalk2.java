// Q: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
import java.util.*;

class Solution
{
    static long f4[] = new long[500];

    static long f3(long n) {
        return (n * (n + 1) * (2 * n + 1) + 3 * n * ( n + 1)) / 12;
    }

    static long f2(long n) {
        return n * (n + 1) / 2;
    }

    public static void main(String args[]) {

        f4[0] = 0;
        for(int i = 1; i < 500; i++)
            f4[i] = f4[i-1] + f3(i);

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            int n = sc.nextInt();
            System.out.printf("Case #%d:\n", t);
            if(n <= 20) {
                for(int i = 1; i <= n; i++)
                    System.out.printf("%d %d\n", i, i);
                continue;
            }
            for(int i = 1; i <= 4; i++)
                System.out.printf("%d %d\n", i, i);
            n -= 4;

            int term = 1;
            int row = 5;
            while(n - f4[term] - f3(term + 1) - f2(term + 2) - (term + 3) >= 1) {

                n -= f4[term];
                System.out.printf("%d %d\n", row, 5);
                term++;
                row++;
            }
            row--; term--;
            term++;

            while(n - f3(term) - f2(term + 1) - (term + 2) >= 1 && term >= 2) {

                n -= f3(term);
                System.out.printf("%d %d\n", row, 4);
                term--;
                row--;
            }
            row++; term++;
            term++;

            while(n - f2(term) - (term + 1) >= 1) {

                n -= f2(term);
                System.out.printf("%d %d\n", row, 3);
                term++;
                row++;
            }
            row--; term--;
            term++;

            while(n - term >= 0 && term >= 2) {
                n -= term;
                System.out.printf("%d %d\n", row, 2);
                term--;
                row--;
            }
            row++; term++;
            term++;

            for(int i = 1; i <= n; i++)
                System.out.printf("%d %d\n", row++, 1);
        }
    }
}
