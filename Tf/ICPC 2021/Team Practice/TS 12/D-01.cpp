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

ll vis[100005];

ll calc(ll xx, ll y, ll t)
{
    ll lim = 1e5;

    __int128 x = xx;
    x *= lim;

    if(t == 1) x += y;
    else x *= y;

    if(t == 2) x /= lim;

    x += (lim - 1);
    x /= lim;

    xx = x;

    return x;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        memset(vis,-1,sizeof vis);
        vis[0] = 0;

        for(ll i = 1; i <= n; i++)
        {
            vector < ll > temp;

            ll t, x, y;

            cin >> t >> x >> y;

            for(ll j = 0; j <= m; j++)
            {
                if(vis[j] != -1)
                {
                    ll yy = y;
//                    cout << i << " : " << j << " = ";
                    ll now = j;

                    while(yy--)
                    {
                        now = calc(now,x,t);

//                        cout << now << " ";

                        if(now > m || vis[now] != -1) break;

                        temp.push_back(now);
                    }


//                    cout << "\n";
                }
            }

            for(auto it: temp) vis[it] = i;
        }

        for(ll i = 1; i <= m; i++) cout << vis[i] << " ";
        cout << "\n";
    }


}
