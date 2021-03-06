#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

const int N = 2005;

int par[N],C[N] , n;
int child[N],value[N];
int glob = 1;
vector<pii>g[N];

bool cmp(pii a,pii b)
{
    return a.second < b.second;
}
void modify(int node)
{
    sort(g[node].begin(),g[node].end(),cmp);
    for(int i = 1;i < g[node].size();i++){
        int v2 = g[node][i].first;
        g[node][i].second = g[node][i - 1].second + 2;
        value[v2] = g[node][i].second;
    }
}
void show(int node)
{
    for(int i = 0;i < g[node].size();i++){
        cout << g[node][i].first << " " << g[node][i].second << "\n";
    }
    cout << endl;
}
int main()
{
    FastRead
    cin >> n;
    FOR(i,1,n)cin >> par[i] >> C[i];

    for(int i = 1;i <= n;i++){
        if(par[i] != 0)child[par[i]]++;
    }
    set<pii>st;
    for(int i = 1;i <= n;i++){
        st.insert(mk(child[i],i));
    }

    while(!st.empty()){
        glob = glob - 100;

        pii P = *st.begin();
        st.erase(st.begin());
        int cnt = P.first;
        int node = P.second;

//        cout << cnt << " " << node << endl;
        assert(cnt == 0);


        if(C[node] > g[node].size()){
            cout << "NO\n";
            return 0;
        }
//        modify(node);

        if(g[node].empty()){
            value[node] = glob;
        }else{
            if(C[node] == 0)value[node] = g[node][0].second - 1;
            else value[node] = g[node][C[node]- 1].second + 1;
//            cout << "what: " << value[node] << "\n";
        }
//        cout << node << " here\n";
//        show(node);
        if(par[node] != 0){
            for(pii i : g[node]){
                g[par[node]].push_back(i);
            }
            g[par[node]].pb(mk(node,value[node]));
            modify(par[node]);
//            show(par[node]);

            st.erase(mk(child[par[node]],par[node]));
            child[par[node]]--;
            st.insert(mk(child[par[node]],par[node]));

        }

    }
    cout << "YES\n";
    for(int i = 1;i <= n;i++)cout << value[i] + 1000 << " ";


}
