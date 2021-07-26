 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll f[10];

const ll mod = (1e9) + 7;

ll dp[10][200005];

ll solve(ll x, ll pos)
{
    if(pos == 0) return 0;

    ll &ret = dp[x][pos];

    if(ret != -1) return ret;

    ret = 0;
    if(x == 9) ret = 1 + solve(0, pos - 1) + solve(1, pos - 1);
    else ret = solve(x + 1, pos - 1);

    while(ret >= mod) ret -= mod;

    return ret;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    cin >> testcase;

    memset(dp,-1,sizeof dp);

    for(ll i = 0; i < 10; i++)
    {
        for(ll j = 1; j <= 200000; j++) solve(i,j);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        string s;
        cin >> s >> m;

        ans = 0;

        for(auto it: s)
        {
            ll num = it - '0';

            ans += solve(num,m);
        }

        cout << (ans + s.size()) % mod << "\n";
    }


}

