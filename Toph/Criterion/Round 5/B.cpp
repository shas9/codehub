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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pll > graph[1000006];
ll arr[1000006];

ll solve(ll par, ll node)
{
    ll ret = 0;

    for(ll i = 0; i < graph[node].size(); i++)
    {
        if(graph[node][i].first == par) continue;

        ll x = solve(node,graph[node][i].first);

        x = min(x,graph[node][i].second);

        ret += x;
    }

    return ret + arr[node];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i < n; i++)
    {
        ll u, v, c;

        slld(u);
        slld(v);
        slld(c);

        graph[u].push_back(make_pair(v,c));
        graph[v].push_back(make_pair(u,c));
    }

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }
    ans = solve(-1,m);

    cout << ans << endl;

}



