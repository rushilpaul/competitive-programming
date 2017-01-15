//Program question at: http://www.codechef.com/AUG12/problems/LEBOMBS
#include <stdio.h>
#include <string.h>
char B[1001];

int main()
{
    int t; scanf("%d\n",&t);
    while(t--)
    {
        int ans=0,a=0,n;
        scanf("%d\n",&n);
        gets(B);
        if(n==1)
        {
            if(B[0] == '1') printf("0\n");
            else printf("1\n");
            continue;
        }
        for(; a<n; a++)
            if(B[a] == '0')
            {
                if(a==0) {
                    if(B[1] == '0') ans++;
                }
                else if(a==n-1) {
                    if(B[n-2] == '0') ans++;
                }
                else if(B[a-1] == '0' && B[a+1] == '0') ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
