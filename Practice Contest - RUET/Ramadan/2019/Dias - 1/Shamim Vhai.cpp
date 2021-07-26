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

vector < ll >  graph[100];
ll dist[100];

void solve(ll node)
{
    queue < ll > q;

    dist[node] = 0;

    q.push(node);

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        ll sz = graph[top].size();

        for(ll i = 0; i < sz; i++)
        {
            ll xx = graph[top][i];

            if(dist[xx] != -1) continue;

            dist[xx] = dist[top] + 1;

            q.push(xx);
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++)
        {
            graph[i].clear();
        }

        ll u, v;

        for(i = 1; i <= n - 1; i++)
        {
            slld(u);
            slld(v);

            graph[u].pb(v);
            graph[v].pb(u);
        }

        ll mn = mxlld;

        for(i = 1; i <= n; i++)
        {
            memset(dist,-1,sizeof dist);

            ll mx = mnlld;

            solve(i);

            for(j = 1; j <= n; j++)
            {
                mx = max(mx,dist[j]);
            }

            mn = min(mx,mn);
        }

        printcase(cs,mn);
    }


}

