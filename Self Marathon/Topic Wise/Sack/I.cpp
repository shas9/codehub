// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

const ll tot_nodes = 5e5 + 5;

ll col[tot_nodes];
vector < ll > g[tot_nodes];
ll p[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll depth[tot_nodes];
ll bag[(1 << 22)];
ll nmask[tot_nodes];
ll ans[tot_nodes];

ll big_dsu(ll node, ll par, ll d = 0, ll mask = 0)
{
    ll cn = 1, x, mx = 0, bigc = -1;

    depth[node] = d;
    nmask[node] = mask;
    p[node] = par;

    for(auto it: g[node])
    {
        if(it != par)
        {
            ll smask = mask ^ (1 << col[it]);

            x = big_dsu(it,node,d + 1, smask);

            cn += x;

            if(x > mx)
            {
                bigc = it;
                mx = x;
            }
        }
    }

    bigchild[node] = bigc;

    return cn;
}

ll mx;

void add(ll node, ll par)
{
    bag[nmask[node]] = max(bag[nmask[node]], (int)depth[node]);

    for(auto it: g[node])
    {
        if(it != par)
        {
            add(it, node);
        }
    }
}

void rem(ll node, ll par)
{
    bag[nmask[node]] = 0;

    for(auto it: g[node])
    {
        if(it != par)
        {
            rem(it, node);
        }
    }
}

void update(ll node, ll par, ll val)
{
    ll mask = nmask[node];

    if(bag[mask])
    {
        mx = max(mx, depth[node] + bag[mask] - (2 * val));
    }

    for(ll i = 0; i < 22; i++)
    {
        ll smask = mask ^ (1 << i);

        if(bag[smask])
        {
            mx = max(mx, depth[node] + bag[smask] - (2* val));
        }
    }

    for(auto it: g[node])
    {
        if(it == par) continue;

        update(it, node, val);
    }
}

void dfs(ll node, ll par, bool keep = 1)
{
    for(auto it: g[node])
    {
        if(it != par && it != bigchild[node])
        {
            dfs(it, node, 0);
        }
    }

    if(bigchild[node] != -1)
    {
        dfs(bigchild[node], node, 1);
        big[bigchild[node]] = 1;
    }

    for(auto it: g[node])
    {
        if(it == par) continue;
        if(big[it]) continue;

        update(it,node,depth[node]);
        add(it,node);
    }

    bag[nmask[node]] = max(bag[nmask[node]], (int)depth[node]);

    ll mask = nmask[node];

    if(bag[mask])
    {
        mx = max(mx, bag[mask] - depth[node]);
    }

    for(ll i = 0; i < 22; i++)
    {
        ll smask = mask ^ (1 << i);

        if(bag[smask])
        {
            mx = max(mx, bag[smask] - depth[node]);
        }
    }

    ans[node] = mx;

    if(bigchild[node] != -1)
    {
        big[bigchild[node]] = 0;
    }

    if(keep == 0)
    {
        rem(node,par);
        mx = 0;
    }
    else
    {
        if(node != 1)
        {
            ll mask = nmask[node] ^ nmask[p[node]];

            if(__builtin_popcount(mask) <= 1)
            {
                mx = max(mx,1);
            }
        }
    }
}

ll dfs2(ll node, ll par)
{
    ll ret = ans[node];

    for(auto it: g[node])
    {
        if(it != par)
        {
            ret = max(ret, dfs2(it, node));
        }
    }

    return ans[node] = ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tags;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++) g[i].clear();
        for(ll i = 2; i <= n; i++)
        {
            ll par;
            char c;

            scanf("%lld %c",&par, &c);

            g[par].push_back(i);
            g[i].push_back(par);

            col[i] = c - 'a';
        }

        mx = 0;
        memset(bigchild,-1,sizeof bigchild);

        big_dsu(1,-1);

        dfs(1,-1);
        dfs2(1,-1);

        for(ll i = 1; i <= n; i++)
        {
            printf("%d ", ans[i]);
        }

        printf("\n");
    }

}


