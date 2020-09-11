import java.util.Scanner;
 
public class A {
 
    public static void main(String args[]) {
 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int tt = 1; tt <= t; tt++) {
 
            int a = sc.nextInt(), b = sc.nextInt();
            int diff = Math.abs(a - b);
            int ans = diff / 10;
            if(diff % 10 != 0)
                ans++;
            System.out.println(ans);
        }
    }
 
}
