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

vector < ll > g[500005];
ll depth[500005];
string str;
ll par[500005];
bool odd[500005][26];
vector < pll > nodes[500005];
pll dfstime[500005];
ll cnt;

void dfs(ll node, ll par)
{
	dfstime[node].first = ++cnt;

	for(auto it: g[node]) if(it != par) dfs(it,node);

	dfstime[node].second = ++cnt;
}

bool solve(ll v, ll h)
{
	if(depth[v] >= h) return 1;

	h--;

	if(nodes[h].empty()) return 1;

	pll z = {dfstime[v].first,0LL};

	auto it1 = lower_bound(nodes[h].begin(),nodes[h].end(),z);

	if(it1 == nodes[h].end()) return 1;

	z = {dfstime[v].second,0LL};

	auto it2 = upper_bound(nodes[h].begin(),nodes[h].end(),z);

	it2--;

	if(it2 < it1) return 1;


	bool ret[26];
	memset(ret,0,sizeof ret);

	if(it1 != nodes[h].begin())
	{
		it1--;
		pll x = *it1;

		for(ll i = 0; i < 26; i++) ret[i] = odd[x.second][i];
	}

	pll x = *it2;

	for(ll i = 0; i < 26; i++) ret[i] ^= odd[x.second][i];

	ll uneven = 0;

	for(ll i = 0; i < 26; i++) if(ret[i]) uneven++;

	return uneven <= 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);
    slld(m);

    for(i = 2; i <= n; i++) slld(par[i]);

    cin >> str;

    depth[1] = 1;

//     if(str == "cbcab") bug;

    for(i = 2; i <= n; i++)
    {
		input = par[i];

		depth[i] = depth[input] + 1;

		g[input].pb(i);
		g[i].pb(input);

		ll ch = str[i - 1] - 'a';

		odd[input][ch] ^= 1;
    }

    cnt = 0;
//     if(str == "cbcab") bug;
    dfs(1,0);

//     if(str == "cbcab") bug;

    for(i = 1; i <= n; i++)
    {
		nodes[depth[i]].pb(make_pair(dfstime[i].first,i));
    }

//	if(str == "cbcab") bug;

    for(i = 1; i <= n; i++) if(!nodes[i].empty())sort(nodes[i].begin(),nodes[i].end());

//	if(str == "cbcab") bug;

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j < nodes[i].size(); j++)
		{
			for(k = 0; k < 26; k++)
			{
				odd[nodes[i][j].second][k] ^= odd[nodes[i][j - 1].second][k];
			}
		}
    }

//    if(str == "cbcab") bug;
    for(i = 1; i <= m; i++)
    {
		ll v, h;

		slld(v);
		slld(h);

		if(solve(v,h)) printf("Yes\n");
		else printf("No\n");
    }




}
