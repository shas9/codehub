// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll depth[100005];
vector < ll > g[100005];
vector < ll > cyc;
vector < ll > cycout;
ll n, m, k;

void dfs(ll node, ll par, ll d)
{
    cyc.push_back(node);
    depth[node] = d;

    for(auto it: g[node])
    {
        if(!cycout.empty()) return;

        if(it != par)
        {
            if(depth[it] && depth[it] < depth[node])
            {
                if(cycout.empty() && (d - depth[it]) < k)
                {

                    while(cyc.back() != it)
                    {
                        cycout.push_back(cyc.back());
                        cyc.pop_back();
                    }

                    cycout.push_back(it);

                    return;
                }
            }
            else if(depth[it] == 0)
            {
                dfs(it,node,d + 1);
            }
        }
    }

    cyc.pop_back();
}

vector < ll > p1, p2;
bool vis[100005];

void dfs1(ll node, ll par, ll lv)
{
    vis[node] = 1;
    if(lv) p2.push_back(node);
    else p1.push_back(node);

    for(auto it: g[node])
    {
        if(it != par)
        {
            if(vis[it] == 0)
            {
                dfs1(it,node,lv ^ 1);
            }
        }
    }
}

ll solve()
{
    memset(vis,0,sizeof vis);
    p1.clear();
    p2.clear();

    dfs1(1,0,0);


    if(p1.size() >= (k + 1) /2)
    {
        p1.resize((k + 1) / 2);

        cycout = p1;

        return 0;
    }


    if(p2.size() >= (k + 1) /2)
    {
        p2.resize((k + 1) / 2);

        cycout = p2;

        return 0;
    }

//    assert(0);
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        for(i = 0; i <= n; i++)
        {
            g[i].clear();
            depth[i];
        }

        cyc.clear();
        cycout.clear();

        for(i = 1; i <= m; i++)
        {
            ll u, v;

            slld(u);
            slld(v);

            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(1,0,1);

        if(!cycout.empty())
        {
            cout << 2 << '\n';

			cout << cycout.size() << '\n';

            for(auto it: cycout) cout << it << " ";

            cout << '\n';
        }
        else
        {
            solve();

            cout << 1 << '\n';

//            assert(cycout.size() == (k + 1) / 2);

            for(auto it: cycout) cout << it << " ";

            cout << '\n';
        }
    }


}



