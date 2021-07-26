// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

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

struct BIT
{
    vector < ll > tree;
    ll n;

    BIT(ll n) : n(n), tree(n + 3, 0) {}

    void init()
    {
        tree.assign(n + 3, 0);
    }

    ll query(ll idx)
    {
        ll sum=0;
        while(idx>0)
        {
            sum+=tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    void update(ll idx, ll x) //n is the size of the array, x is the number to add
    {
        while(idx<=n)
        {
            tree[idx]+=x;
            idx += idx & (-idx);
        }
    }
} bit(200002);

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        ans = 0;

        for(ll i = 1; i <= m; i++) g[i].clear();

        bool on = 0;

        for(ll i = 1; i <= k; i++)
        {
            ll u, v;

            cin >> u >> v;

            g[v].pb(u);
        }

        bit.init();

        for(ll i = 1; i <= m; i++)
        {
            sort(g[i].rbegin(), g[i].rend());

            if(i == 1 && !g[i].empty())
            {
                for(ll j = g[i].back(); j <= n; j++)
                {
                    bit.update(j,1);
                    ans++;
                }

                continue;
            }

            if(!g[i].empty() && g[i].back() == 1) on = 1;
			ll lim = 2e5 + 1;


            if(on)
            {
				for(auto it: g[i])
				{
					ll x = bit.query(it);
					if(it > 1)  x -= bit.query(it - 1);
					if(x == 0) bit.update(it,1);
				}

				ans += bit.query(lim);
            }
            else
            {
                for(auto it: g[i])
                {
                    ans++;

                    ll obs = bit.query(lim) - bit.query(it);

                    ans += obs;

                    ll x = bit.query(it);
					if(it > 1)  x -= bit.query(it - 1);
					if(x == 0) bit.update(it,1);

                    lim = it - 1;
                }

            }

//            cout << ans << "\n";

        }

        ans = (n * m) - ans;

        cout << ans << "\n";
    }


}


