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

map < ll, ll > sz1, sz2;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m)
    {
        sz1.clear();
        sz2.clear();

        for(ll i = 1; i <= m; i++)
        {
            ll u,v;
            cin >> u >> v;

            sz1[u]++;
            sz2[v]++;
        }

        ll mx1 = 0, mx2 = 0;

        for(ll i = 1; i <= n; i++)
        {
            if(sz1[i] == n) mx1++;
            if(sz2[i] == n) mx2++;
        }

        cout << n - max(mx1, mx2) << "\n";
    }


}


