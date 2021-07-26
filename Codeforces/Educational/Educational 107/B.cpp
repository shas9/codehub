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

ll sz(ll x)
{
    ll cnt = 0;

    while(x)
    {
        cnt++;
        x/=10;
    }

    return cnt;
}

ll gun1[] = {1, 79, 463, 1229, 97787, 101749, 1001621, 99998473, 100002613};
ll gun2[] = {1, 37, 877, 1279, 98953, 100049, 1001219, 99999941, 100003549};

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
        ll a, b, c;

        cin >> a >> b >> c;

        ll val = 1;

        while(sz(val) < c) val *= 10;

        ll x = val * gun1[a - c];
        ll y = val * gun2[b - c];

        cout << x << " " << y << "\n";
    }


}


