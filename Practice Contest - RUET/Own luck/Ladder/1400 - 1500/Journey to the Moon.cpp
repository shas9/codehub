
#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define mx 100000


using namespace std;

vector < ll > graph[mx + 10];
ll n, p;
ll arr[mx + 10];
bool vis[mx + 10];

ll siz;

ll dfs(ll u)
{
    vis[u] = 1;

    ll x = graph[u].size();

    for(ll i = 0; i < x; i++)
    {
        ll v = graph[u][i];

        if(vis[v] == 0)
        {
            siz++;
            dfs(v);
        }
    }

    return siz;
}


ll solve()
{
    ll i = 0;

    arr[i] = 0;

    memset(vis,false,sizeof(vis));

    for(ll j = 0; j < n; j++)
    {
        if(vis[j] == 0)
        {
//            cout << " - " << j << endl;
            siz = 1;
            arr[++i] = dfs(j);
            arr[i] += arr[i - 1];
        }
    }

//    for(ll j = 1; j <= i; j++)
//    {
//        cout << arr[j] - arr[j - 1] << " ";
//    }
//
//    cout << endl;

    ll ans = 0;

    for(ll j = 1; j < i; j++)
    {
        ll x = arr[i] - arr[j];

//        cout << x << " -- " << arr[j] << endl;
        ans += (arr[j] - arr[j - 1]) * x;
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, o, t;
    ll testcase;
    ll input, flag, tag, ans;
    ll temp;

    ll c, d, nl, np;
    ll r, x, u, v;

    string in;

//    freopen("in.txt", "r", stdin);

    while(cin >> n >> p)
    {
        for(i = 0; i <= n; i++)
        {
            graph[i].clear();
        }

        for(i = 1; i <= p; i++)
        {
            slld(u);
            slld(v);

            graph[u].pb(v);
            graph[v].pb(u);
        }

        ans = solve();

        plld(ans);

    }


}






