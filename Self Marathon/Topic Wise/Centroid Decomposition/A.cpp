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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll mx = 100005;

ll cenpar[mx];
ll info[mx];
ll sz[mx];
bool done[mx];


vector < ll > g[mx];

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			dfs(it,node);
			sz[node] += sz[it];
		}
	}
}

ll decompose(ll cen, ll d = 0)
{
	dfs(cen,-1);

	ll target = sz[cen] / 2;
	ll p = -1;
	bool ok = false;

	while(!ok)
	{
		ok = true;

		for(auto it: g[cen])
		{
			if(it != p && done[it] == false && sz[it] > target)
			{
				ok = false;
				p = cen;
				cen = it;
				break;
			}

		}
	}

	done[cen] = true;
	info[cen] = d;

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			cenpar[decompose(it, d + 1)] = cen;
		}
	}

	return cen;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(ll i = 1; i < n; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		g[u].pb(v);
		g[v].pb(u);
    }

    decompose(1);

    for(ll i = 1; i <= n; i++)
    {
		printf("%c ", info[i] + 'A');
    }

    printf("\n");
}

