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
    cout << x << "\n";
    cin >> x;

    assert(x != -1);

    return x;
}

bool calc(ll x, ll y, ll k)
{
    vector < ll > v1, v2, v;

//    cout << x << " " << y << "\n";

    while(x)
    {
        v1.push_back(x % k);
        x /= k;
    }

    while(y)
    {
        v2.push_back(y % k);
        y /= k;
    }

    while(v1.size() != v2.size())
    {
        if(v1.size() < v2.size())  v1.push_back(0);
        else v2.push_back(0);
    }

//    for(auto it: v1) cout << it << " ";
//    cout << " is v1\n";
//
//    for(auto it: v2) cout << it << " ";
//    cout << " is v2\n";

    while(!v1.empty())
    {
        ll x = (v1.back() - v2.back() + k + k) % k;
        v.push_back(x);

        v1.pop_back();
        v2.pop_back();
    }

    assert(v2.empty());

    ll ret = 0;

    for(auto it: v)
    {
        ret *= k;
        ret += it;
    }

    return ask(ret);
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    if(ask(0)) return;

    vector < ll > v;

    for(ll i = 1; i < n; i++)
    {
        if(i & 1)
        {
            if(calc(i - 1, i, k)) return;
        }
        else
        {
            if(calc(i, i - 1, k)) return;
        }
    }

    assert(0);
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
        solve();
    }


}

