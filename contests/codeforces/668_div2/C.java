import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class C {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            int n = sc.nextInt(), k = sc.nextInt();
            char A[] = sc.next().toCharArray();
            boolean possible = true;
            Set<Integer> set = new HashSet<>();

            for(int i = 0; i < n; i++) {

                boolean q = A[i] == '?';
                if(set.contains(i) || q)
                    continue;

                for(int j = i; j < n - k; j += k) {
                    set.add(j);
                    if (A[j] != '?' && A[j] != A[i])
                        possible = false;
                    else if (A[j] == '?')
                        A[j] = A[i];
                }
                for(int j = i; j >= 0; j -= k) {
                    set.add(j);
                    if (A[j] != '?' && A[j] != A[i])
                        possible = false;
                    else if (A[j] == '?')
                        A[j] = A[i];
                }
            }

            int ones = 0, z = 0;
            for(int i = 0; i < k; i++) {
                if(A[i] == '1')
                    ones++;
                else if(A[i] == '0')
                    z++;
            }
            if(ones > k / 2 || z > k / 2)
                possible = false;

            for(int i = k; i < n; i++) {

                char ch = A[i];
                if(ch == '?')
                    continue;
                if(ch == '1')
                    ones++;
                else if(ch == '0')
                    z++;
                if(A[i - k] == '1')
                    ones--;
                else if(A[i - k] == '0')
                    z--;
                if(ones > k / 2 || z > k / 2)
                    possible = false;
            }
            System.out.println(possible ? "YES" : "NO");
        }
    }
}


