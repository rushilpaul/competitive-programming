import java.util.*;

class Pair {
    int x, y;
    void swap() {
        int t = x;
        x = y;
        y = t;
    }

    boolean reduce() {
        // assuming x is even
        if(x == 0 && y == 1) {
            y = 0;
            return false;
        }
        if(x % 4 == 0 && (y-1) % 4 == 0) {
            x /= 2;
            y = (y + 1) / 2;
            return true;
        }
        else if(x % 4 == 0 && (y-1) % 4 != 0) {
            x /= 2;
            y = (y - 1) / 2;
            return false;
        }
        else if(x % 4 != 0 && (y-1) % 4 == 0) {
            x /= 2;
            y = (y - 1) / 2;
            return false;
        }
        else if(x % 4 != 0 && (y-1) % 4 != 0) {
            x /= 2;
            y = (y + 1) / 2;
            return true;
        }
        throw new RuntimeException();
    }
}

public class Solution {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {

            Pair p = new Pair();
            p.x = sc.nextInt();
            p.y = sc.nextInt();
            boolean xPos = p.x >= 0;
            boolean yPos = p.y >= 0;
            p.x = Math.abs(p.x);
            p.y = Math.abs(p.y);

            if(p.x % 2 == p.y % 2)
                System.out.printf("Case #%d: IMPOSSIBLE\n", t);

            else {
                StringBuilder ans = new StringBuilder();
                boolean firstX = true;
                List<Boolean> jumpsX = new ArrayList(); // jumpsX[i] is true if ith jump was made in the X coordinate
                while(p.x > 0 || p.y > 0) {
                    if(p.x % 2 != 0) {
                        p.swap();
                        firstX = !firstX;
                    }
                    boolean inc = p.reduce();
                    if(firstX) {
                        jumpsX.add(false);
                        ans.append(inc ? 'S' : 'N');
                    }
                    else {
                        jumpsX.add(true);
                        ans.append(inc ? 'W' : 'E');
                    }
                }
                for(int i = 0; i < jumpsX.size(); i++)
                    if(jumpsX.get(i) && !xPos)
                        ans.setCharAt(i, ans.charAt(i) == 'E' ? 'W' : 'E');
                    else if(!jumpsX.get(i) && !yPos)
                        ans.setCharAt(i, ans.charAt(i) == 'N' ? 'S' : 'N');

                System.out.printf("Case #%d: %s\n", t, ans);
            }
        }
    }
}

