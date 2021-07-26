#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<ll>graph[123459];
ll ara[123459], chk[200009];
ll node1, dist1 = 0, node2, dist2 = 0;

void dfs(ll u, ll p, ll lv)

{
    if(lv > dist1 && chk[u]) {
        dist1 = lv;
        node1 = u;
    }
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd  = graph[u][i];
        if(nd  == p)
            continue;
        dfs(nd, u, lv + 1);
    }
}

void dfs2(ll u, ll p, ll lv)

{
    if(lv > dist2 && chk[u]) {
        dist2 = lv;
        node2 = u;
    }
    else if(lv == dist2 && chk[u]) {
        node2 = min(node2, u);
    }

    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd  = graph[u][i];
        if(nd  == p)
            continue;
        dfs2(nd, u, lv + 1);
    }
}

ll dist = 0;

ll dfs3(ll node, ll par, ll lv)
{
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd  == p)
            continue;

        ll tmp = dfs3(nd, u, lv + 1);
        if(tmp > 0)
            dist += tmp;

    }
}

int main()
{
   ll n,m;
   scanf("%lld %lld",&n,&m);
   for(ll i=1;i<n;i++)
   {
       ll u, v;
       scanf("%lld %lld",&u,&v);
       graph[u].pb(v);
       graph[v].pb(u);

   }
   for(ll i=1;i<=m;i++){
    scanf("%lld",&ara[i]);
    chk[ara[i]]=1;
   }

    dfs(1, -1, 1);
    dfs2(node1, -1, 1);

    cout << node2 << endl;

    ans = dfs3(node, -1);


    return 0;
}
