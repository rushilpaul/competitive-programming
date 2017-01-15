#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define max_buf_size 4096
using namespace std;
char buf[max_buf_size+1];
int buf_ptr=max_buf_size, cur_buf_size=max_buf_size;

unsigned int readuint()
{
	unsigned int n = 0;
	char ch;
	do
	{
		buf_ptr++;
		if(buf_ptr >= cur_buf_size)
		{
			buf_ptr = 0;
			cur_buf_size = fread(buf,sizeof(char),max_buf_size,stdin);
			if(cur_buf_size == 0) return 0;
		}
	}while( !isdigit(ch=buf[buf_ptr]) );

	while( isdigit(ch=buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(buf_ptr >= cur_buf_size)
		{
			buf_ptr = 0;
			cur_buf_size = fread(buf,sizeof(char),max_buf_size,stdin);
			if(cur_buf_size == 0) return n;
		}
	}
	return n;
}

int readint()
{
	int n=0,sign=1;
	char ch;
	do
	{
		buf_ptr++;
		if(buf_ptr >= cur_buf_size)
		{
			buf_ptr = 0;
			cur_buf_size = fread(buf,sizeof(char),max_buf_size,stdin);
			if(cur_buf_size == 0) return 0;
		}
	}while( !isdigit(ch=buf[buf_ptr]) && ch != '-');
	if(ch == '-')
	{
		sign=-1;
		buf_ptr++;
		if(buf_ptr >= cur_buf_size)
		{
			buf_ptr = 0;
			cur_buf_size = fread(buf,sizeof(char),max_buf_size,stdin);
			if(cur_buf_size == 0) return 0;
		}
	}
	while( isdigit(ch=buf[buf_ptr]) )
	{
		buf_ptr++;
		n = n*10 + ch-48;
		if(buf_ptr >= cur_buf_size)
		{
			if(cur_buf_size < max_buf_size) break;	// eof
			buf_ptr = 0;
			cur_buf_size = fread(buf,sizeof(char),max_buf_size,stdin);
			if(cur_buf_size == 0) break;
		}
	}
	return n*sign;
}

int main()
{
	int t = readint();
	while(t--)
	{
		int n = readint();
		vector<int> ar;
		for(int a=0;a<n;a++) ar.push_back(readint());
		//for(int a=0;a<n;a++) printf("%d ",ar[a]);
		sort(ar.begin(),ar.end());
		printf("%d ",ar[0]);
		if(n == 1)
			continue;
		if((n-1)%2)	// odd
		{
			for(int a=1;a<n;a+=2)
			{
				if(a == n-1) printf("%d ",ar[a]);
				else
				printf("%d %d ",ar[a+1],ar[a]);
			}
		}
		else
		{
			for(int a=1;a<n;a+=2)
			{
				printf("%d %d ",ar[a+1],ar[a]);
			}
		}
		printf("\n");
	}
}
