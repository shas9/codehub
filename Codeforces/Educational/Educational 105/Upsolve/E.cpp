 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

set < ll > g[200005][26];
map < pll, ll > mp;
ll odd, even, odd2;

void addedge(ll u, ll v, ll c)
{
	ll x = -1;

	if(mp.find({v,u}) != mp.end()) x = mp[{v,u}];
	g[u][c].insert(v);
	mp[{u,v}] = c;

//	cout << v << " " << u << " = " << x << "\n";

	if(x == -1) return;
	if(x == c) even++;
	else
	{
		for(ll i = 0; i < 26; i++)
		{
			for(auto it: g[v][i])
			{
				if(mp.find({it,v}) == mp.end()) continue;

				odd2 += mp[{it,v}] != 1;
			}

			for(auto it: g[u][i])
			{
				if(mp.find({it,u}) == mp.end()) continue;

				odd2 += mp[{it,u}] != 1;
			}
		}
		for(auto it: g[v][x])
		{
			if(it == u) continue;

			if(mp.find({it,v}) == mp.end()) continue;

			if(mp[{it,v}] == c) odd++;
		}

		for(auto it: g[u][c])
		{
			if(it == v) continue;

			if(mp.find({it,u}) == mp.end()) continue;

			if(mp[{it,u}] == x) odd++;
		}
	}

	return;
}

void cutedge(ll u, ll v)
{
	ll x = -1;
	ll c = mp[{u,v}];

	if(mp.find({v,u}) != mp.end()) x = mp[{v,u}];
	g[u][c].erase(v);
	mp[{u,v}] = -1;

	if(x == -1) return;

	if(x == c) even--;
	else
	{
		for(ll i = 0; i < 26; i++)
		{
			for(auto it: g[v][i])
			{
				if(mp.find({it,v}) == mp.end()) continue;

				odd2 -= mp[{it,v}] != 1;
			}

			for(auto it: g[u][i])
			{
				if(mp.find({it,u}) == mp.end()) continue;

				odd2 -= mp[{it,u}] != 1;
			}
		}

		for(auto it: g[v][x])
		{
			if(mp.find({it,v}) == mp.end()) continue;

			if(mp[{it,v}] == c) odd--;
		}

		for(auto it: g[u][c])
		{
			if(mp.find({it,u}) == mp.end()) continue;

			if(mp[{it,u}] == x) odd--;
		}
	}

	return;
}

void addedge1(ll u, ll v, ll c)
{
	mp[{u,v}] = c;

	ll x = -1;

	if(mp.find({v,u}) != mp.end()) x = mp[{v,u}];

	if(x != -1) odd++;
	if(x == c) even++;

	return;
}

void cutedge1(ll u, ll v)
{
	ll c = mp[{u,v}];

	mp[{u,v}] = -1;

	ll x = -1;

	if(mp.find({v,u}) != mp.end()) x = mp[{v,u}];

	if(x != -1) odd--;
	if(x == c) even--;

	return;
}

bool solve(ll k)
{
	if(k % 2 == 0) return even;
	if(k & 1) return odd;
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
		odd = 0, even = 0, odd2 = 0;
		for(ll i = 1; i <= n; i++) for(ll j = 0; j < 26; j++) g[i][j].clear();
		mp.clear();

		for(ll i = 1; i <= m; i++)
		{
			char c;
			ll u, v;

			cin >> c;

			if(c == '+')
			{
				cin >> u >> v >> c;
				addedge1(u,v,(c - 'a'));
			}
			else if(c == '-')
			{
				cin >> u >> v;
				cutedge1(u,v);
			}
			else
			{
				cin >> u;

				if(solve(u)) cout << "YES\n";
				else cout << "NO\n";
			}

//			cout << odd << " " << even << "\n";
		}
    }


}


