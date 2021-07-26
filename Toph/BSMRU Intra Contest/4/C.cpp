// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

#define mx 100000005

bool check(int n, int pos)
{
	return n & (1 << pos);
}

int Set(int n, int pos)
{
	return n = n | (1 << pos);
}

int status[(mx / 32) + 5];

vector < int > primes;

void sieve(int n)
{
    int i, j, sq;

    sq = int( sqrt(n) );

    for(i = 3; i <= sq; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            for(j = i * i; j <= n; j += (i << 1))
            {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }

    primes.clear();

    primes.pb(2);

    for(i = 3; i <= n; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            primes.pb(i);
        }
    }


}

const ll mxn = 100000;
ll arr[mxn + 5];
pll tree[mxn * 4 + 5];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = {arr[b],arr[b]};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = {max(tree[left].first, tree[right].first), min(tree[left].second, tree[right].second)};

}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = {val,val};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = {max(tree[left].first, tree[right].first), min(tree[left].second, tree[right].second)};
}

pll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return {mnlld,mxlld};
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pll p1 = sum(left, b, mid, i, j);
    pll p2 = sum(right, mid + 1, e,i, j);

    return {max(p1.first,p2.first), min(p1.second,p2.second)};
}

ll solve(ll l, ll r)
{
	ll it1 = lower_bound(primes.begin(),primes.end(),l) - primes.begin();
	ll it2 = lower_bound(primes.begin(),primes.end(),r) - primes.begin();

//	cout << l << " " << it1 << " && " << r << " " << it2 << endl;

	if(it2 >= primes.size() || primes[it2] != r) it2--;

	return it2 - it1 + 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) slld(arr[i]);

    init(1,1,n);
    sieve(100000000);

    for(i = 1; i <= m; i++)
    {
		ll t;
		slld(t);
		slld(l);
		slld(r);

		if(t == 1)
		{
			update(1,1,n,l,r);
		}
		else
		{

			pll x = sum(1,1,n,l,r);

//			cout << x.first << " " << x.second << endl;

			ans = solve(x.second,x.first);

			printf("%lld\n", ans);
		}
    }


}



