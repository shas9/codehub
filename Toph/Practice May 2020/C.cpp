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

struct node
{
	ll a, b, rem;

	node(ll _a, ll _b, ll _c)
	{
		a = _a;
		b = _b;
		rem = _c;
	}
};

ll solve(ll n, ll m, ll a)
{
	map < pll, ll > dist;

	queue < node > qq;

	qq.push(node(n,m,a));

	dist[{n,m}] = dist[{m,n}] = 0;

	ll ret = n * m;

	while(!qq.empty())
	{
		node top = qq.front();
		qq.pop();

		if(top.a * top.b < top.rem) continue;

		if(top.a * top.b == top.rem) dist[{top.a,top.b}];

		if(top.rem % top.a == 0) return dist[{top.a,top.b}] + 1;

		if(top.rem % top.b == 0) return dist[{top.a,top.b}] + 1;

		if(top.rem < top.a) return dist[{top.a,top.b}] + 2;

		if(top.rem < top.b) return dist[{top.a,top.b}] + 2;

		ll xx = (top.rem / top.a);
		pll x = {top.a, top.b - xx};

		xx *= top.a;

		ll yy = (top.rem / top.b);
		pll y = {top.a - yy, top.b};

		yy *= top.b;

		if(dist.find(x) == dist.end())
		{
			pll x1 = x;
			swap(x1.first,x1.second);

			dist[x] = dist[x1] = dist[{top.a,top.b}] + 1;
			qq.push(node(x.first,x.second,top.rem - xx));
		}

		if(dist.find(y) == dist.end())
		{
			pll y1 = y;
			swap(y1.first,y1.second);

			dist[y] = dist[y1] = dist[{top.a,top.b}] + 1;

			qq.push(node(y.first,y.second,top.rem - yy));
		}
	}

//	return ret;
}

ll solve1(ll n, ll m, ll a)
{
	if(a % n == 0) return 1;
	if(a % m == 0) return 1;

	for(ll i = 1; i <= n; i++)
	{
		if(a % i == 0 && (a / i) <= m) return 2;
	}

	for(ll i = 1; i <= m; i++)
	{
		if(a % i == 0 && (a / i) <= n) return 2;
	}

	return 3;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll a;
    while(cin >> n >> m >> a)
    {
//		cout << solve(n,m,a) << " " << solve1(n,m,a) << endl;


		ans = min(solve1(n,m,a), solve1(n,m,n*m - a));

		printf("%lld\n", ans);
    }


}



