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

vector < ll > g[200005];
ll ans[200005];
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];

            g[i].clear();
            ans[i] = 0;
        }

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            g[arr[i]].pb(in);
        }

        for(ll i = 1; i <= n; i++)
        {
            if(!g[i].empty())
            {
                sort(g[i].begin(), g[i].end());

                ll sum = 0;

                for(auto &it: g[i])
                {
                    sum += it;
                    it = sum;
                }

                for(ll j = 1; j <= g[i].size(); j++)
                {
                    ll baki = g[i].size() % j;

                    ans[j] += g[i].back();

                    if(baki) ans[j] -= g[i][baki - 1];
                }
            }
        }

        for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

        cout << "\n";
    }


}

