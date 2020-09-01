import java.util.*;

public class RBTREES {

    static List<Integer> G[];
    static int n;
    static char[] label;

    static int dist;

    static int dfs(int u, int parent, boolean red) {

        int reds = 0;
        if(red) {
            if(label[u] != 'r')
                reds--;
        }
        else {
            if(label[u] != 'b')
                reds++;
        }

        for(int v : G[u])
            if(v != parent)
                reds += dfs(v, u, !red);

        dist += Math.abs(reds);
        return reds;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            n = sc.nextInt();
            G = new List[n+1];
            label = new char[n+1];

            Arrays.setAll(G, (i) -> new ArrayList<>());

            for(int i = 0; i < n - 1; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                G[u].add(v);
                G[v].add(u);
            }
            String labels = sc.next();
            for(int i = 1; i <= n; i++)
                label[i] = labels.charAt(i-1) == '0' ? 'r' : 'b';

            long ans = -1;
            dist = 0;
            if (dfs(1, 0, true) == 0)
                ans = dist;
            dist = 0;
            if (dfs(1, 0, false) == 0)
                ans = Math.min(ans == -1 ? Long.MAX_VALUE : ans, dist);
            System.out.println(ans);
        }
    }
}

