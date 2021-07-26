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

string str;

vector  < ll > graph[200005];

ll ans;

pll dp[200005];

pll trav(ll node, ll par)
{

//    cout << node << endl;

    ll sz = graph[node].size();


    ll cnt = 0;
    ll tots = 0, totj = 0;

    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[node][i];

        if(top == par) continue;

        dp[top] = trav(top,node);

        tots += dp[top].first;
        totj += dp[top].second;
    }

    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[node][i];

        cnt += dp[top].first * (totj - dp[top].second);
    }

    ans += cnt;

    if(node == 1) return make_pair(tots,totj);

    if(str[node - 2] == 's') return make_pair(tots  + 1,totj);

    return make_pair(tots,totj + 1);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    slld(n);

    cin >> str;

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    ans = 0;
    pll _x = trav(1,-1);

    cout << ans << endl;
}



