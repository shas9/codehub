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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

using namespace std;

map < ll, vector < ll > > graph;
map < ll, ll > path;
queue < ll > q;
set < ll > s;
ll ans;


void bfs(ll source, ll time)
{
    ll i, j, k, l, temp;

    q.push(source);

    path[source] = 1;
    ans++;

    while(!q.empty())
    {
        if(path[q.front()] - 1 < time)
        {
            for(i = 0; i < graph[q.front()].size(); i++)
            {
                if(path[graph[q.front()][i]] == 0)
                {
                    path[graph[q.front()][i]] = path[q.front()] + 1;
                    ans++;
                    q.push(graph[q.front()][i]);
                }
            }
        }
        q.pop();
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase = 0;
    ll input, flag, tag;

    ll nodes;
    ll edges;

    ll a, b;

    while(1)
    {
        slld(edges);

        graph.clear();
        s.clear();

        if(edges == 0)
        {
            return 0;
        }

        for(i = 1; i <= edges; i++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);

            s.insert(a);
            s.insert(b);
        }

        while(1)
        {
            slld(a);
            slld(b);

            path.clear();
            ans = 0;

            while(!q.empty())
            {
                q.pop();
            }

            if(a == 0 && b == 0)
            {
                break;
            }

            bfs(a,b);

            //cout << s.size() << " - " << ans  << endl;

            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n", ++testcase, s.size() - ans, a, b);

        }
    }


}


