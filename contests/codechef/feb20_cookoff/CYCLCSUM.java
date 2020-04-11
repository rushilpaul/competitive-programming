import java.util.*;

class Main
{
    static int n;

    public static long max(long... ar)
    {
        long ans = ar[0];
        for(long i : ar)
            ans = Math.max(ans, i);
        return ans;
    }

    static Long[] maxSubArraySum(Integer ar[])
    {
        long max_so_far = Long.MIN_VALUE, max_ending_here = 0;
        Long mxSum[] = new Long[n];

        for (int i = 0; i < n; i++)
        {
            max_ending_here = max_ending_here + ar[i];
            max_so_far = max(max_so_far, max_ending_here);
            mxSum[i] = max_so_far;

            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return mxSum;
    }

    static Long[] maxSubArraySumBackward(Integer ar[])
    {
        long max_so_far = Long.MIN_VALUE, max_ending_here = 0;
        Long mxSum[] = new Long[n];

        for (int i = n-1; i >= 0; i--)
        {
            max_ending_here = max_ending_here + ar[i];
            max_so_far = max(max_so_far, max_ending_here);
            mxSum[i] = max_so_far;

            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return mxSum;
    }

    public static Long[] getMxCumSum(Integer ar[])
    {
        Long C[] = new Long[n];
        C[0] = (long) ar[0];
        for(int i = 1; i < n; i++)
            C[i] = C[i-1] + ar[i];

        for(int i = 1; i < n; i++)
            C[i] = max(C[i], C[i-1]);

        return C;
    }

    public static Long[] getMxCumSumBackward(Integer ar[])
    {
        Long C[] = new Long[n];
        C[n-1] = (long) ar[n-1];
        for(int i = n-2; i >= 0; i--)
            C[i] = C[i+1] + ar[i];

        for(int i = n-2; i >= 0; i--)
            C[i] = max(C[i], C[i+1]);

        return C;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0)
        {
            t -= 1;
            n = sc.nextInt();
            Integer ar[] = new Integer[n];
            for(int a=0;a<n;a++)
                ar[a] = sc.nextInt();

            Long mxSumF[] = maxSubArraySum(ar); // mxSumF[i] = max sum of all subarrays A[0..i]

            Long mxSumB[] = maxSubArraySumBackward(ar); // mxSumB[i] = max sum of all subarrays from A[i..n]

            Long C_F[] = getMxCumSum(ar);   // C_F[i] = max( prefix_sum(0..i) )

            Long C_B[] = getMxCumSumBackward(ar);   // C_B[i] = max( suffix_sum(i..n-1) )

            long ans;
            for(int i = 0; i < n; i++)
            {
                ans = max(i > 0 ? mxSumF[i-1] : Long.MIN_VALUE, mxSumB[i], (i > 0 ? C_F[i-1] + C_B[i] : C_B[i]) );
                System.out.print(ans + " ");
            }
            System.out.println();
        }
    }
}


