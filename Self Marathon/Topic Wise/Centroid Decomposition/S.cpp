// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb emplace_back

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

const ll maxn  = 50000;
vector < ll > primes;
bool vis[maxn+10];
ll prr[6000];
ll psz;

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
			primes.pb(i);
    }

    psz = 0;

    for(auto it: primes)
    {
		prr[++psz] = it;
    }

}

const ll mx = 50005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll dist[mx];
ll n, ans;

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

void calc(ll node, ll par, ll d = 1)
{
	for(ll i = 1; i <= psz; i++)
	{
		if(prr[i] >= d)
		{
			ans += dist[prr[i] - d];
		}
	}
	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
			calc(it,node, d + 1);
	}
}

void update(ll node, ll par, ll d = 1)
{
	dist[d]++;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			update(it,node,d + 1);
		}
	}
}

void rem(ll node, ll par, ll d = 1)
{
	dist[d]--;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			rem(it,node,d + 1);
		}
	}
}

ll decompose(ll cen)
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
	dist[0] = 1;

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			calc(it,cen);
			update(it,cen);
		}
	}

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			rem(it,cen);
		}
	}

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			cenpar[decompose(it)] = cen;
		}
	}

	return cen;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve();

    slld(n);
    ans = 0;

    for(ll i = 1; i < n; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		g[u].pb(v);
		g[v].pb(u);
    }

    decompose(1);

    double anss = (n * 1LL * (n - 1)) / 2.0;
    anss = ans / anss;

    printf("%.10f\n", anss);

}


