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

ll ask(ll x)
{
    cout << "? " << 1 << " " << x << endl;
    ll ret;
    cin >> ret;

    assert(ret != -1);

    return ret;
}

ll solve(ll n, ll k)
{
    ll lo = 1;
    ll hi = n;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll sum = ask(mid);

        ll zero = (mid - sum);

        if(zero == k)
        {
            ret = mid;
            hi = mid - 1;
        }
        else if(zero < k)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    assert(ret != -1);

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        cin >> k;

        ans = solve(n, k);

        cout << "! " <<  ans << endl;

        return 0;
    }


}


