#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(),v.end()
#define pb push_back

LL ar[86] = { 2, 3, 4, 6, 9, 14, 22, 35, 56, 90, 145, 234, 378, 611, 988, 1598, 2585, 4182, 6766, 10947, 17712, 28658, 46369, 75026, 121394, 196419, 317812, 514230, 832041, 1346270, 2178310, 3524579, 5702888, 9227466, 14930353, 24157818, 39088170, 63245987, 102334156, 165580142, 267914297, 433494438, 701408734, 1134903171, 1836311904, 2971215074, 4807526977, 7778742050, 12586269026, 20365011075, 32951280100, 53316291174, 86267571273, 139583862446, 225851433718, 365435296163, 591286729880, 956722026042, 1548008755921, 2504730781962, 4052739537882, 6557470319843, 10610209857724, 17167680177566, 27777890035289, 44945570212854, 72723460248142, 117669030460995, 190392490709136, 308061521170130, 498454011879265, 806515533049394, 1304969544928658, 2111485077978051, 3416454622906708, 5527939700884758, 8944394323791465, 14472334024676222, 23416728348467686, 37889062373143907, 61305790721611592, 99194853094755498, 160500643816367089, 259695496911122586, 420196140727489674, 679891637638612259 };

map<LL, vector<int> > dp;

vector<int> f(LL x, vector<int>& done)
{
	if(x < 2) return {-1};
	if(x == 2 and done[0] == 0) return {0};
	if(x == 3 and done[1] == 0) return {1};
	auto it = dp.find(x);
	if(it != dp.end()) return it->second;
	rep(i,86)
	{
		if(done[i])
			continue;
		done[i] = 1;
		auto ret = f(x-ar[i], done);
		done[i] = 0;
		if(ret[0] != -1)
		{
			ret.pb(i);
			dp[x] = ret;
			return dp[x];
		}
	}
	dp[x] = {-1};
	return {-1};
}

class AlmostFibonacciKnapsack
{
	public:
		vector <int> getIndices(long long x)
		{
			vector<int> done(86,0);
			vector<int> ans = f(x,done);
			for(int &i : ans) i++;
			return ans;
		}
};

int main()
{
	AlmostFibonacciKnapsack ob;
	for(LL x = 2; x <= 1000; x++)
	{
		dp.clear();
		auto r = ob.getIndices(x);
		assert(r[0] != -1);
		if(x % 100 == 0) printf("%lld\n",x);
	}
	return 0;
}


