#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	cin.ignore(1,'\n');
	while(t--)
	{
		string s="";
		while(s.length() == 0) {
		getline(cin,s); }
		int n = s.length();
		int i1 = s.find('+')+2;
		int i2 = s.find('=')+2;
		int id = s.find(' ');
		string s_op1 = s.substr(0,id), s_op2 = s.substr(i1,i2-4-i1+1), s_op3 = s.substr(i2);
		int op1=-1, op2=-1, op3=-1;
		try { op1 = stoi(s_op1); } catch(...) {}
		try { op2 = stoi(s_op2); } catch(...) {}
		try { op3 = stoi(s_op3); } catch(...) {}
		if(s_op1.find('m') != string::npos) op1 = -1;
		if(s_op2.find('m') != string::npos) op2 = -1;
		if(s_op3.find('m') != string::npos) op3 = -1;
		
		if(op1 == -1)
			op1 = op3-op2;
		else if(op2 == -1)
			op2 = op3-op1;
		else if(op3 == -1)
			op3 = op1+op2;
		printf("%d + %d = %d\n",op1,op2,op3);
	}
	return 0;
}
