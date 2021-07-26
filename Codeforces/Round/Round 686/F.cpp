 // God put a smile upon your face <3

#include <bits/stdc++.h>

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


const ll N = 200005;
ll arr[N];
ll mxend[N];
ll tree[N * 4];

struct segtree
{
    ll n;

    void treeinit(ll node, ll b, ll e)
    {
        if(b == e)
        {
            tree[node] = arr[b];
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeinit(left, b, mid);
        treeinit(right, mid + 1, e);

        tree[node] = min(tree[left], tree[right]);
    }

    void init(ll _n)
    {
        n = _n;
        treeinit(1,1,n);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return mxlld;
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return min(p1,p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

void process(ll n)
{
	mxend[n + 1] = 0;

	for(ll i = n; i >= 1; i--) mxend[i] = max(mxend[i + 1], arr[i]);

	seg.init(n);
}

ll solve2(ll lo, ll hi, ll mx)
{
	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(mxend[mid] > mx)
		{
			lo = mid + 1;
		}
		else if(mxend[mid] < mx)
		{
			hi = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

ll solve1(ll y, ll mx, ll n)
{
	ll lft = -1;
	ll lo = y;
	ll hi = n - 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		ll x = seg.query(y,mid);

		if(x < mx)
		{
			hi = mid - 1;
		}
		else if(x > mx)
		{
			lo = mid + 1;
		}
		else
		{
			lft = mid;
			hi = mid - 1;
		}
	}

	ll rgt = -1;
	lo = y;
	hi = n - 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		ll x = seg.query(y,mid);

		if(x < mx)
		{
			hi = mid - 1;
		}
		else if(x > mx)
		{
			lo = mid + 1;
		}
		else
		{
			rgt = mid;
			lo = mid + 1;
		}
	}


//	cout << lft << " " << rgt << " " << mx << endl;

	if(lft == -1) return -1;

	ll ret = solve2(lft + 1, min(n,rgt + 1), mx);

	return ret;
}

bool solve(ll n)
{
	ll mx = 0;

	for(ll i = 1; i + 2 <= n; i++)
	{
		mx = max(mx, arr[i]);

		ll get = solve1(i + 1, mx, n);

		if(get != -1)
		{
			cout << "YES\n";
//			cout << i << " " << get.first << " " << get.second << "\n";
			cout << i << " " << get - i - 1 << " " << n - get + 1 << "\n";

			return 1;
		}
	}

	return 0;
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
		slld(n);

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		process(n);

		if(solve(n) == 0) cout << "NO\n";
    }


}


