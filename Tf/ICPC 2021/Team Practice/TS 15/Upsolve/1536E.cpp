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

char grid[2003][2003];
ll pwr2[4000006];
const ll mod = 1000000007;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    pwr2[0] = 1;

    for(ll i = 1; i <= 4e6; i++) pwr2[i] = (2 * pwr2[i - 1]) % mod;

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        for(i = 1; i <= n; i++) cin >> grid[i] + 1;

        ll cnt = 0;

        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cnt += grid[i][j] == '#';

        ans = 1;

        bool on = 0;

        if(cnt == (n * m)) cnt--, on = 1;

        ans = pwr2[cnt];

        if(on == 1)
        {
            for(ll i = cnt - 1; i >= 0; i--) ans = (ans + pwr2[i]) % mod;
        }

        cout << ans << "\n";
    }


}


