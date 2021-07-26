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

bool comp(pll a, pll b)
{
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        vector < pll > v(n);

        ll tot = 0;

        for(auto &it: v) cin >> it.first >> it.second, tot += it.first;

        sort(v.begin(), v.end(), comp);

        ll totx = tot;

        ans = 0;

        for(auto it: v)
        {
            ll dis = min(it.first, max(0LL, (tot - it.second)));

            ans += dis;
            tot -= dis;
        }

        cout << ans + ((totx - ans) * 2) << "\n";
    }


}

