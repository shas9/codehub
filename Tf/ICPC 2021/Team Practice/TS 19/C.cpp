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

ll f(ll x)
{
    ll ret = (x * (x + 1)) / 2;

    return ret;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k >> n >> m)
    {
        ans = -1;

        for(ll i = 4; i <= 10000; i++)
        {
            ll c1 = f(i) - f(3);
            ll c2 = max(0LL, f(i - k) - f(2));

            if(c1 + c2 == n + m)
            {
                if(c1 <= n)
                {
                    ans = (n - c1);
                    break;
                }
            }
        }

        assert(ans != -1);

        cout << ans << "\n";
    }


}

