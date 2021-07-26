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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        sort(v.rbegin(), v.rend());

        ll mn = mxlld;

        for(ll i = 0; i + 1 < n; i++)
        {
            mn = min(mn, v[i] - v[i + 1]);
        }

        if(v[n - 2] - v[n - 1] == mn)
        {
            ll x = v[n - 1];
            v.insert(v.begin(), v[n - 2]);
            v.pop_back();
            v.pop_back();
            v.push_back(x);
        }
        else if(v[0] - v[1] == mn)
        {
            v.push_back(v[1]);
            v.erase(v.begin() + 1);
        }
        else
        {
            ll x = -1, y = -1;

            for(ll i = 0; i + 1 < n; i++)
            {
                if(v[i] - v[i + 1] == mn)
                {
                    x = i;
                    y = i + 1;
                    break;
                }
            }

            assert(x != -1 && y != -1);

            vector < ll > v1;

            for(ll i = y; i < n; i++) v1.push_back(v[i]);
            for(ll i = 0; i <= x; i++) v1.push_back(v[i]);

            v = v1;
        }

        reverse(v.begin(), v.end());

        for(auto it: v) cout << it << " ";

        cout << "\n";
    }


}


