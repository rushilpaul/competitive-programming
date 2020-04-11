import java.util.*;

class Operand {
    long c0 = 1, c1 = 1, ca = 1;
    public long countAll() {
        return c0 + c1 + ca * 2;
    }

    public long a() { return ca; }
    public long A() { return ca; }
}

class REBIT {

	static int mod = 998244353;

    static Operand eval(Operand op1, Operand op2, char operator) {

        Operand result = new Operand();
        switch(operator) {
            case '&':
                result.c1 = op1.c1 * op2.c1;

                result.c0 = op1.c0 * op2.countAll() % mod + op1.countAll() * op2.c0 % mod - (op1.c0 * op2.c0) + op1.a() * op2.A() * 2 % mod;

                result.ca = op1.a() * op2.a() % mod + op1.a() * op2.c1 % mod + op1.c1 * op2.a();

                break;

            case '|':
                result.c1 = op1.c1 * op2.countAll() % mod + op1.countAll() * op2.c1 % mod - (op1.c1 * op2.c1) + op1.a() * op2.A() * 2 % mod;

                result.c0 = op1.c0 * op2.c0;

                result.ca = op1.a() * op2.a() % mod + op1.a() * op2.c0 % mod + op1.c0 * op2.a();
                break;

            case '^':
                result.c0 = op1.c0 * op2.c0 % mod + op1.c1 * op2.c1 % mod + op1.a() * op2.a() * 2 % mod;

                result.c1 = op1.c0 * op2.c1 % mod + op1.c1 * op2.c0 % mod + op1.a() * op2.A() * 2 % mod;

                result.ca = op1.c1 * op2.A() % mod + op1.A() * op2.c1 % mod + op1.a() * op2.c0 % mod + op1.c0 * op2.a() % mod;
        }

		result.c0 %= mod;
		result.c1 %= mod;
		result.ca %= mod;
        return result;
    }

    static Operand solve(String s) {

        Stack<Object> stack = new Stack();

        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(ch == '#')
                stack.push(new Operand());
            else if(ch != ')')
                stack.push(ch);

            else {	// closing bracket, time to evaluate the last expression
                Operand op1 = (Operand) stack.pop();
                char operator = (char) stack.pop();
                Operand op2 = (Operand) stack.pop();
                stack.pop();	// removing ( bracket
                Operand result = eval(op1, op2, operator);
                stack.push(result);
            }
        }
        return (Operand) stack.pop();
    }

	static long pow(long a, int p) {

		if(p == 0)
			return 1;
		long ans = pow(a, p/2);
		ans = ans * ans % mod;
		if((p & 1) == 1)
			ans = ans * a % mod;
		return ans;
	}

	static long mul(long x, long Q) {
		x = x * Q % mod;
		if(x < 0)
			x += mod;
		return x;
	}

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {

            String exp = sc.next();
            Operand ans = solve(exp);

			long Q = pow(ans.countAll(), mod-2);
			ans.c0 = mul(ans.c0, Q);
			ans.c1 = mul(ans.c1, Q);
			ans.ca = mul(ans.ca, Q);

            System.out.printf("%d %d %d %d\n", ans.c0, ans.c1, ans.a(), ans.A());
        }
    }

}

