import com.google.inject.internal.util.$ToStringBuilder;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Facebook Hacker Cup 2020 qualifiers
 * https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/D1
 * O(N * M)
 *
 * dp[i][g] = min cost of reaching target city from ith city with g units of gas
 * dp[i][g] = min( dp[i+1][g-1], dp[i+1][m-1] + C[i])
 *
 * Alternate solution
 * dp[i] = min cost of reaching target from city i starting with full tank if C[i] > 0, else INF
 * dp[i] = if cost[i] > 0: min( ans[j] ) for all j E (i+1, i+m)
 *         else INF
 */
class Solution2 {

    static int cost[] = new int[1000001];

    static class Node {
        Node left, right;
        long val;
        Node(long val) { this.val = val; }
        Node() {}
    }

    static Node build(int i, int j) {
        if(i == j) {
            return new Node(Long.MAX_VALUE);
        }
        int mid = (i + j) / 2;
        Node left = build(i, mid);
        Node right = build(mid+1, j);
        Node root = new Node(Math.min(left.val, right.val));
        root.left = left;
        root.right = right;
        return root;
    }

    static Node findMin(Node root, int i, int j, int L, int R) {

        if (R < i || L > j)
            return new Node(Long.MAX_VALUE);
        if (L <= i && R >= j)
            return root;

        int mid = (i + j) / 2;
        Node left = findMin(root.left, i, mid, L, R);
        Node right = findMin(root.right, mid+1, j, L, R);
        Node ans = new Node(Math.min(left.val, right.val));
        return ans;
    }

    // point update
    static void update(Node root, int i, int j, int pos, long val) {

        if (pos < i || pos > j)
            return;
        if(i == j) {
            root.val = val;
            return;
        }
        int mid = (i + j) / 2;
        update(root.left, i, mid, pos, val);
        update(root.right, mid+1, j, pos, val);
        root.val = Math.min(root.left.val, root.right.val);
    }

    static int n, m;

//    static long solve(int i, int g) {
//
//        if(g < 0) return -1;
//        if(i == n-1)
//            return 0;
//
//        if(dp[i][g] != -2)
//            return dp[i][g];
//
//        long cost1 = solve(i+1, g - 1);
//        long cost2 = solve(i+1, m - 1);
//        long minCost = Long.MAX_VALUE;
//        if(cost1 >= 0)
//            minCost = cost1;
//        if(cost2 >= 0 && cost[i] > 0)
//            minCost = Math.min(minCost, cost2 + cost[i]);
//
//        if(minCost == Long.MAX_VALUE)
//            minCost = -1;
//        return dp[i][g] = minCost;
//    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            n = sc.nextInt();
            m = sc.nextInt();
            for(int i = 0; i < n; i++)
                cost[i] = sc.nextInt();
            cost[0] = 1;

            long ans = Long.MAX_VALUE;
            Node root = build(0, n-1);
            update(root, 0, n-1, n-1, 0);

            for(int i = n-2; i >= 0; i--) {
                if (cost[i] == 0)
                    continue;
                long min = findMin(root, 0, n - 1, i + 1, i + m).val;
                ans = min;
                if (ans == Long.MAX_VALUE)
                    continue;
                ans += cost[i];
                update(root, 0, n - 1, i, ans);
            }
            if(ans == Long.MAX_VALUE)
                ans = -1;
            else
                ans--;
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
}

