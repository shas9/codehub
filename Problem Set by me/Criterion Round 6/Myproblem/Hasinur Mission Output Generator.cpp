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

//ll power(ll x, ll y, ll p)
//{
//    ll res = 1;      // Initialize result
//
//    x = x % p;  // Update x if it is more than or
//    // equal to p
//
//    while (y > 0)
//    {
//        // If y is odd, multiply x with result
//        if (y & 1)
//            res = (res*x) % p;
//
//        // y must be even now
//        y = y>>1; // y = y/2
//        x = (x*x) % p;
//    }
//    return res;
//}

//ll fact[1000005];
vector < pll > graph[1000005];
ll dp[1000005];
ll dp2[1000005];
ll subnode[1000005];
ll subnode2[1000005];
ll degree[1000005];

const ll maxn = 1000000;
bool vis[maxn+10];

void clr()
{
    for(ll i = 1; i <= 1000000; i++)
    {
        graph[i].clear();
        dp[i] = dp2[i] = subnode2[i] = subnode[i] = degree[i] = 0;
    }
}

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

//    while(cin >> n >> m)
//    {
//        cout << npr(n,m) << " " << n * (n - 1) << endl;
//    }

    sieve();

    for(ll cs = 0; cs <= 11; cs++)
    {
        clr();
        string str;

        ll tmp = cs / 10;

        str = tmp + '0';

        str += (cs % 10) + '0';

        str += ".in";

//        cout << str << endl;

        char ch[10];

        for(i = 0; i < str.size(); i++)
        {
            ch[i] = str[i];
        }

        ch[str.size()] = '\0';

        char *c = ch;

//        cout << c << endl;
        freopen(c, "r", stdin);

        str = "";

        tmp = cs / 10;

        str = tmp + '0';

        str += (cs % 10) + '0';

        str += ".out";

//        cout << str << endl;

        char chf[10];

        for(i = 0; i < str.size(); i++)
        {
            chf[i] = str[i];
        }

        chf[str.size()] = '\0';

        char *c1 = chf;

//        cout << c << endl;
        freopen(c1, "w", stdout);

        slld(n);
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

//        bug;

        solve(root,0,0);

//        bug;


        long long anss = 0;

        for(i = 1; i <= n; i++)
        {
//            cout << i << " " << dp2[i] << " " << dp[i] << endl;

//            cout << npr(5,2) << endl;

            anss += ((long long)dp2[i] * (long long)(dp2[i] - 1));
        }


        printf("%lld\n", anss);

    }
}





