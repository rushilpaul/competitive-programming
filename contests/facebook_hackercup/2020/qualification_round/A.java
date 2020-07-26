import java.util.*;

class A {
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int t = 1; t <= T; t++) {
            int n = sc.nextInt();
            char[] IN = sc.next().toCharArray();
            char[] OUT = sc.next().toCharArray();
            boolean G[][] = new boolean[n][n];  // default = all false
            for(int i = 0; i < n-1; i++)
                G[i+1][i] = G[i][i+1] = true;
            for(int i = 0; i < n; i++)
                G[i][i] = true;

            for(int i = 0; i < n; i++) {
                int incoming = IN[i], outgoing = OUT[i];
                if(incoming == 'N')
                    for (int j = 0; j < n; j++)
                        if(j != i)
                            G[j][i] = false;
                if(outgoing == 'N')
                    for (int j = 0; j < n; j++)
                        if(j != i)
                            G[i][j] = false;
            }

            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    for(int k = 0; k < n; k++)
                        if(G[j][i] && G[i][k])
                            G[j][k] = true;

            System.out.printf("Case #%d:\n", t);
            for(int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    System.out.printf("%c", G[i][j] ? 'Y' : 'N');
                System.out.println();
            }
        }
    }
}

