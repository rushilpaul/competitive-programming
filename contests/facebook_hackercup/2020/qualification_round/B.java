import java.util.*;

class Solution {
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            char[] s = sc.next().toCharArray();
            int x = 0, y = 0;
            for(char i : s)
                if(i == 'A')
                    x++;
                else
                    y++;
            System.out.printf("Case #%d: %c\n", t, Math.abs(x - y) <= 1 ? 'Y' : 'N');
        }
    }
}

