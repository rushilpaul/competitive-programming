//Program question at: http://www.codechef.com/problems/LUCKYSWP
#include <stdio.h>
char s[100002];
int main()
{
	int t; scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		int len = strlen(s);
		s[len] = ' '; s[len+1] = '\0'; len++;
		int s4, s7, f4, f7, n4, n7, max4, max7, max7_, a, last4=-1;
		s4 = s7 = f4 = f7 = n4 = n7 = max4 = max7 = 0;
		int flag=0;
		for(a=0;a<len;a++)
		{
			char c = s[a];
			if(c == '4') { n4++; last4=a; }
			if(c == '7') { flag=1; n7++; }
			if(!flag && c=='4') f4++;
			if(flag)
			{
				if(c != '4')
				{
					max4 = s4 > max4 ? s4 : max4;
					s4=0;
				}
				else s4++;
			}
			if(c != '7')
			{
				max7_ = max7;
				max7 = s7 > max7 ? s7 : max7;
				s7=0;
			}
			else s7++;
		}
		for(a=last4;a<len;a++) if(s[a] == '7') f7++;
		printf("n4 = %d\nn7 = %d\nfirst 4 = %d\nlast 7 = %d\nlongest 4 = %d\nlongest 7 = %d\n", n4,n7,f4,f7,max4,max7_);

		if(n7 > n4) printf("ans = %d\n\n", n7 + max4 + f4);
		else if(n4 > n7) printf("ans = %d\n\n", n4 + max7_ + f7);
		else printf("ans = %d\n\n", n4 + (max4+f4 > max7_+f7 ? max4+f4 : max7_+f7) );
	}
	return 0;
}
