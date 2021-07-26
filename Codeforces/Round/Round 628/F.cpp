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

vector < ll > graph[100005];
deque < ll > nd;
ll dist[100005];
ll mark[100005];
ll sq;

void clc(ll n)
{
    for(ll i = 1; i <= n; i++) graph[i].clear();
    nd.clear();
    memset(dist,0,sizeof dist);
}

ll solve(ll node)
{
    nd.push_back(node);

    dist[node] = nd.size();

    for(auto u:graph[node])
    {
        if(dist[u])
        {
            if(dist[node] - dist[u] + 1 >= sq)
            {
                cout << 2 << endl;
                cout << dist[node] - dist[u] + 1 << endl;

                for(ll i = dist[u] - 1; i < dist[node]; i++)
                {
                    cout << nd[i] << " ";
                }

                cout << endl;

                exit(0);
            }
        }
        else
        {
            solve(u);
        }
    }

    if(mark[node] == 0)
    {
        for(auto sex: graph[node])
        {
            mark[sex] = 1;
        }
    }

    nd.pop_back();
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
//        clc(n);

        sq = sqrt(n);

        if(sq * sq < n) sq++;

        for(i = 1; i <= m; i++)
        {
            ll u, v;

            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        solve(1);

        cout << 1 << endl;

        for(i = 1; i <= n && sq; i++)
        {
            if(mark[i] == 1) continue;

            cout << i << " ";

            sq--;
        }
    }
}


