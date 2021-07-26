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
ll least[100005];
ll poss[100005];


ll solve(ll n)
{
	memset(least,0,sizeof least);
	memset(poss,0,sizeof poss);

	poss[0] = 1;

	for(ll i = 1; i <= n; i++)
	{
		poss[i] = (poss[i - 1] * 2);
		if(poss[i] >= (1e18)) poss[i] = 1e18;
	}

	ll ret = 0, sum = 0;

	for(ll i = n; i >= 0; i--)
	{
		least[i] = arr[i] + ((least[i + 1] + 1) / 2);

		if(least[i] > poss[i]) return -1;

		sum += arr[i];
	}

	ll nodes = 1;

	for(ll i = 0; i <= n; i++)
	{
		ret += min(nodes,sum);

		nodes -= arr[i];
		sum -= arr[i];

		nodes *= 2;

		if(nodes >= 1e18) nodes = 1e18;
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

    while(cin >> n)
    {
		for(i = 0; i <= n; i++) slld(arr[i]);

		ans = solve(n);

		printf("%lld\n", ans);
    }


}



