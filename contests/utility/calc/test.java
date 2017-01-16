class test
{
static String operators = "+-*/%^";

static int operate(int n1, int n2, char op)
{
  if(op == '+') return n1 + n2;
  if(op == '-') return n1 - n2;
  if(op == '*') return n1 * n2;
  if(op == '/') return n1 / n2;
  if(op == '%') return n1 % n2;
  if(op == '^') return (int)Math.pow(n1,n2);
  return -99999; // should not execute
}

public static void main(String args[])
{
if(args.length == 0) return;
String exp = args[0];
int var[] = new int[(int)Math.round(exp.length()/2.0)];
char op[] = new char[var.length-1], v=0,o=0;
for(int a=0;a<exp.length();a++)
{
  char ch = exp.charAt(a);
  if(Character.isDigit(ch)) var[v] = var[v]*10 + (ch-48);
  if(a != exp.length()-1)
	  if(Character.isDigit(exp.charAt(a+1))) v++;
  
  if(operators.indexOf(ch) != -1)
  {
	if(a!=0 && o!=0) {
	if(operators.indexOf(op[o-1]) >= operators.indexOf(ch))
	{
		var[v-2] = operate( var[v-2], var[v-1], op[o-1] );
		v--; o--; a--;
	}		}
	else
		op[o++] = ch;
  }
}
var[v-2] = operate( var[v-2], var[v-1], op[o-1] );
System.out.println(var[0]);
}
}

// 1*2+3



