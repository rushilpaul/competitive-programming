import java.util.Scanner;

public class B {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tt = 1; tt <= T; tt++) {

            int a = sc.nextInt(), b = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt(), n = sc.nextInt();
            if (a < b) {
                int t = a;
                a = b;
                b = t;
                t = x;
                x = y;
                y = t;
            }
            if (a == b && x < y) {
                int t = x;
                x = y;
                y = t;
            }
            System.out.println(Math.min(f1(a,b,x,y,n), f2(a,b,x,y,n)));
        }
    }

    static long f1(int a, int b, int x, int y, int n) {
        int diff = Math.min(n, b - y);
        b -= diff;
        n -= diff;
        diff = Math.min(n, a - x);
        a -= diff;
        n -= diff;
        return (long) a * b;
    }

    static long f2(int a, int b, int x, int y, int n) {
        int diff = Math.min(n, a - x);
        a -= diff;
        n -= diff;
        diff = Math.min(n, b - y);
        b -= diff;
        n -= diff;
        return (long) a * b;
    }

}
