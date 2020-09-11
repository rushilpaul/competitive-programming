import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
public class B {
 
    public static void main(String args[]) {
 
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tt = 1; tt <= T; tt++) {
 
            int n = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
            List<Integer> factors = new ArrayList<>();
            int diff = y - x;
            for(int i = 1; i <= diff; i++)
                if(diff % i == 0)
                    factors.add(i);
 
            List<Integer> ans = new ArrayList<>();
            boolean done = false;
 
            for(int d : factors) {
                int p = (y - x) / d + 1;
                int r = n - p;
                if(r < 0)
                    continue;
 
                if(p == n && y - (n-1) * d > 0) {
                    done = true;
                    for(int j = x; j <= y; j += d)
                        System.out.print(j + " ");
                    System.out.println();
                    break;
                }
                if(p <= n) {
 
                    List<Integer> list = new ArrayList<>();
                    int val = x - d;
                    while(val > 0 && r > 0) {
                        r--;
                        list.add(val);
                        val -= d;
                    }
                    for(int i = x; i <= y; i += d)
                        list.add(i);
                    val = y + d;
                    while(r > 0) {
                        r--;
                        list.add(val);
                        val += d;
                    }
                    if(ans.size() == 0 || Collections.max(list) < Collections.max(ans))
                        ans = list;
                }
            }
            if(done)
                continue;
            else {
                for(int i : ans)
                    System.out.print(i + " ");
                System.out.println();
            }
        }
    }
 
}
