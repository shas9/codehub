#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < int,int >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}


vector < pll > graph[1000005];
ll dp[1000005];
ll dp2[1000005];
ll subnode[1000005];
ll subnode2[1000005];
ll degree[1000005];

const ll maxn = 1000000;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

}

ll beauty(ll x)
{
    return vis[x] == 0;
}

void dfs(ll node, ll par)
{
    dp[node] = 0;
    subnode[node] = 0;

//    cout << node << " " << par << endl;

    for(auto it:graph[node])
    {
        if(it.first == par) continue;

        dfs(it.first,node);

        subnode[node] += subnode[it.first];

        if(it.second)
        {
            dp[node] += subnode[it.first];
        }
        else
        {
            dp[node] += dp[it.first];
        }
    }

    subnode[node] += 1;
}

void solve(ll node, ll par, ll conn)
{
    if(par)
    {
        if(conn)
        {
            dp2[node] = subnode2[par];
        }
        else
        {
            dp2[node] = dp2[par];

            dp2[node] -= dp[node];
        }
    }

    dp2[node] += dp[node];


    for(auto it:graph[node])
    {
        if(it.first == par) continue;

        subnode2[node] = subnode2[par] + subnode[node] - subnode[it.first];

        solve(it.first,node,it.second);
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in9.txt", "r", stdin);
//
//    freopen("out09.txt", "w", stdout);

    sieve();

    slld(n);
    {
//        precal(n);
        assert(2 <= n && n <= 1000000);

        for(i = 1; i < n; i++)
        {
            ll u, v, w;

            slld(u);
            slld(v);
            slld(w);

            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            assert(1 <= w && w <= 1000000);
            assert(u != v);

            w = beauty(w);

            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));

            degree[u]++;
            degree[v]++;
        }

        ll root = 0;

//        bug;

        for(i = 1; i <= n; i++)
        {
            if(degree[i] == 1)
            {
                root = i;
                dfs(i,-1);
                break;
            }
        }

        solve(root,0,0);


        long long anss = 0;

        for(i = 1; i <= n; i++)
        {
            anss += ((long long)dp2[i] * (long long)(dp2[i] - 1));
        }


        printf("%lld\n", anss);

    }
}




