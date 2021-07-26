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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100005


using namespace std;

vector < ll > graph[maxn];
vector < ll > v[2];
bool on;
ll vis[maxn];

void dfs(ll ind)
{
    ll sz = graph[ind].size();

    for(ll i = 0; i < sz; i++)
    {
        ll id = graph[ind][i];
        if(vis[id] != -1)
        {
            if(vis[id] == vis[ind])
            {
                on = 1;
                return;
            }
            else
            {
                continue;
            }
        }

        if(vis[ind] == 1) vis[id] = 0;
        else vis[id] = 1;

        v[vis[id]].pb(id);

        dfs(id);
    }
}

ll solve(ll n)
{
    v[0].clear();
    v[1].clear();

    on = 0;

    memset(vis,-1,sizeof(vis));
    ll flag = 0;

    for(ll i = 1; i <=  n; i++)
    {
        if(vis[i] == -1)
        {
            if(flag)
            vis[i] = 0;
            else
            vis[i] = 1;

            v[vis[i]].pb(i);
            dfs(i);
        }

        if(on) break;
    }

    if(on) return -1;
    else return 1;

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    for(i = 0; i < maxn; i++) graph[i].clear();

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    ans = solve(n);

    if(ans == -1) cout << -1 << endl;
    else
    for(i = 0; i < 2; i++)
    {
        ll sz = v[i].size();
        cout << sz << endl;

        for(j = 0; j < sz; j++) cout << v[i][j] << " ";

        cout << endl;


    }

}


