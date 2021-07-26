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

struct node
{
    ll w, x, y;
};

vector < node > edge;
vector < pll > graph[505];
ll par[505];
ll dist[505];

bool comp(node a, node b)
{
    return a.w <= b.w;
}

void bfs(ll node)
{
    queue < ll > q;

    memset(dist,-1,sizeof dist);

    q.push(node);

    dist[node] = 0;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            pll xx = graph[top][i];

//            cout << top << " --> " << xx.first << " " << graph[top].size() << endl;

            if(dist[xx.first] != -1) continue;

            dist[xx.first] = max(dist[top], xx.second);

            q.push(xx.first);
        }
    }
 }

 ll findpar(ll x)
 {
     if(par[x] == x) return x;

     return par[x] = findpar(par[x]);
 }


 void mst(ll n)
 {
     ll cnt = 0;
     for(ll i = 0; i < edge.size(); i++)
     {
         node xx = edge[i];

         ll px = findpar(xx.x);
         ll py = findpar(xx.y);

         if(px == py) continue;

         par[px] = py;

         graph[xx.x].push_back(make_pair(xx.y,xx.w));
         graph[xx.y].push_back(make_pair(xx.x,xx.w));

         cnt++;

         if(cnt == n-1) return;
     }
 }
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        edge.clear();
        for(i = 0; i <= n; i++) graph[i].clear();

        for(i = 0; i <= n; i++) par[i] = i;

        for(i = 1; i <= m; i++)
        {
            node xx;

            slld(xx.x);
            slld(xx.y);
            slld(xx.w);

            edge.push_back(xx);
        }

        sort(edge.begin(),edge.end(),comp);

        mst(n);

        slld(input);

        bfs(input);

        printf("Case %lld:\n", cs);
        for(ll i = 0; i < n; i++)
        {
            if(dist[i] == -1)
            {
                printf("Impossible\n");
                continue;
            }
            printf("%lld\n", dist[i]);
        }
    }


}

/*

100
6 6
0 1 10
0 2 10
1 3 20
2 4 40
4 5 30
3 5 30
0

*/

