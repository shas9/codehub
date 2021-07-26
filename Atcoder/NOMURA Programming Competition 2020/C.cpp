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

ll childrem[100005];
ll arr[100005];

ll solve(ll n)
{
	ll par = 0;

	ll possleaf = 1;

	ll ret = 0;

	for(ll i = 0; i <= n; i++)
	{
		if(arr[i] > possleaf) return -1;

		possleaf -= arr[i];

		childrem[i + 1] = possleaf;

		possleaf = min((long long)(1e18), possleaf * 2);

		ll tmp = arr[i];

		while(tmp)
		{
//			if(par >= i) bug;

			ll rem = childrem[par];

			rem = min(rem, tmp);


			ret += (rem * (i - par));

			tmp -= rem;
			childrem[par] -= rem;

			if(childrem[par] == 0) par++;
		}
	}

	return ret + 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
//		childrem[0] = 1;
//
//		for(i = 1; i <= n; i++)
//			if(i <= 50) childrem[i] = 2 * childrem[i - 1];
//			else childrem[i] = childrem[i - 1];

		childrem[0] = 2;

		for(i = 0; i <= n; i++) slld(arr[i]);

		ans = solve(n);

		printf("%lld\n", ans);

    }

}



