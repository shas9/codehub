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

ll perp[5003];
ll c[5003];
pll vis[5003];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 1; i <= n; i++)
        {
            cin >> perp[i];
        }

        for(ll i = 1; i <= n; i++)
        {
            cin >> c[i];
        }

        ans = mnlld;
        for(ll i = 1; i <= n; i++) vis[i] = {mnlld, 0};

        for(ll i = 1; i <= n; i++)
        {
			ll cycle = 0;
			ll full = 0;

			ll now = i;

			if(vis[i].first != mnlld)
			{
				full = vis[i].first;
				cycle = vis[i].second;
			}
			else
			{
				while(1)
				{
//					cout << now << " " << perp[now] << endl;
					now = perp[now];
					full += c[now];
					cycle++;

					assert(cycle <= n);

					if(now == i) break;
				}

//				bug;

				while(1)
				{
					now = perp[now];

					assert(vis[now].first == mnlld);

					vis[now] = {full,cycle};

					assert(cycle <= n);

					if(now == i) break;
				}

			}


            ll rem = m % cycle;
            ll totcost = (m / cycle) * full;

            if(m >= cycle) ans = max(ans, totcost);
            if(rem == 0) rem += cycle, totcost -= full;

            totcost = max(totcost, 0LL);
            now = i;

            for(ll j = 0; j < rem; j++)
            {
                now = perp[now];

                totcost += c[now];

                ans = max(ans, totcost);
            }

            totcost = 0;
            now = i;

            for(ll j = 0; j < min(cycle, m); j++)
            {
				now = perp[now];

				totcost += c[now];

				ans = max(ans, totcost);
            }

//			cout << endl;
        }

        cout << ans << "\n";
    }


}




