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
ll sz[mx];
bool done[mx];
map < ll, ll > distup, distdown;
ll p10[mx];
ll phi;
ll n, m;
vector < pll > g[mx];
ll ans = 0;

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			dfs(it.first,node);
			sz[node] += sz[it.first];
		}
	}
}

ll mul(ll x, ll y)
{
	return ((x % m) * (y % m)) % m;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void calc(ll node, ll par, ll d, ll up, ll down)
{
	ll x = - mul(down, power(p10[d], phi - 1, m));
	x = (x + m + m) % m;

	assert(x >= 0);

	ans += distdown[up];
	ans += distup[x];

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			ll nup = (mul(it.second, p10[d]) + up) % m;
			ll ndown = (mul(down, 10) + it.second) % m;

			calc(it.first, node, d + 1, nup, ndown);
		}
	}
}

void update(ll node, ll par, ll d, ll up, ll down)
{
	ll x = - mul(down, power(p10[d], phi - 1, m));
	x = (x + m + m) % m;

	assert(x >= 0);

	distdown[x]++;
	distup[up]++;

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			ll nup = (mul(it.second, p10[d]) + up) % m;
			ll ndown = (mul(down, 10) + it.second) % m;

			update(it.first, node, d + 1, nup, ndown);
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
			if(it.first != p && done[it.first] == false && sz[it.first] > target)
			{
				ok = false;
				p = cen;
				cen = it.first;
				break;
			}
		}
	}

	done[cen] = true;

	distup.clear();
	distdown.clear();

	distdown[0] = distup[0] = 1;

	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			calc(it.first, cen, 1, it.second % m, it.second % m);
			update(it.first, cen, 1, it.second % m, it.second % m);
		}
	}

	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			cenpar[decompose(it.first)] = cen;
		}
	}

	return cen;
}

ll calphi()
{
	ll mm = m;

	double res = mm;

	for(ll i = 2; i * i <= mm; i++)
	{
		if(mm % i == 0)
		{
			while(mm % i == 0) mm /= i;
			res *= (1.0 - (1.0 / i));
		}
	}

	if(mm > 1) res *= (1.0 - (1.0 / mm));

	return phi = (long long)res;
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i < n; i++)
    {
		ll u, v, w;

		slld(u);
		slld(v);
		slld(w);
		u++;
		v++;

//		cout << u << " " << v << endl;

		g[u].pb({v,w});
		g[v].pb({u,w});
    }

    p10[0] = 1;

    for(i = 1; i <= n; i++) p10[i] = (p10[i - 1] * 10) % m;

    calphi();

    decompose(1);

    printf("%lld\n", ans);
}



