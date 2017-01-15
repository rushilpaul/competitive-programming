#include <stdio.h>
#include <string.h>
char s[1001];

inline int isdigit(char ch)
{ return ch >= '0' && ch <= '9'; }

int max(int s1, int s2, int e1, int e2)
{
	int a1,a2;
	for(a1=s1,a2=s2;a1<=e1 && a2<=e2;a1++,a2++)
	{
		if(!isdigit(s[a1])) s[a1] = '9';
		if(!isdigit(s[a2])) s[a2] = '9';
		if(s[a1] == s[a2]) continue;
		if(s[a1] > s[a2]) return 1;
		else return 0;
	}
	return 0;
}

int main()
{
	gets(s);
	int l = strlen(s),a=0;
	int start=0,end=0,c=0,f=0;
	int a_start=0, a_end, len=0;
	int last=0;
	while(isdigit(s[a])) { c++; a++; }
	if(!a)	// first letter is at 0th pos
	{
		a_start = a;
		start = a;
		s[a] = '9';
		f=1;
	}
	if(a == l) { printf("%s",s); return 0; }
	for(;a<l;a++)
	{
		if(s[a] >= '0' && s[a] <= '9') { c++; last = 0; }
		else
		{
			if(f)
			{
				a_end = end-1;
				len = c+1;
				f=0;
			}
			else
			{
				if(!last) { last = 1; continue; }
				end = a-1;
				if( (c == len && max(start,a_start,end,a_end)) || (c > len) ) { a_start = start; a_end = end; len = c+1; }
				last = 0;
				a = end;
			}
		}
	}
	if(isdigit(s[l-1]))
	{
		end = l-1;
		if(c == len && max(start,a_start,end,a_end) ) { a_start = start; a_end = end; len = c; }
		if(c > len) { a_start = start; a_end = end; len = c; }
	}
	while(a_start <= a_end) { if(!isdigit(s[a_start])) s[a_start] = '9'; printf("%c",s[a_start++]); }
}
