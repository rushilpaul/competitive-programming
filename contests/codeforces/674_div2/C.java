import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class C {

    static long ans;

    public static void main(String[] args) throws Exception {

        FastScanner sc = new FastScanner();

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int L = 1, R = n;
            ans = R;
            if(n == 1)
                ans = 0;
            while(L < R) {
                int x = (L + R) / 2;
                long r1 = f(n, x), r2;
                for(int mid = x;; mid++) {
                    r2 = f(n, mid);
                    if(r2 != r1)
                        break;
                }
                if(r1 > r2)
                    L = x + 1;
                else if(r1 <= r2) {
                    R = x;
                }
            }
            println(ans + "");
        }
    }

    static long f(int n, int x) {
        long r = 0L + x + (n + x-1) / x - 2;
        ans = min(ans, r);
        return r;
    }

    static final Random random = new Random();

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

        public List<Integer>[] adjacencyList(int nodes, int edges) {
            return adjacencyList(nodes, edges, false);
        }
        public List<Integer>[] adjacencyList(int nodes, int edges, boolean isDirected) {

            List<Integer>[] adj = new ArrayList[nodes + 1];
            Arrays.setAll(adj, (i) -> new ArrayList<>());
            for (int i = 0; i < edges; i++) {
                int a = nextInt(), b = nextInt();
                adj[a].add(b);
                if (!isDirected) adj[b].add(a);
            }
            return adj;
        }
    }

    static class FastWriter {

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        void print(int n) throws Exception { writer.write(n + ""); }
        void println(int n) throws Exception { writer.write(n + "\n"); }

        void print(long n) throws Exception { writer.write(n + ""); }
        void println(long n) throws Exception { writer.write(n + "\n"); }

        void print(String s) throws Exception { writer.write(s); }
        void println(String s) throws Exception { writer.write(s); writer.newLine(); }

        void println(int ar[]) throws Exception { for(int e : ar) writer.write(e + " "); writer.newLine(); }
        void println(long ar[]) throws Exception { for(long e : ar) writer.write(e + " "); writer.newLine(); }
        void println(double ar[]) throws Exception { for(double e : ar) writer.write(e + " "); writer.newLine(); }
        void close() throws Exception { writer.close(); }
        <T> void println(List<T> L) throws Exception { for(T o : L) writer.write(o + " "); writer.newLine(); }
    }

    static int findDistance(List<Integer> G[], int nodes, int src, int dst) {

        LinkedList<Integer> queue = new LinkedList<>();
        int dist[] = new int[nodes + 1];
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

    static void sort(List<Integer> A) {
        shuffleList(A);
        Collections.sort(A);
    }

    static void shuffleList(List<Integer> A) {
        int n = A.size();
        for(int i = 0; i < n; i++) {
            int tmp = A.get(i);
            int randomPos = i + random.nextInt(n-i);
            A.set(i, A.get(randomPos));
            A.set(randomPos, tmp);
        }
    }

    static void sort(int A[]) {
        shuffleArray(A);
        Arrays.sort(A);
    }
    static void sort(long A[]) {
        shuffleArray(A);
        Arrays.sort(A);
    }
    static void sort(double A[]) {
        shuffleArray(A);
        Arrays.sort(A);
    }
    static void shuffleArray(int[] A) {
        int n = A.length;
        for(int i = 0; i < n; i++) {
            int tmp = A[i];
            int randomPos = i + random.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
    }
    static void shuffleArray(long[] A) {
        int n = A.length;
        for(int i = 0; i < n; i++) {
            long tmp = A[i];
            int randomPos = i + random.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
    }
    static void shuffleArray(double[] A) {
        int n = A.length;
        for(int i = 0; i < n; i++) {
            double tmp = A[i];
            int randomPos = i + random.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
    }

    static int[] subArray(int A[], int x, int y) {
        int B[] = new int[y - x + 1];
        for(int i = x; i <= y; i++)
            B[i-x] = A[i];
        return B;
    }

    static int[] toArray(List<Integer> L) {
        return L.stream().mapToInt(x -> x).toArray();
    }

    static void println(int[] A) {
        for(int e: A) System.out.print(e + " ");
        System.out.println();
    }

    static void println(long[] A) {
        for(long e: A) System.out.print(e + " ");
        System.out.println();
    }

    static void println(List arr) {
        for(Object e: arr) System.out.print(e + " ");
        System.out.println();
    }

    static void print(String s) {
        System.out.print(s);
    }

    static void println(String s) {
        System.out.println(s);
    }

    static List<Integer> toList(int ar[]) {
        return Arrays.stream(ar).boxed().collect(Collectors.toList());
    }

    static List<Long> toList(long ar[]) {
        return Arrays.stream(ar).boxed().collect(Collectors.toList());
    }

    static List<Double> toList(double ar[]) {
        return Arrays.stream(ar).boxed().collect(Collectors.toList());
    }

    static long gcd(long a, long b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int abs(int a){  return (a>=0) ? a: -a;  }
    private static int min(int... ins){ return Arrays.stream(ins).min().getAsInt(); }
    private static int max(int... ins){ return Arrays.stream(ins).max().getAsInt(); }
    private static int sum(int... ins){ return Arrays.stream(ins).sum(); }
    private static long abs(long a){ return (a>=0) ? a: -a; }
    private static long min(long... ins){ return Arrays.stream(ins).min().getAsLong(); }
    private static long max(long... ins){ return Arrays.stream(ins).max().getAsLong(); }
    private static long sum(long... ins){ return Arrays.stream(ins).sum(); }
    private static double abs(double a){ return (a>=0) ? a: -a; }
    private static double min(double... ins){ return Arrays.stream(ins).min().getAsDouble(); }
    private static double max(double... ins){ return Arrays.stream(ins).max().getAsDouble(); }
    private static double sum(double... ins){ return Arrays.stream(ins).sum(); }

    private static class Pair implements Comparable<Pair> {
        int x, y;
        Pair(int x, int y) { this.x = x; this.y = y; }
        Pair() {}

        @Override
        public int compareTo(Pair other) {
            return x == other.x ? y - other.y : x - other.x;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x &&
                    y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}

