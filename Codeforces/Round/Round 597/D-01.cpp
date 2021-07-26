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

struct edge
{
	ll w, u, v;
};

ll par[2003];

bool comp(edge a, edge b)
{
	return a.w < b.w;
}

ll psc[2003];
ll wc[2003];
pll cord[2003];
vector < edge > vec;
bool done[2003];

ll fnd(ll x)
{
	if(par[x] == x) return x;

	return par[x] = fnd(par[x]);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++) cin >> cord[i].first >> cord[i].second;

		for(i = 1; i <= n; i++) cin >> psc[i];

		for(i = 1; i <= n; i++) cin >> wc[i];

		for(i = 1; i <= n; i++) par[i] = i;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
			{
				edge xx;
				xx.u = i;
				xx.v = j;

				if(i == j) xx.w = psc[i];
				else
				{
					ll dist = abs(cord[i].first - cord[j].first) + abs(cord[i].second - cord[j].second);
					xx.w = dist * (wc[i] + wc[j]);
				}

				vec.push_back(xx);
			}

		sort(vec.begin(),vec.end(),comp);

		vector < ll > a;
		vector < pll > b;

		memset(done,0,sizeof done);

		ll taka = 0;

		for(edge ed: vec)
		{
			if(a.size() == n) break;
			ll paru = fnd(ed.u);
			ll parv = fnd(ed.v);

			if(done[paru] && done[parv]) continue;

			if(paru == parv)
			{
				if(ed.u == ed.v)
				{
					a.push_back(ed.u);

					taka += ed.w;

					done[paru] = 1;
				}

				continue;
			}

			par[paru] = parv;
			done[paru] = done[parv] = (done[paru] | done[parv]);

			b.push_back({ed.u,ed.v});

			taka += ed.w;
		}

		cout << taka << "\n";

		cout << a.size() << "\n";

		for(auto it: a) cout << it << " ";

		cout << "\n";

		cout << b.size() << "\n";

		for(auto it: b) cout << it.first << " " << it.second << "\n";
    }


}




