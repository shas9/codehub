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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define mx 1000016

vector < ll > g[1000016];

ll par[21][mx];
ll depth[mx];
ll pwr[21];

void dfs0(ll src,ll p,ll level)
{
    depth[src]=level;
    par[0][src]=p;
    for(ll i=0; i<g[src].size(); i++)
    {
        ll adj=g[src][i];
        if(adj!=p)
        {
            dfs0(adj,src,level+1);
        }
    }
}
void preL(ll n)
{

    for(ll i=1; i<=17; i++)
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
    for(ll i=0; i<=17; i++)
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
    for(ll i=17; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

ll dist(ll u, ll v)
{
	return depth[u] + depth[v] - (2 * depth[lca(u,v)]);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(m);

    n = 4;

    for(ll i = 2; i <= 4; i++)
    {
		g[1].pb(i);
		g[i].pb(1);
    }

    for(ll i = 1; i <= m; i++)
    {
		slld(input);

		g[input].pb(n + 1);
		g[input].pb(n + 2);

		g[n + 1].pb(input);
		g[n + 2].pb(input);

		n += 2;
    }

    ll lft = 2, rgt = 4;
    ans = 2;


    dfs0(1,-1,0);
    preL(n);
    n = 5;

    for(ll i = 1; i <= m; i++)
    {
		ll ans1 = dist(n,lft);
		ll ans2 = dist(n,rgt);

		if(ans1 > ans && ans1 > ans2)
		{
			ans = ans1;
			rgt = n;
		}
		else if(ans2 > ans)
		{
			ans = ans2;
			lft = n;
		}

//		cout << n << " " <<  lft << " " << rgt << " " << ans1 << " " << ans2 << " " << lca(n,rgt) <<  endl;

		n += 2;

		printf("%d\n", ans);
    }


}


