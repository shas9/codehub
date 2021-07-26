#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%.10lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll graph[350][350];
ll next[350][350];

ll floyd(ll i, ll j)
{
    vector < ll > path;

    path.clear();

    path.pb(i);

    while(i != j)
    {
        i = next[i][j];
        path.pb(i);
    }

    return path.size() - 1;
}

int main()
{
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);

    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            graph[i][j] = mxlld;
        }
    }

    ll u, v, c;
    for(i = 1; i <= m; i++)
    {
        slld(u);
        slld(v);
        slld(c);

        graph[u][v] = min(graph[u][v],c);
        graph[v][u] = min(graph[v][u],c);
    }


    for(i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            next[i][j] = j;
        }
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }

                if(graph[i][k] + graph[k][j] == graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = min(next[i][j],next[i][k]);
                }
            }
        }
    }

    ans = 0;


    for(i = 1; i <= n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            ans += floyd(i,j);
        }
    }

    double av = (ans * 1.0) / n;

    plf(av);


}


