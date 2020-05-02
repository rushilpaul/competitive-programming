import java.util.*;

class Node {
    int minId;
    Node left, right;
    Node(int id, Node left, Node right) { minId = id; this.left = left; this.right = right; }
}

class Solution {

    static List<Integer> path = new ArrayList();
    static List<Integer> depths = new ArrayList();
    static Map<Integer, Integer> indexByNode = new HashMap();
    static Map<Integer, Integer> factors[] = new Map[100001];
    static List<Integer> tree[] = new List[100001];
    static int values[] = new int[100001];

    // build a seg-tree out of depths
    static Node build(int x, int y) {

        if(x == y)
            return new Node(x, null, null);

        int mid = (x + y) / 2;
        Node left = build(x, mid);
        Node right = build(mid+1, y);
        if(depths.get(left.minId) < depths.get(right.minId))
            return new Node(left.minId, left, right);
        else
            return new Node(right.minId, left, right);
    }

    static int query(Node root, int x, int y, int Qx, int Qy) {

        if(Qy < x || Qx > y)
            return -1;
        if(Qx <= x && Qy >= y)
            return root.minId;

        int mid = (x + y) / 2;
        int left = query(root.left, x, mid, Qx, Qy);
        int right = query(root.right, mid+1, y, Qx, Qy);
        if(left == -1)
            return right;
        else if(right == -1)
            return left;
        if(depths.get(left) < depths.get(right))
            return left;
        else
            return right;
    }

    static int lca(Node root, int u, int v) {
        u = indexByNode.get(u);
        v = indexByNode.get(v);
        if(u > v) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        int lcaIndex = query(root, 0, depths.size() - 1, u, v);
        assert(lcaIndex >= 0 && lcaIndex < depths.size());
        return path.get(lcaIndex);
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt();
            for(int i = 0; i < n; i++) {
                tree[i] = new ArrayList<>();
                factors[i] = new HashMap<>();
            }

            for(int i = 0; i < n-1; i++) {

                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                tree[u].add(v);
                tree[v].add(u);
            }
            for(int i = 0; i < n; i++)
                values[i] = sc.nextInt();

            path.clear();
            depths.clear();
            indexByNode.clear();

            dfs(0, -1, 0);
            Node root = build(0, depths.size() - 1);
            final int mod = 1000000007;

            int Q = sc.nextInt();
            while(Q-- > 0) {

                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;

                int LCA = lca(root, u, v);
                Map<Integer, Integer> lcaFactorsRoot = factors[LCA];
                Map<Integer, Integer> product = merge(factors[u], factors[v]);
                // remove LCA
                for(int i : lcaFactorsRoot.keySet())
                    product.merge(i, -2 * lcaFactorsRoot.get(i), Integer::sum);

                Map<Integer, Integer> lcaFactors = getPrimeFactors(values[LCA]);
                for(int i : lcaFactors.keySet())
                    product.merge(i, lcaFactors.get(i), Integer::sum);

                long ans = 1;
                for(int p : product.keySet())
                    ans = ans * (product.get(p) + 1) % mod;
                System.out.println(ans);
            }
        }
    }

    static Map<Integer, Integer> merge(Map<Integer, Integer> m1, Map<Integer, Integer> m2) {

        Map<Integer, Integer> product = new HashMap(m1);
        for(int i : m2.keySet())
            product.merge(i, m2.get(i), Integer::sum);
        return product;
    }

    static Map<Integer, Integer> getPrimeFactors(int n) {

        Map<Integer, Integer> F = new HashMap();
        for(int i = 2; i*i <= n; i++) {
            int s = 0;
            while(n % i == 0) {
                n /= i;
                s++;
            }
            if(s > 0)
                F.put(i, s);
        }
        if(n > 1)
            F.put(n, 1);
        return F;
    }


    static void dfs(int u, int parent, int depth) {

        path.add(u);
        depths.add(depth);
        if(!indexByNode.containsKey(u))
            indexByNode.put(u, path.size() - 1);

        Map factorsU = getPrimeFactors(values[u]);
        if(parent != -1)
            factors[u] = merge(factorsU, factors[parent]);
        else
            factors[u] = factorsU;

        for(int v : tree[u]) {
            if(v != parent) {
                dfs(v, u, depth + 1);
                path.add(u);
                depths.add(depth);
            }
        }
    }
}

