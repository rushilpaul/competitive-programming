import java.util.*;

public class D {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int tt = 1; tt <= T; tt++) {

            String n = "0" + sc.next(), tmp = n;
            int s = sc.nextInt();
            while(sum(n) > s) {
                n = reduce(n);
            }
            System.out.println(Long.parseLong(n) - Long.parseLong(tmp));
        }
    }

    static String reduce(String s) {

        char A[] = s.toCharArray();
        int n = s.length();

        for(int i = n-1; i >= 0; i--) {
            if(A[i] != '0') {
                A[i] = '0';
                StringBuilder sb = new StringBuilder();
                for(int j = 0; j < i; j++)
                    sb.append(A[j]);
                String next = add1(sb.toString());
                for(int j = 0; j < next.length(); j++) {
                    A[i - j - 1] = next.charAt(next.length() - j - 1);
                }
                break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int j = 0; j < A.length; j++)
            sb.append(A[j]);
        return sb.toString();
    }

    static String add1(String s) {
        if(s.length() == 0)
            return "1";
        LinkedList<Character> A = new LinkedList<>();
        for(int i = 0; i < s.length(); i++)
            A.add(s.charAt(i));
        int i = A.size() - 1;
        while(i >= 0 && A.get(i) == '9') {
            A.set(i, '0');
            i--;
        }
        if(i < 0)
            A.addFirst('1');
        else
            A.set(i, (char)((int)A.get(i) + 1));
        StringBuilder sb = new StringBuilder();
        for(char ch : A)
            sb.append(ch);
        return sb.toString();
    }

    static int sum(String n) {
        int s = 0;
        for(char ch : n.toCharArray())
            s += (ch - '0');
        return s;
    }

}

