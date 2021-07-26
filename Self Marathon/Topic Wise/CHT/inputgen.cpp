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


ll par[100005];
ll dsu(ll node)
{
	if(par[node] == node) return node;

	return par[node] = dsu(par[node]);
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

    freopen("input.txt", "w", stdout);

    srand(time(NULL));

    n = 100000;

    for(ll i = 1; i <= n; i++)
    {
		par[i] = i;
    }

    cout << n << endl;

    for(ll i = 1; i <= n; i++)
    {
		ll x =  rand() % 100001;

		if(rand() % 3 == 0) x *= -1;

		cout << x << ' ';
    }

    cout << endl;

    for(ll i = 1; i <= n; i++)
    {
		ll x =  rand() % 100001;

		if(rand() % 3 == 0) x *= -1;

		cout << x << ' ';
    }

    cout << endl;
//
//    for(ll i = 1; i < n; i++) cout << i << " " << i + 1 << endl;

    ll edge = 0;

    while(edge < n)
    {
		if(edge == (n - 1)) break;
		ll u = rand() % n + 1;
		ll v = rand() % n + 1;

		if(dsu(u) == dsu(v)) continue;

		edge++;

		cout << u << " " << v << endl;

		par[dsu(u)] = par[dsu(v)];
    }

    return 0;

}


