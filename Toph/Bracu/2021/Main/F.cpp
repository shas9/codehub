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

string str;
int arr[1000006];


struct info
{
	int cnt[27];
	ll res;
};

struct segtree
{

    ll n;
    vector < info > tree;

    void treeupdate(ll node, ll b, ll e)
    {
////		cout << node << " " << b << " " << e << endl;
//		if(node == 0)exit(0);
        if(b == e)
        {
            for(ll i = arr[b]; i >= 0; i--) tree[node].cnt[i] = 1;
            tree[node].res = 0;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid);
        treeupdate(right, mid + 1, e);

        tree[node].res = tree[left].res + tree[right].res;

        for(ll i = 0; i < 26; i++)
        {
			tree[node].cnt[i] = tree[left].cnt[i] - tree[left].cnt[i + 1] + tree[right].cnt[i] - tree[right].cnt[i + 1];
        }

        for(ll i = 0; i + 1 < 26; i++)
        {
			tree[node].res += (tree[right].cnt[i] - tree[right].cnt[i + 1]) * 1LL * tree[left].cnt[i + 1];
        }

        for(ll i = 24; i >= 0; i--)
        {
			tree[node].cnt[i] = tree[node].cnt[i] + tree[node].cnt[i + 1];
        }
    }


    void init(ll _n)
    {
        n = _n;
        tree.resize(4 * n + 2);

        treeupdate(1,1,n);
    }

    vector < info > in;

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
			return -1;
        }

        if(b >= i && e <= j)
        {
			ll sz = in.size();
			in.push_back(tree[node]);
            return sz;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        if(p1 == -1) return p2;
        if(p2 == -1) return p1;

        info ret;
        ret.res = in[p1].res + in[p2].res;

        for(ll i = 0; i < 26; i++)
        {
			ret.cnt[i] = in[p1].cnt[i] - in[p1].cnt[i + 1] + in[p2].cnt[i] - in[p2].cnt[i + 1];
        }

        for(ll i = 0; i + 1 < 26; i++)
        {
			ret.res += (in[p2].cnt[i] - in[p2].cnt[i + 1]) * 1LL * in[p1].cnt[i + 1];
        }

        for(ll i = 24; i >= 0; i--)
        {
			ret.cnt[i] = ret.cnt[i] + ret.cnt[i + 1];
        }

        ll sz = in.size();
        in.push_back(ret);

        return sz;
    }

    ll query(ll x, ll y)
    {
		in.clear();
        return in[treequery(1,1,n,x,y)].res;
    }

} seg;


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> str)
    {
		n = str.size();
		for(ll i = 0; i < n; i++)
		{
			arr[i + 1] = str[i] - 'a';
		}

		seg.init(n);


		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll l, r;

			cin >> l >> r;

			ans = seg.query(l,r);

			cout << ans << "\n";
		}
    }


}

