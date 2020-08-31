import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class ALIENIN {

    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

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

    public static void main(String[] args) {

        InputReader sc = new InputReader(System.in);
        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt(), d = sc.nextInt();
            int A[] = new int[n];
            for(int i = 0; i < n; i++)
                A[i] = sc.nextInt();
            Arrays.sort(A);

            double L = 0, R = 1e10, delta = 1e-6;
            while(R - L > 1e-7) {
                double mid = (L + R) / 2;
                if(check(A, d, mid))
                    L = mid + delta;
                else
                    R = mid - delta;
            }
            System.out.printf("%.7f\n", L);
        }
    }

    static boolean check(int A[], int d, double cd) {

        int n = A.length;
        double latestCdTime = 0;

        for(int i = 0; i < n; i++) {
            if(latestCdTime > A[i] + d)
                return false;
            latestCdTime = cd + Math.max(latestCdTime, A[i]);
        }
        return true;
    }

}

