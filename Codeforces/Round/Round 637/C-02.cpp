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

ll par[100005];
ll pos[100005];
ll cnt[100005];

multiset < ll > mt;

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

bool solve(ll n)
{
	par[n + 1] = 0;

	for(ll i = 1; i <= n; i++) cnt[i] = 1;

	for(ll i = 1; i <= n; i++)
	{
		ll ps = pos[i];

		ll u = fnd(ps);

		multiset < ll > :: iterator it = mt.end();
		it--;
		ll mx = *it;

//		cout << u << " ~~ " << mx << " ~~ " << cnt[u] << endl;

		if(cnt[u] != mx) return 0;

		cnt[fnd(u + 1)] += cnt[u];

		cnt[u] = 0;

		par[u] = fnd(u + 1);

		mt.erase(it);

		if(par[u] == 0) continue;

		mt.insert(cnt[par[u]]);
//
//		for(ll j = 1; j <= n; j++)
//		{
//			cout << fnd(j) << " " << cnt[fnd(j)] << endl;
//		}
//
//		cout << "Done" << endl;
	}

	return 1;
}
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
		slld(n);

		mt.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			pos[input] = i;

			par[i] = i;

			mt.insert(1);
		}

		if(solve(n)) cout << "Yes" << "\n";
		else cout << "No" << "\n";
    }


}


