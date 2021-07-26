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

ll diff[6000];
ll arr[2005];

void precalc(ll n)
{
	memset(diff,0,sizeof diff);

	sort(arr + 1, arr + 1 + n);

	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			ll d = arr[i] - arr[j];

			diff[d]++;
		}
	}

	for(int i = 5500; i >= 0; i--)
	{
		diff[i] += diff[i + 1];
	}
}

ll solve(ll n)
{
	ll ret = 0;

	for(int i = 1; i <= 5000; i++)
	{
		for(int j = 1; j <= 5000; j++)
		{
			ll x = i + j;

			if(x >= 5000) break;

			ret += diff[x + 1] * (diff[i] - diff[i + 1]) * (diff[j] - diff[j + 1]);

//			if(i >= 3000)cout << i << " " << j << " " << ret << endl;
		}
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
		for(i = 1; i <= n; i++) slld(arr[i]);

		ll tot = (n * (n - 1)) / 2;

		tot = (tot * tot * tot);

		precalc(n);

		ans = solve(n);

//		cout << ans << " " << tot << endl;
		double ret = ((ans * 1.0) / (tot * 1.0));

		printf("%.10f\n", ret);


    }


}


