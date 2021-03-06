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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll save[200005];
ll in[200005];
ll col[200005];
vector < ll > graph[200005];
ll ans[200005];

void dfs(ll node, ll par)
{
    save[node] = 0;
    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll xx = graph[node][i];

        if(xx == par) continue;

        dfs(xx,node);
        save[node] += save[xx];
    }

    save[node] += col[node];

    save[node] = max(0LL, save[node]);

    return;
}

void solve(ll node, ll par)
{
    save[node] = save[par];

    save[node] = max(0LL, save[node]);

    ans[node] = save[node] + col[node];

    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll xx = graph[node][i];

        if(xx == par) continue;

        ans[node] += save[xx];
    }

    for(ll i = 0; i < graph[node].size(); i++)
    {
        ll xx = graph[node][i];

        if(xx == par) continue;

        save[node] = ans[node] - save[xx];

        solve(xx,node);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(col[i]);

        if(col[i] == 0) col[i] = -1;
    }

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        in[u]++;
        in[v]++;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(in[i] == 1)
        {
            dfs(i, -1);
            break;
        }
    }


    solve(i,0);

    for(i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;




}


