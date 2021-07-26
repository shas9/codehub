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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		k *= -1, m *= -1; // for min
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		ll ret = l.k * x + l.m;

		ret *= -1;
		return ret; // ret *= -1 for minimum
	}
} tree[1000006];

void update(ll node, ll b, ll e, ll i, ll m, ll c)
{
    if(i > e || i < b)
    {
        return;
    }

	tree[node].add(m,c);

    if(b == i && e == i) return;

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, m, c);
    update(right, mid + 1, e, i, m, c);
}

long long sum(ll node, ll b, ll e, ll i, ll j, ll x)
{

    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
        return tree[node].query(x);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    long long p1 = sum(left, b, mid, i, j, x);
    long long p2 = sum(right, mid + 1, e,i, j, x);

    return min(p1,p2);
}

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);
    slld(m);

    for(ll i = 1; i <= n; i++)
    {
        ll c, p;

        slld(c);
        slld(p);

        update(1,1,n,i,-2 * c, c * 1LL * c + p);
    }

    for(ll i = 1; i <= n; i++)
    {
        ll c, k;

        slld(c);
        slld(k);

        vec.resize(k);

        for(ll j = 0; j < k; j++) slld(vec[j]);

        sort(vec.begin(),vec.end());

        vec.push_back(n + 1);

        ll prev = 1;

        long long mn = mxlld;

		long long lo = sum(1,1,n,1,n,c);

        for(auto it: vec)
        {
            if(prev < it)
            {
                mn = min(mn, sum(1,1,n,prev, it - 1, c));
            }

            if(mn == lo) break;

            prev = it + 1;
        }

        if(mn == mxlld) assert(0);

        mn += (c * 1LL * c);

        printf("%lld\n", mn);
    }
}


/*

4 100
1000000000 1000000000
1 1000000000
500000000 1000000000
999999999 1000000000
1 3 2 3 4

*/



