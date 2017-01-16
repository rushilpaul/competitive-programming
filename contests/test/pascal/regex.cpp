// regex_search example
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main ()
{
	string s ("this subject has a submarine as a subsequence");
	smatch m;
	regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

	cout << "Target sequence: " << s << std::endl;
	cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	cout << "The following matches and submatches were found:" << std::endl;

    while (std::regex_search (s,m,e))
	{
		for (auto x:m) cout << x << " ";
        cout << endl;
        s = m.suffix().str();
    }
	return 0;
}
