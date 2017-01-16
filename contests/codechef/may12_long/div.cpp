//Problem setter's solution
#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000
#define maxn 1000000

typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;



int main()
{
    int i,j,k,tests,cs=0,n,m;


    //freopen("D:\\divpair.in","r",stdin);
    //freopen("D:\\divpair2.out","w",stdout);

    scanf("%d",&tests);
    assert(1<=tests && tests<=100000);

    while(tests--)
    {
        scanf("%d%d",&n,&m);
        assert(1<=n && n<=1000000000);
        assert(2<=m && m<=1000000000);


        LL x=n/m,y=n%m;
        LL ans=0;

        ans += x*x*(m-1);
        ans += x*(x-1);
        if(m%2==0) ans-=x;

        ans/=2;
        ans+=x*y;
        if(y>m/2) ans+= y-m/2;

        printf("%lld\n",ans);
    }
    return 0;
}

