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

ll par[100005];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= 100000; i++) par[i] = i;

		for(i = 1; i <= n; i++) slld(arr[i]);

		cin >> m;

		for(i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);


			par[fnd(u)] = fnd(v);
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			ans += fnd(arr[i]);
		}

		cout << ans << '\n';
    }

}



