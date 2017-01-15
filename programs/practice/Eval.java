import java.util.*;
class Eval
{
static String operators = "+-*/%^";
static int find(char op[], int len)
{
 char max = '-'; int i=-1;
 for(int a=0;a<len;a++)
    if( operators.indexOf(max) < operators.indexOf(op[a])) { i=a; max=op[a]; }
 return i==-1 ? 0 : i;
}

static int operate(int n1, int n2, char op)
{
if(op == '+') return n1+n2;
if(op == '-') return n1-n2;
if(op == '*') return n1*n2;
if(op == '/') return n1/n2;
if(op == '%') return n1%n2;
if(op == '^') return (int)Math.pow(n1,n2);
return -9999; // should not execute
}

static StringBuffer removeSp(StringBuffer s)
{
for(int a=0;a<s.length();a++) if(s.charAt(a)==' ') { s.delete(a,a+1); a--; }
return s;
}

public static void main()
{
Scanner sc = new Scanner(System.in);
StringBuffer exp = new StringBuffer(sc.nextLine());
exp = removeSp(exp);
int n = exp.length();
int var[] = new int[(int)Math.round(n/2.0)];
char op[] = new char[n/2];
int k=0;
for(int a=0;a<exp.length();a++)
if(operators.indexOf(exp.charAt(a)) != -1) { op[k++] = exp.charAt(a);
exp = exp.delete(a,a+1);
exp = exp.insert(a, ' ');
}

String var_s[] = exp.toString().split(" ");
for(int a=0;a<var_s.length;a++)
var[a] = Integer.parseInt(var_s[a]);
int var_len=var.length, op_len=k;

for(int b=0;b<k;b++)
{
int i = find(op,op_len);
var[i] = operate(var[i],var[i+1],op[i]);
for(int a=i+1;a<var_len-1;a++)
 var[a] = var[a+1];
for(int a=i;a<op.length-1;a++)
 op[a] = op[a+1];
op_len--;
var_len--;
int a=0;
for(;a<op_len;a++)
System.out.print(var[a] + "" + op[a]);
System.out.println(var[a]);
}
}
}
