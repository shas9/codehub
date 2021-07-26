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

ll mark[200004];

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
        memset(mark,0,sizeof mark);

        for(ll i = 1; i <= n; i++)
        {
            ll u, v;

            cin >> u >> v;

            for(ll j = u; j <= u + v; j++)
            {
                assert(mark[j] == 0);

                mark[j]++;
            }
        }

        pll ans = {-1,mxlld};

        for(ll i = 0; i <= 480; i++)
        {
            ll now = i;
            ll conflict = 0;

            while(now <= 200000)
            {
                if(mark[now]) conflict++;

                now += m;
            }

            if(ans.second > conflict)
            {
                ans = {i, conflict};
            }
        }

        cout << ans.first << " " << ans.second << "\n";
    }


}
