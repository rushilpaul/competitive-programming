//Program question at: http://www.codechef.com/SEP12/problems/HORSES
#include <stdio.h>
char s[60000];
void swap(int *x, int *y)
{
if(*x == *y) return;
*x ^= *y;
*y ^= *x;
*x ^= *y;
}
int split(int* ar, int pivot, int i, int j)
{
	int left = i;
	int right = j;
	while(left < right)
	{
		while( pivot < ar[right] && right > left) right--;
		swap(&ar[left], &ar[right]);
		while( pivot >= ar[left] && left < right) left++;
		swap(&ar[right], &ar[left]);
	}
	return left;
}
void sort(int* ar, int i, int j)
{
	int pivot = ar[i],sp;
	if(j > i)
	{
		sp = split(ar, pivot, i, j);
		ar[sp] = pivot;
		sort(ar, i, sp-1);
		sort(ar, sp+1, j);
	}
}
int main()
{
	int t; gets(s); t = atoi(s);
	while(t--)
	{
		int tmp=0,n=0,a,min=1000000000;
		gets(s);
		int ar[atoi(s)],len;
		gets(s); len = strlen(s);
		s[len] = 32; s[len+1] = 0;
		for(a=0;a<len+2;a++)
		{
			if(s[a] == 32)
			{
				ar[n++] = tmp;
				tmp = 0;
				continue;
			}
			tmp = tmp*10 + (s[a]-48);
		}
		sort(ar,0,n-1);
		for(a=0;a<n-1;a++)
		{
			tmp = ar[a+1] - ar[a];
			if(tmp < min) min = tmp;
			if(!min) break;
		}
		printf("%d\n",min);
	}
	return 0;
}
