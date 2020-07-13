import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class FROGV {

    static class Pair {
        int x, y;
        Pair(int x, int y) { this.x = x; this.y = y; }
        Pair() {}
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt(), P = sc.nextInt();
        Pair ar[] = new Pair[n];

        for(int i = 0; i < n; i++) {
            int pos = sc.nextInt();
            ar[i] = new Pair(pos, i);
        }
        Arrays.sort(ar, Comparator.comparingInt(A -> A.x));

        int label[] = new int[n];
        int pos[] = new int[n+1];
        label[0] = 1;
        pos[ar[0].y] = 0;

        for(int i = 1; i < n; i++) {
            pos[ar[i].y] = i;
            if(ar[i].x <= ar[i-1].x + k)
                label[i] = label[i-1];
            else
                label[i] = label[i-1] + 1;
        }

        while(P-- > 0) {
            int A = sc.nextInt() - 1, B = sc.nextInt() - 1;
            System.out.println(label[pos[A]] == label[pos[B]] ? "Yes" : "No");
        }
    }
}

