class calc
{
    static String operators = "+-*/%^";

    static int validate(String exp)
    {
        int brack=0;
        char ch;
        boolean var = true, op = false;
        if(!Character.isDigit( exp.trim().charAt(0)) ) return 0;
        for(int a=0; a<exp.length(); a++)
        {
            ch = exp.charAt(a);
            if(ch == '(')
            {
                if(a!=0)
                    if(!op) return a;	// an operator should preceed an opening bracket
                var = op = false;
                brack++;
                continue;
            }
            if(ch == ')')
            {
                if(!var) return a-1;	// an operand should preceed a closing bracket
                var = op = false;
                brack--;
                continue;
            }
            if(operators.indexOf(ch) != -1)
            {
                if(op) return a;
                op = true;
                var = false;
                continue;
            }
            if(Character.isDigit(ch) || Character.isLetter(ch))
            {
                var = true;
                op = false;
                continue;
            }
            if(ch == ' ') continue;
            return a;
        }
        if(brack < 0) return 0;
        if(brack > 0) return exp.length();
        return -1;
    }

    static int operate(int n1, int n2, char op)
    {
        if(op == '+') return n1 + n2;
        if(op == '-') return n1 - n2;
        if(op == '*') return n1 * n2;
        if(op == '/') return n1 / n2;
        if(op == '%') return n1 % n2;
        if(op == '^') return (int)Math.pow(n1,n2);
        return -99999;	// should never execute
    }

    public static void main(String args[])
    {
        String usage = "Usage: calc <options> \"<mathematical expression>\"\n-C --> Ignore Case\nSupported operators are: +,-,*,/,%,^\nIf no expression is given as a parameter, calc will read it from standard input.\nExamples: calc \"1 + 2 * (4-1)\"";
        if(args.length > 2) {
            System.err.println("Too many parameters.\n"+usage);
            System.exit(1);
        }
        boolean ignorecase = false, commandexp = false;
        String exp = "";
        // parsing the command line arguments
        for(int a=0; a<args.length; a++)
        {
            if(args[a].length() == 0) continue;
            if(args[a].equalsIgnoreCase("-c")) {
                ignorecase = true;
                args[a] = "";
                continue;
            }
            if(args[a].length() >=  3) {
                exp = args[a];
                commandexp = true;
            }
        }
        if(!commandexp)
        {
            // System.out.print("Enter a mathematical expression: ");
            exp = new java.util.Scanner(System.in).nextLine();
        }
        if(exp.length() == 0) System.exit(0);
        int err = validate(exp);
        if( err != -1)
        {
            if(commandexp) System.out.println(exp);
            for(int a=0; a<err; a++) System.err.print(" ");
            System.err.println("^");
            System.err.println("Error in expression syntax.");
            System.exit(2);
        }
        exp = exp.replace(" ","");

        int var[] = new int[(int)Math.ceil(exp.length()/2.0)];
        char op[] = new char[var.length-1];
        int var_k=0, op_k=0;
        int nbrack=0;
        for(int a=0; a<exp.length(); a++)
        {
            char ch = exp.charAt(a);
            if(ch == '(') {
                nbrack++;
                continue;
            }
            if(ch == ')')
            {
                nbrack--;
                var[var_k-2] = operate(var[var_k-2], var[var_k-1], op[op_k-1]);
                var_k--;
                op_k--;
                continue;
            }
            if(Character.isDigit(ch))
            {
                if(a!=0)
                    if(!Character.isDigit(exp.charAt(a-1))) var_k++;
                var[var_k] = var[var_k]*10 + (ch-48);
            }
            if(operators.indexOf(ch) != -1)
            {
                if(nbrack == 0) {
                    if(op_k != 0)
                        if(operators.indexOf(ch) <= operators.indexOf( op[op_k-1] ))
                        {
                            var[var_k-1] = operate(var[var_k-1], var[var_k], op[op_k-1]);
                            var_k--;
                            op_k--;
                            a--;
                            continue;
                        }
                }
                op[op_k++] = ch;
            }
        }	// end of for loop
        var_k++;
        if(op_k >= 1) {
            var[var_k-2] = operate(var[var_k-2], var[var_k-1], op[op_k-1]);
            var_k--;
            op_k--;
        }
        System.out.println(var[0]);
    }
}

// 1 * (2 + (3^2) )
// 1+2+3

