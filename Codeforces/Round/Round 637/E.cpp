// God put a smile upon your face <3

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


ll arr[10004];
ll dist[10004][1003];
bool vis[10004][1003];

struct edge
{
	ll node;
	ll tm;
	ll cost;

	edge(ll a, ll b, ll c)
	{
		node = a;
		tm = b;
		cost = c;
	}
};

ll solve(ll n, ll m)
{
	ll g, r;
	slld(g);
	slld(r);

	deque < pll > dq;

	memset(vis,0,sizeof vis);
	memset(dist,0,sizeof dist);

	dq.push_back({1,0});

	ll ret = mxlld;

//	bug;

	while(!dq.empty())
	{
		pll top = dq.front();
		dq.pop_front();

//		cout << top.first << " " << top.second << endl;

		if(top.second == 0)
		{
			if(abs(arr[top.first] - n) <= g)
			{
//				bug;
				ret = min(ret, abs(arr[top.first] - n) + dist[top.first][0] * (r + g));
			}
		}

		if(top.second == g)
		{
			if(vis[top.first][0] == 0)
			{
				vis[top.first][0] = 1;
				dist[top.first][0] = dist[top.first][top.second] + 1;

				dq.push_back({top.first,0});
			}

			continue;
		}

		if(top.first < n)
		{
			pll psh = {top.first + 1, top.second + abs(arr[top.first] - arr[top.first + 1])};

			if(vis[psh.first][psh.second] == 0 && psh.second <= g)
			{
				vis[psh.first][psh.second] = 1;
				dist[psh.first][psh.second] = dist[top.first][top.second];

				dq.push_front(psh);
			}
		}

		if(top.first > 1)
		{
			pll psh = {top.first - 1, top.second + abs(arr[top.first] - arr[top.first - 1])};

			if(vis[psh.first][psh.second] == 0 && psh.second <= g)
			{
				vis[psh.first][psh.second] = 1;
				dist[psh.first][psh.second] = dist[top.first][top.second];

				dq.push_front(psh);
			}
		}

	}


	if(ret == mxlld) ret = -1;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= m; i++) slld(arr[i]);

		sort(arr + 1, arr + 1 + m);

		ans = solve(n,m);

		printf("%lld\n", ans);
    }


}


