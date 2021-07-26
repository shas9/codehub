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

vector < pll > ans;
vector < pll > v;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        v.resize(n);
        ans.resize(n);

        ll cnt = 0;

        for(auto &it: v) cin >> it.first, it.second = cnt++;

        sort(v.begin(), v.end());

        for(ll i = 0; i < n; i++)
        {
            ll mx = max(v[i].first - v.front().first, v.back().first - v[i].first);
            ll mn = mxlld;

            if(i) mn = min(mn, v[i].first - v[i - 1].first);
            if(i + 1 < n) mn = min(mn, v[i + 1].first - v[i].first);

            ans[v[i].second] = {mn, mx};
        }

        for(auto it: ans)
        {
            cout << it.first << " " << it.second << "\n";
        }

    }


}


