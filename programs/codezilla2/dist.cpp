//Program question at: http://www.codechef.com/COZL2012/problems/RBX12R01
#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

typedef long long LL;

int maxio=1000000;
char buf[1000000], *s = buf + maxio;
inline char getc1(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline LL input() { char t = getc1(); LL n=1,res=0; while(t!='-' && !isdigit(t)) t=getc1(); if(t=='-') { n=-1; t=getc1(); } while(isdigit(t)) {   res = res*10 + (t&15); t=getc1(); } return res*n; }

char dir[] = { 'U', 'D', 'L', 'R' };
char left_[] = { 'L', 'R', 'D', 'U' };
char rite[] = { 'R', 'L', 'U', 'D' };

inline int find(char d)
{
	for(int a=0;a<4;a++) if(dir[a] == d) return a;
	return -1;
}

int main()
{
	int t = input();
	while(t--)
	{
		LL x=0, y=0;
		char dr = ' ', cur='U', ans='U';
		do
		{
			LL steps = input();
			dr = getc1();
			if(cur == 'U') y += steps;
			else if(cur == 'D') y -= steps;
			else if(cur == 'L') x -= steps;
			else if(cur == 'R') x += steps;	
			if(dr == 'L') cur = left_[find(cur)];
			else if(dr == 'R') cur = rite[find(cur)];
		}
		while (dr != '\n' && dr != '\r');
		double dist = sqrt(x*x + y*y);
		stringstream ss; ss << dist;
		string str = ss.str();
		int i = str.find(".");
		if(i == -1) printf("%.1f", dist);
		else printf("%s", str.substr(0,i+2).c_str());

		if(!x)
			printf("%s\n", y>0 ? "N" : "S");
		else if(!y)
			printf("%s\n", x>0 ? "E" : "W");
		else if(x > 0)
			printf("%s\n", y>0 ? "NE" : "SE");
		else if(x < 0)
			printf("%s\n", y>0 ? "NW" : "SW");
	}
	return 0;
}
