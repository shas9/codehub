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
ll vis[400][400], price[400][400];

struct node {
    ll p;
    ll cost;
    ll len;

    node(ll point, ll cst, ll l) {
        p = point;
        cost = cst;
        len = l;
    }
};

bool operator <(node a, node b) {
    return a.cost > b.cost;
}

ll dj(ll i, ll j)
{
    priority_queue < node > pq;
    pq.push( node(i, 0, 0));
    vis[i][i] = 0;

    while(!pq.empty()) {
        node u = pq.top();
        pq.pop();

        for(ll k = 0; k < graph[ u.p ].size(); k++) {
            ll p = u.p;

            if(vis[i][  graph[p][k] ] == -1)
            {
                vis[i][ graph[p][k] ] = u.len + 1;
                price[i][ graph[p][k] ] = u.cost + cost[p][k];
                pq.push( node(graph[p][k], u.cost + cost[p][k], u.len + 1) );
                //cout<< graph[p][k] << " ekjherkherkh " << endl;
                //cout << u.cost << "   wefweef  " << cost[p][k] << "  ev " << price[i][ graph[p][k] ] << endl;
            }
            else {
                if( (u.cost + cost[p][k]) == price[i][ graph[p][k] ]) {
                    if(vis[i][ graph[p][k] ] > u.len + 1) {
                        vis[i][ graph[p][k] ] = u.len + 1;
                        price[i][ graph[p][k] ] = u.cost + cost[p][k];
                        pq.push( node(graph[p][k], u.cost + cost[p][k], u.len + 1) );
                    }
                }
                if( (u.cost + cost[p][k]) < price[i][ graph[p][k] ]) {
                    vis[i][ graph[p][k] ] = u.len + 1;
                    price[i][ graph[p][k] ] = u.cost + cost[p][k];
                    pq.push( node(graph[p][k], u.cost + cost[p][k], u.len + 1) );
                    //cout << graph[p][k] << " fefhejfhkefhwieuhf   " << endl;
                    //cout << u.cost + cost[p][k] << "  ev " << price[i][ graph[p][k] ] << endl;
                }
            }
        }
    }

    if(vis[i][j] != -1)
        return vis[i][j];
    return vis[i][j] = 0;

}

int main()
{
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
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
            if(vis[i][j] != -1)
            {
                ans += vis[i][j];
                continue;
            }
            //cout << i << "  " << j << endl;
            vis[i][j] = dj(i,j);
            ans += vis[i][j];
        }
    }

    double av;

    av = ans / (n * 1.0);

    plf(av);
}

