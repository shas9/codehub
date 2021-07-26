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

ll dist[100005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        memset(dist,-1,sizeof dist);
        map < ll, bool > mp;

        mp[0] = 1;

        for(ll i = 1; i <= n; i++)
        {
            ll t, xx, y;

            cin >> t >> xx >> y;

            double x = (xx * 1.0 / (100000.0));

            vector < ll > v;

//            cout << x << endl;

            for(auto it: mp)
            {
                ll now = it.first;
                ll cnt = 0;

                while(cnt < y)
                {
                    cnt++;

                    if(t == 1)
                    {
                        now = ceil(now + x);
                    }
                    else
                    {
                        now = ceil(now * x);
                    }

                    if(now > m) break;

                    if(dist[now] != -1) break;

                    dist[now] = i;

                    v.push_back(now);
                }
            }

            for(auto it: v) mp[it] = 1;
        }

        for(ll i = 1; i <= m; i++) cout << dist[i] << " ";
        cout << "\n";
    }


}


