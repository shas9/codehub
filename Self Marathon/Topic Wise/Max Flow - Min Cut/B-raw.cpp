// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

/*
 MAX FLOW Template code credit: Zobayer vai
 Link: http://zobayer.blogspot.com/2010/05/maximum-flow-dinitz-algorithm.html
*/
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
const int INF = 1000000000;
const int MAXN = 300, MAXE = 20110; //take node and edge twice in case node splitting
int src, snk, nNode, nEdge;
int Q[MAXN], last_edge[MAXN], pro[MAXN], dist[MAXN];
int flow[2*MAXE], cap[2*MAXE], prev_edge[2*MAXE], to[2*MAXE];
int edge_no[MAXN][MAXN];
inline void init(int _src, int _snk, int _n)
{
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(last_edge);
}
inline void addedge(int u, int v, int c, int bi = 0) //bi = 0 for unidirected or directed
{
 //   cout << u << " adding " << v << " " << c << endl;

    edge_no[u][v] = nEdge;
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = bi==1?c:0, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;
}
bool bfs()
{
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while (st < en)
    {
        u = Q[st++];
        for (i = last_edge[u]; i >= 0; i = prev_edge[i])
        {
            v = to[i];
            if (flow[i] < cap[i] && dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk] != -1;
}
int dfs(int u, int fl)
{
    if (u == snk) return fl;
    for (int &e = pro[u], v, df; e >= 0; e = prev_edge[e])
    {
        v = to[e];
        if (flow[e] < cap[e] && dist[v] == dist[u] + 1)
        {
            df = dfs(v, min(cap[e] - flow[e], fl));
            if (df > 0)
            {
                flow[e] += df;
                flow[e ^ 1] -= df;
       //         cout << "DFS " << u << " " << v << endl;
                return df;
            }
        }
    }
    return 0;
}
ll dinitz()
{
    ll ret = 0;
    int df;
    while (bfs())
    {
        for (int i = 0; i <= nNode; i++) pro[i] = last_edge[i];
        while (true)
        {
            df = dfs(src, INF);
            if (df) ret += (ll)df;
            else break;
        }
    }
    return ret;
}

pll arr[105];
ll cc[105];
ll dd[105];
ll peng = 0;

bool solve(ll n, long double d, ll snk)
{
	init(0,snk,n * 2 + 1);

	for(ll i = 1; i <= n; i++)
	{
		addedge(0, i, cc[i]);
		addedge(i, i + n, dd[i]);
	}

	d *= d;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			if(i == j) continue;

			long double dist = ((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first)) + ((arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));

			if(dist <= d || abs(d - dist) <= 0.000000000001) addedge(i + n, j, INF);
		}
	}

//	cout << snk << " " << dinic :: maxflow() << endl;

	return (dinitz() == peng);
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
		long double m;
		cin >> m;

		peng = 0;

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i].first);
			slld(arr[i].second);
			slld(cc[i]);
			slld(dd[i]);

			peng += cc[i];
		}

		printf("Case %lld:", cs);

		bool ase = 0;

		for(ll i = 1; i <= n; i++)
		{
			if(solve(n,m,i)) printf(" %lld", i - 1), ase = 1;
		}

		if(!ase) printf(" -1");

		printf("\n");


    }


}



