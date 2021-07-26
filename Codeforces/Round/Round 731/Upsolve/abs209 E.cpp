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


vector < ll > g[200005];
vector < pll > v;
map < string, ll > mp;
ll out[200005];
ll vis[200005];


void dfs(ll node)
{
    if(vis[node]) return;

    out[node] = 3;

    vis[node] = 1;

    if(g[node].size() == 0)
    {
        out[node] = 1;
        vis[node] = 2;
        return;
    }

    for(auto it: g[node])
    {
        dfs(it);

        if(out[it] == 1)
        {
            out[node] = 2;
        }
    }

    bool on = 1;

    for(auto it: g[node])
    {
//        if(vis[it] == 1) continue;
        if(out[it] != 2)
        {
            on = 0;
            break;
        }
    }

    if(on) out[node] = 1;

    vis[node] = 2;

//    cout << node << " +++ " << out[node] << "\n";

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 1; i <= 2e5; i++) g[i].clear();
        memset(vis,0,sizeof vis);
        memset(out,0,sizeof out);

        v.clear();
        mp.clear();

        ll cnt = 0;

        for(ll i = 1; i <= n; i++)
        {
            string s, f, b;

            cin >> s;

            for(ll j = 0; j < 3; j++) f += s[j];
            for(ll j = s.size() - 3; j < s.size(); j++) b += s[j];

            ll x, y;

            if(mp.find(f) == mp.end()) mp[f] = ++cnt;
            if(mp.find(b) == mp.end()) mp[b] = ++cnt;

            x = mp[f];
            y = mp[b];

            v.push_back({x,y});
            g[y].pb(x);
            vis[x]++;

//            cout << x << " " << y << "\n";
        }

        queue < ll > q;

        for(ll i = 1; i <= cnt; i++)
        {
            if(vis[i] == 0)
            {
                q.push(i);
                out[i] = 1;
            }
        }

        while(!q.empty())
        {
            ll top = q.front();
            q.pop();

            for(auto it: g[top])
            {
                if(out[it] == 0)
                {
                    if(out[top] == 1)
                    {
                        out[it] = 2;
                        q.push(it);
                        continue;
                    }

                    vis[it]--;

                    if(vis[it] == 0)
                    {
                        q.push(it);
                        out[it] = 1;
                    }
                }
            }
        }

        for(ll i = 1; i <= n; i++)
        {
            ll x = v[i - 1].second;

            if(out[x] == 1) cout << "Takahashi\n";
            else if(out[x] == 2) cout << "Aoki\n";
            else cout << "Draw\n";
        }
    }


}
