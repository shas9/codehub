#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dist[503][503];
vector < ll > edge;
ll ans[503];
bool vis[503];

void solve(ll n)
{
    ll idx = n;

    for(auto k:edge)
    {
        vis[k] = 1;

        ll sum = 0;

        for(ll i = 1; i <= n;  i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

                if(vis[i] == 0 || vis[j] == 0) continue;

                sum += dist[i][j];
            }
        }

        ans[idx--] = sum;
    }

    return;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        edge.clear();
        memset(vis,0,sizeof vis);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                slld(dist[i][j]);
            }
        }

        for(i = 0; i < n; i++)
        {
            slld(input);
            edge.push_back(input);
        }

        reverse(edge.begin(),edge.end());

        solve(n);

        for(i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }


}


