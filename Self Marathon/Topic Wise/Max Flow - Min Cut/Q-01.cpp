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


namespace dinic
{
	const ll inf = (1e16);
	const ll maxn = 305, maxe = 5005; //take node and edge twice in case node splitting

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

namespace hkarp
{
	const ll MaxLeftNodes = 50000;
	const ll MaxRightNodes = 50000;
	const ll MaxEdges = 150000;

	ll LeftNodesNo, RightNodesNo, edges;
	ll last[MaxLeftNodes], previous[MaxEdges], to[MaxEdges];
	ll matching[MaxRightNodes], dist[MaxLeftNodes], Q[MaxLeftNodes];
	bool used[MaxLeftNodes], vis[MaxLeftNodes];

	void init(ll _LeftNodesNo, ll _RightNodesNo)
	{
		LeftNodesNo = _LeftNodesNo;
		RightNodesNo = _RightNodesNo;
		edges = 0;
		fill(last, last + LeftNodesNo + 1, -1);
	}

	void addedge(ll u, ll v)
	{
		to[edges] = v;
		previous[edges] = last[u];
		last[u] = edges++;
	}

	void bfs()
	{
		fill(dist, dist + LeftNodesNo + 1, -1);
		ll QueueSize = 0;
		for (ll u = 1; u <= LeftNodesNo; ++u)
		{
			if (used[u] == 0)
			{
				Q[QueueSize++] = u;
				dist[u] = 0;
			}
		}
		for (ll i = 0; i < QueueSize; i++)
		{
			ll u1 = Q[i];
			for (ll e = last[u1]; e >= 0; e = previous[e])
			{
				ll u2 = matching[to[e]];
				if (u2 >= 0 && dist[u2] < 0)
				{
					dist[u2] = dist[u1] + 1;
					Q[QueueSize++] = u2;
				}
			}
		}
	}

	bool dfs(ll u1)
	{
		vis[u1] = 1;
		for (ll e = last[u1]; e >= 0; e = previous[e])
		{
			ll v = to[e];
			ll u2 = matching[v];
			if (u2 < 0 || vis[u2] == 0 && dist[u2] == dist[u1] + 1 && dfs(u2))
			{
				matching[v] = u1;
				used[u1] = 1;
				return 1;
			}
		}
		return 0;
	}

	ll bpm()
	{
		fill(used, used + LeftNodesNo + 1, 0);
		fill(matching, matching + RightNodesNo + 1, -1);
		for (ll res = 0;;)
		{
			bfs();
			fill(vis, vis + LeftNodesNo + 1, 0);
			ll f = 0;
			for (ll u = 1; u <= LeftNodesNo; ++u)
				if (used[u] == 0 && dfs(u))
					++f;
			if (f == 0)
				return res;
			res += f;
		}
	}
}

using namespace hkarp;

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

		hkarp :: init(120,120);

		for(i = 1; i <= n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			u++;
			v++;

			hkarp :: addedge(u, v);
		}

		ans = hkarp :: bpm();

		printf("%lld\n", ans);
    }


}



