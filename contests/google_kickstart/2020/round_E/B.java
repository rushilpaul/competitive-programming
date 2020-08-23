import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            a -= c;
            b -= c;
            int filler = n - (a + b + c);
            if(filler < 0) {
                System.out.printf("Case #%d: IMPOSSIBLE\n", t);
                continue;
            }

            List<Integer> ans = new ArrayList<>();

            for(int i = 0; i < a; i++)
                ans.add(n-1);
            for(int i = 0; i < c - 1; i++)
                ans.add(n);

            if(c == 1) {
                if (n >= 2 && a + b < 1) {
                    System.out.printf("Case #%d: IMPOSSIBLE\n", t);
                    continue;
                }
                if(a == 0) {
                    ans.add(n); // add for c
                    c--;
                }
            }
            
            for(int i = 0; i < filler; i++)
                ans.add(1);

            if(c > 0)
                ans.add(n);

            for(int i = 0; i < b; i++)
                ans.add(n-1);

            StringBuilder builder = new StringBuilder();
            for(Integer i : ans)
                builder.append(i + " ");
            System.out.printf("Case #%d: %s\n", t, builder.toString());
        }
    }
}

