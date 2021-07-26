#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f

vii *G;
vi Dist;

void Dijkstra(ll source, ll N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
    Dist.assign(N+1,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        ll u = Q.top().second;
        Q.pop();
        for(ll i = 0; i < G[u].size(); i++){
                pii c = G[u][i];
            ll v = c.first;
            ll w = c.second;
            if(Dist[v] > Dist[u]+w){
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}
/*===========================================*/
int main() {
    ll N, M, u, v, w, source, T, S, D;
    cin >> N >> T >> M >> S >> D;
    G = new vii[N+1];

    for(ll i=0;i<M;++i){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    Dijkstra(S,N);

    ll temp = Dist[D];

    if(temp <= T)
    {
        cout << "alive " << temp << endl;
    }
    else
    {
        cout << "died" << endl;
    }

    return 0;
}
