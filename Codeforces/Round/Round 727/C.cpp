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

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        sort(v.begin(), v.end());

        vector < ll > v1;

        for(ll i = 1; i < n; i++) v1.push_back(v[i] - v[i - 1]);

        sort(v1.rbegin(), v1.rend());

        while(v1.size())
        {
            ll x = max(0LL, (v1.back() - 1) / k);

//            cout << v1.back() << " " << x << " " << m << "\n";

            if(m < x) break;

            m -= x;
            v1.pop_back();
        }

        cout << v1.size() + 1 << "\n";
    }


}

