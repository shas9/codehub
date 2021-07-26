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

ll lft[200], rgt[200];
const ll mod = 1e9 + 7;

ll power(ll x, ll y, ll p)
{
    if(y < 0) return 0;

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

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        string s;
        cin >> s;

        memset(lft,0,sizeof lft);
        memset(rgt,0,sizeof rgt);

        for(ll i = 0; i < n; i++)
        {
            rgt[s[i]]++;
        }

        ans = 0;

        ll tot = rgt['?'];

        for(ll i = 0; i < n; i++)
        {
            rgt[s[i]]--;
            bool mark = s[i] == '?';

            if(s[i] == 'b' || s[i] == '?')
            {
                ans += (lft['a'] * rgt['c'] * power(3, tot - mark, mod)) % mod;
                ans += ((lft['?'] * rgt['c']) % mod * power(3, tot - mark - 1, mod)) % mod;
                ans += ((lft['a'] * rgt['?']) % mod * power(3, tot - mark - 1, mod)) % mod;
                ans += ((lft['?'] * rgt['?']) % mod * power(3, tot - mark - 2, mod)) % mod;
            }

            lft[s[i]]++;

            ans %= mod;
        }

        cout << ans << "\n";
    }


}
