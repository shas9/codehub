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

vector < ll > graph[2005];
ll dist[2005];
bool vis[2005];
ll n;

ll solve(ll ind)
{
    queue < ll > q;

    memset(dist,1000000,sizeof dist);

    memset(vis,0,sizeof vis);

    q.push(ind);

    dist[ind] = 0;

    ll ans = mxlld;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        ll sz = graph[top].size();

        for(ll i = 0; i < sz; i++)
        {
            ll node = graph[top][i];

            if(node == ind)
            {
                return dist[top] + 1;
            }

            if(vis[node]) continue;

            vis[node] = 1;

            dist[node] = dist[top] + 1;

            q.push(node);
        }
    }

    return -1;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            slld(input);

            if(input)
            {
                graph[i].push_back(j);
            }
        }
    }

    for(i = 1; i <= n; i++)
    {
        ans = solve(i);

        if(ans == -1) cout << "NO WAY" << endl;
        else
        {
            cout << ans << endl;
        }
    }

}
