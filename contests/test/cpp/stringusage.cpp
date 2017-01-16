#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char buffer[256];
	gets(buffer);
	string s = buffer;
	string i = "good ";
	s.insert(0,i);
	cout << s << endl;
	cout << buffer << endl;
	return 0;
}
