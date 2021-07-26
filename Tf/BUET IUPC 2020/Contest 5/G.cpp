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

vector < pair < ll, ll > > graph[6003];
ll dp[6003][6003];

ll sc[6003];

ll solve(ll node, ll fuel)
{
    if(fuel < 0) return 0;

    if(dp[node][fuel] != -1) return dp[node][fuel];

    dp[node][fuel] = 0;

    for(ll i = 0; i < graph[node].size(); i++)
    {
        dp[node][fuel] = max(dp[node][fuel], solve(graph[node][i].first, fuel - graph[node][i].second));
    }

    dp[node][fuel] += sc[node];

    return dp[node][fuel];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(k);

        for(i = 0; i <= n; i++)
        {
            graph[i].clear();
        }

        for(i = 0; i < n; i++)
        {
            slld(sc[i]);
        }

        for(i = 1; i <= m; i++)
        {
            ll u, v, c;

            slld(u);
            slld(v);
            slld(c);

            graph[u].push_back(make_pair(v,c));
        }

        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= k; j++)
                dp[i][j] = -1;
        }

        ans = 0;

        for(i = 0; i < 1; i++)
        {
            ans = max(ans, solve(i,k));
        }

        cout << ans << endl;


    }


}


