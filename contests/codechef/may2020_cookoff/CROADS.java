import java.util.HashSet;
import java.util.Scanner;

class CROADS {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        for(int i = 1; i <= 31; i++)
            set.add(1<<i);

        while(t-- > 0) {

            int n = sc.nextInt();
            if(set.contains(n)) {
                System.out.println(-1);
                continue;
            }
            long ans = (n + 1) / 2 - 1;
            for(int i = 2; i <= n; i <<= 1) {
                int times = i * 2;
                ans += i * ((n - i + times - 1) / times);
                if((n - i) % times == 0)
                    ans += i;
            }
            System.out.println(ans);
        }
    }
}

