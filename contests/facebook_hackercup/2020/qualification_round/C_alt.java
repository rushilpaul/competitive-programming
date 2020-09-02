import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class Timber {

    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private FastIO.InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return readString();
        }

        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }

    static class Pair implements Comparable {
        int a,b;
        Pair(int a, int b) { this.a = a; this.b = b; }

        public int compareTo(Object o1) {
            Pair o = (Pair) o1;
            return a == o.a ? b - o.b : a - o.a;
        }
    }

    public static void main(String[] args) {

        InputReader sc = new InputReader(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            int n = sc.nextInt();
            Pair[] pairs = new Pair[n];
            Map<Integer, Integer> dp = new HashMap<>();

            for(int i = 0; i < n; i++) {
                int p = sc.nextInt();
                int h = sc.nextInt();
                pairs[i] = new Pair(p, h);
            }
            Arrays.sort(pairs);
            long ans = 0;
            for(int i = 0; i < n; i++) {
                int p = pairs[i].a;
                int h = pairs[i].b;
                dp.merge(p + h, dp.getOrDefault(p, 0) + h, Integer::max);
                dp.merge(p, dp.getOrDefault(p - h, 0) + h, Integer::max);
                ans = Math.max(ans, dp.get(p));
                ans = Math.max(ans, dp.get(p + h));
            }
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
}

