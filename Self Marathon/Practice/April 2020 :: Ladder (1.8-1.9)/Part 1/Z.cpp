#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

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

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll fact[100005];
vector < pll > graph[100005];
ll dp[100005];
ll dp2[100005];
ll subnode[100005];
ll subnode2[100005];
ll degree[100005];

void precal(ll n)
{
    fact[0] = 1;
    ll i;

    for(i = 1; i <= 100000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    for(i = 1; i <= n; i++)
    {
        graph[i].clear();
        dp[i] = 0;
        dp2[i] = 0;
        degree[i] = 0;
        subnode[i] = 0;
        subnode2[i] = 0;
    }

}

ll npr(ll n, ll r)
{
    if(r > n) return 0;

    return (fact[n] * power(fact[n - r], mod - 2, mod)) % mod;
}

ll beauty(ll x)
{
    while(x)
    {
        ll y = x % 10;

        if(y == 4 || y == 7);
        else return 0;

        x /= 10;
    }

    return 1;
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

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    while(cin >> n >> m)
//    {
//        cout << npr(n,m) << " " << n * (n - 1) << endl;
//    }


    while(cin >> n)
    {
        precal(n);

        for(i = 1; i < n; i++)
        {
            ll u, v, w;

            cin >> u >> v >> w;

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

//        bug;

        solve(root,0,0);

//        bug;


        ll anss = 0;

        for(i = 1; i <= n; i++)
        {
//            cout << i << " " << dp2[i] << " " << dp[i] << endl;

//            cout << npr(5,2) << endl;

            anss += (dp2[i] * (dp2[i] - 1));
        }


        cout << anss << endl;

    }
}
