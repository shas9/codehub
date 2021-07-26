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

#define mod 958585860497

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

ll arr[100005];
multiset < ll > mset;
ll tree[5000006];

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = max(tree[node], val);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = max(tree[left],  tree[right]);
}

ll query(ll node, ll b, ll e, ll i, ll j)
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

    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid + 1, e,i, j);

    return max(p1,p2);


}


ll solve(ll n)
{
	for(ll i = 1; i <= n; i++) mset.insert(i);

	ll ret = 1;

	while(!mset.empty())
	{
		auto it = mset.end();
		it--;

		ll prvsz = mset.size();

		queue < ll > q;

		q.push(*it);

	}
}

ll solve1(ll n)
{
	ll ret = 1;

	for(ll i = 1; i <= n; i++)
	{
		ll sum = query(1,1,1000000,arr[i] + 1, 1000000);

		ret = max(ret, sum + 1);

		update(1,1,1000000,arr[i],sum + 1);
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

    mset.clear();

    slld(n);

    for(i = 1; i <= n; i++)
    {
		slld(arr[i]);
    }


    ans = solve1(n);

    printf("%lld\n", ans);


}



