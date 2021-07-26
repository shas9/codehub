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

ll dp[303][303];
ll arr[303];
const ll mod = 1000003;

ll mul[303];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll calc(ll x, ll y)
{
    ll ret = mul[y] * power(mul[x - 1], mod - 2, mod);

    ret %= mod;

    return ret;
}

ll solve(ll l, ll r)
{
    ll &ret = dp[l][r];

    if(ret != mnlld) return ret;

    if(l == r) return ret = arr[l] * arr[l];

    ret = mnlld + 1;

    for(ll i = l; i + 1 <= r; i++)
    {
        ret = max(ret, solve(l,i) + solve(i + 1, r) - 2 * calc(l,i) * calc(i + 1, r));
    }

    ll x = 1;

    for(ll i = l; i <= r; i++) x = (x * arr[i]) % mod;

    ret = (ret + x * x);

    return ret;
}



int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 0; i <= 300; i++) for(ll j = 0; j <= 300; j++) dp[i][j] = mnlld;

        ll gun = 1;
        mul[0] = 1;

        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            mul[i] = (mul[i - 1] * arr[i]) % mod;
            gun = (gun * arr[i]) % mod;
        }

        ans = (solve(1,n) - ((gun * gun))) ;

        cout << ans << "\n";
    }


}


