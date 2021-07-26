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

vector < ll > g[400005];
vector < ll > vis;
queue < ll > q, q1;
vector < bool > inf, mul;

void dfs(ll node, ll par)
{
    vis[node] = 1;

    for(auto it: g[node])
    {
//        if(it != par)
        {
            if(vis[it] == 1)
            {
                q.push(it);
            }
            else if(vis[it] == 0)
            {
                dfs(it, node);
            }
            else
            {
                q1.push(it);
            }
        }
    }

    vis[node] = 2;
}

int main()
{
    ll i, j, k, l, m, n, r;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        assert(q.empty() && q1.empty());

        cin >> n >> m;

        for(ll i = 1; i <= n; i++)
        {
            g[i].clear();
        }

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;
            g[u].pb(v);
        }

        vis.assign(n + 1, 0);
        inf.assign(n + 1, 0);
        mul.assign(n + 1, 0);

        dfs(1,-1);

        while(!q.empty())
        {
            ll top = q.front();
            q.pop();

            inf[top] = 1;

            for(auto it: g[top])
            {
                if(inf[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        while(!q1.empty())
        {
            ll top = q1.front();
            q1.pop();

            mul[top] = 1;

            for(auto it: g[top])
            {
                if(mul[it] == 0)
                {
                    q1.push(it);
                }
            }
        }

        for(ll i = 1; i <= n; i++)
        {
            if(inf[i]) cout << -1 << " ";
            else if(mul[i]) cout << 2 << " ";
            else if(vis[i]) cout << 1 << " ";
            else cout << 0 << " ";
        }

        cout << "\n";

    }


}



