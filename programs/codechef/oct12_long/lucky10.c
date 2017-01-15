//Program question at: http://www.codechef.com/OCT12/problems/LUCKY10
#include <stdio.h>
#define min(a,b) a<b?a:b
#define put(c,n) while(n--) putchar(c)
typedef long long LL;

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		char ch = getchar();
		LL A_4=0, A_7=0, A_03=0, A_56=0, B_4=0, B_7=0, B_03=0, B_56=0, tmp;
		while(!isdigit(ch)) ch = getchar();
		do
		{
			ch -= 48;
			if(ch == 4) A_4++;
			else if(ch == 7) A_7++;
			else if(ch == 5 || ch==6) A_56++;
			else if(ch < 4) A_03++;
		}
		while(isdigit(ch = getchar()));
		while(!isdigit(ch)) ch = getchar();
		do
		{
			ch -= 48;
			if(ch == 4) B_4++;
			else if(ch == 7) B_7++;
			else if(ch == 5 || ch==6) B_56++;
			else if(ch < 4) B_03++;
		}
		while(isdigit(ch = getchar()));
		// for 7s in A
		tmp = min(A_7, B_56);
		A_7 -= tmp;
		B_56 -= tmp;
		put('7',tmp);
		if(!A_7) goto B7;
		tmp = min(A_7,B_03);
		A_7 -= tmp;
		B_03 -= tmp;
		put('7',tmp);
		if(!A_7) goto B7;
		tmp = min(A_7,B_4);
		A_7 -= tmp;
		B_4 -= tmp;
		put('7',tmp);
		if(!A_7) goto B7;
		tmp = min(A_7,B_7);
		A_7 -= tmp;
		B_7 -= tmp;
		put('7',tmp);
		
		B7:;	// for 7s in B
		tmp = min(B_7, A_56);
		B_7 -= tmp;
		A_56 -= tmp;
		put('7',tmp);
		if(!B_7) goto A4;
		tmp = min(B_7,A_03);
		B_7 -= tmp;
		A_03 -= tmp;
		put('7',tmp);
		if(!B_7) goto A4;
		tmp = min(B_7,A_4);
		B_7 -= tmp;
		A_4 -= tmp;
		put('7',tmp);
		if(!B_7) goto A4;
		tmp = min(B_7,A_7);
		B_7 -= tmp;
		A_7 -= tmp;
		put('7',tmp);
		
		A4:;	// for 4s in A
		tmp = min(A_4,B_03);
		A_4 -= tmp;
		B_03 -= tmp;
		put('4',tmp);
		if(!A_4) goto B4;
		tmp = min(A_4,B_4);
		A_4 -= tmp;
		B_4 -= tmp;
		put('4',tmp);
		
		B4:;	// for 4s in B
		tmp = min(B_4,A_03);
		B_4 -= tmp;
		A_03 -= tmp;
		put('4',tmp);
		if(!B_4) goto end;
		tmp = min(B_4,A_4);
		B_4 -= tmp;
		A_4 -= tmp;
		put('4',tmp);
		end:
		putchar('\n');
	}
	return 0;
}
