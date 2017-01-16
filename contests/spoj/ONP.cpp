#include <bits/stdc++.h>
using namespace std;

char s[401];
int i,n;

string term();
string exp();

string id()
{
	string ans = string(1,s[i]);
	i++;
	return ans;
}

// power -> id ^ power | id | ( exp ) | ( exp ) ^ power
string power()
{
	string ans="";
	if(s[i] == '(')
	{
		i++;
		string op1 = exp();
		i++;
		if(s[i] == '^')
		{
			i++;
			string op2 = power();
			ans = op1 + op2 + '^';
		}
		else
			ans = op1;
		return ans;
	}
	string op1 = id();
	if(i >= n or s[i] != '^') return op1;
	i++;
	string op2;
	if(s[i] == '(')
	{
		i++;
		op2 = exp();
		i++;
	}
	else
		op2 = power();
	ans = op1 + op2 + '^';
	return ans;
}

// quot -> power / quot | power
string quot()
{
	string ans = "";
	string op1 = power();
	if(i >= n or s[i] != '/') return op1;
	i++;
	ans = op1 + quot() + '/';
	return ans;
}

// factor -> quot * factor | quot
// a ^ c / b ^ c
// a / b * c
// a / (b * c)
// a * b / c
string factor()
{
	string ans="";
	string op1 = quot();
	if(i >= n or s[i] != '*') return op1;
	i++;
	ans = op1 + factor() + '*';
	return ans;
}

// a * (b + c)
// term -> factor * term | factor

// term -> quot * ( exp ) | quot
string term()
{
	string ans="";
	string op1 = factor();
	if(i >= n or s[i] != '*') return op1;
	i++;
	ans = op1 + term() + '*';
	return ans;
}

// a * b / c
// a / b * c
// a - b + c
// exp -> term - exp | term + exp | term
string exp()
{
	string ans="";
	string op1 = term();
	if(i < n and (s[i] == '-' or s[i] == '+'))
	{
		char op = s[i++];
		string op2 = exp();
		ans = op1 + op2 + op;
	}
	else
		ans = op1;
	return ans;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		i=0;
		scanf("%s",s);
		n = strlen(s);
		cout << exp() << endl;
	}
	return 0;
}
