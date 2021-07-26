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

ll on[22][1000006];
const ll mod = 1000000007;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        ll cxor = 0;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            cxor ^= in;

            for(ll j = 0; j < 20; j++)
            {
                if(check(cxor,j)) on[j][i] = 1;
                else on[j][i] = 0;

                on[j][i] += on[j][i - 1];
            }
        }

        for(ll i = 1; i <= m; i++)
        {
            cin >> l >> r;
            l--;

            ans = 0;

            for(ll j = 0; j < 20; j++)
            {
                ll add = on[j][r] - (l > 0 ? on[j][l - 1] : 0);

                add = (add * (r - l + 1 - add)) % mod;

                ans += ((1 << j) * add) % mod;
            }

            cout << ans % mod << "\n";

        }
    }


}

