// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector<ll>graph[200005];
ll par[20][200005];
ll depth[200005];
ll pwr[20];
ll arr[200005];
ll n;

void clr(ll n)
{
	for(ll i = 0; i <= n + 3; i++)
	{
		for(ll j = 0; j < 20; j++) par[j][i] = 0;
		depth[i] = 0;
		graph[i].clear();
	}
}

void dfs0(ll src,ll p,ll level)
{
    depth[src]=level;
    par[0][src]=p;
    for(ll i=0; i<graph[src].size(); i++)
    {
        ll adj=graph[src][i];
        if(adj!=p)
        {
            dfs0(adj,src,level+1);
        }
    }
}
void preL()
{

    for(ll i=1; i<=19; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(par[i-1][j]==-1)continue;
            par[i][j]=par[i-1][par[i-1][j]];                       ///i means 2^i th parent of j th node par[i][j] means 2^i th parent of jth node
        }
    }
}
ll lca(ll u,ll v)
{
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    ll diff=depth[v]-depth[u];
    for(ll i=0; i<=19; i++)
    {
        if(check(diff,i)==1)
        {
            v=par[i][v];
        }
    }
    if(u==v)
    {
        return u;
    }
    for(ll i=19; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

ll solve(ll u, ll v)
{
	ll llca = lca(u,v);

	ll dist = depth[u] + depth[v] - (2 * depth[llca]) + 1;

	if(dist > 100) return 0;

//	assert(dist <= 100);

	ll vec[110];

	ll idx = 0;

	while(u != llca)
	{
		vec[idx++] = arr[u];

		u = par[0][u];
	}

	while(v != llca)
	{
		vec[idx++] = arr[v];

//		assert(idx <= 104);

		v = par[0][v];
	}

	vec[idx++] = arr[llca];

	sort(vec, vec + idx);

//	for(auto it: vec) cout << it << " ";
//	cout << endl;

	ll ret = 100;

	for(ll i = 1; i < idx; i++)
	{
		ret = min(ret, vec[i] - vec[i - 1]);
	}

	return ret;
}


int main()
{
    ll i, j, k, l,m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		clr(n);
		slld(m);

		for(i = 1; i <= n; i++) slld(arr[i]);

//		for(i = 0; i <= n + 2; i++) graph[i].clear();

		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}


		dfs0(1,-1,0);
		preL();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			ans = solve(u,v);

			printf("%d\n", ans);
		}
    }


}



