import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

class Solution {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0) {
            int n = scanner.nextInt();
            int ar[] = new int[n];
            int freq[] = new int[11];

            for(int i =0; i < n; i++) {
                ar[i] = scanner.nextInt();
                freq[ar[i]]++;
            }
            TreeMap<Integer, Integer> map = new TreeMap<>();
            for(int i = 0; i < 11; i++)
                if(freq[i] > 0)
                    map.merge(freq[i], 1, Integer::sum);

            int ans = 0, max_f = Integer.MIN_VALUE;
            for(int f : map.keySet()) {
                int val = map.get(f);
                if(val > max_f) {
                    max_f = val;
                    ans = f;
                }
            }
            System.out.println(ans);
        }
    }
}

