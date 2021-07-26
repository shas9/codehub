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
    ll mod = 1e9 + 7;

    x %= mod;

    if(x < 0) x += mod;

    return x;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll x, y;

    while(cin >> x >> y)
    {
        cin >> n;
        n--;
        n %= 6;

        if(n == 0) cout << f(x) << "\n";
        if(n == 1) cout << f(y) << "\n";
        if(n == 2) cout << f(y - x) << "\n";
        if(n == 3) cout << f(-x) << "\n";
        if(n == 4) cout << f(-y) << "\n";
        if(n == 5) cout << f(x - y) << "\n";
    }
}

