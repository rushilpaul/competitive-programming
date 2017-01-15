#include <cstdio>
class _A
{
	public: 
		virtual void show()
		{
			printf("base show()\n");
		}
		
};

class A : public _A
{
	public:
		virtual void show()
		{
			printf("derived show()\n");
		}
};

int main()
{
	_A ob;
	ob.show();
	A* ob1;
	ob1 = &ob;
	ob1->show();
	return 0;
}
