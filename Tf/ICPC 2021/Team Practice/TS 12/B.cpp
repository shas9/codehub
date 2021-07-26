 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

ll fxor(ll n)
{
    ll mod = (n % 4);

    if(mod == 0) return n;
    if(mod == 1) return 1;
    if(mod == 2) return n + 1;
    return 0;
}

ll solve(ll l, ll r)
{
    return fxor(l - 1) ^ fxor(r);
}

bool possible(ll l, ll r)
{
    ll xxor = solve(l,r);

    for(ll i = 60; i >= 0; i--)
    {
        if(check(xxor,i))
        {
            ll mx = (1LL << (i + 1)) - 1;
            ll mn = (1LL << (i));

            if(mx >= l && mn <= r) return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> l >> r;

        if(possible(l,r)) cout << "YES\n";
        else cout << "NO\n";
    }


}

