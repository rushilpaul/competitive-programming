import java.io.*;
import java.util.*;

public class A {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            long k = sc.nextLong();

            long ans = k + ((k * y + k - 1) + x - 2) / (x - 1);
            System.out.println(ans);
        }
    }
}

