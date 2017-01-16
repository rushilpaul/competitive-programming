// Takes 2 input files and compares for equality
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

char s1[1000001],s2[1000001];

double round(double n, int k)
{
	int d = pow(10,k);
	return round(n * d) / d;
}

int main(int nargs, char **args)
{
	if(nargs < 4)
	{
		printf("Usage: %s <input file1> <input file2> <option>\nOption 1 for testing string wise, 2 for testing number wise\n",args[0]);
		return -1;
	}
	int op = atoi(args[3]);
	FILE *f1 = fopen(args[1],"r"), *f2 = fopen(args[2],"r");
	if(!f1 || !f2)
	{
		printf("Error opening files\n");
		return 2;
	}
	if(op == 1)
	{
		while(1)
		{
			int n1 = fscanf(f1,"%s",s1), n2 = fscanf(f2,"%s",s2);
			if(n1 == n2 and n1 == 0 || n1 == EOF) { fclose(f1); fclose(f2); break; }
			if(n1 != n2)
			{
				printf("Not equal. Reached EOF for one of the input files\n");
				return 1;
			}
			if(strcmp(s1,s2))
			{
				printf("Not equal.\n[%s != %s]",s1,s2);
				return 1;
			}
		}
	}
	else if(op == 2)
	{
		if(nargs < 5)
		{
			printf("Error margin not specified\n");
			return 2;
		}
		double thres = atof(args[4]);
		float m1,m2;
		while(1)
		{
			int n1 = fscanf(f1,"%f",&m1), n2 = fscanf(f2,"%f",&m2);
			if(n1 == n2 and (n1 == 0 || n1 == EOF))
			{
				fclose(f1);
				fclose(f2);
				break;
			}
			if(n1 != n2)
			{
				printf("Not equal. Reached EOF for one of the input files\n");
				return 1;
			}
			if(abs(m1-m2) > thres)
			{
				printf("Not equal.\n[%.8f != %.8f]",m1,m2);
				return 1;
			}
		}
	}
	else
	{
		printf("Bad option value specified\n");
		return 2;
	}
	printf("Equal!\n");
	return 0;
}
