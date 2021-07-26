 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e12
#define mnlld -1e12

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
ll t1[N * 4];
ll t2[N * 4];
ll csum[N];

struct segtree
{
    ll n;

    void treeinit(ll node, ll b, ll e)
    {
        if(b == e)
        {
            t1[node] = csum[b];
            t2[node] = csum[b];
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeinit(left, b, mid);
        treeinit(right, mid + 1, e);

        t1[node] = max(t1[left], t1[right]);
        t2[node] = min(t2[left], t2[right]);

    }

    void init(ll _n)
    {
        n = _n;
        treeinit(1,1,n);
    }

    pll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mnlld,mxlld};
        }

        if(b >= i && e <= j)
        {
            return {t1[node],t2[node]};
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery(left, b, mid, i, j);
        pll p2 = treequery(right, mid + 1, e,i, j);

        return {max(p1.first,p2.first), min(p1.second, p2.second)};

    }

    pll query(ll x, ll y)
    {
		if(x > y) return {0,0};
        return treequery(1,1,n,x,y);
    }

} seg;

string str;



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
		cin >> n >> m;
		cin >> str;

		csum[0] = 0;

		for(ll i = 0; i < n; i++)
		{
			if(str[i] == '-') arr[i + 1] = -1;
			else arr[i + 1] = 1;
		}

		for(ll i = 1; i <= n; i++)
		{
			csum[i] = arr[i] + csum[i - 1];
		}

		seg.init(n);

		for(ll i = 1; i <= m; i++)
		{
			ll l, r;
			cin >> l >> r;

			ll mxl = 0;
			ll mnl = 0;

			pll ask1 = seg.query(1, l - 1);
			pll ask2 = seg.query(r + 1, n);

			mxl = max(mxl,ask1.first);
			mnl = min(mnl,ask1.second);

//			cout << ask1.first << " " << ask1.second << "\n";

			if(r < n)
			{
				ask2.first -= csum[r];
				ask2.second -= csum[r];

//				cout << ask2.first << " " << ask2.second << "\n";

				mxl = max(mxl, ask2.first + csum[l - 1]);
				mnl = min(mnl, ask2.second + csum[l - 1]);

			}

			cout << mxl - mnl + 1 << "\n";

		}


    }


}



