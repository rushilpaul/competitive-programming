import java.util.*;

class Solution {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0) {

            int n = sc.nextInt();
            int A[] = new int[n];
            List<Integer> s = new ArrayList<>();
            int cur = 0;
            for(int i = 0; i < n; i++) {
                A[i] = sc.nextInt();
                if(A[i] == 0)
                    cur++;
                else {
                    if(cur > 0)
                        s.add(cur);
                    cur = 0;
                }
            }
            if(cur > 0)
                s.add(cur);
            Collections.sort(s, Comparator.reverseOrder());
            if(s.size() == 0) {
                System.out.println("No");
            }
            else if(s.size() == 1) {
                if(f(s.get(0)))
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }
            else {
                if(s.get(0) == s.get(1)) {
                    System.out.println("No");
                } else {
                    if(f(s.get(0)))
                        System.out.println(s.get(0) / 2 + 1 > s.get(1) ? "Yes" : "No");
                    else
                        System.out.println("No");
                }
            }
        }
    }

    static boolean f(int x) {
        return x % 2 == 1;
    }
}

