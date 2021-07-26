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

ll arr[1003];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    ll mx = mnlld, mn = mxlld;

    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i];

        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    ll x1 = 0, x2 = 0;

    for(ll i = 1; i <= n; i++)
    {
        x1 += abs(mn - arr[i]);
        x2 += abs(mx - arr[i]);
    }

    if(x1 < x2) cout << "Remove Light Bulbs\n";
    else cout << "Add Light Bulbs\n";


}

