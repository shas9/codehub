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

const ll N = 300005;
ll arr[N];
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

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
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

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = min(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
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

ll mx[N];

ll bam(ll lo, ll hi, ll num)
{
	ll pos = hi;
	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(seg.query(mid, pos) < num)
		{
			lo = mid + 1;
		}
		else
		{
			ret = mid;
			hi = mid - 1;
		}
	}

	return ret;
}

ll dan(ll lo, ll hi, ll num)
{
	ll pos = lo;
	ll ret = lo;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

//		cout << num << " == " << pos << " " << mid << " = " << seg.query(pos, mid)  << endl;

		if(seg.query(pos, mid) < num)
		{
			hi = mid - 1;
		}
		else
		{
			ret = mid;
			lo = mid + 1;
		}
	}

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
		slld(n);

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		seg.init(n);

		for(ll i = 1; i <= n; i++) mx[i] = mxlld;

		for(ll i = 1; i <= n; i++)
		{
			ll num = arr[i];
			ll lft = bam(1, i, num);
			ll rgt = dan(i, n, num);

//			cout << num << ": " << lft << " " << rgt << endl;

			mx[num] = min(mx[num], rgt - lft + 1);
		}

		ll lim = n + 1;

		for(ll i = 1; i <= n; i++)
		{
//			cout << i << ": " << mx[i] << endl;
			if(mx[i] == mxlld)
			{
				lim = i;
				break;
			}
		}

		for(ll i = 2; i <= n; i++)
		{
			mx[i] = min(mx[i], mx[i - 1]);
		}

		string out = "";

//		cout << lim << endl;

		for(ll i = 1; i <= n; i++)
		{
			{
				ll sz = n - i + 1;

				if(sz >= lim) out += '0';
				else if(mx[sz] < i) out += '0';
				else out += '1';
			}
		}

		cout << out << "\n";
    }


}

