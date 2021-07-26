// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

string str;
ll dp[100005];
const ll mod = (1e9) + 7;

ll solve(ll pos)
{
    ll &ret = dp[pos];

    if(ret != -1) return ret;

    if(pos <= 1) return ret = 1;

    ret = (solve(pos - 2) + solve(pos - 1)) % mod;

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
        memset(dp, -1, sizeof dp);

        ll n = 0;
        ll u = 0;
        ans = 1;

        for(auto it: str)
        {
            if(it == 'n')
            {
                ans = (ans * solve(u)) % mod;
                u = 0;
                n++;
            }
            else if(it == 'u')
            {
                ans = (ans * solve(n)) % mod;
                n = 0;
                u++;
            }
            else if(it == 'm' || it == 'w')
            {
                ans = 0;
            }
            else
            {
                ans = (ans * solve(u) * solve(n)) % mod;
                n = u = 0;
            }
        }

        ans = (ans * solve(u) * solve(n)) % mod;

        cout << ans << "\n";
    }


}
