import java.io.*;
import java.util.*;

public class D {

    static class FastScanner {
        private InputStream sin = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        public FastScanner(){}
        public FastScanner(String filename) throws FileNotFoundException {
            File file = new File(filename);
            sin = new FileInputStream(file);
        }
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            }else{
                ptr = 0;
                try {
                    buflen = sin.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b) || b == ':'){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
        public double nextDouble() { return Double.parseDouble(next());}
        public long[] nextLongArray(final int n){
            final long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
        public int[] nextIntArray(final int n){
            final int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
        public double[] nextDoubleArray(final int n){
            final double[] a = new double[n];
            for (int i = 0; i < n; i++)
                a[i] = nextDouble();
            return a;
        }
        public ArrayList<Integer>[] getAdj(int n) {
            ArrayList<Integer>[] adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
            return adj;
        }
        public ArrayList<Integer>[] adjacencyList(int nodes, int edges) {
            return adjacencyList(nodes, edges, false);
        }
        public ArrayList<Integer>[] adjacencyList(int nodes, int edges, boolean isDirected) {
            ArrayList<Integer>[] adj = getAdj(nodes);
            for (int i = 0; i < edges; i++) {
                int a = nextInt(), b = nextInt();
                adj[a].add(b);
                if (!isDirected) adj[b].add(a);
            }
            return adj;
        }
    }

    public static void main(String[] args) {

        FastScanner sc = new FastScanner();
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt(), ja = sc.nextInt(), jb = sc.nextInt();
            ArrayList<Integer> G[] = sc.adjacencyList(n, n-1);

            // check if ja >= dist(a,b)
            int dist[] = new int[n+1];
            Arrays.fill(dist, -1);
            int maxDist = 0, maxNode = -1;
            int D = dist(G, n, a, b, dist);

            for(int i = 1; i <= n; i++)
                if(dist[i] > maxDist) {
                    maxDist = dist[i];
                    maxNode = i;
                }
            Arrays.fill(dist, -1);
            dist(G, n, maxNode, a, dist);
            for(int i = 1; i <= n; i++)
                maxDist = Math.max(maxDist, dist[i]);

            if(ja >= D) {
                System.out.println("Alice");
                continue;
            }
            jb = Math.min(jb, maxDist);
            if(jb > 2 * ja)
                System.out.println("Bob");
            else
                System.out.println("Alice");
        }
    }

    static int dist(ArrayList<Integer> G[], int n, int src, int dst, int dist[]) {

        LinkedList<Integer> queue = new LinkedList<>();
        int ans = -1;
        dist[src] = 0;
        queue.add(src);
        while(queue.size() > 0) {
            int u = queue.poll();
            if(u == dst) {
                ans = dist[u];
            }
            for(int v : G[u]) {
                if(dist[v] >= 0)
                    continue;
                queue.add(v);
                dist[v] = dist[u] + 1;
            }
        }
        return ans;
    }
}

