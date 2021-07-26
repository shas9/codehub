#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
 
#ifdef LOCAL
#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
#define tham getchar()
#endif
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))
 
mt19937_64 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
//const ll mod = ;
//const ld error = ;
const ld PI = acosl(-1);
 
//const int/ll inf = ;
const int nmax = (2<<10)+100;
///===========================================  template  =======================================================
 
 
typedef int F;
const F infflow = 1e9+5;
typedef int C;													///COST
 
struct edge
{
    int v, w;		//edge is v -> w, flow is in that direction too
    F cap, flow;
    C cost;													///COST
    edge(int _v = 0, int _w = 0, F _c = 0, C _cost = 0){		///CHANGE
        v = _v, w = _w, cap = _c, flow = 0;
        cost = _cost;										///COST
    }
 
	//u represents from which vertex we request the function
    F flowfrom(int u) {return (u == v)? flow : -flow;}
    int other(int u) {return (u == v)? w: v;}
    F rescap(int u) {return (u == v)? cap - flow: flow;}
    void sendflow(int u, F f) {flow += (u == v)? f: -f;}
    C costfrom(int u) {return (u == v)? cost : -cost;}		///COST
};
 
vector<edge> E;
vector<int> adj[nmax];
 
//add edge from v to w
inline void addEdge(int v, int w, F c, C cost)		///CHANGE
{
    E.emplace_back(v, w, c, cost);						///CHANGE
    adj[v].push_back((int)E.size()-1);
    adj[w].push_back((int)E.size()-1);
}
 
const C infcost = 1e9;
C dist[nmax];			// init to inf
vector<int> dirty;
int link[nmax];
bool inQ[nmax];
inline bool spfa(int s, int t)
{
	for(int x : dirty) dist[x] = infcost;
	dirty.clear();
 
    queue<int> q;
    q.push(s);
    inQ[s] = true;
    dist[s] = 0, link[s] = -1;
 
    while(!q.empty()){
        s = q.front();
        q.pop();
        inQ[s] = false;
 
        for(int i: adj[s]){
            int v = E[i].other(s);
            if(E[i].rescap(s) == 0) continue;
 
            if(dist[v] > dist[s] + E[i].costfrom(s)){
				if(dist[v] == infcost) dirty.push_back(v);
                dist[v] = dist[s] + E[i].costfrom(s);
                link[v] = i;
                if(!inQ[v]){
                    q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }
    return dist[t] != infcost;
}
 
inline pair<F, C> update(int s, int t){
    int cur = t;
    F blkflow = infflow;
    C cost = 0;
    while(cur != s){
        int id = link[cur];
        cur = E[id].other(cur);
        blkflow = min(blkflow, E[id].rescap(cur));
        cost += E[id].costfrom(cur);
    }
	cost *= blkflow;
    cur = t;
    while(cur != s){
        int id = link[cur];
        cur = E[id].other(cur);
        E[id].sendflow(cur, blkflow);
    }
    return make_pair(blkflow, cost);
}
 
inline pair<F, C> maxflow(int s, int t)		//s - source, t - sink
{
    pair<F, C> ret = make_pair(F(0), C(0));
    while(spfa(s, t)){
        auto p = update(s, t);
        ret.first += p.first;
        ret.second += p.second;
    }
    return ret;
}
 
int used[nmax][12];
int wtf[nmax];
 
int main(){
    FASTIO;
 
    for(int i = 0; i<10; i++){
        wtf[bt(i)] = i;
    }
 
    int d, n;
    cin>>d>>n;
 
    int S = int(2*bt(d));
    int T = int(2*bt(d)+1);
    for(int i = 0; i<bt(d); i++){
        addEdge(2*i, 2*i+1, 2e3, 0);
        if(i != 0) addEdge(2*i+1, 0, 2e3, 1);
 
        for(int j = 0; j<d; j++){
            if(!(i & bt(j))){
                int i2 = i | bt(j);
                addEdge(2*i+1, 2*i2, 2e3, 1);
            }
        }
    }
 
    for(int i = 0; i<=T; i++) dist[i] = infcost;
 
    for(int t = 0; t<n; t++){
        string m;
        cin>>m;
        int x = 0;
        for(int i = 0; i<d; i++){
            if(m[i] == '1') x |= bt(i);
        }
 
        addEdge(2*x, T, 1, 0);
        addEdge(S, 2*x+1, 1, 0);
    }
 
    auto p = maxflow(S, T);
 
    assert(p.first == n);
    p.second--;
 
    cout<<p.second<<endl;
 
    for(int i = 0; i<bt(d); i++){
        for(auto e : adj[2*i+1]){
 
            int j = E[e].other(2*i+1)/2;
 
 
            if((i&j) == i && i != j){
//                debug(), dbg(i), dbg(j), E[e].flowfrom(2*i+1);
                used[i][wtf[i^j]]+=E[e].flowfrom(2*i+1);
            }
        }
    }
 
    int cur = 0;
 
    for(int i = 0; i<p.second; i++){
        bool found = false;
        for(int j = 0; j<d; j++){
            if(used[cur][j]){
                used[cur][j]--;
                cout<<j<<" ";
 
                cur |= bt(j);
 
                found = true;
                break;
            }
        }
 
        if(!found){
            cout<<"R ";
            cur = 0;
        }
    }
 
 
    return 0;
}

