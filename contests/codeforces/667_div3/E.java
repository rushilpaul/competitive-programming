import java.io.*;
import java.util.*;

public class E {

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
        public ArrayList<Integer>[] adjacencyList(int nodes, int edges) throws IOException {
            return adjacencyList(nodes, edges, false);
        }
        public ArrayList<Integer>[] adjacencyList(int nodes, int edges, boolean isDirected) throws IOException {
            ArrayList<Integer>[] adj = getAdj(nodes);
            for (int i = 0; i < edges; i++) {
                int a = nextInt(), b = nextInt();
                adj[a].add(b);
                if (!isDirected) adj[b].add(a);
            }
            return adj;
        }
    }

    static final Random random = new Random();

    public static void main(String args[]) {

        FastScanner sc = new FastScanner();
        int T = sc.nextInt();
        while(T-- > 0) {

            int n = sc.nextInt(), k = sc.nextInt();
            int A[] = sc.nextIntArray(n);
            for(int i = 0; i < n; i++)
                sc.nextInt();

            sort(A);

            int ans = 0, leftEdge = 0;
            int dp[] = new int[n];

            for(int i = 0; i < n; i++) {

                while(A[i] - A[leftEdge] > k)
                    leftEdge++;
                int saved = i - leftEdge + 1;
                if(i - 1 >= 0)
                    dp[i] = dp[i-1];
                dp[i] = Math.max(dp[i], saved);
                ans = Math.max(ans, (leftEdge - 1 >= 0 ? dp[leftEdge - 1] : 0) + saved);
            }
            System.out.println(ans);
        }
    }

    static void sort(int A[]) {
        shuffleArray(A);
        Arrays.sort(A);
    }

    static void shuffleArray(int[] A) {
        int n = A.length;
        for(int i=0; i<n; ++i){
            long tmp = A[i];
            int randomPos = i + random.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = (int) tmp;
        }
    }
}

