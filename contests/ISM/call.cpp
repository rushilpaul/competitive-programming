#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> table;
	vector<int> price;
	vector<string> names;
	while(1)
	{
		char ph[16]; scanf("%s",&ph);
		if (ph == "000000") break;
		table.push_back(ph);
		char name[26]; scanf("%s",&name);
		names.push_back(name);
		int p; scanf("%d",&p);
		price.push_back(p);
			
	}
	printf("%s\n",names[0].c_str());
	return 0;
}
