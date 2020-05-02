// Q: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Pair2 {
    int r, c;

    Pair2(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class PascalWalk {

    static List<Integer> findBits(int n) {
        int i = 0;
        List<Integer> rows = new ArrayList<>();
        while (n > 0) {
            if (n % 2 == 1)
                rows.add(i + 1);
            n >>= 1;
            i++;
        }
        return rows;
    }

    static List<Pair2> getCells(int row) {

        List<Pair2> cols = new ArrayList();
        for (int i = 1; i <= row; i++)
            cols.add(new Pair2(row, i));
        return cols;
    }

    static void solve(int n) {

        int tmp = n;
        int zeros = 0;
        while (n > 0) {
            if (n % 2 == 0)
                zeros++;
            n >>= 1;
        }
        n = tmp;
        List<Integer> rows = findBits(n);
        Collections.sort(rows);

        int row = 0;
        int i = 0;
        while (i < rows.size()) {

            // do a edge walk to current row
            for (int r = row + 1; r < rows.get(i); r++)
                System.out.printf("%d %d\n", r, i % 2 == 0 ? 1 : r);
            row = rows.get(i);

            List<Pair2> cells = getCells(row);
            if(i % 2 != 0)
                Collections.reverse(cells);
            for (Pair2 p : cells)
                System.out.printf("%d %d\n", p.r, p.c);
            i++;
        }

        row++;
        for (i = 1; i <= 30 - zeros; i++, row++)
            System.out.printf("%d %d\n", row, rows.size() % 2 != 0 ? row : 1);
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            System.out.println("Case #" + t + ":");
            int n = sc.nextInt();
            if(n <= 30)
                for(int i = 1; i <= n; i++)
                    System.out.printf("%d %d\n", i, i);
            else
                solve(n - 30);
        }
    }

}
