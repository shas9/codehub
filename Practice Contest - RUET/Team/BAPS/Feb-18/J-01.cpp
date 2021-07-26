#include <bits/stdc++.h>

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

vector < ll > graph[400];
vector < ll > cost[400];

vector < pair < ll, ll > > arr[400][400];
map < ll, ll > track[400];

ll bfs(ll i, ll  j)
{
    priority_queue < pair < ll , ll > > pq;

    pair < ll , ll > cost_i;

    track[i][0] = 0;
    cost_i = make_pair(0,i);

    pq.push(cost_i);

    while(!pq.empty())
    {
        pair < ll , ll > cost_ind;

        cost_ind = pq.top();
        pq.pop();

        for(ll k = 0; k < graph[cost_ind.first].size(); k++)
        {
            ll temp = graph[cost_ind.first][k];

            if(track[in])
        }
    }
}

int main()
{
//    freopen("trip.in", "r", stdin);
//    freopen("trip.out", "w", stdout);

    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;


    for(i = 1; i <= 350; i++)
    {
        graph[i].clear();
        cost[i].clear();
    }

    ll u, v, c;

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(u);
        slld(v);
        slld(c);

        graph[u].pb(v);
        graph[v].pb(u);

        cost[u].pb(c);
        cost[v].pb(c);
    }

    ans = 0;

    memset(vis,-1,sizeof(vis));

    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j<= n; j++)
        {
            ans += dj(i,j);
        }
    }

    double av;

    av = ans / (n * 1.0);

    plf(av);
}


