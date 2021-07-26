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

vector < ll > g[2003];
vector < bool > vis;
ll n;

void dfs(ll node)
{
    cout << "? " << node << endl;

    vector < vector < ll > > v(n + 1);
    vector < ll > dist(n + 1);
    ll in;

    for(ll i = 1; i <= n; i++)
    {
        cin >> in;
        v[in].push_back(i);
        dist[i] = in;
    }

    ll now = node;

    for(ll i = 1; i <= n; i++)
    {
        vis[now] = 1;

        if(v[i].empty()) break;

        for(auto it: v[i])
        {
            g[now].push_back(it);
        }

        if(v[i].size() > 1) break;

        now = v[i].front();
    }

    ll dd = n;

    for(ll i = n; i >= 1; i--)
    {
        if(!v[i].empty())
        {
            for(auto it: v[i])
            {
                if(vis[it] == 0)
                {
                    now = it;
                    break;
                }
            }
            dd = i;
            break;
        }
    }

    if(vis[now]) return;

    vis[now] = 1;

    cout << "? " << now << endl;

    vector < vector < ll > > v2(n + 1);

    for(ll i = 1; i < dd; i++)
    {
        cin >> in;

        v2[in].push_back(i);
    }

    for(ll i = 1; i < dd; i++)
    {
        if(v2[i].empty()) break;

        if(v2[i].size() == 1)
        {
            g[now].push_back(v2[i].front());
            now = v2[i].front();

            for(auto it: v2[i - 1]) vis[it] = 1;
        }
        else
        {
            ll mn = mxlld;
            ll fx = -1;

            for(auto it: v2[i])
            {
                if(mn > dist[it])
                {
                    mn = dist[it];
                    fx = i;
                }
                else if(mn == dist[it]) assert(0);
            }

            g[now].push_back(fx);
            now = fx;

            if(v2[i].size() == 2)
            {
                if(v2[i].front() != now)
                {
                    vis[now] = 1;

                }
            }
        }
    }

    return;
}

void solve(ll node)
{
    cout << "? " << node << endl;

    for(ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        if(x == 1) g[node].pb(i);
    }

    return;
}

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++) g[i].clear();

        cout << "? " << 1 << endl;

        vector < ll > v(n + 1);
        ll odd = 0;

        for(ll i = 1; i <= n; i++)
        {
            cin >> v[i];

            if(v[i] & 1) odd++;
        }

        if(odd < ((n + 1) / 2))
        {
            for(ll i = 1; i <= n; i++)
            {
                if(v[i] & 1) solve(i);
            }
        }
        else
        {
            for(ll i = 2; i <= n; i++)
            {
                if(!(v[i] & 1)) solve(i);
                if(v[i] == 1)
                {
                    g[1].pb(i);
                }
            }
        }

        cout << "!" << endl;

        for(ll i = 1; i <= n; i++)
        {
            for(auto it: g[i])
            {
                cout << it << " " << i << endl;
            }
        }
    }


}

