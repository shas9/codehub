#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < ll > graph[200005];
bool vis[200005];

void makefalse(ll pos)
{
    queue < ll > q;

    q.push(pos);

    vis[pos] = true;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll x = graph[top][i];

            if(vis[x] == true) continue;

            vis[x] = true;

            q.push(x);
        }
    }
}

ll solve(ll start)
{
    queue < ll > q;

    q.push(start);

    vis[start] = true;

    bool on = 1;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        //cout << " -- " << top << endl;

        if(graph[top].size() != 2)
        {
            //cout << top << endl;
            on = 0;
        }

        //cout << "Skipped" << endl;

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll x = graph[top][i];

            if(vis[x] == true)
            {
                continue;
            }

            vis[x] = true;

            q.push(x);

            //cout << x << endl;
        }

        //bug;
    }

    if(on) return 1;
    else return 0;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(vis[i] == false)
        {
            //cout << i << endl;
            ans += solve(i);
            //bug;
        }
    }

    cout << ans << endl;


}


