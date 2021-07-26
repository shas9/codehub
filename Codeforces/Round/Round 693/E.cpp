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

const ll N = 400005;
struct info
{
	ll x, y, id;
} arr[N];

pll tree[N * 4];

struct segtree
{
    ll n;

    void treeinit(ll node, ll b, ll e)
    {
        if(b == e)
        {
            tree[node] = {arr[b].y, arr[b].id};
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
            tree[node].first = val;
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

    pll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mxlld,-1};
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery(left, b, mid, i, j);
        pll p2 = treequery(right, mid + 1, e,i, j);

        return min(p1,p2);
    }

    pll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

bool comp(info a, info b)
{
	if(a.x != b.x) return a.x < b.x;

	return a.y < b.y;
}

ll ans[N];
vector < pll > v[N];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			ll h, w;

			cin >> h >> w;

			arr[i * 2] = {h,w,i};
			arr[i * 2 - 1] = {w,h,i};

			ans[i] = -1;

			v[i].clear();
		}

		sort(arr + 1, arr + 1 + (n * 2), comp);

		for(ll i = 1; i <= (n * 2); i++)
		{
			v[arr[i].id].push_back({i, arr[i].y});
		}

		seg.init(n * 2);

		ll ptr = 0;

		for(ll i = 1; i <= (n * 2); i++)
		{
			pll ask = seg.query(1,i);

//			cout << arr[i].x << " " << arr[i].y << " is " << ask.first << " " << ask.second << "\n";
		}

		for(ll i = 2; i <= (n * 2); i++)
		{
//			for(ll ii = 1; ii <= (n * 2); ii++)
//			{
//				pll ask = seg.query(1,ii);
//
////				cout << arr[ii].x << " " << arr[ii].y << " isisis " << ask.first << " " << ask.second << "\n";
//			}

			if(ans[arr[i].id] != -1) continue;

			while(arr[ptr + 1].x < arr[i].x) ptr++;

			if(v[arr[i].id].front().first != i)
			{
				seg.update(v[arr[i].id].front().first, mxlld);
			}

			pll ask = seg.query(1,ptr);

//			cout << arr[i].x << " " << arr[i].y << " " << i << " " << ask.first << " " << ask.second << " " << ptr << "\n";

			if(ask.first < arr[i].y)
			{
				ans[arr[i].id] = ask.second;
			}

			if(v[arr[i].id].front().first != i)
			{
				seg.update(v[arr[i].id].front().first, v[arr[i].id].front().second) ;
			}
		}

		for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

		cout << "\n";
    }


}
