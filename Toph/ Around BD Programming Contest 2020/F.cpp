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

#define mx 200005

ll arr[mx];
pll tree[mx*4];

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].first += val;
        tree[node].second += (val / abs(val));
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node].first = tree[left].first + tree[right].first;
    tree[node].second = tree[left].second + tree[right].second;
}

ll asksum(ll node, ll b, ll e, ll i, ll j)
{

    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].first;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = asksum(left, b, mid, i, j);
    ll p2 = asksum(right, mid + 1, e,i, j);

    return p1 + p2;
}

ll askcnt(ll node, ll b, ll e, ll i, ll j)
{

    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].second;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = askcnt(left, b, mid, i, j);
    ll p2 = askcnt(right, mid + 1, e,i, j);

    return p1 + p2;
}

struct node
{
    ll l, r, x, id, blc;
};

node q[mx];
ll ans[mx];

bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }

    if(a.blc % 2 == 0)
    {
        return a.r < b.r;
    }
    else
    {
        return a.r > b.r;
    }
}

ll cnt;

set < ll > st;
map < ll, ll > mp;

void add(ll x)
{
	x = arr[x];
	update(1,1,cnt,mp[x],x);
}

void rem(ll x)
{
	x = arr[x];
	update(1,1,cnt,mp[x],-x);
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		mp.clear();
		st.clear();
		memset(tree,0,sizeof tree);

		slld(n);

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);

			arr[i] += (1e13);

			st.insert(arr[i]);
		}

		slld(m);

		ll ssq = sqrt(m) + 20;

		for(ll i = 1; i <= m; i++)
		{
			slld(q[i].l);
			slld(q[i].r);
			slld(q[i].x);

			q[i].x += (1e13);

			q[i].id = i;
			q[i].blc = i / ssq;

			st.insert(q[i].x);
		}

		cnt = 0;

		for(auto it: st)
		{
			mp[it] = ++cnt;
		}

		sort(q + 1, q + 1 + m, comp);

		ll l = 1;
		ll r = 0;

		for(ll i = 1; i <= m; i++)
		{
			while(l > q[i].l) add(--l);
			while(r < q[i].r) add(++r);
			while(l < q[i].l) rem(l++);
			while(r > q[i].r) rem(r--);

			ll idx = mp[q[i].x];

			ll anss = 0;

			if(idx > 1)
			{
				ll sum1 = asksum(1,1,cnt,1,idx - 1);
				ll cnt1 = askcnt(1,1,cnt,1,idx - 1);

				anss += cnt1 * q[i].x - sum1;
			}

			if(idx < cnt)
			{
				ll sum2 = asksum(1,1,cnt,idx + 1, cnt);
				ll cnt2 = askcnt(1,1,cnt,idx + 1, cnt);

				anss += sum2 - cnt2 * q[i].x;
			}

			ans[q[i].id] = anss;
		}

		printf("Case %lld:\n", cs);
		for(ll i = 1; i <= m; i++) printf("%lld\n", ans[i]);

    }


}



