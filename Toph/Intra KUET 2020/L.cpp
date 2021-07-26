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

void brute(ll n)
{
	vector < ll > len(n + 1);

	for(ll i = 1; i <= n; i++)
	{
		ll sum = 0;

		for(ll j = i; j <= n; j++)
		{
			sum += j;

			if(sum & 1)
			{
				len[j - i + 1]++;
			}
		}
	}

	ll tot = 0;

	for(ll i = 1; i <= n; i++)
	{
//		if(i & 1) cout << i << ": " << len[i] << endl;

		tot += len[i];
	}
//
//	for(ll i = 1; i <= n; i++)
//	{
//		if(!(i & 1)) cout << i << ": " << len[i] << endl;
//	}

	cout << "Total: " << tot << endl;

}

//ll arr[10000002];
//
//void precalc()
//{
//	arr[1] = 1;
//	arr[2] = 2;
//
//	ll cnt = 0;
//	ll now = 2;
//
//	for(ll i = 3; i <= 10000000; i++)
//	{
//		arr[i] = arr[i - 1] + now;
//		cnt++;
//
//		if(cnt == 2) now++, cnt = 0;
//	}
//}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//
//	precalc();
//	while(cin >> n)
//	{
//		brute(n);
//		cout << arr[n] << endl;
//	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		ans = (n + 1) / 2;

		ans = ans * (ans - 1);

		ans += (n + 1) / 2;

		if(n % 2 == 0) ans += (n + 1) / 2;

		cout << ans << endl;

//		brute(n);

    }


}



