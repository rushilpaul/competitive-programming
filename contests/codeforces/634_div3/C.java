import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
 
public class Solution {
 
    static int freq[] = new int[200002];
    static int singles = 0;
 
    public static void main(String args[]) {
 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
 
            int n = sc.nextInt();
            int ar[] = new int[n];
            Arrays.fill(freq, 0, n+1, 0);
            for(int i = 0; i < n; i++) {
                ar[i] = sc.nextInt();
                freq[ar[i]]++;
            }
 
            singles = 0;
            for(int i = 1; i <= n; i++)
                if(freq[i] >= 1)
                    singles++;
 
            // if x is possible
            int left = 1, right = n/2 * 2;
 
            while(left <= right) {
                int mid = (left + right) / 2;
                if(possible(ar, mid))
                    left = mid+1;
                else
                    right = mid-1;
            }
            System.out.println(right);
        }
    }
 
    static boolean possible(int ar[], int x) {
 
        if(x == 1)
            return true;
 
        for(int i = 0; i < ar.length; i++) {
            if (freq[ar[i]] >= x) {
                if(singles >= x && freq[ar[i]] - x >= 1)
                    return true;
                if(singles - 1 >= x)
                    return true;
            }
        }
        return false;
    }
}
