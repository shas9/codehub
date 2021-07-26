
#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

struct ed
{
	ll node, ww, tt;

	ed(ll a, ll b, ll c)
	{
		node = a;
		ww = b;
		tt = c;
	}

	bool operator < (const ed &a)const
	{
		if(ww != a.ww) return ww > a.ww;

		return tt > a.tt;
	}
};

vector < ed > graph[100005];
ll tp[100005];
ll dist[100005];

ll djk(ll n)
{
	priority_queue < ed > pq;

	for(ll i = 1; i <= n; i++) dist[i] = mxlld, tp[i] = -1;

	pq.push(ed(1,0,1));

	dist[1] = 0;

	while(!pq.empty())
	{
		ed top = pq.top();
		pq.pop();

		if(dist[top.node] < top.ww) continue;

		for(ed x: graph[top.node])
		{
			if(dist[x.node] > dist[top.node] + x.ww)
			{
				tp[x.node] = x.tt;
				dist[x.node] = dist[top.node] + x.ww;

				pq.push(ed(x.node,dist[x.node],x.tt));
			}
			else if(dist[x.node] == (dist[top.node] + x.ww))
			{
				if(x.tt == 0) tp[x.node] = 0;
				else
				{
					if(tp[x.node] == -1) tp[x.node] = 1;
				}
			}

		}
	}

	ll ret = 0;

	for(ll i = 2; i <= n; i++) ret += tp[i];

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(i = 1; i <= n; i++) graph[i].clear();

		for(i = 1; i <= m; i++)
		{
			ll u, v, w;
			slld(u);
			slld(v);
			slld(w);

			graph[u].pb(ed(v,w,0));
			graph[v].pb(ed(u,w,0));
		}

		for(i = 1; i <= k; i++)
		{
			ll u, w;

			slld(u);
			slld(w);

			graph[1].pb(ed(u,w,1));
			graph[u].pb(ed(1,w,1));
		}

		ans = k - djk(n);

		printf("%lld\n", ans);
    }


}
