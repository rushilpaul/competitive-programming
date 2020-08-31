import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class ELOMAX {

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

    public static void main(String[] args) throws Exception {

        InputReader sc = new InputReader(System.in);
        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt(), m = sc.nextInt();
            int R[][] = new int[n][m+1];

            for(int i = 0; i < n; i++)
                R[i][0] = sc.nextInt();

            for(int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    R[i][j + 1] = R[i][j] + sc.nextInt();
            }
            Map<Integer, Integer> ratingMonth = new HashMap<>();
            Map<Integer, Integer> rankMonth = new HashMap<>();

            for(int i = 0; i < n; i++) {
                int maxValue = Integer.MIN_VALUE, month = 0;
                for(int j = 1; j <= m; j++)
                    if(R[i][j] > maxValue) {
                        maxValue = R[i][j];
                        month = j;
                    }
                ratingMonth.put(i, month);
            }

            int playerRank[][] = new int[n][m+1];

            for (int j = 1; j <= m; j++) {

                TreeMap<Integer, List<Integer>> treeMap = new TreeMap();
                for (int i = 0; i < n; i++) {
                    treeMap.putIfAbsent(R[i][j], new ArrayList<>());
                    treeMap.get(R[i][j]).add(i);
                }

                int currentRank = 1;
                for(int r : treeMap.descendingKeySet()) {
                    List<Integer> players = treeMap.get(r);
                    for(Integer p : players)
                        playerRank[p][j] = currentRank;
                    currentRank += players.size();
                }
            }
            for (int i = 0; i < n; i++) {
                int best = Integer.MAX_VALUE, month = 0;
                for (int j = 1; j <= m; j++) {
                    if (playerRank[i][j] < best) {
                        best = playerRank[i][j];
                        month = j;
                    }
                }
                rankMonth.put(i, month);
            }
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (ratingMonth.get(i).intValue() != rankMonth.get(i).intValue())
                    ans++;
            System.out.println(ans);
        }
    }
}

