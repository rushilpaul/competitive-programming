//Program question at: http://www.codechef.com/JUNE12/problems/LUCKY8
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char buf[40];
int L[20], R[20], ans[20], len, ansn;

inline int count(int n)
{
	int a=0,c=0;
	for(;a<len;a++) if(ans[a] == n) c++;
	return c;
}

inline int max(int a, int b) { return a>b ? a:b; }
inline int min(int a, int b) { return a<b ? a:b; }
inline void f(int i, int n)
{
	int a=0,n4=0,n7=0,t;
	for(;a<=i;a++) if(ans[a] == 4) n4++; else if(ans[a] == 7) n7++;
	while(n)
	{
		if(n4 == n7)
		{
			n4 += n/2;
			n7 += (n-n/2);
			break;
		}
		else if(n4 > n7)
		{
			t = min(n,n4-n7);
			n -= t;
			n7 += t;
		}
		else if(n7 > n4)
		{
			t = min(n,n7-n4);
			n -= t;
			n4 += t;
		}
	}
	ansn = max(ansn,n4*n7);
}

void solve(int i, bool flagL, bool flagR)
{
	while(i<len)
	{
		if(flagL && !flagR)
		{
			if(4 > L[i])
			{
				f(i-1,len-i);
				return;
			}
			if(4 == L[i])
			{
				ans[i] = 4;
				solve(i+1, 1, 0);
				ans[i] = 7;
				f(i,len-i-1);
				return;
			}
			if(7 > L[i])
			{
				ans[i] = 7;
				f(i,len-i-1);
				return;
			}
			if(7 == L[i])
			{
				ans[i] = 8;
				f(i,len-i-1);
				ans[i] = 7;
				i++;
				continue;
			}
			// else
				ans[i] = 9;
				if(ans[i] > L[i])
				{
					f(i,len-i-1);
					return;
				}
				else
				{
					i++;
					continue;
				}
		}
		if(!flagL && flagR)
		{
			if(7 < R[i])
			{
				f(i-1,len-i);
				return;
			}
			if(7 == R[i])
			{
				ans[i] = 4;
				f(i,len-i-1);
				ans[i] = 7;
				i++;
				continue;
			}
			if(4 < R[i])
			{
				ans[i] = 4;
				f(i,len-i-1);
				return;
			}
			if(4 == R[i])
			{
				ans[i] = 3;
				f(i,len-i-1);
				ans[i] = 4;
				i++;
				continue;
			}
			// else
				ans[i] = 0;
				if(ans[i] < R[i])
				{
					f(i,len-i-1);
					return;
				}
				else
				{
					i++;
					continue;
				}
		}
		if(flagL && flagR)
		{
			if(R[i] - L[i] == 1)
			{
				ans[i] = L[i];
				solve(i+1,1,0);
				ans[i]++;
				solve(i+1,0,1);
				return;
			}
			bool four = 4 > L[i] && 4 < R[i];
			bool sev = 7 > L[i] && 7 < R[i];
			if (four && sev)
			{
				f(i-1,len-i);
				return;
			}
			else if (four && !sev)
			{
				ans[i] = 4;
				f(i,len-i-1);
			}
			else if (!four && sev)
			{
				ans[i] = 7;
				f(i,len-i-1);
			}
			if (L[i] == 4 || L[i] == 7 || R[i] == 4 || R[i] == 7)
			{
				if(L[i] == R[i]) { ans[i] = L[i]; i++; continue; }

				if(L[i] == 4 && R[i] == 7)
				{
					ans[i] = 4;
					solve(i+1,1,0);
					ans[i] = 7;
					solve(i+1,0,1);
					ans[i] = 5;
					f(i,len-i-1);
					return;
				}
				if(R[i] - L[i] >= 2)
				{
					ans[i] = L[i]+1;
					f(i,len-i-1);

					if(L[i] == 4 || L[i] == 7)
					{
						ans[i] = L[i];
						solve(i+1,1,0);
					}
					if(R[i] == 4 || R[i] == 7)
					{
						ans[i] = R[i];
						solve(i+1,0,1);
					}
					return;
				}
			}
			else
			{
				if (R[i] - L[i] >= 2)
				{
					ans[i] = L[i]+1;
					f(i,len-i-1);
					return;
				}
				ans[i] = L[i];
			}
		}
		i++;
	} // end of while
	ansn = max(ansn, count(4)*count(7));
}

int main()
{
	int a,tt; scanf("%d\n",&tt);
	while(tt--)
	{
		gets(buf); int t = strlen(buf),sp;
		for(a=t-1;a>0;a--) if(buf[a] == 32) { sp=a; break; }
		len = t-sp-1;
		memset(ans,0,len*4);
		for(a=0;a<len;a++) R[a] = buf[sp+1+a]-48;
		for(a=0;a<len-sp;a++) L[a] = 0;
		for(a=0;a<sp;a++) L[a+len-sp] = buf[a]-48;
		ansn = 0;
		solve(0,1,1);
		printf("%d\n",ansn);
	}
	return 0;
}
