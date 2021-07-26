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

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
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

const ll mod = 998244353;


struct segtree
{

    ll n;
    vector < ll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,0);
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

        tree[node] = (tree[left] + tree[right]) % mod;
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
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

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return (p1 + p2) % mod;
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ans = power((power(2,n,mod)),mod - 2, mod);

		segtree odd;
		segtree even;

		odd.init(n + 1);
		even.init(n + 1);

		if(n & 1) even.update(n + 1,1);
		else odd.update(n + 1, 1);


		for(ll i = n; i >= 1; i--)
		{
			if(i & 1)
			{
				ll ask = even.query(i + 1, n + 1);
				odd.update(i,ask);
//
//				cout << ask << "-\n";
			}
			else
			{
				ll ask = odd.query(i + 1, n + 1);
				even.update(i, ask);

//				cout << ask << "+\n";

			}

//			for(ll j = 1; j <= n + 1; j++) cout << odd.query(j,j) << " ";
//			cout << endl;
//
//			for(ll j = 1; j <= n + 1; j++) cout << even.query(j,j) << " ";
//			cout << endl;
		}

//		cout << odd.query(1,1) << " " << even.query(1,1) << "\n";

		ans = (ans * odd.query(1,1)) % mod;

		cout << ans << "\n";
    }


}

