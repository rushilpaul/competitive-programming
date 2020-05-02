import java.util.*;

class Node {
    int minId;
    Node left, right;
    Node(int id, Node left, Node right) { minId = id; this.left = left; this.right = right; }
}

class Query {
    int L, R, id, ans = 1, lca;
}

class Solution {

    static int n;
    static final int mod = 1000000007;
    static final int MAXN = 200001;
    static List<Integer> path = new ArrayList();
    static List<Integer> depths = new ArrayList();
    static Map<Integer, Integer> indexByNode = new HashMap();
    static Map<Integer, Integer> factors[] = new Map[MAXN];
    static List<Integer> tree[] = new List[MAXN];
    static int values[] = new int[MAXN];

    // For Mo's algorithm
    static int cur = 0;
    static int ID[] = new int[MAXN];    // flattened out DFS pre-order traversal of tree
    static int start[] = new int[MAXN >> 1];    // start time of each node
    static int end[] = new int[MAXN >> 1];    // end time of each node
    static int singleValues[] = new int[MAXN];
    static List<Query> queries = new ArrayList<>(MAXN >> 1);
    static int nodeFreq[] = new int[MAXN];

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

            n = sc.nextInt();
            for(int i = 0; i < n; i++) {
                tree[i] = new ArrayList<>();
                factors[i] = new HashMap<>();
                nodeFreq[i << 1] = nodeFreq[(i << 1) + 1] = 0;
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

            int Q = sc.nextInt();
            for(int q = 0; q < Q; q++) {

                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;

                Query query = new Query();
                query.id = q;

                if(start[u] > start[v]) {
                    int tmp = u;
                    u = v;
                    v = tmp;
                }
                int LCA = lca(root, u, v);
                query.lca = LCA;
                if(LCA == u) {
                    query.L = start[u];
                    query.R = start[v];
                } else {
                    query.L = end[u];
                    query.R = start[v];
                }

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
                query.ans = (int) ans;

                queries.add(query);
            }

            int blockSize = (int) Math.sqrt(2 * n);
            Collections.sort(queries, (q1, q2) -> {
               int blockQ1 = q1.L / blockSize;
               int blockQ2 = q2.L / blockSize;
               return blockQ1 == blockQ2 ? q1.R - q2.R : blockQ1 - blockQ2;
            });

            compute();
        }
    }

    static long add(int freq[], int prime) {

        long ans = power(freq[prime] + 1, mod - 2);
        freq[prime]++;
        return ans * (freq[prime] + 1) % mod;
    }

    static long remove(int freq[], int prime) {

        long ans = power(freq[prime] + 1, mod - 2);
        freq[prime]--;
        return ans * (freq[prime] + 1) % mod;
    }

    static long update(int freq[], int x, boolean add) {

        // If (x) occurs twice, then don't consider its value
        int val = singleValues[x];
        if(val == 1)
            return 1;
        long ans = 1;

        if(add)
            nodeFreq[x]++;
        else
            nodeFreq[x]--;

        if (!add && nodeFreq[x] == 0)
            ans = remove(freq, val);

        else if(!add && nodeFreq[x] == 1)
            ans = add(freq, val);

        else if(add && nodeFreq[x] == 1)
            ans = add(freq, val);

        else if(add && nodeFreq[x] == 2)
            ans = remove(freq, val);
	    return ans;
    }

    static void compute() {

        // Perform standard Mo's Algorithm
        int curL = queries.get(0).L, curR = curL - 1;
        int freq[] = new int[1000001];
        for(int i = 0; i < 1000001; i++)
            freq[i] = 0;
        long ans = 1;

        for(Query query : queries) {

            while (curL < query.L)
                ans = ans * update(freq, ID[curL++], false) % mod;
            while (curL > query.L)
                ans = ans * update(freq, ID[--curL], true) % mod;
            while (curR < query.R)
                ans = ans * update(freq, ID[++curR], true) % mod;
            while (curR > query.R)
                ans = ans * update(freq, ID[curR--], false) % mod;

            int u = ID[curL], v = ID[curR];

            // Case 2
            if (query.lca != u && query.lca != v)
                ans = ans * update(freq, query.lca, true) % mod;

            query.ans = (int)((long) query.ans * ans % mod);

            if (query.lca != u && query.lca != v)
                ans = ans * update(freq, query.lca, false) % mod;
        }

        Collections.sort(queries, Comparator.comparingInt(q -> q.id));

        for(Query query : queries)
            System.out.println(query.ans);
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

        start[u] = cur;
        ID[cur++] = u;
        path.add(u);
        depths.add(depth);
        if(!indexByNode.containsKey(u))
            indexByNode.put(u, path.size() - 1);

        singleValues[u] = 1;
        Map<Integer, Integer> factorsU = getPrimeFactors(values[u]);
        for(int f : factorsU.keySet()) {    // remove factor > 1000 (if any)
            int exp = factorsU.get(f);
            if(f > 1000) {
                singleValues[u] = f;
                factorsU.remove(f);
                break;
            }
        }
        factors[u] = parent == -1 ? factorsU : merge(factorsU, factors[parent]);

        for(int v : tree[u]) {
            if(v != parent) {
                dfs(v, u, depth + 1);
                path.add(u);
                depths.add(depth);
            }
        }
        end[u] = cur;
        ID[cur++] = u;
    }

    static long power(int b, int p) {
        if(p == 0) return 1;
        long ans = power(b, p/2);
        ans = ans * ans % mod;
        if((p & 1) == 0)
            ans = ans * b % mod;
        return ans;
    }
}

