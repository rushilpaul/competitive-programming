#include <cstdio>
#include <string>
using namespace std;

struct student
{
	int id;
	string name;
	student(int id, string name) : id(id), name(name) {}
	student() {}
};

class record
{
	student *ar;
	int n;
	public:
		record(int n) : n(n)
		{
			ar = new student[n];
		}
		student* begin()
		{
			return ar;
		}
		student* end()
		{
			return ar+n;
		}
		student& operator[](int i)
		{
			return ar[i];
		}
};

int main()
{
	record A(2);
	A[0] = student(1,"Rushil");
	for(auto p = A.begin(); p < A.end(); p++)
	{
		printf("%d %s\n",p->id, p->name.c_str());
	}
	return 0;
}

