// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

namespace dinic
{
	const ll inf = (1e16);
	const ll maxn = 5005, maxe = 3000005; //take node and edge twice in case node splitting

	ll src, snk, nNode, nEdge;
	ll Q[maxn], last_edge[maxn], pro[maxn], dist[maxn];
	ll flow[2 * maxe], cap[2 * maxe], prev_edge[2* maxe], to[2 * maxe];

	void init(ll _src, ll _snk, ll _n)
	{
		src = _src;
		snk = _snk;
		nNode = _n;
		nEdge = 0;

		memset(last_edge, -1, sizeof last_edge);
	}

	// use init() before adding edge to set source, sink and number of nodes and resetting
	void addedge(ll u, ll v, ll c, ll bi = 0) // bi = 0 for directed, bi = 1 for undirected
	{

		to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;
		to[nEdge] = u, cap[nEdge] = (bi == 1? c:0), flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;
	}

	bool bfs()
	{
		ll st, en;

		memset(dist,-1,sizeof dist);

		dist[src] = st = en = 0;
		Q[en++] = src;

		while(st < en)
		{
			ll u = Q[st++];

			for(ll i = last_edge[u]; i >= 0; i = prev_edge[i])
			{
				ll v = to[i];

				if(flow[i] < cap[i] && dist[v] == -1)
				{
					dist[v] = dist[u] + 1;
					Q[en++]	= v;
				}
			}
		}

		return dist[snk] != -1;
	}

	ll dfs(ll u, ll fl)
	{
		if(u == snk) return fl;

		for(ll &e = pro[u]; e >= 0; e = prev_edge[e])
		{
			ll v = to[e];

			if(flow[e] < cap[e] && (dist[v] == dist[u] + 1))
			{
				ll df = dfs(v, min(cap[e] - flow[e], fl));

				if(df > 0)
				{
					flow[e] += df;
					flow[e ^ 1] -= df;

					return df;
				}

			}
		}

		return 0;
	}

	ll maxflow()
	{
		ll ret = 0;

		while(bfs())
		{
			for(ll i = 0; i <= nNode; i++) pro[i] = last_edge[i];

			while(true)
			{
				ll df = dfs(src,inf);

				if(df) ret += df;
				else break;
			}
		}

		return ret;
	}
};

using namespace dinic;

const ll maxxn  = 50002;
vector < ll > primes;
bool vis[maxxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }
}

vector < pll > fact[105];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    while(cin >> n >> m)
    {
		ll nodecnt = 2;

		for(i = 1; i <= n; i++) fact[i].clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			for(j = 0; primes[j] * primes[j] <= input; j++)
			{
				while(input % primes[j] == 0)
				{
					fact[i].pb({primes[j],nodecnt});

					input /= primes[j];

					nodecnt++;
				}
			}

			if(input > 1)
			{
				fact[i].pb({input,nodecnt});
				nodecnt++;
			}
		}

		dinic :: init(1,nodecnt,nodecnt);

		for(i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			for(auto it: fact[u])
			{
				for(auto jt: fact[v])
				{
					if(it.first == jt.first)
					{
						if(u & 1)
						{
							dinic :: addedge(it.second, jt.second, 1);
						}
						else
						{
							dinic :: addedge(jt.second, it.second, 1);
						}
					}
				}
			}
		}

		for(i = 1; i <= n; i++)
		{
			if(i & 1) for(auto it: fact[i]) dinic :: addedge(1, it.second, 1);
			else for(auto it: fact[i]) dinic :: addedge(it.second, nodecnt, 1);
		}

		ans = dinic :: maxflow();

		cout << ans << '\n';

    }


}



