import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int ar[] = new int[n];
            for (int i = 0; i < n; i++)
                ar[i] = sc.nextInt();
            for (int i = n - 1; i >= 0; i--)
                System.out.print(ar[i] + " ");
            System.out.println();
        }
    }
}

