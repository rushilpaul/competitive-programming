#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define max_buf_size 4096
typedef long long LL;
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

LL readuLL()
{
	LL n = 0;
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

int main()
{
	int t = readint();
	while(t--)
	{
		LL n = readuLL();
		
	}
}
