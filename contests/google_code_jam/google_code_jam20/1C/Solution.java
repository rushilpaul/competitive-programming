import java.lang.reflect.Array;
import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */

class Pair {
    int x, y;
    Pair(int x, int y) { this.x = x; this.y = y; }
}

public class Solution
{

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            int u = sc.nextInt();
            List<Pair> L[] = new ArrayList[26];
            Map<Integer, Integer> known = new HashMap<>();
            for(int i = 0; i < 26; i++) {
                L[i] = new ArrayList<>();
                L[i].add(new Pair(0,9));
            }

            for(int i = 0; i < 10000; i++) {

                String m = sc.next();
                String r = sc.next();
                long mInt = Long.parseLong(m);

                int ch = r.charAt(0) - 'A';
                if(m.length() == r.length())
                    L[ch].add(new Pair(1, m.charAt(0) - '0'));
            }

            for(int i = 0; i < 26; i++) {
                while(L[i].size() >= 2) {
                    Pair p1 = L[i].remove(0);
                    Pair p2 = L[i].remove(0);
                    // combine
                    if(p1.x > p2.x) {
                        Pair tmp = p1;
                        p1 = p2;
                        p2 = tmp;
                    }
                    L[i].add(new Pair(p2.x, Math.min(p1.y, p2.y)));
                }
                if(L[i].get(0).x == L[i].get(0).y) {
                    System.out.printf("Found out %d for %c\n", L[i].get(0).x, i + 'A');
                    known.put(L[i].get(0).x, i);
                }
            }
            System.out.printf("Case #%d: ", t);

            for(int i = 0; i < 10; i++)
                if(known.containsKey(i))
                    System.out.printf("%c", (char)(known.get(i) + 'A'));
                else
                    System.out.printf("?");

            System.out.println();
        }
    }
}
