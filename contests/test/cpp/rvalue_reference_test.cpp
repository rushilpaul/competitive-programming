#include <cstdio>
#include <algorithm>

class hash
{
	public:
		int *ar;
		hash()
		{
			printf("hash() called\n");
			ar = new int[10];
			for(int a=1;a<=10;a++)
				ar[a-1] = a;
		}
		hash(hash& ob)
		{
			printf("Copy cons with lvalue reference called\n");
		}
		hash(hash &&ob) : ar(std::move(ob.ar))
		{
			printf("Copy cons with rvalue reference called\n");
		}
		hash& operator=(hash &&ob)
		{
			printf("operator= with rvalue reference called\n");
			delete ar;
			ar = std::move(ob.ar);
			ob.ar = NULL;
			return *this;
		}
		void print()
		{
			for(int a=0;a<10;a++)
				printf("%d ",ar[a]);
			printf("\n");
		}
		~hash()
		{
			if(ar) delete ar;
		}
};

void f(int &r)
{
	printf("f(&)\n");
}

void f(int &&r)
{
	printf("f(&&)\n");
}

int main()
{

	return 0;
}
