//Program question at: http://www.codechef.com/JAN13/problems/CVOTE
#include <stdio.h>
#include <stdlib.h>
int maxio=4096;
char buf[4096], *s = buf + 4096;
inline char _getc(void) { if(s >= buf + maxio) { fread(buf,sizeof(char),maxio,stdin); s = buf; } return *(s++); }
inline int input() { char t = _getc(); int n=1,res=0; while(t!='-' && !isdigit(t)) t=_getc(); if(t=='-') { n=-1; t=_getc(); } while(isdigit(t)) { res = 10*res + (t&15); t=_getc(); } return res*n; }

typedef struct Name_
{
	char name[11];
	char city[11];
	int s;
} Name;

inline int cmp(const void *a, const void *b)
{
	return strcmp( (*(Name**)a)->name, (*(Name**)b)->name );
}

inline int cmp1(const void *a, const void *b)
{
	return strcmp( (*(Name**)a)->city, (*(Name**)b)->city );
}

inline int cmp2(char *a, char *b)
{
	return strcmp(a,b);
}

int search(char* key, Name **addr, int size)
{
	int l=0,r=size-1,m,a;
	while(l <= r)
	{
		m = (l+r)/2;
		a = strcmp(key,addr[m]->name);
		if(a == 0) return m;
		if(a > 0) l = m+1;
		else r = m-1;
	}
	printf("error\n");
	return -1;
}

int main()
{
	int n = input(), m = input(), k=0,a,b;
	char ch;
	Name names[n];
	Name **addr = (Name**)malloc(sizeof(Name*)*n);
	for(a=0;a<n;a++)
	{
		names[a].s = 0;
		while( (ch = _getc()) != ' ') names[a].name[k++] = ch;
		names[a].name[k] = 0;
		k=0;
		while( (ch = _getc()) != '\n') names[a].city[k++] = ch;
		names[a].city[k] = 0;
		k=0;
		addr[a] = &names[a];
	}
	qsort(addr,n,sizeof(Name*),cmp);
	char chef[m][11];
	for(a=0;a<m;a++)
	{
		k=0;
		while( (ch = _getc()) != '\n') chef[a][k++] = ch;
		chef[a][k] = 0;
	}
	// main logic
	qsort(chef,m,11,(int(*)(const void*, const void*)) cmp2);
	int max=0,x=0;
	for(a=0;a<m;a++)
	{
		int i = search(chef[a],addr,n);
		(addr[i]->s)++;
		if(a == m-1) continue;
		while( !(strcmp(chef[a],chef[a+1])) )
		{
			a++;
			(addr[i]->s)++;
			if(a == m-1) break;
		}
		if(addr[i]->s > max)
		{
			max = addr[i]->s;
			x = a;
		}
	}
	qsort(addr,n,sizeof(Name*),cmp1);
	max=0; b=x;
	for(a=0;a<n;a++)
	{
		k=addr[a]->s;
		if(a != n-1)
		while( !(strcmp(addr[a]->city,addr[a+1]->city)) )
		{
			k += addr[a+1]->s;
			a++;
			if(a == n-1) break;
		}
		if(k > max) { max = k; x = a; }
	}
	printf("%s\n%s\n",addr[x]->city,chef[b]);
	return 0;
}
