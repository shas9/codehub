// God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define nsz 100100 //take maximum nodes + some number

struct dijkstra
{
    pll dis[nsz];
    vector<ll> ed[nsz], cost[nsz];

    void addedge(ll u, ll v, ll c)
    {
		ed[u].pb(v);
		cost[u].pb(c);
    }

    void solve(ll src, ll dst)
    {
        ll i, j, ad, u;

        for(i = 0; i < nsz; i++)
        {
            dis[i] = {mxlld-100000, -1};
        }

        priority_queue <pll, vector<pll>, greater <pll> > pq;

        pq.push(pll(0, src));

        dis[src] = {1,-1};

        while(!pq.empty())
        {
            pll v = pq.top();
            u = v.second;
            //if (v.first >= lv[u]) continue;
            pq.pop();
            if(u == dst) return;

            for(i=0; i<ed[u].size(); i++)
            {
                ad = ed[u][i];
                if(dis[u].first+cost[u][i]<dis[ad].first)
                {
                    dis[ad].first = dis[u].first+cost[u][i];
                    dis[ad].second = u;
                    pq.push(pll(dis[ad].first, ad));
                }
            }
        }
    }

};


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		dijkstra me;

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;
			cin >> u >> v >> c;

			me.addedge(u,v,c);
			me.addedge(v,u,c);
		}

		me.solve(1,n);

		vector < ll > path;

		ll now = n;

		while(now != -1 && now != 1)
		{
			path.push_back(now);

			now = me.dis[now].second;
		}

		if(now == -1)
		{
			cout << -1 << "\n";
			continue;
		}

		path.push_back(1);

		reverse(path.begin(),path.end());

		for(auto it: path) cout << it << " ";

		cout << "\n";

//		printf("%lld\n", me.dis[n]);
    }


}


