// Q: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
import java.util.*;

class A
{
    static boolean check(List<String> s) {

        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < s.size(); j++)
                if(i == j) continue;
                else {
                    if (!(s.get(i).startsWith(s.get(j)) || s.get(j).startsWith(s.get(i))))
                        return false;
                }
        return true;
    }

    static boolean check2(List<String> s) {

        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < s.size(); j++)
                if(i == j) continue;
                else {
                    if (!(s.get(i).endsWith(s.get(j)) || s.get(j).endsWith(s.get(i))))
                        return false;
                }
        return true;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            int n = sc.nextInt();
            String[] P = new String[n];

            for (int i = 0; i < n; i++) {
                String s = sc.next();
                P[i] = s;
            }
            int pos[] = new int[n];
            int pos2[] = new int[n];

            List<String> prefixes = new ArrayList();
            boolean possible = true;

            for (int i = 0; i < n; i++) {

                int as = P[i].indexOf('*');
                if(as == -1) {
                    prefixes.add(P[i]);
                    as = P[i].length();
                } else {
                    if (as > 0)
                        prefixes.add(P[i].substring(0, as));
                }
                pos[i] = as;
            }
            if(!check(prefixes))
                possible = false;

            List<String> suffixes = new ArrayList();

            for (int i = 0; i < n; i++) {

                int as = P[i].lastIndexOf('*');
                if(as == -1) {
                    suffixes.add(P[i]);
                    as = 0;
                } else {
                    if(as != P[i].length() - 1)
                        suffixes.add(P[i].substring(as+1));
                }
                pos2[i] = as;
            }

            if(!check2(suffixes))
                possible = false;

            if(!possible) {
                System.out.printf("Case #%d: %s\n", t, "*");
                continue;
            }

            int prefixLen = prefixes.stream().map(x -> x.length()).mapToInt(x -> x).max().orElse(-1);
            String prefix = prefixes.stream().filter(x -> x.length() == prefixLen).findFirst().orElse("");

            int suffixLen = suffixes.stream().map(x -> x.length()).mapToInt(x -> x).max().orElse(-1);
            String suffix = suffixes.stream().filter(x -> x.length() == suffixLen).findFirst().orElse("");

            String ans = prefix;

            for(int i = 0; i < n; i++) {
                try {
                    ans += P[i].substring(pos[i], pos2[i]).replaceAll("\\*", "");
                } catch (Exception ex) { }
            }
            System.out.printf("Case #%d: %s\n", t, ans + suffix);
        }
    }
}
