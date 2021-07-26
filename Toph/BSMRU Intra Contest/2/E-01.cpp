// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007

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

struct node
{
    ll l, r, id, blc;
};

const ll lim = 20000;

node q[lim];
ll ans[lim];
ll arr[lim];
ll llcm = 1;
multiset < ll > st[1000006];

const ll maxn  = 1000002;
vector < ll > primes;
bool vis[maxn+10];

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


void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

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

void add(ll x)
{
	x = arr[x];

	for(auto i:primes)
	{
		if(i * i > x) break;

		if(x % i) continue;

		ll cn = 0;

		while(x % i == 0) x /= i, cn++;


		multiset < ll > :: iterator it = st[i].end();

		ll mx = 0;

		if(st[i].empty() == 0) it--,  mx = *it;

		if(cn > mx) llcm = (llcm * power(i,cn - mx,mod)) % mod;

		st[i].insert(cn);
	}

	if(x > 1)
	{
		ll i = x;
		ll cn = 1;
		multiset < ll > :: iterator it = st[i].end();

		ll mx = 0;

		if(st[i].empty() == 0) it--,  mx = *it;

		if(cn > mx) llcm = (llcm * power(i,cn - mx,mod)) % mod;

		st[i].insert(cn);
	}
}

void rem(ll x)
{
	x = arr[x];

	for(auto i:primes)
	{
		if(i * i > x) break;

		if(x % i) continue;

		ll cn = 0;

		while(x % i == 0) x /= i, cn++;

		multiset < ll > :: iterator it = st[i].end();
		it--;

		llcm = (llcm * power(power(i,*it,mod),mod - 2,mod)) % mod;

		st[i].erase(cn);

		it = st[i].end();

		if(st[i].empty()) continue;

		it--;

		llcm = (llcm * power(i,*it,mod)) % mod;
	}

	if(x > 1)
	{
		ll i = x;
		ll cn = 1;
		multiset < ll > :: iterator it = st[i].end();
		it--;

		llcm = (llcm * power(power(i,*it,mod),mod - 2,mod)) % mod;

		st[i].erase(cn);

		it = st[i].end();

		if(st[i].empty()) return;

		it--;

		llcm = (llcm * power(i,*it,mod)) % mod;
	}
}


// q[i].blc = l / ssq;  /// block count

/*
    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(l < q[i].l) remove(l++);
    while(r > q[i].r) remove(r--);
*/

int main()
{
    ll i, j, k, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    sieve();


    for(i = 1; i <= n; i++)
    {
		slld(arr[i]);
    }

    ll ssq = sqrt(n) + 20;

	slld(m);

	for(i = 1; i <= m; i++)
	{
		slld(q[i].l);
		slld(q[i].r);
		q[i].blc = l / ssq;  /// block count
		q[i].id = i;
	}

	sort(q + 1, q + 1 + m, comp);

	l = 1;
	r = 0;

	for(i = 1; i <= m; i++)
	{
//		cout << q[i].l << " " << q[i].r
//		bug;
		while(l > q[i].l) add(--l);
//		bug;
		while(r < q[i].r) add(++r);
//		bug;
		while(l < q[i].l) rem(l++);
//		bug;
		while(r > q[i].r) rem(r--);
//		bug;

		ans[q[i].id] = llcm;
	}

	for(i = 1; i <= m; i++)
	{
		printf("%lld\n", ans[i]);
	}


}



