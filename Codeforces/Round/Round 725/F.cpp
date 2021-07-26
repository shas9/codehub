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

ll fnd(ll x)
{
    ll y = 9999999999 + 1;
    ll dig = 10;

    ll ret = 0;
    ll prev = 0;

    while(y > 1)
    {
        ll add = (x + 1) / y - prev;

        prev += add;

        ret += add * dig;

        y /= 10;
        dig--;
    }

//    cout << x << " ** " << ret << "\n";

    return ret;
}

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
        cin >> l >> r;

        ans = fnd(r - 1) - fnd(l - 1) + (r - l);

        cout << ans << "\n";
    }


}

