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

map < string, ll > mp;
vector < pair < ll, pll > > edges;

ll par[200];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll solve(ll n)
{
	for(ll i = 1; i <= n; i++) par[i] = i;

	sort(edges.begin(),edges.end());

	ll ret = 0;

	for(auto it: edges)
	{
		ll u = it.second.first;
		ll v = it.second.second;

		ll pu = fnd(u);
		ll pv = fnd(v);

		if(pu == pv) continue;

		ret += it.first;

		par[pu] = pv;
	}

	set < ll > st;

	for(ll i = 1; i <= n; i++) st.insert(fnd(i));

	if(st.size() > 1) return -1;

	return ret;
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
		mp.clear();
		edges.clear();

		slld(n);

		ll cnt = 0;

		for(i = 1; i <= n; i++)
		{
			string s1, s2;
			ll u,v,w;

			cin >> s1 >> s2 >> w;

			if(mp.find(s1) == mp.end()) mp[s1] = ++cnt;
			if(mp.find(s2) == mp.end()) mp[s2] = ++cnt;

			u = mp[s1];
			v = mp[s2];

			edges.push_back({w,{u,v}});
		}

		ans = solve(cnt);

		if(ans == -1) printf("Case %lld: Impossible\n", cs);
		else printf("Case %lld: %lld\n", cs, ans);
    }


}


