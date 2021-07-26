 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

ll dp[1003][1003][3][2][2];
const ll mod = 998244353;
string x, y;

ll solve(ll posx, ll posy, ll took, bool xt, bool yt)
{
    ll &ret = dp[posx][posy][took][xt][yt];

    if(ret != -1) return ret;

    if(posx == x.size() && posy == y.size()) return ret = (xt && yt);

    ret = (xt && yt);

    if(took == 0)
    {
        ret = solve(posx + 1, posy, 1, 1, 0) + solve(posx, posy + 1, 2, 0, 1);
    }
    else if(took == 1)
    {
        if(posx < x.size() && x[posx] != x[posx - 1])
        {
            ret += solve(posx + 1, posy, 1, 1, yt);
        }

        if(posy < y.size() && x[posx - 1] != y[posy])
        {
            ret += solve(posx, posy + 1, 2, xt, 1);
        }
    }
    else
    {
        if(posx < x.size() && x[posx] != y[posy - 1])
        {
            ret += solve(posx + 1, posy, 1, 1, yt);
        }

        if(posy < y.size() && y[posy - 1] != y[posy])
        {
            ret += solve(posx, posy + 1, 2, xt, 1);
        }
    }

    return ret %= mod;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> x >> y)
    {
        memset(dp,-1,sizeof dp);

        ans = 0;

        for(ll i = 0; i < x.size(); i++)
        {
            for(ll j = 0; j < y.size(); j++)
            {
                ans = (ans + solve(i,j,0,0,0)) % mod;
            }
        }

        cout << ans << "\n";
    }


}

