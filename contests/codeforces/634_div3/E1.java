import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    static int freq[][];	// 1 based
    static int A[];

    static void init() {

        freq = new int[A.length + 1][27];
        Arrays.fill(freq[0], 0);
        for(int i = 1; i < A.length; i++)
            for(int k = 1; k <= 26; k++)
                freq[i][k] = freq[i-1][k] + (A[i] == k ? 1 : 0);
    }

    static int getFreq(int i, int j, int k) {
        return freq[j][k] - freq[i-1][k];
    }

    static int solve() {

        int n = A.length - 1;
        int maxLen = 0;
        for(int k = 1; k <= 26; k++)	// take max of 1-palindromes
            maxLen = Math.max(maxLen, getFreq(1, n, k));

        for(int i = 1; i <= n; i++)
            for(int j = i+2; j <= n; j++)
                for(int k = 1; k <= 26; k++) {
                    if(A[i] == A[j]) {
                        int outerSize = 2 * Math.min(getFreq(1, i, A[i]), getFreq(j, n, A[i]));
                        maxLen = Math.max(maxLen, outerSize + getFreq(i+1, j-1, k));
                    }
                }
        return maxLen;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            A = new int[n + 1];
            for (int i = 1; i <= n; i++)
                A[i] = sc.nextInt();
            init();
            System.out.println(solve());
        }
    }
}


