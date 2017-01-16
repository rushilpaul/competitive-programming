#include<iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
using namespace std;

int main()
{

int n;
cin >> n;
int a[100], b[100], i, j, pos1, pos2, sum = 0, temp;
bool check[100];
for(i = 0; i < n; i++)
{
	scanf("%d", &a[i]);
	b[i] = a[i];
	check[i] = 0;
}

cout << "bw1";
fflush(stdout);
for(i = 0; i < n; i++)
{
	for(j = 0; j < n-1; j++)
	{
		if(b[j] > b[j+1])
		{
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
						
		}
	}
}

cout << "bw";
fflush(stdout);
for(i = 0; i < n ; i++)
{
	if(b[i] == a[i])
		check[i] = 1;	
}
while(1)
{
	int count = 0;
	for(i = 0; i < n ; i++)
	{
		if(b[i] == a[i])
			count++;	
	}
	if(count == n)
		break;
	int min = 10000; 
	for(i = 0; i < n ; i++)
	{
		if(check[i] != 0)
		{
			for(j = 0; j < n ; j++)
			{
				if(i == j) continue;
				if(check[j] != 0)
				{
					if((a[j] == b[i]) && (b[j] == a[i]))
					{
						sum = sum + a[i] + a[j];
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
						check[i] = 1;
						check[j] = 1;
						goto leaveI;
					}
					if(a[i] == b[j])
					{
						if(a[i] + a[j] < min)
						{
							min = a[i] + a[j];
							pos1 = i;
							pos2 = j;
						}
					}
				}
			}
		}
		
		temp = a[pos1];
		a[pos1] = a[pos2];
		a[pos2] = temp;
		sum = sum + a[pos1] + a[pos2];
		check[pos1] = 1;
		leaveI:;		
	}
	cout << "\n" << sum;
	fflush(stdout);
}
return 0;
}
