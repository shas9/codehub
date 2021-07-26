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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define mx 300005

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pair < ll, ll > > graph[mx];

ll res;

ll arr[mx];
bool vis[mx];

ll dfs(ll x, ll y)
{
    if(vis[x]) return 0;

    vis[x] = 1;

    ll sz = graph[x].size();

    ll ans = 0;
    ll top_2 = 0;
    ll top_1 = 0;
    for(ll i = 0; i < sz; i++)
    {
        ll flag = dfs(graph[x][i].first, graph[x][i].second);

        if(flag > top_1)
        {
            top_2 = top_1;
            top_1 = flag;
        }
        else if(flag > top_2)
        {
            top_2 = flag;
        }
    }

    ans = arr[x] + top_1;
    res = max(res,ans + top_2);
    res = max(res, ans);

    return max(0LL,ans - y);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    for(ll ii = 1; ii <= n - 1; ii++)
    {
        slld(i);
        slld(j);
        slld(k);

        graph[i].push_back(make_pair(j,k));

//        bug;
    }

    dfs(1,0);

    printf("%lld\n", res);


}



