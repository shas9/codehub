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
ll dist[mx];
ll n, k, ans;

vector < ll > g[mx];

ll tree[mx*4];

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = max(tree[left], tree[right]);
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return max(p1,p2);
}

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
	if(d <= k)
	{
		ans += dist[k - d];
	}

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
			calc(it,node, d + 1);
	}
}

void update(ll node, ll par, ll d)
{
	update(1,1,n,node,d);

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			update(it,node,d + 1);
		}
	}
}

void rem(ll node, ll par, ll d)
{
	update(1,1,n,node,0);

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

	update(cen,-1,0);

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
			cenpar[decompose(it)] = cen;
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}

