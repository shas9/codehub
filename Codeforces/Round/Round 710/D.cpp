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

vector < pll > vec;
map < ll, ll > mp;

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
        vec.clear();
        mp.clear();

        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            mp[in]++;
        }

        for(auto it: mp)
        {
            vec.push_back({it.second, it.first});
        }

        sort(vec.rbegin(), vec.rend());

        ll processed = 0;
        ll extra = 0;

        for(auto it: vec)
        {
            ll x = it.first;

            ll y = min(x, extra);

            x -= y;
            extra -= y;

            y = min(x / 2, processed / 2);

            x -= y * 2;
            processed -= y * 2;

            processed += (it.first - x);

            extra += x;

//            cout << extra << "\n";
        }

        cout << extra << "\n";
    }


}

