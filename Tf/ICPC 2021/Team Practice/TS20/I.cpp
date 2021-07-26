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

ll get(pll a)
{
    ll x = (a.first - a.second + 1) / 2;
    return x;
}

bool comp(pll a, pll b)
{
    ll x = (a.first - a.second + 1) / 2;
    ll y = (b.first - b.second + 1) / 2;

    return x < y;
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
        vector < pll > vv;

        ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            ll u, v;
            cin >> u >> v;

            if(u <= v) ans++;
            else vv.push_back({u,v});
        }

        sort(vv.begin(), vv.end(), comp);

        for(auto it: vv)
        {
            ll x = get(it);

            if(x <= m)
            {
                ans++;
                m -= x;
            }
        }

        if(ans * 2 > n) cout << "Make Byteland Great Again!\n";
        else cout << "Fake Polls!\n";
    }


}


