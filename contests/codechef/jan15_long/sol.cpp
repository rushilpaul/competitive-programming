#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
inline int getchar_unlocked(){return getchar();}
#endif 
inline void in(int &x){int c=getchar_unlocked();x = 0;int neg=0;for(;((c<48||c>57)&&c!='-');c=getchar_unlocked());if(c=='-'){neg=1;c=getchar_unlocked();}for(;c>47&&c<58;c=getchar_unlocked()){x=(x<<1)+(x<<3)+c-48;}if(neg)x=-x;}
 
#define mod 1000000007ll
int T,n,m,L,R,P[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
short F[5][1002];

void preprocess()
{
	for(int k,i=2;i<1001;i++)
	{
		F[0][i]=0;
		k=i;
		for(int j=0;P[j]*P[j]<=k;j++)
		if(k%P[j]==0)
		{
			int d=1;
			while(k%P[j]==0)
			{
				d*=P[j];
				k/=P[j];
			}
			F[++F[0][i]][i]=d;
		}
		if(k>1)F[++F[0][i]][i]=k;
	}
}
long long pw(long long a,long long p)
{
	long long res=1;
	a%=mod;
	while(p)
	{
		if(p&1)res=res*a%mod;
		p>>=1;
		a=a*a%mod;
	}
	return res;
}
 
int main()
{
	preprocess();
	in(T);//scanf("%d",&T);
	while(T--)
	{
		in(n);in(m);in(L),in(R);//scanf("%d %d %d %d",&n,&m,&L,&R);
		long long d,res=0,cal=pw(m,n);
		if(L==1){res=cal;L++;}
		for(int i=L;i<=R;i++)
		{
			res=(res+cal)%mod;
			if(res<0)res+=mod;
			
			int len=F[0][i];
			if(len==1)
			{
				res=(res-pw(m-m/i,n))%mod;
			}
			if(len==2)
			{
				for(int x,j=1;j<=len;j++)
				{
					x=F[j][i];
					d=0;
					for(int k=1;k<=m;k++)if(k%x!=0)d++;
					res=(res-pw(d,n))%mod;
				}
				d=0;
				for(int j=1;j<=m;j++)if(j%F[1][i]!=0&&j%F[2][i]!=0)d++;
				res+=pw(d,n);
			}
			else if(len==3)
			{
				for(int x,j=1;j<=len;j++)
				{
					x=F[j][i];
					d=0;
					for(int k=1;k<=m;k++)if(k%x!=0)d++;
					res=(res-pw(d,n))%mod;
					//cout<<res<<" == "<<x<<" "<<d<<" : "<<pw(d,n)<<endl;
				}
				//cout<<".........\n";			
				for(int y,x,j=1;j<=len;j++)
				{
					x=F[j][i];
					if((j+1)>len)y=F[j%len+1][i];
					else y=F[j+1][i];
					d=0;
					for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0)d++;
					res=(res+pw(d,n))%mod;
					//cout<<res<<" == "<<x<<" "<<y<<" "<<d<<" : "<<pw(d,n)<<endl;
				}
				//cout<<",,,,,,,,,\n";			
				d=0;				
				for(int j=1;j<=m;j++)if(j%F[1][i]!=0&&j%F[2][i]!=0&&j%F[3][i]!=0)d++;
				res=(res-pw(d,n))%mod;
				//cout<<res<<" == "<<d<<" : "<<pw(d,n)<<endl;
			}
			else if(len==4)
			{
				int x,y,z;
				for(int j=1;j<=len;j++)
				{
					x=F[j][i];
					d=0;
					for(int k=1;k<=m;k++)if(k%x!=0)d++;
					res=(res-pw(d,n))%mod;
				}
				
				for(int j=1;j<=len;j++)
				{
					x=F[j][i];
					if((j+1)>len)y=F[j%len+1][i];
					else y=F[j+1][i];
					d=0;
					for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0)d++;
					res=(res+pw(d,n))%mod;
					//cout<<res<<" == "<<x<<" "<<y<<" "<<d<<" : "<<pw(d,n)<<endl;
				}
				
				d=0;
				x=F[1][i],y=F[3][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0)d++;
				res=(res+pw(d,n))%mod;
				
				d=0;
				x=F[2][i],y=F[4][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0)d++;
				res=(res+pw(d,n))%mod;	
				
				d=0;
				x=F[1][i],y=F[2][i],z=F[3][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0&&k%z!=0)d++;
				res=(res-pw(d,n))%mod;
				
				d=0;
				x=F[1][i],y=F[2][i],z=F[4][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0&&k%z!=0)d++;
				res=(res-pw(d,n))%mod;
				
				d=0;
				x=F[1][i],y=F[3][i],z=F[4][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0&&k%z!=0)d++;
				res=(res-pw(d,n))%mod;
				
				d=0;
				x=F[2][i],y=F[3][i],z=F[4][i];
				for(int k=1;k<=m;k++)if(k%x!=0&&k%y!=0&&k%z!=0)d++;
				res=(res-pw(d,n))%mod;
				
				d=0;
				for(int j=1;j<=m;j++)
				if(j%F[1][i]!=0&&j%F[2][i]!=0&&j%F[3][i]!=0&&j%F[4][i]!=0)d++;				
				res=(res+pw(d,n))%mod;
			}
		}
		printf("%lld\n",(res+mod)%mod);
	}
	return 0;
} 