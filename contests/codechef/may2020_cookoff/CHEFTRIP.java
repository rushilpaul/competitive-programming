import java.io.*;
import java.util.*;

class CHEFTRIP {

    // Seg-tree to find LCA

    static class Node {
        int minLeft, minRight, minVal;
        Node left = null, right = null;
    }

    static Node merge(Node left, Node right) {

        if(left == null)
            return right;
        if(right == null)
            return left;
        Node node = new Node();
        node.minVal = Math.min(left.minVal, right.minVal);
        if(left.minVal < right.minVal) {
            node.minLeft = left.minLeft;
            node.minRight = left.minRight;

        } else if(left.minVal > right.minVal) {
            node.minLeft = right.minLeft;
            node.minRight = right.minRight;

        } else {    // if they're both equal
            node.minLeft = left.minLeft;
            node.minRight = right.minRight;
        }
        return node;
    }

    static Node build(int i, int j) {

        if(i == j) {
            Node node = new Node();
            node.minVal = height.get(i);
            node.minLeft = node.minRight = i;
            return node;
        }
        int mid = (i + j) / 2;
        Node left = build(i, mid);
        Node right = build(mid+1, j);
        Node node = merge(left, right);
        node.left = left;
        node.right = right;
        return node;
    }

    static Node query(Node root, int i, int j, int L, int R) {

        if(L <= i && R >= j)
            return root;

        if(R < i || L > j)
            return null;

        int mid = (i + j) / 2;
        Node left = query(root.left, i, mid, L, R);
        Node right = query(root.right, mid + 1, j, L, R);
        return merge(left, right);
    }

    static int index[], turns[], parent[];
    static List<Integer> path, height;

    static void dfs(List<Integer> G[], int u, int parent, int h) {

        path.add(u);
        height.add(h);
        index[u] = height.size() - 1;

        for(int v : G[u]) {
            if(v != parent) {
                dfs(G, v, u, h+1);
                path.add(u);
                height.add(h);
            }
        }
    }

    static boolean isTurn(int A[], int u1, int u2, int u3) {
        return u1 >= 0 && u2 >= 0 && u3 >= 0 && ((A[u1] > A[u2] && A[u2] < A[u3]) || (A[u1] < A[u2] && A[u2] > A[u3]));
    }

    static void calc(List<Integer> G[], int A[], int u, int P1, int P2) {

        parent[u] = P1;
        if(P1 != -1)
            turns[u] = turns[P1];
        if(P1 != -1 && P2 != -1)
            turns[u] += (isTurn(A, u, P1, P2) ? 1 : 0);

        for(int v : G[u]) {
            if(v != P1)
                calc(G, A, v, u, P1);
        }
    }

    public static void main(String args[]) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(reader);

        int t = sc.nextInt();
        while(t-- > 0) {

            path = new ArrayList<>(200000);
            height = new ArrayList<>(200000);
            int n = sc.nextInt(), q = sc.nextInt();
            index = new int[n+1];
            turns = new int[n+1];
            parent = new int[n+1];

            List<Integer> G[] = new List[n + 1];
            Arrays.setAll(G, (i) -> new ArrayList<>());

            for (int i = 0; i < n - 1; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                G[u].add(v);
                G[v].add(u);
            }

            int A[] = new int[n+1];
            for(int i = 1; i <= n; i++)
                A[i] = sc.nextInt();

            dfs(G, 1, -1, 0);
            Node root = build(0, height.size() - 1);
            calc(G, A, 1, -1, -1);

            while (q-- > 0) {
                int u = sc.nextInt(), v = sc.nextInt();
                int indexU = index[u], indexV = index[v];
                if(indexU > indexV) {
                    int tmp = indexU;
                    indexU = indexV;
                    indexV = tmp;
                    tmp = u;
                    u = v;
                    v = tmp;
                }
                Node result = query(root, 0, height.size() - 1, indexU, indexV);
                int lca = path.get(result.minLeft);
                int ans = turns[u] + turns[v] - 2 * turns[lca];

                int leftChild = -1, rightChild = -1;
                if(result.minLeft - 1 >= 0)
                    leftChild = path.get(result.minLeft - 1);

                if(result.minRight + 1 < path.size())
                    rightChild = path.get(result.minRight + 1);

                boolean firstInc = true;

                if(lca == u || lca == v) {

                    int child = lca == u ? rightChild : leftChild;

                    if(A[lca] >= A[child])
                        firstInc = false;
                    if(isTurn(A, parent[lca], lca, child))
                        ans--;

                } else {

                    if(A[u] >= A[parent[u]])
                        firstInc = false;

                    if (isTurn(A, parent[lca], lca, leftChild))
                        ans--;
                    if (isTurn(A, parent[lca], lca, rightChild))
                        ans--;

                    if (isTurn(A, leftChild, lca, rightChild))
                        ans++;
                }
//                System.out.print(((ans == 1 && firstInc) || ans == 0) ? "1" : "0");
                writer.write(((ans == 1 && firstInc) || ans == 0) ? '1' : '0');
            }
            writer.write("\n");
        }
        writer.flush();
    }

}
