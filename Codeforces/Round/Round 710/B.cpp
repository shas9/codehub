 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

string str;
ll dp[55][55][2][2];
ll n, k;

ll solve(ll pos, ll last, bool first, bool on)
{
    ll &ret = dp[pos][last][first][on];

    if(ret != -1) return ret;

    if(pos == n)
    {
        if(on) return 0;

        return 1e10;
    }

    if(str[pos] == '.')
    {
        return ret = solve(pos + 1, last, first, on);
    }

    if(first == 0)
    {
        return ret = 1 + solve(pos + 1, pos, 1, 1);
    }

    if((pos - last) > k) return ret = 1e10;

    ret = solve(pos + 1, last, first, 0);

    ret = min(ret, 1 + solve(pos + 1, pos, first, 1));

    return ret;
}

int main()
{
    ll i, j, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;

        cin >> str;

        memset(dp,-1,sizeof dp);

        ans = solve(0,0,0,0);

        cout << ans << "\n";
    }


}

