import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
    static int n;

    static int[][] mul(int A[][], int B[][]) {
        int C[][] = new int[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++)
                    C[i][j] = C[i][j] ^ (A[i][k] & B[k][j]);
                C[i][j] = C[i][j] & 1;
            }
        return C;
    }

    static int[][] pow(int M[][], int p) {
        if(p == 1) {
            return M;
        }
        int root[][] = pow(M, p / 2);
        root = mul(root, root);
        if((p & 1) == 1)
            root = mul(root, M);
        return root;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            n = sc.nextInt();
            int k = sc.nextInt() - 1;
            long A[] = new long[n];
            int M[][] = new int[n][n];

            for(int i = 0; i < n; i++)
                A[i] = sc.nextLong();

            for(int i = 0; i < n; i++) {
                int L = sc.nextInt() - 1;
                int R = sc.nextInt() - 1;

                for(int j = L; j <= R; j++)
                    M[j][i] = 1;
            }
            if(k == 0)
                for(int i = 0; i < n; i++)
                    System.out.print(A[i] + " ");
            else {
                M = pow(M, k);
                for (int i = 0; i < n; i++) {
                    long ans = 0;
                    for (int j = 0; j < n; j++)
                        ans = ans ^ ((M[j][i] & 1) == 1 ? A[j] : 0);
                    System.out.print(ans + " ");
                }
            }
            System.out.println();
        }
    }
}

