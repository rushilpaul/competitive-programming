#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
#include <cassert>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;
 
//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
 
void assertOO(int a, int n, int b) {
	assert( a <= n && n <= b );
}
 
#define Q_LIMIT 5
#define M_LIMIT 100000
#define M 101000
 
int in[M], out[M], depth[M], time_stamp;
int ONES[M<<2], TWOS[M<<2];
int typ[M], v[M];
vi adj[M];
 
void update(int cur, int s, int e, int x, int *ST)
{
	if(x < s || e <= x) return;
	if(x == s && s == e-1)
	{
		printf("x = %d, node = %d\n",x,cur);
		ST[cur] = 1;
		return;
	}
	int m = (s+e)>>1, c1 = (cur << 1), c2 = c1 | 1;
	update(c1, s, m, x, ST);
	update(c2, m, e, x, ST);
	ST[cur] = ST[c1] + ST[c2];
}
 
int query(int cur, int s, int e, int S, int E, int *ST)
{
	if(s >= E || e <= S) return 0;
	if(s >= S && e <= E) return ST[cur];
	int m = (s+e)>>1, c1 = (cur << 1), c2 = c1 | 1;
	return query(c1, s, m, S, E, ST) + query(c2, m, e, S, E, ST);
}
 
void dfs(int cur, int prev, int _depth=0)
{
	in[cur] = time_stamp++;
	depth[cur] = _depth;
	rep(i, adj[cur].sz)
		if(adj[cur][i] != prev)
			dfs(adj[cur][i], cur, _depth+1);
	out[cur] = time_stamp;
}
 
long long nc2(int x)
{
	return (1LL * x * (x-1)) >> 1;
}

int main()
{
	int q;
	gi(q);
 
	assertOO(1, q, Q_LIMIT);
 
	while(q--) {
		time_stamp = 0;
		rep(i, M) adj[i].clear();
 
		int m;
		gi(m);
 
		assertOO(1, m, M_LIMIT);
 
		int n = 0;
		rep(i, m)
		{
			scanf("%d%d", &typ[i], &v[i]);
 
			assertOO(0, typ[i], 1);
			assertOO(0, v[i], n);
 
			if(typ[i] == 0) {
				n++;
				adj[v[i]].pb(n);
			}
		}
 
		dfs(0, -1);
		/*
		for(int a=0;a<8;a++)
			printf("%d ",a);
		printf("\n");
		for(int a=0;a<time_stamp;a++)
			printf("%d ",in[a]);
		printf("\n");
		for(int a=0;a<time_stamp;a++)
			printf("%d ",out[a]);
		printf("\n");
		*/
 
		memset(ONES, 0, sizeof ONES);
		memset(TWOS, 0, sizeof TWOS);
 
		update(1, 0, time_stamp, in[0], depth[0]%2 ? ONES : TWOS);
		n = 0;
		rep(i, m)
		{
			if (typ[i] == 0)
			{
				n++;
				printf("Updating: %s\n",depth[n]%2 ? "ones":"twos");
				update(1, 0, time_stamp, in[n], depth[n]%2 ? ONES : TWOS);
			}
			else
			{
				for(int a=1;a<=15;a++)
					printf("%d ",ONES[a]);
				printf("\n");
				for(int a=1;a<=15;a++)
					printf("%d ",TWOS[a]);
				printf("\n");
				long long ans = nc2(query(1, 0, time_stamp, in[v[i]], out[v[i]], ONES));
				ans += nc2(query(1, 0, time_stamp, in[v[i]], out[v[i]], TWOS));
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
