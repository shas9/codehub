#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll a, b, c;

        cin >> a >> b >> c >> r;

        if(a > b) swap(a,b);

        ans = 0;

        ll lf = c - r;
        ll rg = c + r;

        if(a < lf && b < lf) ans = abs(b - a);
        else if(a > rg && b > rg) ans = abs(b - a);
        else if(a < lf && b > rg) ans = abs(lf - a) + abs(b - rg);
        else if(a < lf) ans = abs(lf - a);
        else if(b > rg) ans = abs(b - rg);

        cout << ans << endl;



    }


}
