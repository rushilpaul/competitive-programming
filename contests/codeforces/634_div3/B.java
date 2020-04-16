import java.util.Scanner;
 
public class Solution {
 
    public static void main(String args[]) {
 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
            StringBuilder sb = new StringBuilder();
 
            for (int i = 0; i < b; i++)
                sb.append((char) (i + 'a'));
 
            for (int i = b; i < a; i++)
                sb.append(sb.charAt(i - b));
 
            for (int i = a; i < n; i++)
                sb.append(sb.charAt(i - a));
 
            System.out.println(sb.toString());
        }
    }
}
