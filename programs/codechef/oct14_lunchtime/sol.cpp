#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define init(mem,v) memset(mem,v,sizeof(mem))
#define read(n) scanf("%d",&n)

#define md 1000000009

ll num;
int tp;
ll mem[64][20];

// This works for both K=3 and 4. But there is a better "pattern solution" for K=3
ll dp(int pos,int carry){
    if(pos<0){
        if(carry==0) return 1;
        else return 0;
    }

    ll& ret=mem[pos][carry];
    if(ret>=0) return ret;

    ret=0;
    if(num & (1LL<<pos)) carry++;
    for(int send=0;send<=tp-1;send++){
        if(carry-send<=tp and send<=carry){
            ret=(ret+dp(pos-1,2*send))%md;
        }
    }
    return ret;
}

int main(){
    int t;
    read(t);
    while(t--){
        scanf("%d%lld",&tp,&num);
        if(tp==3) printf("%lld\n",(1+num/2)%md);
        else{
            init(mem,-1);
            printf("%lld\n",dp(63,0));
        }
    }
}