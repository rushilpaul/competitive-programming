import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution {

    static int solve(int A[]) {	// 1-based Array

        int n = A.length - 1;
        List<Integer> pos[] = new ArrayList[201];
        for(int i = 1; i <= n; i++) {
            if(pos[A[i]] == null)
                pos[A[i]] = new ArrayList();
            pos[A[i]].add(i);
        }

        int freq[][] = new int[n+1][201];
        Arrays.fill(freq[0], 0);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 200; j++)
                freq[i][j] = freq[i-1][j] + (A[i] == j ? 1 : 0);

        int ans = 1;
        for(int c = 1; c <= 200; c++) {
            if(pos[c] == null)
                continue;
            // iterate over the first half of each array
            for(int k = 1; k <= pos[c].size() / 2; k++) {
                int innerMax = 0;
                int L = pos[c].get(k-1) + 1;
                int R = pos[c].get(pos[c].size() - k) - 1;
                for(int j = 1; j <= 200; j++)
                    innerMax = Math.max(innerMax, freq[R][j] - freq[L-1][j]);
                ans = Math.max(ans, innerMax + k * 2);
            }
        }
        return ans;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int A[] = new int[n + 1];
            for (int i = 1; i <= n; i++)
                A[i] = sc.nextInt();
            System.out.println(solve(A));
        }
    }
}


